<?php
for($i = 0; $i < 10; $i++) {
    echo "Number ".$i.'<br>';
}

echo '<br>'."Using while loop:".'<br>';
$j = 0;
while ($j < 10) {
    echo $j.'<br>';
    $j++;
}

echo '<br>'."Using do..while loop:".'<br>';
do {
    echo $j;
    $j--;
} while($j > 0);
?>

    