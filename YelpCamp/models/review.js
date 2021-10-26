const mongoose = require('mongoose');
const escape = require('escape-html');

const reviewSchema = new mongoose.Schema({
    body: {
        type: String,
        required: true
    },
    rating: {
        type: Number,
        min: 1,
        required: true
    },
    author: {
        type: mongoose.Schema.Types.ObjectId,
        ref: 'User',
        required: true
    },
    campground: {
        type: mongoose.Schema.Types.ObjectId,
        ref: 'Campground',
        required: true
    }
});

reviewSchema.pre('save',function(next){
    this.body = escape(this.body);
    next();
});

module.exports = mongoose.model('Review',reviewSchema);