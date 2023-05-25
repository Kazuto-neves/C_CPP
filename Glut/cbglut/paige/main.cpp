#include<Windows.h>
#include <gl/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <stb_image.h>
//#include <textura.h>

//textura CuboTex[1];

#define tamP 1.5
#define tamH 1.2
#define Vel 0.01

GLfloat T1=0;
GLuint tex_id;
GLuint tex_i;
GLuint text_ii;
GLdouble Q=0,W=1,E=3,R=0,T=0,Y=0,A=0,S=1,D=0;
GLfloat x=0.2,y=0,z=0;
char sentido = 'A';



using namespace std;
void carregatextura(GLuint tex_id, string filePath)
{
    unsigned char* imgData;
    int largura,altura,canais;
    stbi_set_flip_vertically_on_load(true);
    imgData=stbi_load(filePath.c_str(),&largura,&altura,&canais,4);
    if(imgData)
    {

        glBindTexture(GL_TEXTURE_2D, tex_id);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8, largura,altura,0,GL_RGBA, GL_UNSIGNED_BYTE,imgData);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        stbi_image_free(imgData);

    }
    else{
        cout<<"ERRO:Nao foi possivel carregar a textura!"<< filePath.c_str()<<endl;

    }

}

void espin()
{

    T1 =T1+0.1;
    if(T1>360) T1=0;
    glutPostRedisplay();


}

void socorro(GLuint id)
{
    glNewList(id,GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D,0);
    glColor3f(1.00,0.00,.00);//vermelho
    glBegin(GL_QUADS);
      glTexCoord2f(0.0,0.0);  glVertex3f(-0.25,0.015,0.25);                          // Top Left
       glTexCoord2f(1.0,0.0);   glVertex3f( 0.25,0.015,0.25);                          // Top Right
      glTexCoord2f(1.0,1.0);    glVertex3f( 0.25,0.015,-0.25);                          // Bottom Right
      glTexCoord2f(1,0.0);    glVertex3f(-0.25,0.015,-0.25);
    glEnd();
    glEndList();
}
//chao
void socorro2(GLuint id)
{
     glNewList(id,GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D,2);
    glColor3f(1.00,0.00,.00);//vermelho
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);  glVertex3f(-0.5,-0.5,0.45);                          // Top Left
        glTexCoord2f(1.0,0.0);   glVertex3f(0.8,-0.5,0.45);                          // Top Right
        glTexCoord2f(1.0,1.0);    glVertex3f(0.8,-0.5,-0.45);                          // Bottom Right
        glTexCoord2f(1,0.0);    glVertex3f(-0.5,-0.5,-0.45);
    glEnd();
    glEndList();
}

void chaleira(GLuint id)
{
    GLfloat Ml[]={0,1,0,1};
    glNewList(id,GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D,1);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,Ml);
    glPushMatrix();
    glTranslatef(0+(x-0.2),0.10+y,0.125+z);
    glScalef(0.5,0.5,0.5);
    glutSolidTeapot(0.125);
    glPopMatrix();
    glPopAttrib();
    glEndList();
}
void copo(GLuint id)
{
    GLfloat Ml[]={0,1,0,1};
    glNewList(id,GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D,1);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,Ml);
    glPushMatrix();
    glTranslatef(0+(x-0.2),0.10+y,-0.125+z);
    glutSolidTeacup(0.125);
    glPopMatrix();
    glPopAttrib();
    glEndList();

}

void mesa()
{
    glNewList(0,GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D,0);
    glPushMatrix();
    glTranslatef((x-0.2),y,z);
    glScalef(1,0.05,1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.20+(x-0.2),-0.24+y,-0.20+z);
    glScalef(0.05,1,0.05);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.20+(x-0.2),-0.24+y,-0.20+z);
    glScalef(0.05,1,0.05);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.20+(x-0.2),-0.24+y,0.20+z);
    glScalef(0.05,1,0.05);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.20+(x-0.2),-0.24+y,0.20+z);
    glScalef(0.05,1,0.05);
    glutSolidCube(0.5);
    glPopMatrix();
    glEnd();
    glEndList();
}

