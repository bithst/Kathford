<?php
$page=$_GET['page'] ? $_GET['page']:'home';
$title=$page;
$page=$page.'.php';
?>

<?php  require_once 'layouts/header.php'?>

<?php
$pagePath='pages/'.$page;
if(file_exists($pagePath) && is_file($pagePath) ){
   require_once $pagePath;
}else{
  require_once 'errors/404.php';
}
?>


<?php  require_once 'layouts/footer.php'?>