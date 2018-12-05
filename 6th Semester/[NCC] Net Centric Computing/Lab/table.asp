<html>
<head>
<title>Tabular data</title>
</head>

<body>

<table border="1">
<tr>
  <th>S.N.</th>
  <th>Item</th>
  <th>Image</th>
</tr>

<%
  Dim i
  i = 0
  For i = 1 To 4
    If i mod 2 = 0 Then
      Response.Write ("<tr bgcolor=""white"">")
    Else
      Response.Write ("<tr bgcolor=""gray"">")
    End if
	
	Response.Write("<td>"&i&"</td><td width=""100"">Item "&i&"</td><td> <img src=""Image"&i&".jpg"" height=""100""></td></tr>")
  Next
%>

</table>

</body>
</html>