<?php
define("user", "admin");
define("pass", "admin");

if($_SERVER["REQUEST_METHOD"] == "POST") {
    if(!empty($_POST["username"]) && !empty($_POST["password"])) {
        session_start();
        $_SESSION["username"] = $_POST["username"];
        $_SESSION["password"] = $_POST["password"];

        if($_SESSION["username"] == user && $_SESSION["password"] == pass) {

        }else {
            session_destroy();
        }
    }
}
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Upload file</title>
</head>
<body>

</body>
</html>
