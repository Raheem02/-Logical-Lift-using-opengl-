#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ScreenHeight 706
#define ScreenWidth 1366

int ScreenNo=1;							// Specifies in which screen the program is running.
int mov=0;								// Specifies that the Text are in Moving.
int BColor[3]={1,1,1};					// Specifies the color of the play instructio and exit button.
int LiftMov=0;							// Specifies that Lift is Moving.
int NoMove=0;							// Keeps the no of times the lift has moved.
int End=0;								// Tell wether the game has ended or not.
char LiftChar[3];						// Used for printong the lift no's.
int StripMover;							// Used for Strip Selectio at Start.
int TButton[2][3]={{683,590,30},{683,110,30}}; //Position of Lift moving button and its radius

GLint LiftFloor[5]={17,26,20,19,31};	// Specifies where the lift has stopped.
GLint SelectedLift[2];					// Contains the lift no of which are selected. 
GLint TBColor[2]={1,1};					// Specifies the color of the lift moving button.
GLint SelectCount=0;					// No of Lift Selected.
GLint FloorCount;						// No of Floors Moved.
GLint LiftColor[5]={1,1,1,1,1};			// Contains the Lift color.
GLint LineColor[5]={1,1,1,1,1};			// Contains the inner boundary color.


typedef struct p
{
double x,y;
}Point;

Point LiftPoint[5]={{100,150},{341.5,150},{583,150},{824.5,150},{1066,150}}; // Position of the Lifts.

void BitmapText(int x,int y,char *string,int type); //prototype of BitmapText

void DrawHead(int a,int b,int radius)
{
	// Draws the head of a man.
	int i,j;
			

			glBegin(GL_POLYGON);
			for(i=(b+radius);i>=(b-radius);i=i-0.0001)
			{
				j=sqrt(radius*radius-(i-b)*(i-b))+a;
				glVertex2f(j,i);
			}
			for(i=(b+radius);i>=(b-radius);i=i-0.0001)
			{
				j=-sqrt(radius*radius-(i-b)*(i-b))+a;
				glVertex2f(j,i);
			}
			glEnd();
}

void DrawMen1(int x,int y)
{
	// Draws the man standing in lift 1.

	glColor3f(0,0,0);

		glBegin(GL_POLYGON);
			glVertex2f(x+00,y+00);
			glVertex2f(x+50,y+00);
			glVertex2f(x+48,y+20);
			glVertex2f(x+25,y+20);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(x+120,y+00);
			glVertex2f(x+70,y+00);
			glVertex2f(x+72,y+20);
			glVertex2f(x+95,y+20);
		glEnd();


	glColor3f(0.4,0.2,0);

		glBegin(GL_POLYGON);
			glVertex2f(x+20,y+20);
			glVertex2f(x+50,y+20);
			glVertex2f(x+60,y+100);
			glVertex2f(x+30,y+120);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(x+100,y+20);
			glVertex2f(x+70,y+20);
			glVertex2f(x+60,y+100);
			glVertex2f(x+90,y+120);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(x+30,y+120);
			glVertex2f(x+60,y+100);
			glVertex2f(x+90,y+120);
		glEnd();

	glColor3f(0,0,0);

		glBegin(GL_POLYGON);
			glVertex2f(x+30,y+120);
			glVertex2f(x+90,y+120);
			glVertex2f(x+90,y+125);
			glVertex2f(x+30,y+125);
		glEnd();

	glColor3f(0.6,0,0);

		glBegin(GL_POLYGON);
			glVertex2f(x+30,y+125);
			glVertex2f(x+90,y+125);
			glVertex2f(x+88,y+185);
			glVertex2f(x+28,y+185);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(x+78,y+185);
			glVertex2f(x+38,y+185);
			glVertex2f(x+38,y+195);
			glVertex2f(x+78,y+195);
		glEnd();


		glBegin(GL_POLYGON);
			glVertex2f(x+18,y+185);
			glVertex2f(x+28,y+185);
			glVertex2f(x+30,y+175);
			glVertex2f(x+24,y+100);
			glVertex2f(x+00,y+100);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(x+102,y+185);
			glVertex2f(x+88,y+185);
			glVertex2f(x+86,y+175);
			glVertex2f(x+96,y+100);
			glVertex2f(x+120,y+100);
		glEnd();

	glColor3f(1,0.8,0.8);

		glBegin(GL_POLYGON);
			glVertex2f(x+9,y+100);
			glVertex2f(x+17,y+100);
			glVertex2f(x+15,y+92);
			glVertex2f(x+10,y+85);
			glVertex2f(x+9,y+76);
			glVertex2f(x+03,y+88);
			glVertex2f(x+06,y+91);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(x+111,y+100);
			glVertex2f(x+103,y+100);
			glVertex2f(x+105,y+92);
			glVertex2f(x+110,y+85);
			glVertex2f(x+111,y+76);
			glVertex2f(x+117,y+88);
			glVertex2f(x+114,y+91);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(x+50,y+195);
			glVertex2f(x+65,y+195);
			glVertex2f(x+65,y+205);
			glVertex2f(x+48,y+205);
			glVertex2f(x+50,y+200);
		glEnd();

	glColor3f(0,0,0);

		glBegin(GL_LINE_STRIP);
			glVertex2f(x+78,y+185);
			glVertex2f(x+58,y+180);
			glVertex2f(x+38,y+185);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(x+56,y+198);
			glVertex2f(x+66,y+198);
			glVertex2f(x+85,y+220);
			glVertex2f(x+82,y+240);
			glVertex2f(x+56,y+246);
			glVertex2f(x+35,y+235);
			glVertex2f(x+30,y+220);
			glVertex2f(x+48,y+198);
		glEnd();

	
}

