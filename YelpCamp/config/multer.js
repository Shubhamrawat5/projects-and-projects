const fs = require('fs/promises');
const cloudinary = require('cloudinary').v2;
const {CloudinaryStorage} = require('multer-storage-cloudinary');

cloudinary.config({
    cloud_name: process.env.CLOUDINARY_CLOUD_NAME,
    api_key: process.env.CLOUDINARY_KEY,
    api_secret: process.env.CLOUDINARY_SECRET
});

const multer = require('multer');
const storage = new CloudinaryStorage({
    cloudinary,
    params: {
        folder: 'YelpCamp'
    }
});
const upload = multer({
    storage,
    limits: {
        fileSize: 10*1024*1024
    }
});

module.exports = {upload,cloudinary};