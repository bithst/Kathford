<?php
  require("database.php");
  $db = new db();

  echo $db->add_user("abc", "def");
?>