void DrawMen2(int x,int y)
{
     
	glColor3f(0,0,0);

	glBegin(GL_POLYGON);
		glVertex2f(x+00,y+00);
		glVertex2f(x+50,y+00);
		glVertex2f(x+48,y+20);
		glVertex2f(x+25,y+20);
	glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(x+120,y+00);
		glVertex2f(x+70,y+00);
		glVertex2f(x+72,y+20);
		glVertex2f(x+95,y+20);
	glEnd();


glColor3f(1,0.5,0.5);


	glBegin(GL_POLYGON);
		glVertex2f(x+30,y+120);
		glVertex2f(x+90,y+120);
		glVertex2f(x+110,y+60);
		glVertex2f(x+10,y+60);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(x+30,y+120);
		glVertex2f(x+90,y+120);
		glVertex2f(x+90,y+125);
		glVertex2f(x+30,y+125);
	glEnd();

	glColor3f(1,1,0.5);
	glBegin(GL_POLYGON);
		glVertex2f(x+30,y+125);
		glVertex2f(x+90,y+125);
		glVertex2f(x+88,y+185);
		glVertex2f(x+28,y+185);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+78,y+185);
		glVertex2f(x+38,y+185);
		glVertex2f(x+38,y+195);
		glVertex2f(x+78,y+195);
	glEnd();


	glBegin(GL_POLYGON);
		glVertex2f(x+18,y+185);
		glVertex2f(x+28,y+185);
		glVertex2f(x+30,y+175);
		glVertex2f(x+26,y+140);
		glVertex2f(x+4,y+140);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+102,y+185);
		glVertex2f(x+88,y+185);
		glVertex2f(x+86,y+175);
		glVertex2f(x+94,y+140);
		glVertex2f(x+116,y+140);
	glEnd();
	glColor3f(1,1,0.5);
	glBegin(GL_POLYGON);
		glVertex2f(x+4,y+140);
		glVertex2f(x+26,y+140);
		glVertex2f(x+27,y+145);
		glVertex2f(x+5,y+145);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+94,y+140);
		glVertex2f(x+116,y+140);
		glVertex2f(x+115,y+145);
		glVertex2f(x+93,y+145);
	glEnd();

	glColor3f(1,0.8,0.8);
	glBegin(GL_POLYGON);
		glVertex2f(x+9,y+140);
		glVertex2f(x+21,y+140);
		glVertex2f(x+17,y+100);
		glVertex2f(x+9,y+100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+99,y+140);
		glVertex2f(x+111,y+140);
		glVertex2f(x+111,y+100);
		glVertex2f(x+103,y+100);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+9,y+100);
		glVertex2f(x+17,y+100);
		glVertex2f(x+15,y+92);
		glVertex2f(x+10,y+85);
		glVertex2f(x+9,y+76);
		glVertex2f(x+03,y+88);
		glVertex2f(x+06,y+91);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+111,y+100);
		glVertex2f(x+103,y+100);
		glVertex2f(x+105,y+92);
		glVertex2f(x+110,y+85);
		glVertex2f(x+111,y+76);
		glVertex2f(x+117,y+88);
		glVertex2f(x+114,y+91);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+195);
		glVertex2f(x+65,y+195);
		glVertex2f(x+65,y+205);
		glVertex2f(x+48,y+205);
		glVertex2f(x+50,y+200);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(x+78,y+185);
		glVertex2f(x+58,y+180);
		glVertex2f(x+38,y+185);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+56,y+198);
		glVertex2f(x+66,y+198);
		glVertex2f(x+85,y+220);
		glVertex2f(x+82,y+240);
		glVertex2f(x+56,y+246);
		glVertex2f(x+35,y+235);
		glVertex2f(x+30,y+220);
		glVertex2f(x+48,y+198);
	glEnd();


	glColor3f(0.72,0.48,0.34);
	glBegin(GL_POLYGON);
	glVertex2f(x+28,y+185);
	glVertex2f(x+36,y+185);
	glVertex2f(x+46,y+165);
	glVertex2f(x+38,y+160);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x+92,y+185);
	glVertex2f(x+84,y+185);
	glVertex2f(x+74,y+165);
	glVertex2f(x+82,y+160);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x+30,y+125);
	glVertex2f(x+30,y+135);
	glVertex2f(x+38,y+140);
	glVertex2f(x+38,y+130);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(x+90,y+125);
	glVertex2f(x+90,y+135);
	glVertex2f(x+82,y+140);
	glVertex2f(x+82,y+130);
	glEnd();


	glColor3f(0.64,0.35,0.27);
	glBegin(GL_POLYGON);
	glVertex2f(x+38,y+170);
	glVertex2f(x+46,y+165);
	glVertex2f(x+74,y+165);
	glVertex2f(x+82,y+170);
	glVertex2f(x+82,y+130);
	glVertex2f(x+38,y+130);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x+48,y+155);
	glVertex2f(x+72,y+155);
	glVertex2f(x+72,y+140);
	glVertex2f(x+48,y+140);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(x+48,y+155);
	glVertex2f(x+72,y+155);
	glVertex2f(x+60,y+150);
	glEnd();

glColor3f(1,0.8,0.8);
	glBegin(GL_POLYGON);
glVertex2f(x+30,y+19);
glVertex2f(x+45,y+19);
glVertex2f(x+45,y+60);
glVertex2f(x+30,y+60);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(x+90,y+19);
glVertex2f(x+75,y+19);
glVertex2f(x+75,y+60);
glVertex2f(x+90,y+60);
glEnd();

}

