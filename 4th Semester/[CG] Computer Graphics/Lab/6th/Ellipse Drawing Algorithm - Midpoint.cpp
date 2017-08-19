#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

void translate(float x, float y, float xc, float yc) {
	putpixel(xc + x, yc + y, 0);
	putpixel(xc - x, yc + y, 0);
	putpixel(xc + x, yc - y, 0);
	putpixel(xc - x, yc - y, 0);
}

void drawEllipse (float xc, float yc, float rx, float ry) {
	float x, y, p;

	x = 0;
	y = ry;
	p = pow(ry, 2) - pow(rx, 3) + (0.25 * pow(rx, 2));

	while((2 * pow(ry, 2) * x) < (2 * pow(rx, 2) * y)) {
		x++;

		if(p < 0) {
			p += (2 * pow(ry, 2) * x) + pow(ry, 2);
		} else {
			y++;
			p += (2 * pow(ry, 2) * x) - (2 * pow(rx, 2) * y) + pow(rx, 2);
		}

		translate(x, y, xc, yc);
	}

	p = (pow(ry, 2) * pow((x + 0.5), 2)) + (pow(rx, 2) * pow((y-1), 2)) - (pow((rx * ry), 2));
	while(y >= 0) {
		y--;
		if(p > 0) {
			p -= (2 * pow(rx, 2) * y) + pow(rx, 2);
		} else {
			x++;
			p -= (2 * pow(ry, 2) * x) - (2 * pow(rx, 2) * y) + pow(rx, 2);
		}
		translate(x, y, xc, yc);
	}
}

int main() {
	float xc, yc, rx, ry;
	
	int gmode, gdriver = DETECT;
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

	printf("Enter the center point of ellipse\n");
	printf("xc: ");
	scanf("%f", &xc);
	printf("yc: ");
	scanf("%f", &yc);
	printf("Enter radii for the ellipse\n");
	printf("rx: ");
	scanf("%f", &rx);
	printf("ry: ");
	scanf("%f", &ry);

	clrscr();
	drawEllipse(xc, yc, rx, ry);

	getch();
	return 0;
}