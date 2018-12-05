<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <link rel="stylesheet" href="style.css">
  <title>Fill the form</title>
</head>
<body>

<form action="add_action.asp" method="post">
  <table align=center>
    <tr>
      <td>Name</td>
      <td><input type="text" name="name" id="name"></td>
    </tr>
    <tr>
      <td>Address</td>
      <td><input type="text" name="address" id="addr"></td>
    </tr>
    <tr>
      <td>Phone</td>
      <td><input type="text" name="phone" id="phn"></td>
    </tr>
    <tr>
      <td><button type="submit">Save new data</button></td>
      <td><a href="display.asp"><button>Back</button></a></td>
    </tr>
  </table>  
</form>

</body>
</html>