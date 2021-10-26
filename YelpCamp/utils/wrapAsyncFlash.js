module.exports = function(fn,path,message){
    return function(req,res){
        fn(req,res).catch(err => {
            req.flash('error',message || err.message);
            res.redirect(path);
        });
    }
}