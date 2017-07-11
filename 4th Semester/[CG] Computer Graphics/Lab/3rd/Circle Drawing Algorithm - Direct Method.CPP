#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int r, int colour) {
  int counter, x, y1, y2;
  for(counter = (xc - r); counter <= (xc + r); counter++)
  {
    x = counter;
    y1 = yc + sqrt(pow(r, 2) - pow((x- xc), 2));
    y2 = yc - sqrt(pow(r, 2) - pow((x- xc), 2));
    putpixel(x, y1, colour);
    putpixel(x, y2, colour);
   // x++;
  }
}

int main() {
  int colour = 5;
  int x, y, r;

  //Initializing graphics
  int gdriver = DETECT, gmode;
  initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

  printf("Enter center point of the circle:\n");
  printf("x: ");
  scanf("%d", &x);
  printf("y: ");
  scanf("%d", &y);
  printf("Enter radius of the circle:\n");
  printf("r: ");
  scanf("%d", &r);

  //Drawing the circle
  clrscr();
  drawCircle(x, y, r, colour);

  getch();
  return 0;
}
