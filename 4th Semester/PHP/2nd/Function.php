<?php
/*
function Test() {
    echo "I'm a function";
}
Test();

function sum($a=null, $b=null) {

    echo $a+$b;
}
sum(12, 20);

function dbl($v) {
    return 2*$v;
}
echo dbl(24);

*/?>

<?php

function sumsub($x, $y) {
    return [$x+$y, $x-$y];
}

$data = sumsub(12, 34);
echo "Sum: ".$data[0].'<br>'."Sub: ".$data[1].'<br>';

?>