void cadeira()
{
    glNewList(0,GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D,1);
    glPushMatrix();
    glTranslatef(0.5+(x-0.2),-0.3+y,0+z);
    glScalef(-0.5,0.5,0.5);
    glutSolidCube(0.5);
    glPopMatrix();
    glEndList();
}

void parede()
{
    glNewList(0,GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D,1);
    glPushMatrix();
    glTranslatef(0.2,0,0);
    glutWireCube(tamP);
    glPopMatrix();
    glEndList();
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
    gluLookAt(Q,W,E,R,T,Y,A,S,D);
    glRotatef(T1,0,1,0);


    cadeira();


    mesa();

    socorro(0);
    socorro2(0);


    copo(0);

    chaleira(0);
    parede();


    glutSwapBuffers();

}

void colisao()
{
    if (sentido == 'A')
    {
        if (z == (tamP* -1) - tamH)
        {
            sentido = 'B';
            z+= Vel;
        }
        else
            z-= Vel;
    }
    else if (sentido == 'B')
    {
        if (z == tamP- tamH)
            sentido = 'C';
        else
            z+= Vel;
    }
    else if (sentido == 'C')
    {
        if (x != tamP - tamH)
        {
            z-= Vel;
            x+= Vel;
        }
        else
            sentido = 'D';
    }
    else if (sentido == 'D')
    {
        if (x == (tamP * -1) + tamH)
            sentido = 'E';
        else
        {
            x-= Vel;
        }
    }
    else if (sentido == 'E')
    {
        if (z != (tamP*-1) + tamH)
        {
            z -= Vel;
            x += Vel;
        }
        else
            sentido = 'H';
    }
    else if (sentido == 'H')
    {
        if (y != (tamP * -1) + tamH)
        {
            y -= Vel;
            z += Vel;
        }
        else
            sentido = 'I';
    }
    else if (sentido == 'I')
    {
        if (z != tamP - tamH)
        {
            y += Vel;
            z += Vel;
        }
        else
            sentido = 'J';
    }
    else if (sentido == 'J')
    {
        if (y != tamP - tamH)
        {
            y += Vel;
            z -= Vel;
        }
        else
            sentido = 'K';
    }
    else if (sentido == 'K')
    {
        if (z != (tamP * -1) + tamH)
        {
            y -= Vel;
            z -= Vel;
        }
        else
            sentido = 'B';
    }
}

void Timer(int value)
{
    colisao();
    glutPostRedisplay();
    glutTimerFunc(15, Timer, 1);
}

void Initin(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glGenTextures(0,&tex_id);
    glGenTextures(1,&tex_i);
    glGenTextures(2,&text_ii);

    carregatextura(tex_id,"C:/Users/Kazuto/Documents/cbglut/paige/TEXTURA/madeira.jpg");
    carregatextura(tex_i,"C:/Users/Kazuto/Documents/cbglut/paige/TEXTURA/floral2.jpg");
    carregatextura(text_ii,"C:/Users/Kazuto/Documents/cbglut/paige/TEXTURA/chao.jpg");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}
void TeclaPressionada(unsigned char tecla, int x, int y) {
    switch (tecla) {
    case 'q': //<-
         Q=Q+0.1;
        break;
    case 'w': //cima
        W+= 0.1;
        break;
    case 'e': //->
        E+= 0.1;
        break;
    case 'r': //baixo
          R+= 0.1;
         break;
    case 't'://+
         T+= 0.1;
        break;
    case 'y'://-
          Y+= 0.1;
        break;
    case 'a':
         A+= 0.1;
         break;
    case 's':
          S+= 0.1;
        break;
    case 'd'://ESC
        D+= 0.1;
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1280,960);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Descanço de Tela");
    Initin();
    glutDisplayFunc(desenha);
    glutTimerFunc(30, Timer, 1);
    glutKeyboardFunc(TeclaPressionada);
    glutIdleFunc(espin);
    glutMainLoop();
    glDisable(GL_TEXTURE_2D);
    glDeleteTextures(0,&tex_id);
    glDeleteTextures(1,&tex_i);
    glDeleteTextures(2,&text_ii);

    return 0;
}
