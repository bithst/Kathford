<?php
  require("connection.php");
  $id = $_GET["id"];

  if (!isset($_GET["id"])) {
    header("Location:display.php");
  }

  $data_sql = "select * from user where id=$id";
  $dat = mysqli_fetch_array(mysqli_query($connection, $data_sql))
?>

<form action="edit_data.php" method="post">
  <input type="hidden" name="id" value="<?php echo $dat[0]?>">
  Username <input type="text" value="<?php echo $dat[1];?>" name="username"><br>
  Password <input type="text" value="<?php echo $dat[2];?>" name="password"><br>
  <input type="submit" value="Save changes">
</form>