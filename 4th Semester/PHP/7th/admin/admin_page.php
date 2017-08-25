<?php
$page=$_GET['page'] ? $_GET['page']:'home';
$title=$page;
$page=$page.'.php';
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Welcome : <?=$title?></title>
    <link rel="stylesheet" href="../public/bootstrap/css/bootstrap.css">
</head>
<body>

<?php
$pagePath='pages/'.$page;
if(file_exists($pagePath) && is_file($pagePath) ){
    require_once $pagePath;
}else{
    require_once '../errors/404.php';
}
?>


<script src="../public/bootstrap/js/jquery.js"></script>
<script src="../public/bootstrap/js/bootstrap.js"></script>

</body>
</html>
