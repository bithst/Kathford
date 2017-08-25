<?php
require_once '../database/connection.php';

if(!empty($_POST) && $_SERVER['REQUEST_METHOD']=='POST'){
    $name=$_POST['name'];
    $sql="INSERT INTO menu(name)VALUES('$name')";
    $result=mysqli_query($conn,$sql);
    if($result==true){
        echo "menu was inserted";
    }

}

?>




<h1>Add Menu</h1>
<hr>

<form action="" method="post">
    <label for="menu"> Menu Name</label>
    <br>
    <input type="text" name="name" id="menu">
    <br>
    <br>
    <button type="submit">Add Menu</button>

</form>