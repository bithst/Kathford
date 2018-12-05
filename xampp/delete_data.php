<?php
  require("connection.php");
  $id = $_GET["id"];

  if (!isset($_GET["id"])) {
    header("Location:display.php");
  }

  $delete_sql = "delete from user where id = $id";
  mysqli_query($connection, $delete_sql);

  header("Location:display.php");
?>