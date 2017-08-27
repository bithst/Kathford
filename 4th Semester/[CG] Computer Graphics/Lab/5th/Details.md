# Ellipse Drawing Algorithm

## Direct Approach
### Algorithm
1. Input center point of ellipse `(xc, yc)` and radius `rx` and `ry`
2. For `count = (xc - rx)` to `(xc + rx)`
   
   >```C
   >x = count
   >y1 = yc + (ry/rx)*sqrt((rx*rx) - pow((x-xc), 2))
   >y2 = yc - (ry/rx)*sqrt((rx*rx) - pow((x-xc), 2))
   >count++
   >putpixel(x, y1)
   >putpixel(x, y2)
   >```

## Trigonometric Approach
### Algorithm
1. Input center point of ellipse `(xc, yc)` and radius `rx` and `ry`
2. For `theta = 0' to '360'
   
   >```C
   >x = xc + rx*cos(theta)
   >y = yc + ry*sin(theta)
   >theta++
   >putpixel(x, y)
   >```