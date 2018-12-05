<%
  Dim connStr, conn, sql
  connStr = "Provider=SQLOLEDB; Data Source=.; Initial Catalog=mydb; User Id=sa; Password=123456;"
  Set conn = Server.CreateObject("ADODB.Connection")
  conn.ConnectionString = connStr
  conn.Open
  sql = "Insert into AddressBook values('AAA', 'Add1', '111')"
  conn.Execute(sql)
  Response.Write ("Data Inserted Successfully")
  conn.Close
%>