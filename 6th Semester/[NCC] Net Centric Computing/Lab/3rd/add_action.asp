<%
  Dim name, address, phone
  name = Request.Form("name")
  address = Request.Form ("address")
  phone = Request.Form("phone")

  Dim connStr, conn, sql
  connStr = "Provider=SQLOLEDB; Data Source=.; Initial Catalog=mydb; User Id=sa; Password=123456;"
  Set conn = Server.CreateObject("ADODB.Connection")
  conn.ConnectionString = connStr
  conn.Open
  sql = "Insert into AddressBook values('"&name&"', '"&address&"', '"&phone&"')"
  conn.Execute(sql)
  conn.Close
  Response.redirect("display.asp")
%>