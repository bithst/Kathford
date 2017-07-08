#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int r, int colour) {
  int x, y, counter, theta;
  for(theta = 0; theta <= 360; theta++) {
    x = xc + r * cos(theta);
    y = yc + r * sin(theta);
    putpixel(x, y, colour);
  }
}

int main() {
  int colour = 10;
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
