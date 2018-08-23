<html>
<head>
<title>Dictionary</title>
</head>

<body>
  <%
    Dim d
    Set d = Server.CreateObject("Scripting.Dictionary")

    Response.Write(d.Count&"<br/>")
    
  %>
</body>

</html>