<?php
  $username = $_POST["username"];
  $password = $_POST["password"];
  $code = $_POST["code"];

  if ($code == 5541) {
    header("Location:index.php?msg=loginsuccess");
  } else {
    header("Location:index.php?msg=loginerror");
  }
?>