<?php
  class db {
    private function __construct() {
      $connection = mysqli_connect("localhost", "root", "", "webtech");
    }

    public function add_user($name, $password) {
      $trim_name = trim($name);
      $trim_password = trim($password);
      mysqli_query("insert into users (name, password) values ('$this->trim_name', '$this->trim_password')");
    }

    public function remove_user($id) {
      $id = trim($id);
      
    }

  }
  
?>