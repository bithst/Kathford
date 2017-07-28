<?php
    $valid = array(
        "jpg", "png", "bmp", "gif", "jpeg"
    );
    $err_file = null;

    if(!empty($_FILES) && $_SERVER["REQUEST_METHOD"] == "POST"){
        $ext = pathinfo($_FILES["upload"]["name"], PATHINFO_EXTENSION);
        $filename = md5(time()).".".$ext;
        $path = "uploads/".$filename;
        $error = $_FILES["upload"]["error"];

        if($error == 0) {
            for($i = 0; $i < sizeof($valid); $i++) {
                if ($ext == $valid[$i]) {
                    move_uploaded_file($_FILES["upload"]["tmp_name"], $path);
                }else {
                    $err_file = "File extension is not supported.";
                }
            }
        }
    }
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>

<form action="" method="POST" enctype="multipart/form-data">
    <input type="file" name="upload">
    <br>
    <?= $err_file?>
    <br>
    <button type="submit" formaction="login.php" method="POST">Upload</button>
</form>

</body>
</html>