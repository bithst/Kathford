<%
  Dim id
  id = Request.QueryString("id")

  Dim connStr, conn, sql
  connStr = "Provider=SQLOLEDB; Data Source=.; Initial Catalog=mydb; User Id=sa; Password=123456;"
  Set conn = Server.CreateObject("ADODB.Connection")
  conn.ConnectionString = connStr
  conn.Open
  sql = "DELETE FROM AddressBook WHERE id=" & id
  conn.Execute(sql)
  conn.Close
  Response.redirect("display.asp")
%>