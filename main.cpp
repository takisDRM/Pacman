#include <stdio.h>
#include "gl/glut.h"
#include "visuals.h"
#include <string.h>

void main()
{ 
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(50,50);
	glutCreateWindow("\"Pacman-like\" - Panagiotis Mavrodakos");

	Setup();
 
	// The rendering function.
	glutDisplayFunc(Render);
	glutReshapeFunc(Resize);
	glutIdleFunc(Idle);
	 
	// Keyboard thread functions.
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(Keyboard2);
	
	//Menu epilogis xrwmatos tou keimenou pou emfanizetai me right-click tou pontikiou.
	glutCreateMenu(MenuSelect);
		glutAddMenuEntry("Red",1);
		glutAddMenuEntry("Blue",3);
		glutAddMenuEntry("Green",2);
		glutAddMenuEntry("White",4);
		glutAddMenuEntry("Cyan",6);
		glutAddMenuEntry("Magenta",7);
		glutAddMenuEntry("Yellow",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
}  