let a = document.getElementById("test");
let i = 0;
a.innerHTML = i;

a.onclick = function () {
  a.innerHTML = i;
  i++;
}

function fun3() {
  var el = document.faram.name.value;
  alert(el);
}

heading2 = document.getElementById("woop");

heading2.onclick = function() {
	alert("Click OK. OK? OK!");
}