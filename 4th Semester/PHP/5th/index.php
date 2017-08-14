<?php
    require "connection.php"
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Wassappp...</title>

    <link rel="stylesheet" href="bootstrap/css/bootstrap.css">

</head>
<body>

<div class="container">
    <div class="row">
        <div class="col-md-12">
            <h1>Student Record</h1>
            <hr>
            <div class="col-md-6">
                <div class="form-group">
                    <label for="name">Student Name</label>
                    <input type="text" name="name" id="name" class="form-control">
                </div>
                <div class="form-group">
                    <label for="email">E-mail</label>
                    <input type="text" name="email" id="email" class="form-control">
                </div>
                <div class="form-group">
                    <label for="password">Password</label>
                    <input type="password" name="password" id="password" class="form-control">
                </div>
                <div class="form-group">
                    <label for="gender">Gender</label><br>
                    <input type="radio" name="gender" value="M">&emsp;Male&emsp;
                    <input type="radio" name="gender" value="F">&emsp;Female&emsp;
                    <input type="radio" name="gender" value="O">&emsp;Other&emsp;
                </div>
                <div class="form-group">
                    <label for="language">Language</label><br>
                    <input type="checkbox" name="language[]" value="nep">&emsp;Nepali&emsp;<br>
                    <input type="checkbox" name="language[]" value="eng">&emsp;English&emsp;<br>
                </div>
            </div>
            <div class="col-md-6">Show</div>
        </div>
    </div>
</div>

</body>
</html>
