//hardcoded to only be able to transfor a 2D triangle, polygonal transformation in future [maybe!?]
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

//! known issues:
//! 1. Doesn't draw the original triangle when doing rotation
//! 2. setbkcolor(0); doesn't set the background color to black but instead to grey

int main() {
	//variables for performing 2D geometric transformation
	int x1, x2, x3, y1, y2, y3;	//vertices for the triangle
	int tx, ty;	//translation vector
	float theta, t;	//rotation angle
	int sx, sy;	//scaling vector

	//other variables
	int choice;

	//initializing graphics driver
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

	//process
	do {
		//setting up the menu
		clrscr();
		printf("1. Translate.\n");
		printf("2. Rotate.\n");
		printf("3. Scale.\n");
		printf("0. Exit\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		clrscr();

		//getting triangle's co-ordinates if any opertaion is to be performed
		if(choice > 0 && choice < 4) {
			printf("X1: ");
			scanf("%d", &x1);
			printf("Y1: ");
			scanf("%d", &y1);
			printf("X2: ");
			scanf("%d", &x3);
			printf("Y2: ");
			scanf("%d", &y3);
			printf("X3: ");
			scanf("%d", &x2);
			printf("Y3: ");
			scanf("%d", &y2);
		}
		switch(choice) {	//jump to the task
			case 1:	//For translating
			printf("Enter the translation vector:\n");
			printf("tx: ");
			scanf("%d", &tx);
			printf("ty: ");
			scanf("%d", &ty);

			//clearing and setting up screen for displaying graphics
			clrscr();
			setbkcolor(0);	//making a black background

			//displaying the original image in red
			setcolor(4);	//setting the stroke color for the line
			line(x1, y1, x2, y2);
			line(x2, y2, x3, y3);
			line(x3, y3, x1, y1);

			//now transalting
			x1 += tx;
			y1 += ty;
			x2 += tx;
			y2 += ty;
			x3 += tx;
			y3 += ty;

			//displaying the translated co-ordinate in white
			setcolor(15);	//setting the stroke color for the line
			line(x1, y1, x2, y2);
			line(x2, y2, x3, y3);
			line(x3, y3, x1, y1);

			getch();
			break;

			case 2:	//for rotating
			printf("Enter rotation angle [through origin]:\n");
			printf("theta: ");
			scanf("%d", &theta);

			//clearing and setting up screen for displaying graphics
			clrscr();
			setbkcolor(0);	//making a black background

			//!issue while doing these three sets of line(); doesn't draw the lines.
			//displaying the original image in red
			setcolor(4);	//setting the stroke color for the line
			line(x1, y1, x2, y2);
			line(x2, y2, x3, y3);
			line(x3, y3, x1, y1);

			//now rotating
			t = 3.14 * theta;
			t /= 180;
			x1 = x1*cos(t) - y1*sin(t);
			y1 = x1*sin(t) + y1*cos(t);
			x2 = x2*cos(t) - y2*sin(t);
			y2 = x2*sin(t) + y2*cos(t);
			x3 = x3*cos(t) - y3*sin(t);
			y3 = x3*sin(t) + y3*cos(t);

			//displaying the rotated co-ordinate in white
			setcolor(15);	//setting the stroke color for the line
			line(x1, y1, x2, y2);
			line(x2, y2, x3, y3);
			line(x3, y3, x1, y1);

			getch();
			break;

			case 3:	//for scaling
			printf("Enter the scaling vector:\n");
			printf("sx: ");
			scanf("%d", &sx);
			printf("sy: ");
			scanf("%d", &sy);

			//clearing and setting up screen for displaying graphics
			clrscr();
			setbkcolor(0);	//making a black background

			//displaying the original image in red
			setcolor(4);	//setting the stroke color for the line
			line(x1, y1, x2, y2);
			line(x2, y2, x3, y3);
			line(x3, y3, x1, y1);

			//now scaling
			x1 *= sx;
			y1 *= sy;
			x2 *= sx;
			y2 *= sy;
			x3 *= sx;
			y3 *= sy;

			//displaying the translated co-ordinate in white
			setcolor(15);	//setting the stroke color for the line
			line(x1, y1, x2, y2);
			line(x2, y2, x3, y3);
			line(x3, y3, x1, y1);

			getch();
			break;
		}

	} while(choice != 0);	//0 is the exit code to exit out of the program

	getch();
	return 0;
}