<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <link rel="stylesheet" href="style.css">
  <title>All data</title>
</head>
<body>
  <%
    Dim connStr, conn, rs, sql
    connStr = "Provider=SQLOLEDB; Data Source=.; Initial Catalog=mydb; User Id=sa; Password=123456;"
    Set conn = Server.CreateObject("ADODB.Connection")
    Set rs = Server.CreateObject("ADODB.Recordset")
    conn.ConnectionString = connStr
    sql = "SELECT * FROM AddressBook"
    conn.Open
    rs.Open sql, conn
  %>

  <table border = 0 align=center width=100%>
    <tr bgcolor= mediumaquamarine>
      <%
        for each col in rs.Fields
          Response.write ("<th>" & col.name & "</th>")
        next
        Response.write ("<th colspan=2>action</th>")
      %>
    </tr>
    <%
      Dim x
      x = 1
      do until rs.EOF
        if x mod 2 = 0 then
          Response.write ("<tr bgcolor=white>")
        else
          Response.write ("<tr bgcolor=lightgray>")
        end if
        x = x + 1
        for each col in rs.Fields
          Response.write ("<td>" & col.value & "</td>")
        next
        Response.write ("<td align=center><a href=""edit_form.asp?id=" & rs.Fields("id").value & """><button>Edit</button></a></td>")
        Response.write ("<td align=center><a href=""delete_action.asp?id=" & rs.Fields("id").value & """><button>Delete</button></a></td>")
        Response.write ("</tr>")
        rs.MoveNext
      loop
    %>
    <tr>
      <td colspan=6 align=center><a href="add.asp"><button>Add</button></a></td>
    </tr>
  </table>
  

  <%
    rs.Close   
    conn.Close
  %>
</body>
</html>