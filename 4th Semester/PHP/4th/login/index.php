<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Page</title>
</head>
<body>

<h1>Login page</h1>
<?php
    session_start();

    if(isset($_SESSION['err'])){
        echo '<hr>';
        echo $_SESSION['err'];
        unset($_SESSION['err']);
    }
?>
<hr>

<form action="login.php" method="post">

    <label for="email">Email</label><br>
    <input type="email" name="email"><br>

    <label for="password">Password</label><br>
    <input type="password" name="password"><br>

    <button type="submit">Login</button>
</form>
</body>
</html>
