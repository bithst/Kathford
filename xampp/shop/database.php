<?php
  class db {
    function __construct() {
      $this->connection = mysqli_connect("localhost", "root", "", "webtech");
    }

    public function add_user($name, $bio = "", $password, $profile_picture = "", $access_type = "basic") {
      $trim_name = trim($name);
      $trim_password = trim($password);
      $query = "insert into users (name, password, bio, profile_image, access_type) values ('$trim_name', '$trim_password')";
      return mysqli_query($this->connection, $query);
    }

    public function remove_user($id) {
      $id = trim($id);
      $query = "delete from user where id = $id";
      return mysqli_query($this->connection, $query);
    }

    public function edit_user($id, $name, $bio = "", $password, $profile_picture = "", $access_type = "basic") {

    }

    public function add_product() {

    }

    function __destruct() {
      mysqli_close($this->connection);
    }
  }
?>