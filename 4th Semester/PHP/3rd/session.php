<?php
    session_start();
    $_SESSION["name"] = "Ram";
    $_SESSION["age"] = 12;

    echo $_SESSION["name"];
?>