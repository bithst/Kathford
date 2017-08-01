<?php
    define('HOST', 'localhost');
    define('USER', 'root');
    define('PASSWORD', '');
    define('DBNAME', 'db_kathford');

    $conn = mysqli_connect(HOST, USER, PASSWORD, DBNAME);

    /*if($conn) {
        echo "Connected successfully.";
    }else {
        echo "Couldn't connect to the SQL server.";
    }*/
?>