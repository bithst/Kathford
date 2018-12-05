<?php
  if(isset($_POST["username"]) && isset($_POST["password"]) && isset($_POST["confirm_password"])) {
    $username = $_POST["username"];
    $password = $_POST["password"];
    $confirm_password = $_POST["confirm_password"];
  } else {
    header("Location:display.php");
  }

  if ($password != $confirm_password) {
    header("Location:register.php");
  }

  $connection = mysqli_connect("localhost", "root", "", "webtech");

  $check_sql = "select * from user where username = '$username'";
  $check_data = mysqli_query($connection, $check_sql);
  while($dat = mysqli_fetch_array($check_data)) {
    if($dat[1] == $username) {
      header("Location:register.php");
    }
  }
  
  $insert_sql = "insert into user (username, password) values ('$username', '$password')";
  mysqli_query($connection, $insert_sql);

  header("Location:display.php");
?>