const {cloudinary} = require('../config/multer');
const User = require('../models/user');
const Campground = require('../models/campground');
const Review = require('../models/review');
const wrapAsync = require('../utils/wrapAsync');
const wrapAsyncFlash = require('../utils/wrapAsyncFlash');

exports.registerShow = (req,res) => {
    res.render('minified/users/register');
}

exports.register = wrapAsyncFlash(async (req,res) => {
    const {username,email,password} = req.body;
    const user = new User({username,email});
    await User.register(user,password);
    req.logIn(user,(err) => {
        if(err) throw err;
        req.flash('success','Welcome to YelpCamp');
        res.redirect('/campgrounds');
    })
},'/register')

exports.loginShow = (req,res) => {
    res.render('minified/users/login');
}

exports.login = (req,res) => {
    req.flash('success','Successfully logged in');
    const Url = (req.session.returnTo)?req.session.returnTo:'/campgrounds';
    delete req.session.returnTo;
    res.redirect(Url);
}

exports.logout = (req,res) => {
    req.logOut();
    req.flash('success','Successfully loggout out');
    res.redirect('/campgrounds');
}

exports.settings = (req,res) => {
    res.render('minified/users/settings');
}

exports.changePasswordShow = (req,res) => {
    res.render('minified/users/change-password');
}

exports.changePassword = wrapAsyncFlash(async (req,res) => {
    const {current:oldPassword,'new':newPassword} = req.body;
    await req.user.changePassword(oldPassword,newPassword);
    req.flash('success','Successfully changed the password');
    res.redirect('/settings');
},'/settings/change-password','Incorrect current password')

exports.delete = (req,res) => {
    res.render('minified/users/delete');
}

exports.destroy = wrapAsync(async (req,res) => {
    await req.user.deleteOne();
    res.redirect('/');
})

exports.myCampgrounds = async (req,res) => {
    req.user.populate('campgrounds',function(){
        res.render('minified/users/my-campgrounds');
    })
}

exports.changeProfilePhoto = wrapAsyncFlash(async (req,res) => {
    if(req.user.profilePhoto.filename) await cloudinary.uploader.destroy(req.user.profilePhoto.filename);
    req.user.profilePhoto = {
        path: req.file.path,
        filename: req.file.filename
    };
    await req.user.save();
    req.flash('success','Successfully changed the profile photo');
    res.redirect('/settings');
},'/settings')

exports.removeProfilePhoto = wrapAsyncFlash(async (req,res) => {
    if(req.user.profilePhoto.filename){
        await cloudinary.uploader.destroy(req.user.profilePhoto.filename);
        req.user.profilePhoto = {};
        await req.user.save();
    }
    req.flash('success','Successfully removed the profile photo');
    res.redirect('/settings');
},'/settings')