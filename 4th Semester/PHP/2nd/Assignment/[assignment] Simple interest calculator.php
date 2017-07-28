<?php
    $result = "";
    if ($_SERVER["REQUEST_METHOD"] == "GET") {
        $result = "Simple Interest = ".($_GET["principle"] * $_GET["time"] * $_GET["rate"]) / 100;
    }
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Simple Interest Calculator</title>
</head>
<body>

<form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
    Principle: <input type="number" name="principle"><br>
    Time: <input type="number" name="time"><br>
    Rate: <input type="number" name="rate"><br>
    <?= $result?>
    <input type="submit" value="Calculate">
</form>


</body>
</html>