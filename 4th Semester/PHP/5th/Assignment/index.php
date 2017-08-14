<?php
require_once "db_connect.php";
session_start();
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Form</title>

    <link rel="stylesheet" href="bootstrap/css/bootstrap.css">

</head>
<body>

<div class="container">
    <div class="row">
        <div class="col-md-12">
            <h1>Student Record</h1>
            <hr>
            <?php
                if(isset($_SESSION['success'])):
            ?>
            <div class="alert alert-success">
                <?=
                    $_SESSION['success'];
                    unset($_SESSION['success']);
                ?>
            </div>
            <?php endif;?>
            <?php
            if(isset($_SESSION['error'])):
                ?>
                <div class="alert alert-danger">
                    <?=
                    $_SESSION['error'];
                    unset($_SESSION['error']);
                    ?>
                </div>
            <?php endif;?>

            <div class="col-md-6">
                <form action="action.php" method="post">
                <div class="form-group">
                    <label for="name">Student Name</label>
                    <input type="text" name="name" id="name" placeholder="Full name" class="form-control">
                </div>
                <div class="form-group">
                    <label for="email">E-mail</label>
                    <input type="text" name="email" id="email" placeholder="E-mail address" class="form-control">
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
                    <input type="checkbox" name="language[]" value="nep">&emsp;Nepali&emsp;
                    <input type="checkbox" name="language[]" value="eng">&emsp;English&emsp;
                </div>
                <div class="form-group">
                    <button type="submit" formmethod="post" formaction="action.php" class="btn btn-success">Add new</button>
                </div>
                </form>
            </div>

            <div class="col-md-6">
                <?php
                    $sql = "SELECT * FROM tbl_student";
                    $result = mysqli_query($conn, $sql);
                    $totalData = mysqli_num_rows($result);
                ?>
            </div>
            <div class="col-md-8">
                <hr>
                <h2>User data</h2>
                <hr>

                <table class="table">
                    <tr>
                        <th>Name</th>
                        <th>Email</th>
                        <th>Gender</th>
                        <th>Language</th>
                    </tr>
                    <?php while($row = mysqli_fetch_assoc($result)) :?>
                    <tr>
                        <td><?= $row['name']?></td>
                        <td><?= $row['email']?></td>
                        <td><?= $row['gender']?></td>
                        <td><?= $row['language']?></td>
                        <td>
                            <form action="delete.php" method="post">
                                <input type="hidden" name="email" value="<?= $row['email'];?>">
                                <button type="submit" formaction="delete.php" formmethod="post" class="btn btn-danger btn-sm">Delete</button>
                            </form>
                        </td>
                    </tr>
                    <?php endwhile;?>
                </table>
            </div>
        </div>
    </div>
</div>

</body>
</html>
