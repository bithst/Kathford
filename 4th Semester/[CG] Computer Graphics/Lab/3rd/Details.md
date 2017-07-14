# Circle Generating Algorithm

## Direct Approach
**Algorithm:**
1. Start
2. Input center (xc, yc) and radius (r)
3. For `counter = xc - r` to `xc + r`
    1. Set `x = counter`
    2. Compute: `y = yc - sqrt(r^2 - (x - xc)^2)`
    3. Increment `counter`
    4. Plot pixel at (x, y)
4. End

## Trigonometric Approach
**Algorithm:**
1. Start
2. Input center (xc, yc) and radius (r)
3. For `theta = 0` to `360`
    1. `x = xc + (r * cos(theta))`
    2. `y = yc + (r * sin(theta))`
    3. Increment `theta`
    4. Plot pixel at (x, y)
4. End