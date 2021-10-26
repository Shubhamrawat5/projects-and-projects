const maxSize = 10*1024*1024;
const files = document.querySelector('#image');
const form = document.querySelector('#main-form');
function fileChange(e){
    for(const file of files.files){
        if(file.size > maxSize){
            e.preventDefault();
            location.reload();
            break;
        }
    }
}
form.addEventListener('submit',fileChange);