<%
  Dim b
  Set b = Server.CreateObject("MSWC.BrowserType")
  Response.Write ("VBScript Support "&b.vbscript&"<br>")
  Response.Write ("Browser "&b.browser&"<br>")
  Response.Write ("Version "&b.version&"<br>")
  Response.Write ("Cookies "&b.cookies&"<br>")
  Response.Write ("OS Platform "&b.platform&"<br>")
%>