const alerts = document.querySelectorAll('.alert');
for(const alert of alerts){
    setTimeout(function(){
        alert.children[0].click();
    },5000);
};