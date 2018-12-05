<html>
<head>
<title></title>
</head>

<body>
  <center>
    <form action="2.asp" method="get">
      <input type="number" name="num"> <br/>
      <input type="submit" value="Find multiplication table"> <br/>
      <button><a href="2.asp">Reset</a></button> <br/>
    </form>
    <%
      If Not IsEmpty(Request.QueryString("num")) Then
        Dim number
        number = Request.QueryString("num")

        Response.Write ("<table>")
		
      For i = 1 To 10
        Response.Write ("<tr><td>"&number&"</td><td>*</td><td>"&i&"</td><td>=</td><td>"&number * i&"</td></tr>")
      Next
		  	
        Response.Write ("</table>")
      End If
    %>
    <hr/>

    <form action="2.asp" method="post">
      <input type="number" name="num1"><br/>
      <input type="number" name="num2"></br>
      <input type="submit" value="Find multiplication between range">
    </form>
    <%
      If Not IsEmpty(Request.Form("num1")) And Not IsEmpty(Request.Form("num2")) And Request.Form("num1") <= Request.Form("num2") Then
        Response.Write ("<table cellpadding=10><tr>")
        For j = Request.Form("num1") To Request.Form("num2")
          Response.Write ("<td><table>")
          For i = 1 To 10
            Response.Write ("<tr><td>"&j&"</td><td>*</td><td>"&i&"</td><td>=</td><td>"&j * i&"</td></tr>")
          Next
          Response.Write ("</table></td>")
        Next
        Response.Write ("</tr></table>")
      End If
    %>
    <hr/>
  </center>
</body>

</html>