void DrawMen3(int x,int y)
{	// Draws the man standing in lift 3.

	glColor3f(0,0,0);

	glBegin(GL_POLYGON);
		glVertex2f(x+00,y+00);
		glVertex2f(x+50,y+00);
		glVertex2f(x+48,y+20);
		glVertex2f(x+25,y+20);
	glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(x+120,y+00);
		glVertex2f(x+70,y+00);
		glVertex2f(x+72,y+20);
		glVertex2f(x+95,y+20);
	glEnd();


glColor3f(0.2,0.8,0);

	glBegin(GL_POLYGON);
		glVertex2f(x+20,y+20);
		glVertex2f(x+50,y+20);
		glVertex2f(x+60,y+100);
		glVertex2f(x+30,y+120);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+100,y+20);
		glVertex2f(x+70,y+20);
		glVertex2f(x+60,y+100);
		glVertex2f(x+90,y+120);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+30,y+120);
		glVertex2f(x+60,y+100);
		glVertex2f(x+90,y+120);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(x+30,y+120);
		glVertex2f(x+90,y+120);
		glVertex2f(x+90,y+125);
		glVertex2f(x+30,y+125);
	glEnd();

	glColor3f(0.4,0.8,1);
	glBegin(GL_POLYGON);
		glVertex2f(x+30,y+125);
		glVertex2f(x+90,y+125);
		glVertex2f(x+88,y+185);
		glVertex2f(x+28,y+185);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+78,y+185);
		glVertex2f(x+38,y+185);
		glVertex2f(x+38,y+195);
		glVertex2f(x+78,y+195);
	glEnd();


	glBegin(GL_POLYGON);
		glVertex2f(x+18,y+185);
		glVertex2f(x+28,y+185);
		glVertex2f(x+30,y+175);
		glVertex2f(x+26,y+140);
		glVertex2f(x+4,y+140);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+102,y+185);
		glVertex2f(x+88,y+185);
		glVertex2f(x+86,y+175);
		glVertex2f(x+94,y+140);
		glVertex2f(x+116,y+140);
	glEnd();
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(x+4,y+140);
		glVertex2f(x+26,y+140);
		glVertex2f(x+27,y+145);
		glVertex2f(x+5,y+145);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+94,y+140);
		glVertex2f(x+116,y+140);
		glVertex2f(x+115,y+145);
		glVertex2f(x+93,y+145);
	glEnd();

	glColor3f(1,0.8,0.8);
	glBegin(GL_POLYGON);
		glVertex2f(x+9,y+140);
		glVertex2f(x+21,y+140);
		glVertex2f(x+17,y+100);
		glVertex2f(x+9,y+100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+99,y+140);
		glVertex2f(x+111,y+140);
		glVertex2f(x+111,y+100);
		glVertex2f(x+103,y+100);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+9,y+100);
		glVertex2f(x+17,y+100);
		glVertex2f(x+15,y+92);
		glVertex2f(x+10,y+85);
		glVertex2f(x+9,y+76);
		glVertex2f(x+03,y+88);
		glVertex2f(x+06,y+91);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+111,y+100);
		glVertex2f(x+103,y+100);
		glVertex2f(x+105,y+92);
		glVertex2f(x+110,y+85);
		glVertex2f(x+111,y+76);
		glVertex2f(x+117,y+88);
		glVertex2f(x+114,y+91);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+195);
		glVertex2f(x+65,y+195);
		glVertex2f(x+65,y+205);
		glVertex2f(x+48,y+205);
		glVertex2f(x+50,y+200);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(x+78,y+185);
		glVertex2f(x+58,y+180);
		glVertex2f(x+38,y+185);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+56,y+198);
		glVertex2f(x+66,y+198);
		glVertex2f(x+85,y+220);
		glVertex2f(x+82,y+240);
		glVertex2f(x+56,y+246);
		glVertex2f(x+35,y+235);
		glVertex2f(x+30,y+220);
		glVertex2f(x+48,y+198);
	glEnd();
}

void DrawMen4(int x,int y)
{
	glColor3f(0,0,0);

	glBegin(GL_POLYGON);
		glVertex2f(x+00,y+00);
		glVertex2f(x+50,y+00);
		glVertex2f(x+48,y+20);
		glVertex2f(x+25,y+20);
	glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(x+120,y+00);
		glVertex2f(x+70,y+00);
		glVertex2f(x+72,y+20);
		glVertex2f(x+95,y+20);
	glEnd();

glColor3f(0.68,0,0.11);

	glBegin(GL_POLYGON);
		glVertex2f(x+20,y+60);
		glVertex2f(x+50,y+60);
		glVertex2f(x+60,y+100);
		glVertex2f(x+30,y+120);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+100,y+60);
		glVertex2f(x+70,y+60);
		glVertex2f(x+60,y+100);
		glVertex2f(x+90,y+120);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+30,y+120);
		glVertex2f(x+60,y+100);
		glVertex2f(x+90,y+120);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(x+30,y+120);
		glVertex2f(x+90,y+120);
		glVertex2f(x+90,y+125);
		glVertex2f(x+30,y+125);
	glEnd();

	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(x+30,y+125);
		glVertex2f(x+90,y+125);
		glVertex2f(x+88,y+185);
		glVertex2f(x+28,y+185);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+78,y+185);
		glVertex2f(x+38,y+185);
		glVertex2f(x+38,y+195);
		glVertex2f(x+78,y+195);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+18,y+185);
		glVertex2f(x+28,y+185);
		glVertex2f(x+30,y+175);
		glVertex2f(x+26,y+140);
		glVertex2f(x+4,y+140);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+102,y+185);
		glVertex2f(x+88,y+185);
		glVertex2f(x+86,y+175);
		glVertex2f(x+94,y+140);
		glVertex2f(x+116,y+140);
	glEnd();
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(x+4,y+140);
		glVertex2f(x+26,y+140);
		glVertex2f(x+27,y+145);
		glVertex2f(x+5,y+145);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+94,y+140);
		glVertex2f(x+116,y+140);
		glVertex2f(x+115,y+145);
		glVertex2f(x+93,y+145);
	glEnd();

	glColor3f(1,0.8,0.8);
	glBegin(GL_POLYGON);
		glVertex2f(x+9,y+140);
		glVertex2f(x+21,y+140);
		glVertex2f(x+17,y+100);
		glVertex2f(x+9,y+100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+99,y+140);
		glVertex2f(x+111,y+140);
		glVertex2f(x+111,y+100);
		glVertex2f(x+103,y+100);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+9,y+100);
		glVertex2f(x+17,y+100);
		glVertex2f(x+15,y+92);
		glVertex2f(x+10,y+85);
		glVertex2f(x+9,y+76);
		glVertex2f(x+03,y+88);
		glVertex2f(x+06,y+91);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+111,y+100);
		glVertex2f(x+103,y+100);
		glVertex2f(x+105,y+92);
		glVertex2f(x+110,y+85);
		glVertex2f(x+111,y+76);
		glVertex2f(x+117,y+88);
		glVertex2f(x+114,y+91);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+195);
		glVertex2f(x+65,y+195);
		glVertex2f(x+65,y+205);
		glVertex2f(x+48,y+205);
		glVertex2f(x+50,y+200);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(x+78,y+185);
		glVertex2f(x+58,y+180);
		glVertex2f(x+38,y+185);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+56,y+198);
		glVertex2f(x+66,y+198);
		glVertex2f(x+85,y+220);
		glVertex2f(x+82,y+240);
		glVertex2f(x+56,y+246);
		glVertex2f(x+35,y+235);
		glVertex2f(x+30,y+220);
		glVertex2f(x+48,y+198);
	glEnd();

	glColor3f(0.72,0.48,0.34);
	glBegin(GL_POLYGON);
	glVertex2f(x+28,y+185);
	glVertex2f(x+36,y+185);
	glVertex2f(x+46,y+165);
	glVertex2f(x+38,y+160);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x+92,y+185);
	glVertex2f(x+84,y+185);
	glVertex2f(x+74,y+165);
	glVertex2f(x+82,y+160);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x+30,y+125);
	glVertex2f(x+30,y+135);
	glVertex2f(x+38,y+140);
	glVertex2f(x+38,y+130);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x+90,y+125);
	glVertex2f(x+90,y+135);
	glVertex2f(x+82,y+140);
	glVertex2f(x+82,y+130);
	glEnd();

	glColor3f(0.64,0.35,0.27);
	glBegin(GL_POLYGON);
	glVertex2f(x+38,y+170);
	glVertex2f(x+46,y+165);
	glVertex2f(x+74,y+165);
	glVertex2f(x+82,y+170);
	glVertex2f(x+82,y+130);
	glVertex2f(x+38,y+130);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x+48,y+155);
	glVertex2f(x+72,y+155);
	glVertex2f(x+72,y+140);
	glVertex2f(x+48,y+140);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(x+48,y+155);
	glVertex2f(x+72,y+155);
	glVertex2f(x+60,y+150);
	glEnd();
