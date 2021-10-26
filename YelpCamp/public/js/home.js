const logoutLink = document.querySelector('#logout-link');
const logoutForm = document.querySelector('#logout-form');
if(logoutLink){
    logoutLink.addEventListener('click',function(e){
        e.preventDefault();
        logoutForm.submit();
    })
}