# Circle Generating Algorithm

## Direct approach
**Algorithm:**
1. Start
2. Input center (xc, yc) and radius (r)
3. For counter = xc - r to xc + r
  1. Set x = counter
  2. Compute: y = yc - sqrt(r^2 - (x - xc)^2)
  3. Increment counter
  4. Plot
4. End
