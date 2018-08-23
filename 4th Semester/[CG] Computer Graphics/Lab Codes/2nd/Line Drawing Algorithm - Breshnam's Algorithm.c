#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void lineBSA(int x1, int y1, int x2, int y2, int color) {
	int dx, dy, twoDy, twoDyDx, p, x, y, xEnd;

	dx = abs(x2 - x1), dy = abs(y2 - y1);
	p = 2 * (dy - dx);
	twoDy = 2 * dy, twoDyDx = 2 * (dy - dx);

	if(x1 > x2) {
		x = x2;
		y = y2;
		xEnd = x1;
	}
	else {
		x = x1;
		y = y1;
		xEnd = x2;
	}

	putpixel(x, y, color);
	while(x < xEnd) {
		x++;
		if(p < 0) {
			p += twoDy;
		}
		else {
			y++;
			p += twoDyDx;
		}

		putpixel(x, y, color);
	}
}

int main() {
	//Initializing end points
	int x1, y1, x2, y2;

	//Initializing graphics driver
	int gdetect = DETECT, gmode;
	int color;
	initgraph(&gdetect, &gmode, "C:\\TURBOC3\\BGI");

	printf("Enter start point:\n");
	printf("x: ");
	scanf("%d", &x1);
	printf("y: ");
	scanf("%d", &y1);
	printf("Enter end point:\n");
	printf("x: ");
	scanf("%d", &x2);
	printf("y: ");
	scanf("%d", &y2);

	//Drawing the line
	clrscr();
	color = 5;
	lineBSA(x1, y1, x2, y2, color);

	getch();
	return 0;
}