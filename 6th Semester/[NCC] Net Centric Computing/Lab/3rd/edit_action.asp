<%
  Dim id, name, address, phone
  id = Request.Form("id")
  name = Request.Form("name")
  address = Request.Form ("address")
  phone = Request.Form("phone")

  Dim connStr, conn, sql
  connStr = "Provider=SQLOLEDB; Data Source=.; Initial Catalog=mydb; User Id=sa; Password=123456;"
  Set conn = Server.CreateObject("ADODB.Connection")
  conn.ConnectionString = connStr
  conn.Open
  sql = "UPDATE AddressBook SET name='" & name & "', address='" & address & "', phone='" & phone & "' WHERE id=" & id
  conn.Execute(sql)
  conn.Close
  Response.redirect("display.asp")
%>