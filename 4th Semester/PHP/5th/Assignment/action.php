<?php
    require_once 'db_connect.php';
    session_start();
    if(!empty($_POST) && $_SERVER['REQUEST_METHOD'] == 'POST') {
        $name = $_POST['name'];
        $email = $_POST['email'];
        $password = $_POST['password'];
        $gender = $_POST['gender'];
        $language = implode(',', $_POST['language[]']);
        $sql = "INSERT INTO tbl_student(name, email, password, gender, language) VALUES('".$name."', '".$email."', '".$password."', '".$gender."', '".$language."')";
        $result = mysqli_query($conn, $sql);
        if($result == true) {
            $_SESSION['success'] = 'Data inserted successfully.';
            header('Location:index.php');
        }else {
            $_SESSION['error'] = 'There was a problem inserting the data.';
            header('Location: index.php');
        }
    }else {
        $_SESSION['error'] = 'Invalid access to file.';
        header('Location: index.php');
    }
?>