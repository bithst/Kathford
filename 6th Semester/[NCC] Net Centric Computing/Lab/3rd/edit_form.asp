<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <link rel="stylesheet" href="style.css">
  <title>Edit User Data</title>
</head>
<body>
  <%
    Dim id, connStr, conn,rs, sql
    id = Request.QueryString("id")
    connStr = "Provider=SQLOLEDB; Data Source=.; Initial Catalog=mydb; User Id=sa; Password=123456;"
    sql = "SELECT * FROM AddressBook WHERE id = " & id
    Set conn = Server.CreateObject("ADODB.Connection")
    Set rs = Server.CreateObject("ADODB.Recordset")
    conn.ConnectionString = connStr
    conn.Open
    rs.Open sql, conn

    Dim name, address, phone
    name = rs.Fields("name").Value
    address = rs.Fields("address").Value
    phone = rs.Fields("phone").Value
  %>

  <form action="edit_action.asp" method=post>
    <input type="hidden" name="id" value=<%Response.write("""" & id & """")%> >

    <table align=center>
      <tr>
        <td>Name</td>
        <td><input type="text" name="name" value=<%Response.write("""" & name & """")%> ></td>
      </tr>
      <tr>
        <td>Address</td>
        <td><input type="text" name="address" value=<%Response.write("""" & address & """")%> ></td>
      </tr>
      <tr>
        <td>Phone</td>
        <td><input type="text" name="phone" value=<%Response.write("""" & phone & """")%> ></td>
      </tr>
      <tr>
        <td><button type="submit">Save changes</button></td>
        <td><a href="display.asp"><button>Back</button></a></td>
      </tr>
    </table>

    
  </form>

  <%
    rs.Close
    conn.Close
  %>
</body>
</html>