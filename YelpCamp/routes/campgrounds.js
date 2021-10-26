const express = require('express');
const router = express.Router();

const middleware = require('../middleware');
const campgroundsController = require('../controllers/campgrounds');
const {upload} = require('../config/multer');

/*
home GET / => home page
index GET /campgrounds => shows all campgrounds
new GET /campgrounds/new => form for new campgrounds
show GET /campgrounds/:id => shows specific campgrounds
create POST /campgrounds => creates a new campgrounds on server
edit GET /campgrounds/:id/edit => form to edit a specific campgrounds
update PATCH /campgrounds/:id => edits form on server
destroy DELETE /campgrounds/:id => deletes form on server
delete GET /campgrounds/:id/delete => confirmation page to delete
*/

// /campgrounds

router.route('/')
    .get(campgroundsController.index)
    .post(middleware.ensureLogin,upload.array('image',10),campgroundsController.create);

router.get('/new',middleware.ensureLogin,campgroundsController.new);

router.route('/:id')
    .all(middleware.findCampground)
    .get(campgroundsController.show)
    .patch(middleware.ensureLogin,middleware.authorizeCampground,upload.array('image',10),campgroundsController.update)
    .delete(middleware.ensureLogin,middleware.authorizeCampground,campgroundsController.destroy);

router.get('/:id/edit',middleware.findCampground,middleware.ensureLogin,middleware.authorizeCampground,campgroundsController.edit);

router.get('/:id/delete',middleware.findCampground,middleware.ensureLogin,middleware.authorizeCampground,campgroundsController.delete);

module.exports = router;