glColor3f(1,0.8,0.8);
	glBegin(GL_POLYGON);
glVertex2f(x+30,y+19);
glVertex2f(x+45,y+19);
glVertex2f(x+45,y+60);
glVertex2f(x+30,y+60);
glEnd();
	
glBegin(GL_POLYGON);
glVertex2f(x+90,y+19);
glVertex2f(x+75,y+19);
glVertex2f(x+75,y+60);
glVertex2f(x+90,y+60);
glEnd();
}

void DrawMen5(int x,int y)
{	// Draws the man standing in lift 5.

	glColor3f(1,0.55,0.11);
	glBegin(GL_POLYGON);
		glVertex2f(x+80,y+5);
		glVertex2f(x+95,y);
		glVertex2f(x+110,y);
		glVertex2f(x+160,y+45);
		glVertex2f(x+155,y+55);
		glVertex2f(x+150,y+55);
		glVertex2f(x+95,y+25);	
		glVertex2f(x+65,y+25);
		glVertex2f(x+10,y+55);
		glVertex2f(x+5,y+55);
		glVertex2f(x,y+45);
		glVertex2f(x+50,y);
		glVertex2f(x+65,y);
	glEnd();

	glColor3f(0,0,0);

	glBegin(GL_POLYGON);
		glVertex2f(x+110,y+33);
		glVertex2f(x+110,y+39);
		glVertex2f(x+50,y+39);
		glVertex2f(x+50,y+33);
		glVertex2f(x+65,y+25);
		glVertex2f(x+95,y+25);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+46,y+35);
		glVertex2f(x+40,y+20);
		glVertex2f(x+45,y+20);
		glVertex2f(x+48,y+34);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+40,y+39);
		glVertex2f(x+26,y+25);
		glVertex2f(x+33,y+25);
		glVertex2f(x+40,y+35);
	glEnd();

	glColor3f(1,0.78,.8);
		glBegin(GL_POLYGON);
		glVertex2f(x+10,y+65);
		glVertex2f(x+10,y+58);
		glVertex2f(x+20,y+52);
		glVertex2f(x+42,y+65);
		glVertex2f(x+42,y+75);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+150,y+65);
		glVertex2f(x+150,y+58);
		glVertex2f(x+140,y+52);
		glVertex2f(x+118,y+65);
		glVertex2f(x+118,y+75);
	glEnd();

	glColor3f(1,0.55,0.11);
	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+39);
		glVertex2f(x+48,y+41);
		glVertex2f(x+45,y+43);
		glVertex2f(x+43,y+47);
		glVertex2f(x+42,y+105);
		glVertex2f(x+118,y+105);
		glVertex2f(x+117,y+47);
		glVertex2f(x+115,y+43);
		glVertex2f(x+112,y+41);
		glVertex2f(x+110,y+39);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+118,y+105);
		glVertex2f(x+130,y+59);
		glVertex2f(x+145,y+59);
		glVertex2f(x+155,y+70);
		glVertex2f(x+116,y+130);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+44,y+130);
		glVertex2f(x+5,y+70);
		glVertex2f(x+15,y+59);
		glVertex2f(x+30,y+59);
		glVertex2f(x+42,y+105);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+118,y+105);
		glVertex2f(x+116,y+130);
		glVertex2f(x+112,y+128);
		glVertex2f(x+103,y+120);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(x+57,y+120);
		glVertex2f(x+53,y+125);
		glVertex2f(x+48,y+128);
		glVertex2f(x+44,y+130);
		glVertex2f(x+42,y+105);
		glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(x+118,y+105);
		glVertex2f(x+103,y+120);
		glVertex2f(x+57,y+120);
		glVertex2f(x+42,y+105);
	glEnd();

	glColor3f(1,.8,.8);

	glBegin(GL_POLYGON);
		glVertex2f(x+70,y+120);
		glVertex2f(x+90,y+120);
		glVertex2f(x+90,y+138);
		glVertex2f(x+70,y+138);
	glEnd();
	glColor3f(1,0.8,0.8);
	DrawHead(x+80,y+162.5,27.5);

glBegin(GL_POLYGON);
	glVertex2f(x+104,y+172.5);
	glVertex2f(x+108.5,y+175);
	glVertex2f(x+110,y+162.5);
	glVertex2f(x+108.5,y+150);
	glVertex2f(x+104,y+152.5);
glEnd();
glBegin(GL_POLYGON);
	glVertex2f(x+55,y+172.5);
	glVertex2f(x+50.5,y+175);
	glVertex2f(x+49,y+162.5);
	glVertex2f(x+50.5,y+150);
	glVertex2f(x+55,y+152.5);
