<?php
    //Variables to show error message on the page if any error occur.
    $err_name = $err_age = $err_gender = $err_country = $err_url = "";
    $err_qualificationYear = $err_username = $err_email = "";
    $err_password = $err_rePassword = $err_vehicle = "";

    //Variables to store data coming from the html page.
    $fName = $mName = $lName = $age = $gender = $country = $vehicle = $social = "";
    $courseName = $qualification = $qualificationDate = $email = $username = $password = $rePassword = "";

    //Constants for error messages.
    define("req", "Required field!!!");
    define("inv", "invalid Value!");

    //Constants for multiple choice and/or lists in the form
    define("_gender", array(
        ["value"=>"male", "text"=>"Male"],
        ["value"=>"female", "text"=>"Female"],
        ["value"=>"other", "text"=>"Other"]
    ));
    define("_country", array(
        ["value"=>"NP", "text"=>"Nepal"],
        ["value"=>"IN", "text"=>"India"],
        ["value"=>"CN", "text"=>"China"],
        ["value"=>"DE", "text"=>"Germany"],
        ["value"=>"US", "text"=>"United States of America"],
        ["value"=>"JP", "text"=>"Japan"],
    )); //Uses ISO2 country codes for the value field
    define("_vehicle", array(
        ["value"=>"cycle", "text"=>"Cycle"],
        ["value"=>"motor-bike", "text"=>"Bike"],
        ["value"=>"car", "text"=>"Car"]
    ));

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(empty($_POST["firstName"]) || empty($_POST["lastName"])) {
        $err_name = req;
    }
    elseif(!preg_match("/^[a-zA-Z ]*$/",$_POST["firstName"]) || !preg_match("/^[a-zA-Z ]*$/",$_POST["middleName"]) || !preg_match("/^[a-zA-Z ]*$/",$_POST["lastName"])) {
        $err_name = "Only alphabets [a-z][A-Z] and whitespaces are allowed!";
    }
    else {
        $fName = test_input($_POST["firstName"]);
        $mName = test_input($_POST["middleName"]);
        $lName = test_input($_POST["lastName"]);
    }

    if(empty($_POST["age"])) {
        $err_age = req;
    }
    elseif($_POST["age"] < 15 || $_POST["age"] > 50){
        $err_age = "Enter age in the range 15 to 50";
    }
    else{
        $age = test_input($_POST["age"]);
    }

    if(empty($_POST["gender"])) {
        $err_gender = req;
    }
    else {
        foreach (_gender as $value) {
            if($_POST["gender"] == $value["value"]) {
                $gender = $_POST["gender"];
                break;
            }
            else {
                $err_gender = inv;
            }
        }
    }

    if(empty($_POST["country"])) {
        $err_country = req;
    }
    else {
        foreach (_country as $value) {
            if($_POST["country"] == $value["value"]) {
                $country = test_input($_POST["country"]);
                break;
            }
            else {
                $err_country = inv;
            }
        }
    }

    if(!empty($_POST["vehicle"])) {
        $vehicle = $_POST["vehicle"];
        for($i = 0; $i < sizeof($_POST["vehicle"]); $i++) {
            $vehicle[$i] = test_input($vehicle[$i]);
        }
    }

    $social = test_input($_POST["socialMedia"]);
    $courseName = test_input($_POST["courseName"]);
    $qualification = test_input($_POST["qualification"]);
    $qualificationDate = test_input($_POST["qualificationDate"]);
    $email = test_input($_POST["email"]);
    $username = test_input($_POST["userName"]);
    $password = test_input($_POST["newPassword"]);
    $rePassword = test_input($_POST["retypedPassword"]);
}

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Form</title>
</head>
<body>
<h1>
    Form
</h1>
<i>Fields with * are <b>required</b>.</i><br><br>

<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
    <fieldset>
        <legend>Personal information</legend>

        Name<br>
        <input type="text" name="firstName" placeholder="First name" autofocus>
        <input type="text" name="middleName" placeholder="Middle name">
        <input type="text" name="lastName" placeholder="Last name">
        * <?= $err_name?>
        <br>

        <br>Age<br>
        <input type="number" name="age" placeholder="15+">
        * <?= $err_age?>
        <br>

        <br>Gender
        * <?= $err_gender?>
        <br>
        <?php
            foreach(_gender as $key=>$value) {
                echo "<input type=\"radio\" name=\"gender\" value=\"".$value["value"]."\"".($key == 0 ? "checked" : "").">".$value["text"]."<br>";
                $key++;
            }
        ?>

        <br>Country<br>
        <select name="country">
        <?php
            foreach(_country as $value) {
                echo "<option value=\"".$value["value"]."\">".$value["text"]."</option>";
            }
        ?>
        </select>
        * <?= $err_country?>
        <br>

        <br>Vehicles owned
        <?= " ".$err_vehicle?>
        <br>
        <?php
            foreach(_vehicle as $value) {
                echo "<input type=\"checkbox\" name=\"vehicle[]\" value=\"".$value["value"]."\">".$value["text"]."<br>";
            }
        ?>

        <br>Social media<br>
        <input type="url" name="socialMedia" placeholder="Web link to your social media page" size="100">
        <?php echo $err_url?>
        <br>
    </fieldset>

    <fieldset>
        <legend>Course information</legend>

        Course name<br>
        <select name="courseName">
            <option value="bscCSIT">B.sc. CSIT</option>
            <option value="bit">BIT</option>
            <option value="bba">BBA</option>
        </select><br>

        <br>Previous qualification<br>
        <input list="qualification" name="qualification" placeholder="Qualification level">
        <datalist id="qualification">
            <option value="slc">School Level Certificate</option>
            <option value="+2">Plus two</option>
            <option value="SEE">Secondary Education Examination</option>
        </datalist>
        *
        <br>

        <br>Qualification year<br>
        <input type="number" name="qualificationDate" min="2012" max="2017" placeholder="Year">
        * <?php echo $err_qualificationYear?>
        <br>
    </fieldset>

    <fieldset>
        <legend>Account information</legend>

        Email<br>
        <input type="email" name="email" size="50" placeholder="someone@example.com">
        * <?php echo $err_email?>
        <br>

        <br>Username<br>
        <input type="text" name="userName" placeholder="User-name (4-16 chars)" min="4" max="16">
        * <?php echo $err_username?>
        <br>

        <br>New password<br>
        <input type="password" name="newPassword" placeholder="8-50 characters" min="8" max="50">
        * <?php echo $err_password?>
        <br>

        <br>Re-type password<br>
        <input type="password" name="retypedPassword" placeholder="Re-type your password" min="8" max="50">
        * <?php echo $err_rePassword?>
        <br>
    </fieldset>


    <br><br><input type="submit" value="Submit">
    <input type="reset" value="Reset">
</form>

<table align="center" border="1">
    <tr>
        <th>Name</th>
        <th>Age</th>
        <th>Gender</th>
        <th>Country</th>
        <th>Vehicles</th>
        <th>Social media</th>
    </tr>

    <tr>
        <td><?= $fName." ".$mName." ",$lName?></td>
        <td><?= $age?></td>
        <td><?= $gender?></td>
        <td><?= $country?></td>
        <td><?php
            if(!empty($vehicle)){
                for($i = 0; $i < sizeof($vehicle); $i++) {
                    echo $vehicle[$i].($i < (sizeof($vehicle)-1) ? "," : "");
                }
            }
            ?>
        </td>
        <td><?= $social?></td>
    </tr>
</table>

</body>
</html>