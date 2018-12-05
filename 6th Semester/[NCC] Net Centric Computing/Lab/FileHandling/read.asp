<%
Dim fs, fname, data
set fs = Server.CreateObject("Scripting.FileSystemObject")
set fname = fs.OpenTextFile("C:\Files\test.txt")

Do Until fname.AtEndOfStream
	data = fname.ReadLine()
	
	Response.Write(data&"<br/>")
Loop


fname.Close
set fname = nothing
set fs = nothing

%>
