<?php
$variable = [
    ['name'=>'Ram', 'address'=>'Kathmandu', 'phone'=>987654321],
    ['name'=>'Ashish', 'address'=>'Bhaktapur', 'phone'=>98766666]
];

/*foreach($variable as $value){
    echo $value['name'].'<br>';
    echo $value['address'].'<br>';
}*/
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Associative array demo</title>
</head>
<body>

<table border="1">
    <tr>
        <th>Name</th>
        <th>Address</th>
        <th>Phone Number</th>
    </tr>
    <?php foreach($variable as $value) {?>
        <tr>
            <td><?= $value['name']?></td>
            <td><?= $value['address']?></td>
            <td><?= $value['phone']?></td>
        </tr>
    <?php }?>
</table>

</body>
</html>
