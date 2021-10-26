const Campground = require('./models/campground');
const Review = require('./models/review');
const AppError = require('./utils/AppError');
const wrapAsync = require('./utils/wrapAsync');
const wrapAsyncFlash = require('./utils/wrapAsyncFlash');

exports.ensureLogin = function(req,res,next){
    if(req.isAuthenticated()) next();
    else{
        req.session.returnTo = req.originalUrl;
        req.flash('error','You must be logged in');
        res.redirect('/login');
    }
}

exports.ensureNoLogin = function(req,res,next){
    if(!req.isAuthenticated()) next();
    else{
        req.flash('error','You must be logged out');
        res.redirect('/campgrounds');
    }
}

exports.authorizeCampground = wrapAsync(async function(req,res,next){
    if(!req.campgroundQuery.author.equals(req.user._id)) throw new AppError('Forbidden',403);
    else next();
})

exports.findCampground = wrapAsync(async function(req,res,next){
    const {id} = req.params;
    const campground = await Campground.findById(id).exec();
    if(!campground) throw new AppError('Campground not found',404);
    else{
        req.campgroundQuery = campground;
        next();
    }
})

exports.authorizeReview = wrapAsync(async function(req,res,next) {
    const {reviewId} = req.params;
    const review = await Review.findById(reviewId).populate('author').exec();
    if(!review) throw new AppError('Not found',404);
    if(review.author.equals(req.user)) next();
    else throw new AppError('Forbidden',403);
})