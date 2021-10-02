var myWindow;
function openHome(){
    window.location.href="../index.html";
}

function openVerification(){
    window.location.href="src/form.html";
}
   
function openGateway(){
    myWindow=window.open("gateway.html","","width=300, height=400");
}

function openPayment(){
    window.location.href="payment.html";
}

function openSlot(){
    window.location.href="slot.html";
}

var count = 0;
var flag=0;

function display_slot(){
	items = document.getElementsByClassName("blockslot");
    flag+=1;
    if(flag==3){
        document.getElementById("cont").style.display="none";
        items[count++].style.display = "block";
    }
    if(count < items.length){
       	items[count++].style.display = "block";
    }
}

function display_payment(){
    var count=0;
    items = document.getElementsByClassName("blockpay");
    if(count < items.length){
       	items[count++].style.display = "block";
    }
    document.getElementById("hide1").style.display="none";
    document.getElementById("hide2").style.display="none";
    document.getElementById("hide3").style.display="none";
}

$.getJSON('https://api.rootnet.in/covid19-in/unofficial/covid19india.org/statewise', function(result) 
{
    addRow($("#resultTable tfoot"), result.data.total);
    result.data.statewise.forEach(el=>addRow($("#resultTable tbody"),el));
    
});

function addRow(parent, el)
{
  var tr = $("<tr/>");
  
  tr.append($("<td>"+(el.state == undefined?"Overall":el.state)+"</td>"));
  tr.append($("<td>"+el.confirmed+"</td>"));
  tr.append($("<td>"+el.recovered+"</td>"));
  tr.append($("<td>"+el.deaths+"</td>"));
  tr.append($("<td>"+el.active+"</td>"));
  parent.append(tr);
}