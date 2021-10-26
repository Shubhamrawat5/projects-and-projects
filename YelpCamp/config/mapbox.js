const mbxGeocoding = require('@mapbox/mapbox-sdk/services/geocoding');
const geocoder = mbxGeocoding({accessToken: process.env.mbxToken});

module.exports = geocoder;