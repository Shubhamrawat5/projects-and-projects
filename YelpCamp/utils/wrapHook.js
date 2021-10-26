exports.pre = function(fn) {
    return function(next){
        fn(this)
            .then(() => next())
            .catch(err => next(err));
    }
}

exports.post = function(fn) {
    return function(doc,next){
        fn(doc)
            .then(() => next())
            .catch(err => next(err));
    }
}