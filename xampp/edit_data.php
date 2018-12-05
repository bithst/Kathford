<?php
  if(!isset($_POST["id"]) || !isset($_POST["username"]) || !isset($_POST["password"])) {
    header("Location:dispaly.php");
  }

  $id = $_POST["id"];
  $username = $_POST["username"];
  $password = $_POST["password"];

  require("connection.php");

  $edit_sql = "update user set username='$username', password='$password' where id='$id'";
  mysqli_query($connection, $edit_sql);

  header("Location:display.php");
?>