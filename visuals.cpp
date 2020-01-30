#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "gl/glut.h"
#include "visuals.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define Pi 3.1415926535897932384626433832795
double x= 0.0f;
double y= 0.0f;
GLdouble radius= 0.4f;
GLdouble mouth= 1.7f;
int numOfTri= 50;
int flag= 1;
int score= 0;


//Metavliti gia tin kinisi tou antikeimenou ston aksona X',X me to keyboard.
double tx = 0.0;

//Metavliti gia tin kinisi tou antikeimenou ston aksona Y',Y me to mouse.
double ty= 0.0;

//Metavlites gia tin allagi xrwmatos kata tin epilogi me to right-button tou mouse.
float red = 1.0;
float green = 1.0;
float blue = 0.0;

//Metavliti gia to Rotate tou antikeimenou ston aksona Z',Z kai ston Y'Y.
int rotx= 0;
int roty= 0;
int rotz= 1;
double rotFace= 0.0;

//Borders
double Y_array[9]= {3.9000f, 2.9000f, 1.9000f, 0.9000f, -0.1000f, -0.8000f, -1.6000f, -2.3000f, -3.0000f};
double X_array[9][14]=  { 
							{-5.5000f, -4.7000f, -3.9000f, -3.1000f, -2.3000f, -0.7000f, 0.1000f, 0.9000, 2.3000f, 3.1000f, 3.9000f, 4.7000f, 5.5000f, 0.0000f}, 
							{-3.9000f, -2.3000f, -0.7000f, 0.9000f, 2.3000f, 3.9000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.0000f},
							{-5.5000f, -3.9000f, -2.3000f, -0.7000f, 0.9000f, 2.3000f, 3.9000f, 5.5000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.0000f},
							{-5.5000f, -3.9000f, -2.3000f, -0.7000f, 0.9000f, 2.3000f, 3.9000f, 5.5000f, 0.000f, 0.000f, 0.000f, 0.000f, 0.0000f},
							{-5.5000f, -4.7000f, -3.9000f, -2.3000f, -1.5000f, 1.6000f, 2.4000f, 3.2000f, 3.9500f, 4.7000f, 5.5000f, 0.000f, 0.000f, 0.0000f},
							{-2.3000f, -0.7000f, 0.9000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f},
							{-5.5000f, -4.7000f, -3.9000f, -3.1000f, -2.3000f, -0.7000f, 0.9000f,  1.6000f, 2.3000f, 3.1000f, 3.9000f, 4.7000f, 5.5000f, 0.0000f},
							{-5.5000f, -0.7000f, 0.9000f, 5.5000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f},
							{-5.5000f, -4.7000f, -3.9000f, -3.1000f, -2.3000f, -1.5000f,-0.7000f, 0.9000f,  1.6000f, 2.3000f, 3.1000f, 3.9000f, 4.7000f, 5.5000f}
						};

