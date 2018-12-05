 <?php
  require("connection.php");

  $select_all_sql = "select * from user";
  $database = mysqli_query($connection, $select_all_sql);

  echo '<table border=1><tr><th>ID</th><th>Username</th><th>Password</th><th>Action</th></tr>';
  while($dat = mysqli_fetch_array($database)) {
    echo "<tr><td>$dat[0]</td><td>$dat[1]</td><td>$dat[2]</td><td> <a href=\"edit_form.php?id=$dat[0]\">Edit</a> <a href=\"delete_data.php?id=$dat[0]\">Delete</a> </td></tr>";
  }
  echo "<tr><td colspan=\"4\"><a href=\"register.php\">Add user</a></td></tr>";
  echo "</table>"
?>