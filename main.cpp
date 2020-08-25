/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <math.h>


static float	tx	=  0.0;
static float	ty	=  0.0;

//float p=-2.3;
void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = rx * cosf(theta);//calculate the x component
		float y = ry * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);




  ///face
  glColor3ub(255, 203, 126);
  DrawCircle(50,50,33.5,33.5,500);
  glBegin(GL_POLYGON);
  glVertex2d(20,35);
  glVertex2d(40,10);
  glVertex2d(60,10);
  glVertex2d(80,35);
  glEnd();
  ///eye brow
  glColor3f(0,0,0);
  DrawCircle(35,60,10,6,500);
  glColor3ub(255, 203, 126);
  DrawCircle(35,57,10,6,500);

  glColor3f(0,0,0);
  DrawCircle(65,60,10,6,500);
  glColor3ub(255, 203, 126);
  DrawCircle(65,57,10,6,500);

  ///eye
  glColor3f(1,1,1);
  DrawCircle(35,55,10,5,500);
  DrawCircle(65,55,10,5,500);
  glColor3f(0,0,0);
  DrawCircle(65,55,3,3,500);
  DrawCircle(35,55,3,3,500);

  ///lip
  glColor3f(1,1,1);
  DrawCircle(50,30,15,7,500);
  glColor3ub(255, 203, 126);
  DrawCircle(50,35,15,7,500);

  ///nose
   glColor3f(1,1,1);
    DrawCircle(50,40,5,8,500);



	glFlush();
}
void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(0, 100,0, 100, -1.0, 1.0);
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("circle");
	init();
    glutDisplayFunc(display);
	//glutKeyboardFunc(my_keyboard);
	//glutSpecialFunc(spe_key);
	//glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;
}


