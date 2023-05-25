#include <GL/gl.h>
#include <GL/freeglut.h>
#include <stdlib.h>

float theta = 0.0f;

void inicia()
{

glClearColor(1.0f,1.0f,1.0f,1.0f);

}

void desenha()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.00,0.00,0.00);
    glVertex2f(-0.5,-0.5);

    glColor3f(0.0,1.0,0.0);
    glVertex2f(0.5,-0.5);

    glColor3f(0.0,0.0,1.0);
    glVertex2f(0.0,0.5);


    glEnd();

    glPopMatrix();
    theta += 1.0f;
    Sleep (1);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("odio");
    inicia();
    glutDisplayFunc(desenha);
    glutMainLoop();
    return 0;

}