glEnd();
}

void delay(int wait)
{	//Sets the delay.

	int i,j,k;
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			for(k=0;k<wait;k++);
}

void unsetlift(int no)
{	// Deselects the lift.
	if(SelectedLift[0]==no)
	{
		SelectedLift[0]=SelectedLift[1];
	}
}

void StripBox(int x,int y,int type)
{	// Writes the box on the lift strip.
	if(type==1)
	{
		glBegin(GL_POLYGON);
			glVertex2f(x,y);
			glVertex2f(x+10,y);
			glVertex2f(x+10,y+40);
			glVertex2f(x,y+40);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex2f(x+190,y);
			glVertex2f(x+200,y);
			glVertex2f(x+200,y+40);
			glVertex2f(x+190,y+40);
		glEnd();
	}
	else
	{
		glBegin(GL_POLYGON);
			glVertex2f(x,y);
			glVertex2f(x+10,y);
			glVertex2f(x+10,y+20);
			glVertex2f(x,y+20);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex2f(x+190,y);
			glVertex2f(x+200,y);
			glVertex2f(x+200,y+20);
			glVertex2f(x+190,y+20);
		glEnd();
	}
}
void StripComp(int Fno,int choice)
{	// Writes the complete Lift Strip.
	double x=LiftPoint[Fno].x;
	double y=LiftPoint[Fno].y;
	glColor3f(0,0,0);
	switch(choice)
	{
	case 0:StripBox(x,y+0,1);
		   StripBox(x,y+80,1);
		   StripBox(x,y+160,1);
		   StripBox(x,y+240,1);
		   StripBox(x,y+320,1);
		   break;
	case 1:StripBox(x,y+20,1);
		   StripBox(x,y+100,1);
		   StripBox(x,y+180,1);
		   StripBox(x,y+260,1);
		   StripBox(x,y+340,1);
		   break;
	case 2:StripBox(x,y+40,1);
		   StripBox(x,y+120,1);
		   StripBox(x,y+200,1);
		   StripBox(x,y+280,1);
		   StripBox(x,y+360,1);
		   break;
	case 3:StripBox(x,y+0,2);
		   StripBox(x,y+60,1);
		   StripBox(x,y+140,1);
		   StripBox(x,y+220,1);
		   StripBox(x,y+300,1);
		   StripBox(x,y+380,2);
		   break;
	}
}
void DrawBtnCrl(int no,int c)
{
	int i,j,a,b,radius,rep;
	a=TButton[no][0];
	b=TButton[no][1];
	radius=TButton[no][2];
	for(rep=0;rep<=1;rep++)
	{
		if(rep==1)
		{
			glPointSize(2);
			glColor3f(1,1,1);
			glBegin(GL_POINTS);
			for(i=(b+radius);i>=(b-radius);i=i-0.0001)
			{
				j=sqrt(radius*radius-(i-b)*(i-b))+a;
				glVertex2f(j,i);
			}
			for(i=(b+radius);i>=(b-radius);i=i-0.0001)
			{
				j=-sqrt(radius*radius-(i-b)*(i-b))+a;
				glVertex2f(j,i);
			}
			glEnd();
		}
		else
		{
			if(c==0)
				glColor3f(1,0,0);
			else
				glColor3f(0,1,0);
			glBegin(GL_POLYGON);
		for(i=(a+radius);i>=(a-radius);i=i-0.005)
		{
			j=sqrt(radius*radius-(i-a)*(i-a))+b;
			glVertex2f(i,j);
		}
		for(i=(a+radius);i>=(a-radius);i=i-0.05)
		{
			j=-sqrt(radius*radius-(i-a)*(i-a))+b;
			glVertex2f(i,j);
		}
		glEnd();
		}
		glPointSize(1);
	}
}
void backgroundp3()
{
	glColor3f(0.88,0.23,0.11);

	glBegin(GL_POLYGON);
	glVertex2f(0,50);
	glVertex2f(1366,50);
	glVertex2f(1366,650);
	glVertex2f(0,650);
	glEnd();
	glColor3f(0.96,0.58,0.54);
	glBegin(GL_POLYGON);
	glVertex2f(0,140);
	glVertex2f(1366,140);
	glVertex2f(1366,560);
	glVertex2f(0,560);
	glEnd();
	
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex2f(608,140);
	glVertex2f(758,140);
	glVertex2f(683,50);
	glEnd();
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex2f(608,560);
	glVertex2f(758,560);
	glVertex2f(683,650);
	glEnd();
	BitmapText(600,680,"LOGICAL LIFT",1);
}
void DrawLiftLine(int x,int y,int c)
{
	if(c==1)
		glColor3f(0,0,0);
	else
		glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(x+45,y+125);
		glVertex2f(x+155,y+125);
		glVertex2f(x+155,y+325);
		glVertex2f(x+45,y+325);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(x+155,y+125);
		glVertex2f(x+190,y+0);
		glVertex2f(x+10,y+400);
		glVertex2f(x+45,y+325);
		glVertex2f(x+190,y+400);
		glVertex2f(x+155,y+325);
		glVertex2f(x+10,y+0);
		glVertex2f(x+45,y+125);
		glEnd();
}
void drawlift(int x,int y,int c,int n)
{
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glVertex2f(x,y);
		glVertex2f(x+10,y);
		glVertex2f(x+10,y+400);
		glVertex2f(x,y+400);
	glEnd();

	if(c==1)
		glColor3f(0.199,0,0.398);
	else
		glColor3f(0.199,0.797,0.598);
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y);
		glVertex2f(x+45,y+125);
		glVertex2f(x+45,y+325);
		glVertex2f(x+10,y+400);
	glEnd();

	if(c==1)
		glColor3f(0.199,0,0.598);
	else
		glColor3f(0.398,0.598,0.598);
	glBegin(GL_POLYGON);
		glVertex2f(x+45,y+325);
		glVertex2f(x+155,y+325);
		glVertex2f(x+190,y+400);
		glVertex2f(x+10,y+400);
	glEnd();

	if(c==1)
		glColor3f(0.199,0,0.398);
	else
		glColor3f(0.199,0.797,0.598);
	glBegin(GL_POLYGON);
		glVertex2f(x+155,y+125);
		glVertex2f(x+190,y);
		glVertex2f(x+190,y+400);
		glVertex2f(x+155,y+325);
	glEnd();

	if(c==1)
		glColor3f(0.199,0,0.598);
	else
		glColor3f(0.398,0.598,0.598);
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y);
		glVertex2f(x+190,y);
		glVertex2f(x+155,y+125);
		glVertex2f(x+45,y+125);
	glEnd();

	if(c==1)
		glColor3f(0.199,0,0.0);
	else
		glColor3f(0.398,0.598,0.398);
	glBegin(GL_POLYGON);
		glVertex2f(x+45,y+125);
		glVertex2f(x+155,y+125);
		glVertex2f(x+155,y+325);
		glVertex2f(x+45,y+325);
	glEnd();

	if(c==1)
		glColor3f(0.199,0.199,0.199);
	else
		glColor3f(0.598,0.598,0.598);
	glBegin(GL_POLYGON);
		glVertex2f(x+55,y+125);
		glVertex2f(x+145,y+125);
		glVertex2f(x+145,y+275);
		glVertex2f(x+55,y+275);
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glVertex2f(x+190,y);
		glVertex2f(x+200,y);
		glVertex2f(x+200,y+400);
		glVertex2f(x+190,y+400);
	glEnd();
	
	if(c==1)
		glColor3f(0.598,0.598,0.598);
	else
		glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glVertex2f(x+71,y+290);
		glVertex2f(x+130,y+290);
		glVertex2f(x+130,y+310);
		glVertex2f(x+71,y+310);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(x+100,y+125);
	glVertex2f(x+100,y+275);
	glEnd();
	sprintf(LiftChar,"%d",LiftFloor[n]);
	glColor3f(0,0,0);
	BitmapText(x+86,y+292,LiftChar,1);
}


