# Line Drawing Algortihm: Breshnam's Algorithm

## Objective
1. To compare DDA line drawing algorithm and Breshnam's line drawing algorithm.

## Algorithm
1. Get end points of the line from the user.
2. Calculate
	```C
	dx = x2 - x1
	dy = y2 - y1
	2*dx
	2*dy
	```


3. if (`dy > dx`)

   >```C
   >2*dx - 2*dy
   >p[0] = 2*dx - dy
   >```

   else
   
   >```C
   >x*dy - 2*dx
   >p[0] = 2*dy - dx 
   >```
4. If (`dy > dx`)

   >if (`p[k] < 0`)  
   >>```C
   >>putpixel(x[k], y[k]+1)
   >>p[k+1] = p[k] + 2*dx
   >>```
   >else
   >>```C
   >>putpixel(x[k]+1, y[k]+1)
   >>p[k+1] = p[k] + 2*dx - 2*dy
   >>```

   else

   >if (`p[k] < 0`)  
   >>```C
   >>putpixel(x[k]+1, y[k])
   >>p[k+1] = p[k] + 2*dy
   >>```
   >else
   >>```C
   >>putpixel(x[k]+1, y[k]+1)
   >>p[k+1] = p[k] + 2*dy - 2*dx
   >>```