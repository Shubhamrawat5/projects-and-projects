const express = require('express');
const router = express.Router({mergeParams: true});
const middleware = require('../middleware');
const reviewsController = require('../controllers/reviews');

/*
create POST /campgrounds/:id/reviews => creates a review on server
destroy DELETE /campgrounds/:id/reviews/:reviewId => deletes review on the server
*/

// /campgrounds/:id/reviews

router.post('/',middleware.findCampground,middleware.ensureLogin,reviewsController.create);

router.delete('/:reviewId',middleware.findCampground,middleware.ensureLogin,middleware.authorizeReview,reviewsController.destroy);

module.exports = router;