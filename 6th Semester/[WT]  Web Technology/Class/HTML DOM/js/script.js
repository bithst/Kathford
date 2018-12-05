btn_counter = document.getElementById("btnCounter");
var count = 0;
btn_counter.onclick = function() {
  btn_counter.innerHTML = "Click #" + count;
  count++;
}

var btn_toggle = document.getElementById("btnToggle");
var txt_toggle = document.getElementById("textToggle");
var toggle = false
btn_toggle.onclick = function() {
  if (toggle) {
    toggle = false;
    txt_toggle.innerHTML = "On";
  } else {
    toggle = true;
    txt_toggle.innerHTML = "Off";
  }
}

var txt_swap_A = document.getElementById("txtSwapA");
var txt_swap_B = document.getElementById("txtSwapB");
var btn_swap = document.getElementById("btnSwap");
var temp;
btn_swap.onclick = function() {
  temp = txt_swap_A.innerHTML;
  txt_swap_A.innerHTML = txt_swap_B.innerHTML;
  txt_swap_B.innerHTML = temp;
}

var x_turn = true;
function TttSet() {
  if (x_turn) {
    set
  }
}