#include<Windows.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

using namespace std;

#define M_PI       3.14159265358979323846

float x = 0.300f;
float X = 0.180f;
float r = -0.80f;

static void teclaPressionado(unsigned char tecla,int posicaoX,int posicaoY)
{
    switch(tecla){
case 'd':
case 'D':
    if(x<=1.76f || x>=0.26f){
        x +=0.010f;
        r +=0.010f;
    }
    break;
case 'a':
case 'A':
    if(x<=1.76f || x>=0.26f){
        x -=0.010f;
        r -=0.010f;
    }
    }
    glutPostRedisplay();
}

void circulo(float sx,float sy,float tx,float ty,float r,float g,float b)
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(tx,ty,0.0f);
    glScalef(sx,sy,0.0f);
    double ang1 = 2*  M_PI/100 ;
    glPolygonMode( GL_FRONT, GL_FILL );
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
        double ang2=0.0;
        glVertex2d( cos(0.0) , sin(0.0));
        int i;
        for ( i=0 ; i< 100 ;i++)
        {

            glVertex2d( cos(ang2),sin(ang2));
            ang2 += ang1 ;
        }

    glEnd();
    glPopMatrix();
    glFlush();
}

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
    circulo(0.25,0.30,0.650f,0.40f,0.05,0.35,0);
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

void carroceria(float x){
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, -0.50f, 0.0f);
    glColor4ub(43,180,6,255);
    glBegin(GL_QUADS);
    glVertex3f(-1.1f, 0.1f, 0.0f);                          // Top Left
    glVertex3f(-0.9f, 0.1f, 0.0f);                          // Top Right
    glVertex3f(-0.9f,-0.1f, 0.0f);                          // Bottom Right
    glVertex3f(-1.1f,-0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void frenteTras(float x){
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, -0.50f, 0.0f);
    glColor4ub(43,180,6,255);
    glBegin(GL_QUADS);
    glVertex3f(-1.2f, 0.0f, 0.0f);                          // Top Left
    glVertex3f(-0.8f, 0.0f, 0.0f);                          // Top Right
    glVertex3f(-0.8f,-0.1f, 0.0f);                          // Bottom Right
    glVertex3f(-1.2f,-0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void LanternaF(float x){
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, -0.50f, 0.0f);
    glColor4ub(245,245,0,255);
    glBegin(GL_QUADS);
    glVertex3f(-0.8f, 0.0f, 0.0f);                          // Top Left
    glVertex3f(-0.79f, 0.0f, 0.0f);                          // Top Right
    glVertex3f(-0.79f,-0.1f, 0.0f);                          // Bottom Right
    glVertex3f(-0.8f,-0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void LanternaT(float x){
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, -0.50f, 0.0f);
    glColor4ub(180,6,6,255);
    glBegin(GL_QUADS);
    glVertex3f(-1.2f, 0.0f, 0.0f);                          // Top Left
    glVertex3f(-1.19f, 0.0f, 0.0f);                          // Top Right
    glVertex3f(-1.19f,-0.1f, 0.0f);                          // Bottom Right
    glVertex3f(-1.2f,-0.1f, 0.0f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void rodas(float x){
    circulo(0.05,0.10,x,-0.65f,0.08, 0.08, 0.08);
}

void moon(){
    circulo(0.12,0.17,0.20f,0.70f,1, 0.94, 0.26);
    circulo(0.12,0.17,0.25f,0.70f,0.09,0.11,0.25);
}

void carro(float x , float r){
    carroceria(x);
    frenteTras(x);
    LanternaF(x);
    LanternaT(x);
    rodas(r);
    rodas(r+0.20);
}

void faixas (float x){
    float t=0.00f;
    for(int i=0;i<4;i++){
        Faixa(x+t);
        t+=0.50f;
    }
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
    faixas(X);
    carro(x,r);
    moon();

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Casa");
    glutKeyboardFunc(teclaPressionado);
    inicia();
    glutDisplayFunc(desenha);
    glutMainLoop();
    return 0;

}
