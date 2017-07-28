<?php
session_start();

if(empty($_SESSION['email'])) {
    $_SESSION["err"] = "Invalid access.";
    header('Location:index.php');
}
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Welcome</title>
</head>
<body>

<h1>x</h1>
<hr>
<a href="login.php">Logout</a>

</body>
</html>
