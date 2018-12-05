<head>
  <style>
  .warning {
    border: solid;
    border-color: red;
    border-radius: 5px;
    border-width: 5px;
    padding: 5px;
  }

  .success {
    border: solid;
    border-color: green;
    border-radius: 5px;
    border-width: 5px;
    padding: 5px;
  }  
  </style>
</head>

<?php
# example variable
$like = "content";
$number = 253;

# example loop
for ($i=0; $i < 10; $i++) { 
  echo("I like " . $like . ".<br/>");
}

if ($number < 500) {
  echo ("Number: " . $number . " is < 500<br/>");
} else {
  echo ("Number: " . $number . " is > 500<br/>");
}

if(isset($_GET["msg"])) {
  $msg = $_GET["msg"];
  if($msg == "loginerror") {
    echo "<div class=\"warning\">" . "Login error!" . '</div>';
  } else if ($msg = "loginsuccess") {
    echo '<div class="success">' . 'Login Successful' . '</div>';
  }
}

?>

<form action="logincheck.php" method="post">
  <h4>Enter your username: </h4>
  <input name="username" type="text"><br>
  <h4>Enter your password: </h4>
  <input name="password" type="password"><br>
  <h4>Enter code [5541]: </h4>
  <input name="code" type="number"><br>
  <input type="submit" value="Send 🕊">
</form>