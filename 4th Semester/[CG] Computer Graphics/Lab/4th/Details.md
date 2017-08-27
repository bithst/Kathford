# Mid-Point Circle Algorithm

##  Algorithm:
1. Input radius and center
2. Obtain the first point in the circumference of circle centerd on the origin as:  
`(x[0], y[0]) = (0, r)`
3. Calculate initial decision parameter  
`p[0] = 1 - r`
4. If `p[k] < 0`, then

	>Next point = `(x[k]+1, y[k])`  
	>And, `p[k+1] = p[k] + (2 * x[k+1]) + 1`  

   else  

	>Next point = `(x[k]+1, y[k]-1)`  
	>And, `p[k+1] = p[k] + (2 * x[k+1]) + 1 - (2 * y[k+1])`
	
5. Determine symmetry point in other seven octants.
6. Move each calculated pixel `(x, y)` onto the circular path centered at `(xc, yc)` and plot the co-ordinate values  
	`x = x + xc`  
	`y = y + yc`
7. Continue steps 4 to 6 until `x >= y`