#include<Windows.h>
#include <gl/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
GLfloat T =0;
void espin()
{

    T =T+0.1;
    if(T>360) T=0;
    glutPostRedisplay();
}
void desenha()
{
    GLfloat Pos[]={0,1,0,1};
    GLfloat Col[]={1,0,0,1};
    GLfloat Ml[]={0,1,0,1};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glLoadIdentity();
    glLightfv(GL_LIGHT0,GL_POSITION,Pos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,Col);

    gluLookAt(0,1,3,0,0,0,0,1,0);

    glRotatef(T,0,1,0);

    glPushMatrix();
    glTranslatef(0.9,-0.4,0.1);
    glScalef(0.5,0.05,0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.12,-0.15,0.10);
    glScalef(0.05,0.5,0.5);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glScalef(1,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.45,-0.5,-0.45);
    glScalef(0.05,1,0.05);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.45,-0.5,-0.45);
    glScalef(0.05,1,0.05);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.45,-0.5,0.45);
    glScalef(0.05,1,0.05);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.45,-0.5,0.45);
    glScalef(0.05,1,0.05);
    glutSolidCube(1);
    glPopMatrix();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,Ml);
    glPushMatrix();
    glTranslatef(0,0.15,0);
    glutSolidTeacup(0.25);
    glPopMatrix();
    glPopAttrib();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,Ml);
    glPushMatrix();
    glTranslatef(0,0.15,0.35);
    glScalef(0.5,0.5,0.5);
    glutSolidTeapot(0.25);
    glPopMatrix();
    glPopAttrib();





   // glutSolidCone(3,3,3,6);
    glutSwapBuffers();

}
void Initin(void)
{
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    Initin();
    glutDisplayFunc(desenha);
    glutIdleFunc(espin);
    glutMainLoop();
    return 0;
}
