const mongoose = require('mongoose');
const escape = require('escape-html');
const {cloudinary} = require('../config/multer');
const Review = require('../models/review');
const Image = require('../models/image');
const wrapHook = require('../utils/wrapHook');
const geocoder = require('../config/mapbox');
const AppError = require('../utils/AppError');

const campgroundScheme = new mongoose.Schema({
    title: {
        type: String,
        required: true
    },
    location: {
        type: String,
        required: true
    },
    geometry: {
        type: {
            type: String,
            enum: ['Point'],
            required: true
        },
        coordinates: {
            type: [Number],
            required: true
        }
    },
    price: {
        type: Number,
        required: true,
        min: 0
    },
    description: {
        type: String,
        required: true
    },
    image: [Image.required],
    reviews: [{
        type: mongoose.Schema.Types.ObjectId,
        ref: 'Review'
    }],
    author: {
        type: mongoose.Schema.Types.ObjectId,
        ref: 'User',
        required: true
    }
},{toJSON: {virtuals:true}});

campgroundScheme.virtual('properties.popupHtml').get(function(){
    return `
            <a href="/campgrounds/${this._id}">${this.title}</a>
            <br>
            ${this.location}`;
});

campgroundScheme.pre('validate', function(next){
    this.title = escape(this.title);
    this.description = escape(this.description);
    this.location = escape(this.location);
    next();
});

campgroundScheme.pre('validate',wrapHook.pre(async function(campground){
    const geo = await geocoder.forwardGeocode({
        query: campground.location,
        limit: 1
    }).send();
    if(geo.body.features.length === 0) throw new AppError('Location not found. Please enter a valid location',400);
    campground.geometry = geo.body.features[0].geometry;
}));

campgroundScheme.post('deleteOne', {document: true, query: false},wrapHook.post(async function(campground){
    for(const file of campground.image) await cloudinary.uploader.destroy(file.filename);
    await Review.deleteMany({_id:{$in:campground.reviews}});
}));

module.exports = mongoose.model('Campground',campgroundScheme);