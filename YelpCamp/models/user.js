const mongoose = require('mongoose');
const passportLocalMongoose = require('passport-local-mongoose');
const Campground = require('../models/campground');
const Review = require('../models/review');
const Image = require('../models/image');
const wrapHook = require('../utils/wrapHook');
const {cloudinary} = require('../config/multer');

const userSchema = new mongoose.Schema({
    email: {
        type: String,
        required: true
        // unique: true
    },
    campgrounds: [{
        type: mongoose.Schema.Types.ObjectId,
        ref: 'Campground'
    }],
    profilePhoto: Image.optional
});
userSchema.plugin(passportLocalMongoose);
//TODO: add email validation

userSchema.post('deleteOne',{document: true, query: false},wrapHook.post(async function(user){
    //deleting all campgrounds of the user
    const campgrounds = await Campground.find({author: user._id});
    for(const campground of campgrounds) await campground.deleteOne();

    //deleting all reviews of the user
    const reviews = await Review.find({author: user._id}).populate('campground','reviews').exec();
    for(const review of reviews){
        await review.deleteOne();
        await review.campground.update({$pull:{reviews: review._id}});
    }

    //deleting profile photo of the user
    if(user.profilePhoto.filename) await cloudinary.uploader.destroy(user.profilePhoto.filename);
}));

module.exports = mongoose.model('User',userSchema);