#include<Windows.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <cmath>

#define PI 3.1415926535

void inicia()
{
    glClearColor(0.09f,0.11f,0.25f,1.0f);
}

void backf()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void pCaca()
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.150f, 0.10f, 0.0f);
    glColor4ub(174,139,192,255);
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, 0.3f, 0.0f);                          // Top Left
    glVertex3f( 0.3f, 0.3f, 0.0f);                          // Top Right
    glVertex3f( 0.3f,-0.3f, 0.0f);                          // Bottom Right
    glVertex3f(-0.3f,-0.3f, 0.0f);
    glEnd();
}

void porta()
{
    glPopMatrix();
    glFlush();
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.150f, 0.10f, 0.0f);
    glColor4ub(61,82,88,255);
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, 0.1f, 0.0f);                          // Top Left
    glVertex3f( 0.1f, 0.1f, 0.0f);                          // Top Right
    glVertex3f( 0.1f,-0.3f, 0.0f);                          // Bottom Right
    glVertex3f(-0.1f,-0.3f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void chao()
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.150f, -0.50f, 0.0f);
    glColor4ub(0,255,0,255);
    glBegin(GL_QUADS);
    glVertex3f(-1.9f, 0.3f, 0.0f);                          // Top Left
    glVertex3f( 1.9f, 0.3f, 0.0f);                          // Top Right
    glVertex3f( 1.9f,-0.6f, 0.0f);                          // Bottom Right
    glVertex3f(-1.9f,-0.6f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void telhado()
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.150f, 0.50f, 0.0f);
    glRotatef(300.0,160.0,1.0,0.0);
    glScalef(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);

    glColor3f(1.0,0,0);
    glVertex2f(-0.5,-0.5);
    glColor3f(0.8,0,0);
    glVertex2f(0.5,-0.5);
    glColor3f(0.67,0,0);
    glVertex2f(0.0,0.5);
    glPopMatrix();
    glEnd();
    glFlush();
}

void Poste1()
{
    glPopMatrix();
    glFlush();
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.850f, 0.10f, 0.0f);
    glColor4ub(128,0,0,255);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.6f, 0.0f);                          // Top Left
    glVertex3f(0.1f, 0.6f, 0.0f);                          // Top Right
    glVertex3f(0.1f,-0.3f, 0.0f);                          // Bottom Right
    glVertex3f(0.0f,-0.3f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void Poste2()
{
    glPopMatrix();
    glFlush();
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.850f, 0.70f, 0.0f);
    glColor4ub(128,0,0,255);
    glBegin(GL_QUADS);
    glVertex3f(0.2f, 0.0f, 0.0f);                          // Top Left
    glVertex3f(0.0f, 0.0f, 0.0f);                          // Top Right
    glVertex3f(0.0f,-0.1f, 0.0f);                          // Bottom Right
    glVertex3f(0.2f,-0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void luz()
{
    glPopMatrix();
    glFlush();
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.650f, 0.68f, 0.0f);
    glColor4ub(255,255,255,255);
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, 0.0f, 0.0f);                          // Top Left
    glVertex3f(0.0f, 0.0f, 0.0f);                          // Top Right
    glVertex3f(0.0f,-0.1f, 0.0f);                          // Bottom Right
    glVertex3f(-0.1f,-0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void globo()
{
    glPopMatrix();
    glFlush();
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.650f, 0.65f, 0.0f);
    glColor4ub(255,255,0,1);
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, 0.0f, 0.0f);                          // Top Left
    glVertex3f(0.0f, 0.0f, 0.0f);                          // Top Right
    glVertex3f(0.0f,-0.1f, 0.0f);                          // Bottom Right
    glVertex3f(-0.1f,-0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void tronco()
{
    glPopMatrix();
    glFlush();
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.600f, 0.10f, 0.0f);
    glColor4ub(128,0,0,255);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.3f, 0.0f);                          // Top Left
    glVertex3f(0.1f, 0.3f, 0.0f);                          // Top Right
    glVertex3f(0.1f,-0.3f, 0.0f);                          // Bottom Right
    glVertex3f(0.0f,-0.3f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void arvore()
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.650f, 0.40f, 0.0f);
    glRotatef(300.0,160.0,1.0,0.0);
    glScalef(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);

    glColor3f(0.05,0.35,0);
    glVertex2f(-0.3,-0.3);
    glColor3f(0.08,0.57,0);
    glVertex2f(0.3,-0.3);
    glColor3f(0.09,0.7,0);
    glVertex2f(0.0,0.9);
    glPopMatrix();
    glEnd();
    glFlush();
}

void Rua(){
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.150f, -0.50f, 0.0f);
    glColor4ub(37,37,37,255);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, 0.1f, 0.0f);                          // Top Left
    glVertex3f( 1.9f, 0.1f, 0.0f);                          // Top Right
    glVertex3f( 1.9f,-0.3f, 0.0f);                          // Bottom Right
    glVertex3f(-1.0f,-0.3f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void Faixa(float x){
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, -0.55f, 0.0f);
    glColor4ub(245,255,0,255);
    glBegin(GL_QUADS);
    glVertex3f(-1.1f, 0.0f, 0.0f);                          // Top Left
    glVertex3f(-0.9f, 0.0f, 0.0f);                          // Top Right
    glVertex3f(-0.9f,-0.1f, 0.0f);                          // Bottom Right
    glVertex3f(-1.1f,-0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void desenha()
{
    backf();
    pCaca();
    porta();
    chao();
    telhado();
    Poste1();
    globo();
    luz();
    Poste2();
    tronco();
    arvore();
    Rua();
    Faixa(0.180);

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Casa");
    inicia();
    glutDisplayFunc(desenha);
    glutMainLoop();
    return 0;

}
