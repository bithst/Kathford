<?php
setcookie("name", "Ram", time()+20);
// setcookie(name, value, time of expiration);

//error_reporting(0);   to not display the errors on the page

session_start();
foreach($_SESSION as $value) {
    echo $value,"<br>";
}
session_destroy();

?>