void DrawScore()
{
	char string[50];
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
	glVertex2f(0,60);
	glVertex2f(200,60);
	glVertex2f(230,85);
	glVertex2f(200,110);
	glVertex2f(0,110);
	glEnd();
	glColor3f(0,0,0);
	sprintf(string,"No of Moves = %d",NoMove);
	BitmapText(20,80,string,1);

		glColor3f(1,0,1);
	glBegin(GL_POLYGON);
	glVertex2f(1366,60);
	glVertex2f(1136,60);
	glVertex2f(1106,85);
	glVertex2f(1136,110);
	glVertex2f(1366,110);
	glEnd();
	glColor3f(0,0,0);
		sprintf(string,"No of Elevators = %d",SelectCount);
	BitmapText(1136,80,string,1);
}

void outline(int x,int y)
{
	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x,y);
	glVertex2f(x+200,y);
	glVertex2f(x+200,y+400);
	glVertex2f(x,y+400);
	glEnd();

}


void Mouse(int button,int state,int x,int y)
{
	
	y=ScreenHeight-y;
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		switch(ScreenNo)
		{
		case 2:if(x>=593 && x<=773 && y>=240 && y<=320)
				   exit(0);
				else if(x>=543 && x<=823 && y>=360 && y<=440)
					ScreenNo=4;
				else if(x>=593 && x<=773 && y>=490 && y<=570)
				   ScreenNo=3;
				break;

		case 3:if(x>=100 && x<=300 && y>=150 && y<=550 && LiftMov==0 && End!=1)
			   {
				   if(LiftColor[0]==0)
				   {
						SelectCount--;
						unsetlift(0);
					
						LiftColor[0]=!LiftColor[0];
				   }
				   else
				   {
					   if(SelectCount!=2)
					   {
					
						   SelectedLift[SelectCount]=0;
						   	SelectCount++;
								
							LiftColor[0]=!LiftColor[0];
					   }
				   }
			   }
		else if(x>=348.5 && x<=548.5 && y>=150 && y<=550 && LiftMov==0 && End!=1)
				{
				   if(LiftColor[1]==0)
				   {
					
						SelectCount--;
						unsetlift(1);
						LiftColor[1]=!LiftColor[1];
					
				   }
				   else
				   {
					   if(SelectCount!=2)
					   {					
						SelectedLift[SelectCount]=1;	
						   SelectCount++;
						LiftColor[1]=!LiftColor[1];
					    }
				   }
			   }
		else if(x>=583 && x<=783 && y>=150 && y<=550 && LiftMov==0 && End!=1)
				{
				   if(LiftColor[2]==0)
				   {
						SelectCount--;
						unsetlift(2);
						LiftColor[2]=!LiftColor[2];
				   }
				   else
				   {
					   if(SelectCount!=2)
					   {
					SelectedLift[SelectCount]=2;		
					   SelectCount++;
				               LiftColor[2]=!LiftColor[2];
					    }
				   }
			   }
	        else if(x>=824.5 && x<=1024.5 && y>=150 && y<=550 && LiftMov==0 && End!=1)
				{
				   if(LiftColor[3]==0)
				   {
						SelectCount--;
						unsetlift(3);
						LiftColor[3]=!LiftColor[3];
				   }
				   else
				   {
					   if(SelectCount!=2)
					   {
						SelectedLift[SelectCount]=3;		
					   SelectCount++;
						LiftColor[3]=!LiftColor[3];
					   }
				   }
			   }
			else if(x>=1066 && x<=1266 && y>=150 && y<=550 && LiftMov==0 && End!=1)
				{
				   if(LiftColor[4]==0)
				   {
						SelectCount--;
						unsetlift(4);
						LiftColor[4]=!LiftColor[4];
				   }
				   else
				   {
					   if(SelectCount!=2)
					   {
								SelectedLift[SelectCount]=4;
					   SelectCount++;
			   		           LiftColor[4]=!LiftColor[4];
				                    }
				   }
				}

				else if(sqrt((x-683)*(x-683)+(y-590)*(y-590))<=30 && End!=1)
				{
		             if(SelectCount==2 && (LiftFloor[SelectedLift[0]]+8)<=49 && (LiftFloor[SelectedLift[1]]+8)<=49 && LiftMov==0)
					{
						LiftMov=1;
						FloorCount=8;
						NoMove++;
						StripMover=20;
					}
				}
				else if(sqrt((x-683)*(x-683)+(y-110)*(y-110))<=30 && End!=1)
				{
					if(SelectCount==2 && (LiftFloor[SelectedLift[0]]-13)>=0 && (LiftFloor[SelectedLift[1]]-13)>=0 && LiftMov==0)
					{
						LiftMov=2;
						FloorCount=13;
						NoMove++;
						StripMover=0;
					}
				}
			break;

		case 4:if(x>=593 && x<=773 && y>=90 && y<=170)
					ScreenNo=3;
				break;
		case 5:if(x>=593 && x<=773 && y>=90 && y<=170 && NoMove>8)
			   {
					LiftFloor[0]=17;
					LiftFloor[1]=26;
					LiftFloor[2]=20;
					LiftFloor[3]=19;
					LiftFloor[4]=31;
					End=0;
					NoMove=0;
					ScreenNo=3;
			   }
				else if(x>=593 && x<=773 && y>=90 && y<=170 && NoMove<=8)
					exit(0);
				break;
		}
	}
	glutPostRedisplay();
}
void PassiveMouse(int x,int y)
{
	y=ScreenHeight-y;
	if(LiftMov==0){
	switch(ScreenNo)
	{
	case 2:if(x>=593 && x<=773 && y>=240 && y<=320)
			   BColor[2]=0;
			else if(x>=543 && x<=823 && y>=360 && y<=440)
			   BColor[1]=0;
			else if(x>=593 && x<=773 && y>=490 && y<=570)
			   BColor[0]=0;
			else
			{
				BColor[0]=1;
				BColor[1]=1;
				BColor[2]=1;
			}
			break;

	case 3:if(x>=100 && x<=300 && y>=150 && y<=550 && LiftColor[0]==1)
					LineColor[0]=0;
			else if(x>=348.5 && x<=548.5 && y>=150 && y<=550 && LiftColor[1]==1)
					LineColor[1]=0;
			else if(x>=583 && x<=783 && y>=150 && y<=550 && LiftColor[2]==1)
					LineColor[2]=0;
			else if(x>=824.5 && x<=1024.5 && y>=150 && y<=550 && LiftColor[3]==1)
					LineColor[3]=0;
			else if(x>=1066 && x<=1266 && y>=150 && y<=550 && LiftColor[4]==1)
					LineColor[4]=0;
			else if(sqrt((x-683)*(x-683)+(y-590)*(y-590))<=30)
					TBColor[0]=0;
			else if(sqrt((x-683)*(x-683)+(y-110)*(y-110))<=30)
					TBColor[1]=0;
			else
			{
				LineColor[0]=1;
				LineColor[1]=1;
				LineColor[2]=1;
				LineColor[3]=1;
				LineColor[4]=1;
				TBColor[1]=1;
				TBColor[0]=1;
			}
			break;

	case 4:if(x>=593 && x<=773 && y>=90 && y<=170)
			   BColor[0]=0;
			else
				BColor[0]=1;
			break;
	case 5:if(x>=593 && x<=773 && y>=90 && y<=170)
			   BColor[0]=0;
			else
				BColor[0]=1;
			break;
	}
	
	glutPostRedisplay();
     }
}
void DrawCircle(int a,int b,int radius,int c)
{
	int i,j,rep;
	for(rep=0;rep<=1;rep++)
	{
		if(rep==1)
		{
			glPointSize(2);
			glColor3f(1,1,1);
			glBegin(GL_POINTS);
			for(i=(b+radius);i>=(b-radius);i=i-0.0001)
			{
				j=sqrt(radius*radius-(i-b)*(i-b))+a;
				glVertex2f(j,i);
			}
			for(i=(b+radius);i>=(b-radius);i=i-0.0001)
			{
				j=-sqrt(radius*radius-(i-b)*(i-b))+a;
				glVertex2f(j,i);
			}
			glEnd();
		}
		else
		{
			if(c==0)
				glColor3f(0,1,1);
			else
				glColor3f(1,1,0);
			glBegin(GL_POLYGON);
		for(i=(a+radius);i>=(a-radius);i=i-0.005)
		{
			j=sqrt(radius*radius-(i-a)*(i-a))+b;
			glVertex2f(i,j);
		}
		for(i=(a+radius);i>=(a-radius);i=i-0.05)
		{
			j=-sqrt(radius*radius-(i-a)*(i-a))+b;
			glVertex2f(i,j);
		}
		glEnd();
		}
		glPointSize(1);
	}
}
void DrawButton(int x,int y,int width,char *string,int c)
{
	DrawCircle(x,y,40,c);
	DrawCircle(x+width,y,40,c);
	if(c==0)
		glColor3f(0,1,1);
	else
		glColor3f(1,1,0);

	glBegin(GL_POLYGON);
		glVertex2f(x-5,y+40);
		glVertex2f(x+width+5,y+40);
		glVertex2f(x+width+5,y-40);
		glVertex2f(x-5,y-40);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(x-5,y+40);
		glVertex2f(x+width+5,y+40);
		glVertex2f(x+width+5,y-40);
		glVertex2f(x-5,y-40);
	glEnd();
	glColor3f(1,0,0);
	BitmapText(x+10,y-5,string,1);
}
void BitmapText(int x,int y,char *string,int type)
{
	int len,i;
	glRasterPos2f(x,y);
	len=(int) strlen(string);
	switch(type)
	{
		case 1:	for(i=0;i<len;i++)
				{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
				}
				break;
		case 2: for(i=0;i<len;i++)
				{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,string[i]);
				}
	}
}
void OpenDoor(int no,int i)
{
	double x=LiftPoint[no].x+100,y=LiftPoint[no].y;
	glBegin(GL_POLYGON);
	glVertex2f(x-i,y+125);
	glVertex2f(x+i,y+125);
	glVertex2f(x+i,y+275);
	glVertex2f(x-i,y+275);
	glEnd();
}