int X_array_bin[9][14]=  { 
							{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, 
							{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
							{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
							{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
							{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
							{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							{1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 0},
							{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
						};

void eatPill();
void finale();

void labyrinthDraw()
{
	//Borders
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
		glVertex2f(-6.2 , -3.4);
		glVertex2f(-6.2 , 3.4);
		glVertex2f(-6.0 , 3.4);
		glVertex2f(-6.0 , -3.4);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(-6.2 , 4.6);
		glVertex2f(6.2 , 4.6);
		glVertex2f(6.2 , 4.4);
		glVertex2f(-6.2 , 4.4);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.2 , 4.4);
		glVertex2f(6.2 , -2.6);
		glVertex2f(6.0 , -2.6);
		glVertex2f(6.0 , 4.4);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.2 , -3.6);
		glVertex2f(-6.2 , -3.6);
		glVertex2f(-6.2 , -3.4);
		glVertex2f(6.2 , -3.4);
	glEnd();

	//Maze
	glBegin(GL_POLYGON);			//X= -6.2 ews -4.8
		glVertex2f(-4.8 , 3.4);		//Y= 3.4 ews 2.8
		glVertex2f(-6.2 , 3.4);
		glVertex2f(-6.2 , 2.8);
		glVertex2f(-4.8 , 2.8);
	glEnd();
	glBegin(GL_POLYGON);			//X= -4.8 ews -4.2
		glVertex2f(-5.0 , 3.4);		//Y= 3.4 ews 1.0
		glVertex2f(-4.4 , 3.4);
		glVertex2f(-4.4 , 0.6);
		glVertex2f(-5.0 , 0.6);
	glEnd();

	glBegin(GL_POLYGON);			//X= -6.2 ews -2.8
		glVertex2f(-6.2 , -0.6);	//Y= -0.8 ews 0.2
		glVertex2f(-2.8 , -0.6);
		glVertex2f(-2.8 , -1.0);
		glVertex2f(-6.2 , -1.0);
	glEnd();
	glBegin(GL_POLYGON);			//X= -2.8 ews -2.8
		glVertex2f(-3.4 , -0.8);	//Y= -0.8 ews 3.4
		glVertex2f(-3.4 , 3.4);
		glVertex2f(-2.8 , 3.4);
		glVertex2f(-2.8 , -0.8);
	glEnd();
	
	glBegin(GL_POLYGON);			//X= -5.0 ews -0.8
		glVertex2f(-5.0 , -2.0);	//Y= -2.4 ews -1.8
		glVertex2f(-1.2 , -2.0);
		glVertex2f(-1.2 , -2.6);
		glVertex2f(-5.0 , -2.6);
	glEnd();
	glBegin(GL_POLYGON);			//X= -1.8 ews -1.2
		glVertex2f(-1.8 , -0.6);	//Y= -0.6 ews -1.8
		glVertex2f(-1.2 , -0.6);
		glVertex2f(-1.2 , -2.0);
		glVertex2f(-1.8 , -2.0);
	glEnd();
	
	glBegin(GL_POLYGON);			//X= -1.2 ews -1.8
		glVertex2f(-1.2 , 0.6);		//Y= -0.6 ews 4.6
		glVertex2f(-1.8 , 0.6);
		glVertex2f(-1.8 , 4.6);
		glVertex2f(-1.2 , 4.6);
	glEnd();

	////////////////////////////////////////////////////////////////////////////////////////////

	//Maze
	glBegin(GL_POLYGON);			//X= -6.2 ews -4.8
		glVertex2f(4.8 , 3.4);		//Y= 3.4 ews 2.8
		glVertex2f(6.2 , 3.4);
		glVertex2f(6.2 , 2.8);
		glVertex2f(4.8 , 2.8);
	glEnd();
	glBegin(GL_POLYGON);			//X= -4.8 ews -4.2
		glVertex2f(5.0 , 3.4);		//Y= 3.4 ews 1.0
		glVertex2f(4.4 , 3.4);
		glVertex2f(4.4 , 0.6);
		glVertex2f(5.0 , 0.6);
	glEnd();

	glBegin(GL_POLYGON);			//X= -6.2 ews -2.8
		glVertex2f(6.2 , -0.6);		//Y= -0.8 ews 0.2
		glVertex2f(1.4 , -0.6);
		glVertex2f(1.4 , -1);
		glVertex2f(6.2 , -1);
	glEnd();
	glBegin(GL_POLYGON);			//X= -2.8 ews -2.8
		glVertex2f(3.4 , 0.6);		//Y= -0.8 ews 3.4
		glVertex2f(3.4 , 3.4);
		glVertex2f(2.8 , 3.4);
		glVertex2f(2.8 , 0.6);
	glEnd();
	

	glBegin(GL_POLYGON);			//X= -1.2 ews -1.8
		glVertex2f(-0.2 , 0.6);		//Y= -0.6 ews 4.6
		glVertex2f(0.4 , 0.6);
		glVertex2f(0.4 , 3.4);
		glVertex2f(-0.2 , 3.4);
	glEnd();
	
	glBegin(GL_POLYGON);			//X= -1.2 ews -1.8
		glVertex2f(1.4 , 4.6);		//Y= -0.6 ews 4.6
		glVertex2f(1.8 , 4.6);
		glVertex2f(1.8 , 0.6);
		glVertex2f(1.4 , 0.6);
	glEnd();

	glBegin(GL_POLYGON);				//X= -1.2 ews -1.8
		glVertex2f(-0.2 , -0.6);		//Y= -0.6 ews 4.6
		glVertex2f(0.4 , -0.6);
		glVertex2f(0.4 , -3.4);
		glVertex2f(-0.2 , -3.4);
	glEnd();
	
	glBegin(GL_POLYGON);			//X= -5.0 ews -0.8
		glVertex2f(5.0 , -2.0);		//Y= -2.4 ews -1.8
		glVertex2f(1.2 , -2.0);
		glVertex2f(1.2 , -2.6);
		glVertex2f(5.0 , -2.6);
	glEnd();

	//Score panel
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
		glVertex2f(6.2 , -3.6);
		glVertex2f(-6.2 , -3.6);
		glVertex2f(-6.2 , -4.7);
		glVertex2f(6.2 , -4.7);
	glEnd();

	//Our Names
	string s = "Mavrodakos Panagiotis CS101108";	//Convert int to string.
	double size=0.002;

	glColor3f(0, 0, 0);
	glPushMatrix();
		glTranslatef(-5.80, -4.0, 0.0);
		glScalef(size, size, size);

		for (int i=0; i<s.length(); i++)
			glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-5.80, -4.4, 0.0);
		glScalef(size, size, size);
		for (int i=0; i<s2.length(); i++)
			glutStrokeCharacter(GLUT_STROKE_ROMAN,s2[i]);
	glPopMatrix();

	glColor3f(1, 1, 1);
	glPushMatrix();
		glTranslatef(-5.83, -4.02, 0.0);
		glScalef(size, size, size);

		for (int i=0; i<s.length(); i++)
			glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-5.83, -4.42, 0.0);
		glScalef(size, size, size);
		for (int i=0; i<s2.length(); i++)
			glutStrokeCharacter(GLUT_STROKE_ROMAN,s2[i]);
	glPopMatrix();
}




///////////////////////////////////////////////////////////////////////////////////////////////
////// Sxediasmos tou Pacman															 //////
///////////////////////////////////////////////////////////////////////////////////////////////
//
void PacmanDraw()
{
	glPushMatrix();
		//Body
		glTranslatef(tx, ty, 0);
		glRotatef(rotFace, rotx, roty, rotz);
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(red, green, blue);
			glVertex2f(x , y);	//The first edge (0,0).
			
			for(int i=0; i<numOfTri; i++)
			{
				glVertex2f( -(x + (radius * cos(i *  (Pi*mouth) / numOfTri))) , (y + (radius * sin(i * (Pi*mouth) / numOfTri))) );
			}
		glEnd();

		//Eye
		glColor3f(0, 0, 0);
		glTranslatef(x-0.09f, y+0.1f, 0);

		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(x , y);
			
			for(int i=0; i<numOfTri; i++)
			{
				glVertex2f( -(x + ((radius-(radius*0.88f)) * cos(i *  Pi*2.1f / numOfTri))) , (y + ((radius-(radius*0.88f)) * sin(i * Pi*2.1f / numOfTri))) );
			}
			
		glEnd();
	glPopMatrix();
}
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////




void Mouse(int button,int state,int x,int y)
{
	 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)	//Se periptosi pou to Left button
	 {														//(button==GLUT_LEFT_BUTTON) einai
		glutPostRedisplay();								//einai patimeno (state==GLUT_DOWN).
	 }
}



//Se afti tin sunartisi metaferete i epilogi apo to menu tou right-button tou mouse wste na
//dwsei nees times stis metavlite red, green, blue kai na morfopoii8ei to neo epilegomeno xrwma.
void MenuSelect(int choice)
{
	switch (choice) 
	{
		case 1:	red = 1.0; 
				green = 0.0; 
				blue = 0.0; 
				break;
		case 2: red = 0.0; 
				green = 1.0; 
				blue = 0.0; 
				break;
		case 3: red = 0.0; 
				green = 0.0; 
				blue = 1.0; 
				break;
		case 4: red = 1.0; 
				green = 1.0; 
				blue = 1.0; 
				break;
		case 5: red= 1.0;
				green= 1.0;
				blue= 0.1;
				break;
		case 6: red= 0.0;
				green= 1.0;
				blue= 1.0;
				break;
		case 7: red= 1.0;
				green= 0.0;
				blue= 1.0;
				break;
	}

	glColor3f(red, green, blue);
	glutPostRedisplay();
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////// Keyboard Path Checks /////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
int check_left_path(double x, double y)
{
	int flag= 1;

	if( (y>=-0.25f && y<=0.25f) && ((x>=-2.45f && x<=-2.35f) || (x>=-5.65f && x<=-5.55f)) )	//Ean vriskete se afta ta simeia na min kini8ei.
		flag= 0;
	else if ( (y>=0.35f && y<= 3.65f) && ((x>=5.35f && x<=5.45f) || (x>=3.75f && x<=3.85f) || (x>=2.15f && x<=2.25f) || (x>=0.75f && x<=0.85f) || (x>=-0.85f && x<=-0.75f) || (x>=-2.45f && x<=-2.35f) || (x>=-4.05f && x<=-3.95f) || (x>=-5.65f && x<=-5.55f)) )
		flag= 0;
	else if( (y>=3.75f && y<=4.05f) && ((x>=-0.85f && x<=-0.75f) || (x>=2.15f && x<=2.25f)) )// || (x>=-5.65f && x<=-5.55f)) )
		flag= 0;
	else if( (y>=-1.25 && y<=-0.35)  && ((x>=0.75f && x<=0.85f) || (x>=-0.85f && x<=-0.75f) || (x>=-2.45f && x<=-2.35f) || (x>=-5.65f && x<=-5.55f)) )
		flag= 0;
	else if( (y>=-1.65 && y<=-1.35)  && ((x>=0.75f && x<=0.85f) || (x>=-0.85f && x<=-0.75f) || (x>=-5.65f && x<=-5.55f)) )
		flag= 0;
	else if( (y>=-2.85 && y<=-1.75)  && ((x>=5.35 && x<=0.85) || (x>=0.75f && x<=0.85f) || (x>=-0.85f && x<=-0.75f) || (x>=5.35 && x<=5.45) || (x>=-5.65f && x<=-5.55f)) )
		flag= 0;
	else if( (y>=-3.05 && y<=-2.95)  && ((x>=0.75f && x<=0.85f) || (x>=-5.65f && x<=-5.55f)) )
		flag= 0;

	return flag;
}

///////////////////////////////////////////////////

int check_right_path(double x, double y)
{
	int flag= 1;

	if( (y>=-0.25f && y<=0.25f) && ((x>=-3.85f && x<=-3.75f) || (x>=5.55f && x<=5.65f)) )	//Ean vriskete se afta ta simeia na min kini8ei.
		flag= 0;
	else if ( (y>=0.35f && y<= 3.65f) && ((x>=-5.45f && x<=-5.35f) || (x>=-3.85f && x<=-3.75f) || (x>=-2.25f && x<=-2.15f) || (x>=-0.65f && x<=-0.55f) || (x>=0.95f && x<=1.05f) || (x>=-2.35f && x<=2.45f) || (x>=3.95f && x<=4.05f) || (x>=5.55f && x<=5.65f)) )
		flag= 0;
	else if( (y>=3.75f && y<=4.05f) && ((x>=-2.25f && x<=-2.15f) || (x>=0.95f && x<=1.05f) || (x>=5.55f && x<=5.65f)) )
		flag= 0;
	else if( (y>=-1.25 && y<=-0.35)  && ((x>=-2.25f && x<=-2.15f) || (x>=-0.65f && x<=-0.55f) || (x>=0.95f && x<=1.05f) || (x>=5.55f && x<=5.65f)) )
		flag= 0;
	else if( (y>=-1.65 && y<=-1.35)  && ((x>=-2.25f && x<=-2.15f) || (x>=-0.65f && x<=-0.55f) || (x>=5.55f && x<=5.65f)) )
		flag= 0;
	else if( (y>=-2.85 && y<=-1.75)  && ((x>=-5.45f && x<=-5.35f) || (x>=-2.45 && x<=-2.35) || (x>=-0.65f && x<=-0.55f) || (x>=0.75f && x<=0.85f) ||  (x>=5.55f && x<=5.65f)) )
		flag= 0;
	else if( (y>=-3.05 && y<=-2.95)  && ((x>=-0.65f && x<=-0.55f)) )// || (x>=5.55f && x<=5.65f)) )
		flag= 0;

	return flag;
}

//////////////////////////////////////////////////////////

int check_up_path(double x, double y)
{
	int flag= 1;

	if( (y>=3.95f && y<=4.05f) && ((x>=-6.65f && x<=-2.15f) || (x>=-0.85f && x<=1.05f) || (x>=2.15 && x<=5.65)) )	//Ean vriskete se afta ta simeia na min kini8ei.
		flag= 0;
	else if( (y>=2.35f && y<=2.45f) && ((x>=-5.65f && x<=-5.35f) || (x>=5.35f && x<=5.65f)) )	//Ean vriskete se afta ta simeia na min kini8ei.
		flag= 0;
	else if( (y>=0.15f && y<=0.25f) && ((x>=-5.25f && x<=-4.15f) || (x>=-2.05f && x<=-0.95f) || (x>=-0.45f && x<=0.65f) || (x>=1.15f && x<=2.05f) || (x>=2.55f && x<=3.65f) || (x>=4.15f && x<=5.25f)) )	//Ean vriskete se afta ta simeia na min kini8ei.
		flag= 0;
	else if( (y>=-1.45f && y<=-1.35f) && ((x>=-5.65f && x<=-2.55f) || (x>=1.15f && x<=5.65f)) )
		flag= 0;
	else if( (y>=-3.05 && y<=-2.95f) && ((x>=-5.25f && x<=-0.95f) || (x>=0.95f && x<=5.25f) || (x>=5.70f && x<=6.65f)) )
		flag= 0;

	return flag;
}

/////////////////////////////////////////////////////////////////

int check_down_path(double x, double y)
{
	int flag= 1;

	if( (y>=3.75f && y<=3.85f) && ((x>=-6.65f && x<=-4.15f) || (x>=-3.65f && x<=-2.55f) || (x>=-0.45 && x<=0.65) || (x>=2.55 && x<=3.65) || (x>=4.15 && x<=5.65)) )	//Ean vriskete se afta ta simeia na min kini8ei.
		flag= 0;
	else if( (y>=-0.25f && y<=-0.15f) && ((x>=-5.65f && x<=-3.75f) || (x>=-2.05f && x<=-0.95f) || (x>=-0.45f && x<=0.65f) || (x>=1.15f && x<=5.65f)) )	//Ean vriskete se afta ta simeia na min kini8ei.
		flag= 0;
	else if( (y>=-1.65 && y<=-1.55f) && ((x>=-5.25f && x<=-2.15f) || (x>=0.95f && x<=5.25f)) )
		flag= 0;
	else if( (y>=-3.05f && y<=-2.95f) && ((x>=-5.65f && x<=6.65f)) )
		flag= 0;


	return flag;
}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////// eatPills /////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
void eatPill()
{
	for(int j=0; j<9; ++j)
	{
		//printf("Y_array[%d]= %f\n", j, Y_array[j]);
		if( ((ty-0.3f) <= Y_array[j]) && ((ty+0.3) >= Y_array[j]) )
		{
			for(int xi=0; xi<14; xi++)
			{
				if( ((tx-0.2f) <= X_array[j][xi]) && ((tx+0.2f) >= X_array[j][xi]) )
				{
					X_array_bin[j][xi]= 0;
				}
			}
		}
	}
	//printf("ty= %f (%f - %f)\n", ty, ty-0.3f, ty+0.3f);
}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////





//Keyboard thread for special characters.
void Keyboard2(int key, int x, int y)
{
	double step= 0.2;

	switch(key)
	{
		case GLUT_KEY_LEFT:	if(check_left_path(tx , ty))	
							{			
								tx-= step;
								if( (ty>=3.70 && ty<=4.10) && (tx>=-6.35f && tx<=-6.20f) )
								{
									ty= -3.0f;
									tx= 5.80f;
								}
							}
							rotx= 0;
							roty= 0;
							rotz= 1;
							rotFace= 0;
							break;

		case GLUT_KEY_RIGHT:if(check_right_path(tx , ty))	
							{
								tx+= step;
								if ( (ty>=-3.05 && ty<=-2.95) && (tx>=6.00f && tx<=6.30f) )
								{
									ty= 3.80f;
									tx= -5.80f;
								}
							}
							rotx= 0;
							roty= 1;
							rotz= 0;
							rotFace= 180;
							break;
							 
		case GLUT_KEY_DOWN:	if(check_down_path(tx , ty))
							{
								ty-= step;
							}
							rotx= 0;
							roty= 0;
							rotz= 1;
							rotFace= 70;
							break;

		case GLUT_KEY_UP:	if(check_up_path(tx , ty))	
							{
								ty+= step;		
							}
							rotx= 0;
							roty= 0;
							rotz= 1;
							rotFace= -115;
							break;
		default:  ;		
	}

	eatPill();

	//View Thesis
	//printf("tx= %f\n",tx);
	//printf("ty= %f\n",ty);
	

	glutPostRedisplay();		//H sunartisi "glutPostRedisplay()" xriazete se oles tis
								//tis sunartiseis pou xrisimopoioun threads, opws kai stin
								//"Idle()". H leitourgia tis einai, na epistrefei stin ektelesi 
								//tou programmatos meta tin efarmogi tou thread.
}







//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////// dots /////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
void dots()
{
	
	GLdouble radius= 0.15f;
	double x_step, y_step;
	int numOfTri= 50;
	
	int x_x_index, x_y_index, y_index;
	int x_plithos, y_plithos;

	glColor3f(1,1,1);
	
	//x_step= 0.8000f;
	x_x_index= 0;
	x_y_index= 0;
	x_plithos=  sizeof(X_array[0]) / 8;

	y_index= 0;
	y_plithos= sizeof(Y_array)/8;

	glPushMatrix();
		for(x_y_index= 0, y_index= 0; x_y_index < y_plithos; x_y_index++, y_index++)
		{
			for(x_x_index= 0; x_x_index < x_plithos; x_x_index++)
			{
				if(X_array_bin[x_y_index][x_x_index])
				{
					glBegin(GL_TRIANGLE_FAN);
						for(int i=0; i<numOfTri; i++)
						{
							glVertex2f( (X_array[x_y_index][x_x_index] + ((radius * cos(i *  Pi*2.1f / numOfTri)))) , (Y_array[y_index] + ((radius * sin(i * Pi*2.1f / numOfTri)))) );
						}
					glEnd();
				}
			}
		}
	glPopMatrix();
}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////




//Keyboard thread for based characters.
void Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:	exit(0);		//Otan patisoume to pliktro 'Escape' stamataei i efarmogi.
					break;			//O ASCII number tou Escape einai o ari8mos 27.

		default:  ;
	}
	glutPostRedisplay();		//H sunartisi "glutPostRedisplay()" xriazete se oles tis
								//tis sunartiseis pou xrisimopoioun threads, opws kai stin
								//"Idle()". H leitourgia tis einai, na epistrefei stin ektelesi 
								//tou programmatos meta tin efarmogi tou thread.
}



void count_score()
{
	int dots, x, y, sizeof_x_dim_X_array, sizeof_y_dim_X_array;

	x= y= dots= sizeof_x_dim_X_array= sizeof_y_dim_X_array= 0;

	sizeof_x_dim_X_array= sizeof(X_array[0])/8;
	sizeof_y_dim_X_array= sizeof(Y_array)/8;

	for(y=0; y < sizeof_y_dim_X_array; y++)
	{
		for(x=0; x < sizeof_x_dim_X_array; x++)
		{
			if(X_array_bin[y][x]) dots++;
		}
	}

	score= dots;
	//printf("score= %d\n",dots);

	//Convert int to string
		stringstream out;
		out << score;
		string s = out.str();
		double size=0.004;
		double plus= 0.001;

		//Draw score
		for(int j=0; j<5; ++j)
		{
			glPushMatrix();
				glTranslatef(-0.3, -4.3, 0.0);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(size+plus, size+plus, size+plus);
				plus= plus+0.00008;

				for (int i=0; i<s.length(); i++)
					glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
			glPopMatrix();
		}
}




void Render()
{    
	//CLEARS FRAME BUFFER ie COLOR BUFFER& DEPTH BUFFER (1.0)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Clean up the colour of the window and the depth buffer.
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	
	glTranslatef(0, 0, -8);

	//Dimiourgeia Antikeimenwn.
	count_score();
	if(score)
	{
		dots();
		PacmanDraw();
		labyrinthDraw();
		count_score();
	}
	else
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		finale();
	}

	glutSwapBuffers();
}



