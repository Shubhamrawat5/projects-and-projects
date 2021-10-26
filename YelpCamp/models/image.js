module.exports.required = {
    _id: false,
    path: {
        type: String,
        required: true
    },
    filename: {
        type: String,
        required: true
    }
}

module.exports.optional = {
    _id: false,
    path: String,
    filename: String
}