void page1(void)
{
	int i,j;
if(mov==0)
{
	glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,1,1);
	BitmapText(200,650,"Atria Institute of Technology",1);
			BitmapText(445,600,"Department of Computer Science and Engineering",1);
		glColor3f(0,1,0);
			BitmapText(500,500,"A Computer Graphics Mini Project On",1);
			BitmapText(615,450,"LOGICAL LIFT",1);
			BitmapText(680,400,"by",1);
		glColor3f(1,0,0);
			BitmapText(130,310,"Abdul Raheem",1);
			BitmapText(950,310,"            ",1);
		glColor3f(1,1,1);	
		BitmapText(525,220,"UNDER THE GUIDENCE OF",1);
		BitmapText(300,155,"            ",1);
                BitmapText(900,155,"          ",1);
		BitmapText(425,155,"       ",2);
                BitmapText(1050,155,"          ",2);
		BitmapText(300,130,"                ",1);
BitmapText(900,130,"                     ",1);
		BitmapText(300,100,"                 ",1);
BitmapText(900,100,"             ",1);
		glColor3f(1,1,1);
		BitmapText(620,25,"Press Enter",1);
		glutSwapBuffers();
		mov=1;
	}
}
void page2(void)
{
		glClear(GL_COLOR_BUFFER_BIT);
                DrawButton(633,530,100,"START",BColor[0]);
		DrawButton(583,400,200," INSTRUCTION",BColor[1]);
		DrawButton(633,280,100," EXIT",BColor[2]);
		glutSwapBuffers();
}

