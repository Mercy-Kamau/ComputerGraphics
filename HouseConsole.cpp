#include <Windows.h>
#include <GL\glut.h>
#include <iostream>
#include <cmath>
#include <math.h>
//#include <stdarg.h>



// current Window width and height
//int  win_width, win_height;


void display() {


	glClear(GL_COLOR_BUFFER_BIT);
	

	

	//Rectangle code
	glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.55f, 0.35f);
	glVertex2f(-0.55f, 0.25f);
	glVertex2f(-0.45f, 0.25f);
	glVertex2f(-0.45f, -0.35f);
	glVertex2f(0.45f, -0.35f);
	glVertex2f(0.45f, 0.25f);
	glVertex2f(0.55f, 0.25f);
	glVertex2f(0.55f, 0.35f);

	glEnd();

	//Semicircle  code
	float RADIUS = 0.1;
	float DEGREE_TO_RAD = 3.14 / 180;
	float CIRCLE_HEIGHT = 0.35;

	glBegin(GL_LINE_LOOP);
	
	glColor3f(1.0f, 0.5f, 0.0f);//Orange
	int M_IN_DEGREE = 180;
	int N_IN_DEGREE = 0;
	for (int nR = N_IN_DEGREE; nR <= M_IN_DEGREE; nR++)
	{
		float fY = sin((float)nR * DEGREE_TO_RAD) * CIRCLE_HEIGHT + 0.35;
		float fX = cos((float)nR * DEGREE_TO_RAD) * CIRCLE_HEIGHT;

		glVertex2f(fX, fY);
	}

	glEnd();

	glColor4f(1.0f, 0.0f, 1.0f, 0.0f);//purple
	glBegin(GL_POLYGON);
	glVertex2f(-0.1f, 0.15f);
	glVertex2f(-0.1f, -0.35f);
	glVertex2f(0.1f, -0.35f);
	glVertex2f(0.1f, 0.15f);

	glEnd();
	//Window 1
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 255, 0);
	glVertex2f(-0.4f, 0.15f);
	glVertex2f(-0.4f, -0.1f);
	glVertex2f(-0.2f, -0.1f);
	glVertex2f(-0.2f, 0.15f);
	glEnd();

	//Window 2
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 255, 0);
	glVertex2f(0.2f, 0.15);
	glVertex2f(0.2f, -0.1f);
	glVertex2f(0.4f, -0.1f);
	glVertex2f(0.4f, 0.15f);
	glEnd();

	//Window Bars 1
	//Vertical
	glBegin(GL_LINES);
	glColor3f(0.5f, 0.5f, 0.5f);//Violet
	glVertex2f(-0.3f, 0.15f);
	glVertex2f(-0.3f, -0.1f);
	glEnd();
	//HorizontalglColor3f(0.5f, 0.5f, 0.5f);//Violet
	glBegin(GL_LINES);
	glColor3f(0.5f, 0.5f, 0.5f);//Violet
	glVertex2f(-0.4f, 0.025f);
	glVertex2f(-0.2f, 0.025f);
	glEnd();

	//Window Bars 2
	//Vertical
	glBegin(GL_LINES);
	glColor3f(0.5f, 0.5f, 0.5f);//Violet
	glVertex2f(0.3f, 0.15f);
	glVertex2f(0.3f, -0.1f);
	glEnd();
	//Horizontal
	glBegin(GL_LINES);
	glColor3f(0.5f, 0.5f, 0.5f);//Violet
	glVertex2f(0.4f, 0.025f);
	glVertex2f(0.2f, 0.025f);
	glEnd();
	


	//circle
	int i;
	float PI = 3.142;
	GLfloat x = 0.065f;
	GLfloat y = -0.1f;
	GLfloat radius = .015f;
	int triangleAmount = 40;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(61, 143, 174);
	glVertex2f(x, y);
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount)));

	}
	glEnd();

	//circle

	GLfloat k = 0.55f;
	GLfloat m = 0.75f;
	GLfloat rad = 0.2f;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(k, m);
	int R = 255;
	int G = 201;
	int B = 0;
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(k + (rad * cos(i * twicePi / triangleAmount)),
			m + (rad * sin(i * twicePi / triangleAmount)));
		R -= 4;
		G -= 4;
		glColor3ub(R, G, B);
	}
	glEnd();

	//circle

	GLfloat l = 0.60f;
	GLfloat n = 0.80f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);
	glVertex2f(l, n);
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(l + (rad * cos(i * twicePi / triangleAmount)),
			n + (rad * sin(i * twicePi / triangleAmount)));
	}
	glEnd();

	glFlush();
}
/*void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, GLdouble(width), 0, GLdouble(height));
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}*/
int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(900, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("2D House with Cresent Moon");
		glutDisplayFunc(display);
		//glutReshapeFunc(reshape);
	glutMainLoop();
}