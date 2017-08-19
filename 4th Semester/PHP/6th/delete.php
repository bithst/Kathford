<?php
    require_once 'db_connect.php';
    session_start();
    if(!empty($_POST) && $_SERVER['REQUEST_METHOD'] == 'POST') {
        $email = $_POST['email'];
        $sql = 'DELETE FROM tbl_student WHERE email=\''.$email.'\'';
        $result = mysqli_query($conn, $sql);
        if($result) {
            $_SESSION['success'] = 'User was removed from database.';
            header('Location: index.php');
        }else {
            $_SESSION['error'] = 'There was a problem while removing the user.';
            header('Location: index.php');
        }
    }else {
        $_SERVER['error'] = 'Invalid access.';
        header('Location: index.php');
    }
?>