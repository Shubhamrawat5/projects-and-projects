const express = require('express');
const router = express.Router();
const passport = require('passport');
const middleware = require('../middleware');

const usersController = require('../controllers/users');

const {upload} = require('../config/multer');

/*
registerShow GET /register => shows register page
register POST /register => registers user on server
loginShow GET /login => shows login page
login POST /login => logins user on server
logout POST /logout => logouts user on the server
settings GET /settings => shows settings page
changePasswordShow GET /settings/change-password => shows change password page
changePassword POST /settings/change-password => changes password on the server
delete GET /settings/delete => shows confirmation page for deleting
destroy POST /settings/delete => deletes user on server
*/

router.route('/register')
    .all(middleware.ensureNoLogin)
    .get(usersController.registerShow)
    .post(usersController.register);

router.route('/login')
    .all(middleware.ensureNoLogin)
    .get(usersController.loginShow)
    .post(passport.authenticate('local',{failureFlash: true, failureRedirect: '/login'}),usersController.login);

router.post('/logout',middleware.ensureLogin,usersController.logout);

router.get('/settings',middleware.ensureLogin,usersController.settings);

router.route('/settings/change-password')
    .all(middleware.ensureLogin)
    .get(usersController.changePasswordShow)
    .post(usersController.changePassword);

router.route('/settings/delete')
    .all(middleware.ensureLogin)
    .get(usersController.delete)
    .post(usersController.destroy);

router.get('/my-campgrounds',middleware.ensureLogin,usersController.myCampgrounds);

router.post('/change-profile-photo',middleware.ensureLogin,upload.single('profile-photo'),usersController.changeProfilePhoto);

router.post('/remove-profile-photo',middleware.ensureLogin,usersController.removeProfilePhoto);

module.exports = router;