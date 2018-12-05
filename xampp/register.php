<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Register User</title>

  <style>
    .container {
      display: grid;
      
    }
  </style>
</head>
<body>

<form action="register_user.php" method="post">
  Username: <input type="text" name="username"><br>
  Password: <input type="password" name="password"><br>
  Confirm password: <input type="password" name="confirm_password">
  <input type="submit" value="Register">
</form>

</body>
</html>