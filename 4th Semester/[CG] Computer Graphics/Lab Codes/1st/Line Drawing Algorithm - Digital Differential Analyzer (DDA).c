#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

int round(float num) {
	num += 0.5;
	return (int)num;
}

void lineDDA(int x1, int y1, int x2, int y2, int color) {
	int dx, dy, steps, k;
	float x_inc, y_inc, x, y;

	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;

	if(abs(dx) > abs(dy)) {
		steps = abs(dx);
	}
	else {
		steps = abs(dy);
	}

	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;

	putpixel(round(x), round(y), color);
	for(k = 0; k < steps; k++) {
		delay(30);
		x += x_inc;
		y += y_inc;

		putpixel(round(x), round(y), color);
	}
}

int main() {
	int x1, y1, x2, y2;
	int gmode, gdriver;

	gdriver = DETECT;
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");	//The path where turbo c3 is running from

	printf("Enter the starting point:\n");
	printf("x: ");
	scanf("%d", &x1);
	printf("y: ");
	scanf("%d", &y1);
	
	printf("Enter the end point:\n");
	printf("x: ");
	scanf("%d", &x2);
	printf("y: ");
	scanf("%d", &y2);

	clrscr();
	lineDDA(x1, y1, x2, y2, 5);

	getch();
	return 0;
}