<?php
//Old method
$a=array('Ram', 'Kathmandu', 987654321, 'Teacher');

//var_dump($a);

//echo '<pre';
//print_r($a);

//echo $a[1];

//sizeof($var) && count($var)

//for($i = 0; $i < count($a); $i++) {
//    echo $a[$i].'<br>';
//}

//New method
$college = [
    ['Ram', 'Bhaktapur', 24],
    ['Hari', 'Lalitpur', 30]
];

echo "The array is:".'<br><pre>';
print_r($college);
echo '<br></pre>';


for($i = 0; $i < sizeof($college); $i++) {
    for($j = 0; $j < sizeof($college[$i]); $j++) {
        echo $college[$i][$j].'<br>';
    }
}