<%
    Dim d
    Set d = Server.CreateObject("Scripting.Dictionary")
    d.Add "Key1", "item1"
    d.Add "Key2", "item2"
    d.Add "Key3", "item3"
    d.Add "Key4", "item4"
    Response.Write("Does item 3 exist?<br>Answer: "&d.Exists("Key3"))
    Response.Write("<br>Value of third item is: "&d.Item("Key3"))

    'Changing the value of item and key
    d.Item("Key4") = "new item4"
    d.Key("Key4") = "new key4"

    'iteratung through Dictionary
    Dim arrKeys, arrItems, i
    arrKeys = d.Keys()
    arrItems = d.Items()
    For i=0 To d.Count-1
        Response.Write("<br>" & arrKeys(i) & " = " &arrItems(i))
    Next

    'Removing the third key
    d.Remove("Key3")
    Response.Write("<br>There are "&d.Count&" items in the dictionary.")
    
    'Removing all the items
    d.RemoveAll()
    Response.Write("<br>There are "&d.Count&" items in the dictionary.")
%>