# Line Drawing Algorithm: Digital Differential Algorithm (DDA)

## Objective
1. To understand the digital differential line drawing algorithm.
2. To apply the algortihm to plot a line with the given endpoints.

## Algorithm
1. Get end point co-ordinates of the line from the user.
2. Calculate:  
    `dy = y2 - y1`
    `dx = x2 - x1`
3. If |dx| > |dy|  
    `step_size = |dx|`  
    else  
    `step_size = |dy|`
4. Calculate:  
    `x_increment = dx / step_size`  
    `y_increment = dy / step_size`
5. Next point:  
    `x_k+1 = x_k + x_increment`  
    `y_k+1 = y_k + y_increment`
6. Perform steps 4 and 5, `step_size` times.