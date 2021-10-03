burger=document.querySelector('.burger')
navbar=document.querySelector('.navbar')
navlist=document.querySelector('.navlist')
rightnav=document.querySelector('.rightnav')

burger.addEventListener('click',()=>{
	navbar.classList.toggle('h-nav-resp');
	rightnav.classList.toggle('v-class-resp');
	navlist.classList.toggle('v-class-resp');
	
})
window.addEventListener("DOMContentLoaded",event =>{
	let topButton =document.getElementById("topButton")
	window.onscroll = () =>{
	    if(
		document.body.scrollTop > 20 || document.documentElement.scrollTop > 20//for hiding top button 
	    ) {
		topButton.style.display = "block"
	    }else{
		topButton.style.display='none'
	    }
	}
       })