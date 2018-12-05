<?php
  class User {
    function __construct() {
      echo "First time <br>";
    }

    function speak() {
      return "Hello world!<br>";
    }

    function repeat($var) {
      echo "I heard '{$var}'.<br>";
    }

    function __destruct() {
      echo "Last time <br>";
    }
  }

  $ram = new User;

  echo $ram->speak();
  $ram->repeat("Say this");
?>