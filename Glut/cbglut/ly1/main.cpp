#include<Windows.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <cmath>
#define M_PI 3.14159265358979323846
float posX=0, posY=0,escalax=0,escalay=0,angulo=0;
int n=0;
void inicia()
{
    glClearColor(0.0f,01.0f,1.0f,0.0f);
}
void LUA()
{
    glPushMatrix();
    glTranslatef(0.400, 0.400, 0.0f);
    glScalef(0.09, 0.09, 0.0f);
    double ang1 = 2* M_PI/100 ;
    glPolygonMode( GL_FRONT, GL_FILL );
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    double angle2=0.0;
    glVertex2d( cos(0.0), sin(0.0));
    int i;
    for ( i=0; i<100; i++)
    {
        glVertex2d( cos(angle2),sin(angle2));
        angle2 += ang1 ;
        glColor3f(1.0, 1.0, 1.0 );
    }
    glEnd();
    glPopMatrix();
    glFlush();
}
void SOL()
{
    glPushMatrix();
    glTranslatef(-0.70, 0.800, 0.0f);
    glScalef(0.09, 0.09, 0.0f);
    double ang1 = 2* M_PI/100 ;
    glPolygonMode( GL_FRONT, GL_FILL );
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    double angle2=0.0;
    glVertex2d( cos(0.0), sin(0.0));
    int i;
    for ( i=0; i<100; i++)
    {
        glVertex2d( cos(angle2),sin(angle2));
        angle2 += ang1 ;
    }
    glEnd();
//RAIO DO SOL
    glScalef(3.0, 3.0, 0.0f);
    glLineWidth(1);
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_LINE_LOOP);
    double angle=0.0;
    glVertex2d( cos(0.0), sin(0.0));
    for ( i=0; i<100; i++)
    {
        glVertex2d( cos(angle),sin(angle));
        angle += ang1 ;
    }
    glEnd();
    glPopMatrix();
    glFlush();
}
void corpo(float a, float b)
{
//corpo
    glColor3f(1.00,0.50,0.20);//laranja
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(-0.3f, 0.1f); // Top Left
    glVertex2f( 0.3f, 0.1f); // Top Right
    glVertex2f( 0.3f,-0.1f); // Bottom Right
    glVertex2f(-0.3f,-0.1f);
    glEnd();
//cauda
    glBegin(GL_TRIANGLES);
    glColor3f(1.00,0.00,0.00);//branco
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.6f, 0.3f);
    glVertex2f(-0.6f, 0.10f);
    glEnd();
//traco da cauda
    glColor3f(0.00,0.00,0.00);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.6f, 0.3f);
    glVertex2f(-0.6f, 0.10f);
    glEnd();
}
void nariz_e_janela(float a, float b)
{
//nariz
    glBegin(GL_TRIANGLES);
    glColor3f(1.00,0.50,0.20);//laranja
    glVertex2f(0.3f, 0.1f);
    glVertex2f(0.5f, 0.03f);
    glVertex2f(0.3f, -0.1f);
    glEnd();
//janela
    glBegin(GL_TRIANGLES);
    glColor3f(1.00,1.00,1.00);//branco
    glVertex2f(0.3f, 0.1f);
    glVertex2f(0.5f, 0.03f);
    glVertex2f(0.3f, -0.02f);
    glEnd();
//traco da janela
    glColor3f(0.00,0.00,0.00);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.3f, 0.1f);
    glVertex2f(0.5f, 0.03f);
    glVertex2f(0.3f, -0.02f);
    glEnd();
}
void asa(float a, float b)
{
//asa
    glColor3f(1.00,0.00,.00);//vermelho
    glBegin(GL_QUADS);
    glVertex2f(-0.04f, 0.02f); // Top Left
    glVertex2f( 0.2f, 0.02f); // Top Right
    glVertex2f( 0.001f,-0.3f); // Bottom Right
    glVertex2f(-0.37f,-0.3f);
    glEnd();
//traco da asa
    glColor3f(0.00,0.00,.00);//vermelho
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.04f, 0.02f); // Top Left
    glVertex2f( 0.2f, 0.02f); // Top Right
    glVertex2f( 0.001f,-0.3f); // Bottom Right
    glVertex2f(-0.37f,-0.3f);
    glEnd();
}
void janela_passageiro(float a, float b)
{
//traco janela
    GLfloat x, y, ang;
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        ang = (i * M_PI) / 180;
        x = a + (cos(ang) * 0.020);
        y = b + (sin(ang) *0.020);
        glVertex2f(x, y);
    }
    glEnd();
//enchimento janela
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        ang = (i * M_PI) / 180;
        x = a + (cos(ang) * 0.020);
        y = b + (sin(ang) *0.020);
        glVertex2f(x, y);
    }
    glEnd();
}
void desenhar()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(n==1)
        LUA();
    else
        SOL();
    glPushMatrix();
    glLoadIdentity();
    glScalef((0.7+(escalax)), (0.7+(escalay)), 0.0f);
    glTranslatef((0.100f+(posX)), (0.10f+(posY)), 0.0f);
    glRotatef(angulo, 0, 0, 1);
    corpo(posX, posY);
    nariz_e_janela(posX, posY);
    asa(posX, posY);
    for(int i =2; i < 8; i++)
        janela_passageiro(-0.50 + (0.090 * i), 0.055);
    glPopMatrix();
    glPopMatrix();
    glFlush();
}
void TeclaPressionada(unsigned char tecla,int x, int y)
{
    switch (tecla)
    {
    case 'a': //<-
    case 'A':
        posX -= 0.10;
        break;
    case 'w': //cima
    case 'W':
        posY += 0.10;
        break;
    case 'd': //->
    case 'D':
        posX += 0.10;
        break;
    case 's': //baixo
    case 'S':
        posY -= 0.10;
        break;
    case '+': //aumenta
        escalax += 0.01;
        escalay+=0.01;
        break;
    case '-': //DIMINUI
        escalax -= 0.01;
        escalay -=0.01;
        break;
    case 't'://esquerda_GIRO
    case 'T':
        angulo += 10;
        break;
    case 'r'://direita_GIRO
    case 'R':
        angulo -= 10;
        break;
    case 'e'://direita_cima
    case 'E':
        posX+=0.10;
        posY+=0.10;
        break;
    case 'q'://esqueda_baixo
    case 'Q':
        posX-=0.10;
        posY+=0.10;
        break;
    case 'z'://esquerda_cima
    case 'Z':
        posX-=0.10;
        posY-=0.10;
        break;
    case 'x'://esquerda_cima
    case 'X':
        posX+=0.10;
        posY-=0.10;
        break;
    case '1'://noite
        glClearColor(0.016f,0.017f,0.30f,0.0f);
        n=1;
        break;
    case '2'://dia
        glClearColor(0.0f,01.0f,1.0f,0.0f);
        n=0;
        break;
    case 27://ESC
        exit(0);
        break;
    }
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(5,5);
    glutInitWindowSize(950,950);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("aviao_paint");
    glutKeyboardFunc(TeclaPressionada);
    glutDisplayFunc(desenhar);
    inicia();
    glutMainLoop();
    return 0;
}