void page3(void)
{
	int m,WinCheck;
	static int i=0;
	
	glClear(GL_COLOR_BUFFER_BIT);
	backgroundp3();
	
	if(LiftMov!=0)
	{

		FloorCount--;	
		if(LiftMov==1)
	            {	
		LiftFloor[SelectedLift[0]]++;
		LiftFloor[SelectedLift[1]]++;
	            }
		else
		{
			LiftFloor[SelectedLift[0]]--;
			LiftFloor[SelectedLift[1]]--;
		}
			if(FloorCount==0)
		{
			LiftMov=0;
			LiftColor[SelectedLift[0]]=1;
		LiftColor[SelectedLift[1]]=1;
		SelectCount=0;
			WinCheck=1;
			for(m=0;m<=4;m++)
		if(!(LiftFloor[m]>=21&&LiftFloor[m]<=25))
			WinCheck=0;
		if(WinCheck==1)
		{
			End=1;
			i=0;
		}
		}
	delay(250);
	}
               drawlift(100,150,LiftColor[0],0);
	drawlift(341.5,150,LiftColor[1],1);
	drawlift(583,150,LiftColor[2],2);
	drawlift(824.5,150,LiftColor[3],3);
	drawlift(1066,150,LiftColor[4],4);
	outline(100,150);
	outline(341.5,150);
	outline(583,150);
	outline(824.5,150);
	outline(1066,150);
	DrawLiftLine(100,150,LineColor[0]);
	DrawLiftLine(341.5,150,LineColor[1]);
	DrawLiftLine(583,150,LineColor[2]);
	DrawLiftLine(824.5,150,LineColor[3]);
	DrawLiftLine(1066,150,LineColor[4]);
	DrawBtnCrl(0,TBColor[0]);
	DrawBtnCrl(1,TBColor[1]);
	
	glColor3f(0,0,0);
	BitmapText(670,585,"+8",1);
	BitmapText(660,105,"-13",1);
	DrawScore();
	
	if(LiftMov!=0)
	{
		if(LiftMov==1)
			StripMover--;
		else
			StripMover++;
		for(m=0;m<=4;m++)
		{
			if(SelectedLift[0]==m || SelectedLift[1]==m)
				StripComp(m,abs(StripMover)%4);
			else
				StripComp(m,0);
		}
	}
	else
	{
		for(m=0;m<=4;m++)	
			StripComp(m,0);
	}
	if(End==1)
	{
	glColor3f(1,1,1);
	i++;

	OpenDoor(0,i);
	OpenDoor(1,i);
	OpenDoor(2,i);
	OpenDoor(3,i);
	OpenDoor(4,i);
	delay(75);
	
	if(i==45)
		ScreenNo=5;
	}
	DrawMen1(100+35,150+35);
	DrawMen2(341.5+35,150+35);
	DrawMen3(583+35,150+35);
	DrawMen4(824.5+35,150+35);
	DrawMen5(1066+20,150+30);

	glutSwapBuffers();
	glutPostRedisplay();
}

void page4(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
	BitmapText(200,600,"INSTRUCTIONS : ",1);
	glColor3f(1,1,0);
      BitmapText(300,500,"*   There are 5 elevators that are struck in  different floors of a 49 storey building.",1);
       BitmapText(300,450,"*   Help the characters inside the elevators to get of elevatrors.",1);
       BitmapText(300,400,"*   Select exactly 2 elevators at a time.",1);
       BitmapText(300,350,"*   Move the elevators either 8 floors upward or 13 floors downward.",1);
       BitmapText(300,300,"*   Elevators door opens only when all the elevators are between 21st and 25th floors.",1);
	DrawButton(633,130,100," START",BColor[0]);
	glutSwapBuffers();
}

void page5(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	if(NoMove>9)
	{
		BitmapText(590,500,"OUTSTANDING..!!",1);	
		BitmapText(500,400,"Can you make it in just 8 moves..!??.",1);
		DrawButton(633,130,100,"START",BColor[0]);
	}
	else
	{
		BitmapText(590,500,"OUTSTANDING..!!",1);
		BitmapText(600,400,"   THE END.",1);
		DrawButton(633,130,100," EXIT",BColor[0]);
	}
	glutSwapBuffers();
}

void Display(void)
{
	switch(ScreenNo)
	{
	case 1:page1(); break;
	case 2:page2();break;
	case 3:page3();break;
	case 4:page4();break; 
	case 5:page5();break;
	}
}

void KeyBoard(unsigned char ch,int x,int y)
{
	if(ScreenNo==1)
	{
		switch(ch)
		{
		case 13:glClear(GL_COLOR_BUFFER_BIT);
				if(mov==1)
				{
			      ScreenNo=2;
				  glutPostRedisplay();
				}
				  break;
		}	
	}
}
void Reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1366,0,706);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0,0,0,1);
}
 int  main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1366,706);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Logical Lift");
	glutKeyboardFunc(KeyBoard);
               glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutPassiveMotionFunc(PassiveMouse);
	glutMouseFunc(Mouse);
	glutMainLoop();
}
                                                                        
                                    
