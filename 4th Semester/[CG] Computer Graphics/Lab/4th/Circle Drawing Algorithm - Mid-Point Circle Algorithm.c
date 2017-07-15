#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void transform(int x, int y, int xc, int yc, int color) {
	putpixel(xc + x, yc + y, color);
    putpixel(xc - x, yc + y, color);
    putpixel(xc + x, yc - y, color);
    putpixel(xc - x, yc - y, color);
    putpixel(xc + y, yc + x, color);
    putpixel(xc - y, yc + x, color);
    putpixel(xc + y, yc - x, color);
    putpixel(xc - y, yc - x, color);

}

void drawCircle(int xc, int yc, int r, int color) {
	int x, y, p;
    
	x = 0;
    y = r;
    p = 1 - r;
    
	while(x < y){
        if(p < 0){
            x = x + 1;
            p = p + (2 * x) + 1;
        }
        else{
            x = x + 1;
            y = y - 1;
            p = p + (2 * x + 1 - (2 * y));
        }
        transform(x, y, xc, yc);
    }
}

int main() {
	//Initializing varriables
	int xc, yc, r;

	//Initializing graphics
	int color = 100;
	int gdriver = DETECT, gmode;
	intgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

	//Input from user
	printf("Enter center point of circle:\n");
	printf("x: ");
	scanf("%d", &xc);
	printf("y: ");
	scanf("%d", &yc);
	printf("Enter radius of circle:\n");
	printf("r: ");
	scanf("%d", &r);

	//Drawing circle
	clrscr();
	drawCircle(xc, yc, r, color);

	getch();
	return 0;
}