<?php
    session_start();

    if($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['email']) && isset($_POST['password'])) {
        $email = $_POST['email'];
        $password = $_POST['password'];

        if($email == "admin@gmail.com" && $password == "admin") {
            $_SESSION["email"] = $email;
            header('Location:home.php');
        }else {
            $_SESSION['err'] = "Invalid email and/or password";
            header('Location:index.php');
        }
    }else {
        $_SESSION['err'] = "Invalid access!";
        header('Location:index.php');
    }
?>