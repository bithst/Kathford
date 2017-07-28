<?php
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>File Upload</title>
</head>
<body>

<form action="<?php $_SERVER["PHP_SELF"]?>" method="POST">
    <fieldset>
        <legend>Login</legend>
        <table align=>
            <tr>
                <td>Username:</td>
                <td><input type="text" name="username" placeholder="Enter your username"></td>
            </tr>
            <tr>
                <td>Password:</td>
                <td><input type="password" name="password" placeholder="Enter your password"></td>
            </tr>
        </table>

        <button type="submit" formaction="login.php" formmethod="post">Login</button>
    </fieldset>
</form>

</body>
</html>