void finale()
{
	PacmanDraw();
	tx= ty= 0;

	//Convert int to string
	string s = "You just ate all the pills... JUNKY!!!";
	string s2= "\n\n\n...Press 'Esc' to EXIT...";
	double size=0.004;

	glPushMatrix();
		glTranslatef(-4.6, 0.8, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(size, size, size);

		for (int i=0; i<s.length(); i++)
			glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.0, -4.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(size-0.0015, size-0.0015, size-0.0015);
		for (int i=0; i<s2.length(); i++)
			glutStrokeCharacter(GLUT_STROKE_ROMAN,s2[i]);
	glPopMatrix();
}




void Resize(int w, int h)
{ 
	// define the visible area of the window ( in pixels )
	if (h==0) h=1;
	glViewport(0,0,w,h); 

	// Setup viewing volume
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
 
	gluPerspective(60.0, (float)w/(float)h, 1.0, 500.0);
}



void Idle()
{   
	double max= 2.0f;
	double min= 1.7f;
	double step= 0.008f;

	if(flag==1)
	{
		mouth= mouth+step;
		if(mouth>=max)	flag= 0;
	}
	else if(flag==0)
	{
		mouth= mouth-step;
		if(mouth<=min) flag= 1;
	}

	glutPostRedisplay();
}



void Setup()
{ 
	//Parameter handling.
	glShadeModel (GL_SMOOTH);


	// Black background
	glClearColor(0.0f,0.0f,0.0f,1.0f);
}