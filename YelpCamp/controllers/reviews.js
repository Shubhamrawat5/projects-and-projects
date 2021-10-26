const Review = require('../models/review');
const wrapAsync = require('../utils/wrapAsync');

exports.create = wrapAsync(async (req,res) => {
    if(req.body.review.rating == 0){
        req.flash('error','Rating must be atleast 1 star');
        res.redirect(`/campgrounds/${req.params.id}`);
        return;
    }
    const review = new Review(req.body.review);
    review.author = req.user._id;
    review.campground = req.campgroundQuery;
    await review.save();
    req.campgroundQuery.reviews.push(review);
    await req.campgroundQuery.save();
    req.flash('success','Successfully added the review');
    res.redirect(`/campgrounds/${req.params.id}`);
})

exports.destroy = wrapAsync(async (req,res) => {
    const {id,reviewId} = req.params;
    await req.campgroundQuery.update({$pull:{reviews:reviewId}});
    await Review.findByIdAndDelete(reviewId);
    req.flash('success','Successfully deleted the review');
    res.redirect(`/campgrounds/${id}`);
})