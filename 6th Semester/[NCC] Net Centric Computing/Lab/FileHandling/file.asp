<%
dim fs, fname
set fs = Server.CreateObject("Scripting.FileSystemObject")
set fname = fs.CreateTextFile("C:\Files\test.txt", true)
fname.WriteLine("Hello!")
fname.Close
set fname = nothing
set fs = nothing
%>