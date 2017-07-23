#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

void drawEllipse(int, int, int, int, int);

int main() {
	//Initializing variables
	int xc, yc, rx, ry;
	int colour = 2;

	//Initializing graphics
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

	printf("Enter center point of ellipse:\n");
	printf("x: ");
	scanf("%d", &xc);
	printf("y: ");
	scanf("%d", &yc);
	printf("Enter radius in x and y direction:\n");
	printf("rx: ");
	scanf("%d", &rx);
	printf("ry: ");
	scanf("%d", &ry);

	//Draawing the ellipse
	clrscr();
	drawEllipse(xc, yc, rx, ry, colour);

	getch();
	return 0;
}

void drawEllipse(int xc, int yc, int rx, int ry, int colour) {
	int x, y, theta;
	for(theta = 0; theta < 360; theta++) {
		x = xc + (rx * cos(theta));
		y = yc + (ry * sin(theta));
		putpixel(x, y, colour);
	}
}