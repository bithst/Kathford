var submit_btn = document.getElementById("submit");

submit_btn.onclick = function() {
	var user = document.login.uname;
	var pass = document.login.pword;
	
	if (user.value == "Ram" && pass.value == "123456") {
		alert("Logged in");
	} else {
		alert("Unauthorized user!!!");
	}
}