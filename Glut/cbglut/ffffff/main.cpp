#include<Windows.h>
#include<GL/glut.h>
#include<iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int winSize = 500;
int ballEdgeSize = 50;
float ballEdgeUnitSize, halfBallEdgeSize;
float defaultZ = -2;
double currentTime, lastTime;
float ballSpeed;

class Vector
{
	public:
		float x, y;

		void zero()
		{
			x - 0;
			y = 0;
		}

		void random()
		{
			x = 1;
			y = 1;

			srand((int)time(0));
			if (rand() %2 == 0)
			{
				x = -1;
			}
			if (rand () %2 == 0)
			{
				y = -1;
			}
		}
};

Vector ballPosition, ballDirection;

float pixelToUnit(float pixel)
{
	return pixel / winSize;
}
static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void placeBall()
{
	ballPosition.zero();
	ballDirection.random();
}

void display()
{
	currentTime = glutGet(GLUT_ELAPSED_TIME)/1000.0;
	currentTime -= lastTime;

	cout << ballDirection.x << endl;

	if (currentTime >= 1/75)   /* 75Hz screen*/
	{
		lastTime += currentTime;

		float speed = ballSpeed *(1 / (float)winSize);
		ballPosition.x += speed * ballDirection.x;
		ballPosition.y += speed * ballDirection.y;

	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(0, 0, 1);

	glPushMatrix();
		glTranslated(ballPosition.x, ballPosition.y, defaultZ);
		glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glVertex2f(-halfBallEdgeSize, -halfBallEdgeSize);
		glVertex2f(halfBallEdgeSize, -halfBallEdgeSize);
		glVertex2f(halfBallEdgeSize, halfBallEdgeSize);
		glVertex2f(-halfBallEdgeSize, halfBallEdgeSize);
	glEnd();

	glutSwapBuffers();
}

static void idle()
{
	glutPostRedisplay();
}
int main(int argc, char *arqv[])
{
	ballEdgeUnitSize = pixelToUnit(halfBallEdgeSize);
	halfBallEdgeSize = ballEdgeSize / 2;
	ballPosition.zero();
	ballDirection.zero();

	glutInit(&argc, arqv);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(winSize, winSize);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Pong");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);

	glutIdleFunc(idle);

	glutMainLoop();
}
