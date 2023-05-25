#include<Windows.h>
#include <gl/glut.h>
#include <GL/freeglut.h>
#include<Windows.h>
#include <gl/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <stb_image.h>
#include <direct.h> // _getcwd
//#include <textura.h>

//textura CuboTex[1];


#define tamC 15
#define tamE 4
#define tamM 1
#define Vel 0.5
#define Vel2 0.01
#define marge 60

GLfloat aspecto,angulo;
GLdouble sent=1;
GLint view=0,viewInt=0;
GLint slices = 16, stacks = 16;
GLint eyex = 40, eyey = 50, eyez = 100, centerx =  0, centery =  0, centerz =  0, upx = 0, upy = 1, upz = 0;
GLdouble movz = 2, movx = -6, movy = 0, movx2 = 8, movz2 = 0.2, movy2 = 0;
char sentido = 'A';
GLfloat T =0;
GLuint tex_id;
GLuint tex_i;

using namespace std;

string dir(){
    char* buffer;
    if ( (buffer = _getcwd( NULL, 0 )) == NULL )
      perror( "_getcwd error" );
   else
   {
      //printf( "%s \nLength: %zu\n", buffer, strlen(buffer) );
      free(buffer);
   }
   return buffer;
}

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

    T =T+0.1;
    if(T>360) T=0;
    glutPostRedisplay();


}

void socorro(GLuint id)
{
    glNewList(id,GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D,1);
    glColor3f(1.00,0.00,.00);//vermelho
    glBegin(GL_QUADS);
      glTexCoord2f(0.0,0.0);  glVertex3f(-0.5, 0.03,0.5);                          // Top Left
       glTexCoord2f(1.0,0.0);   glVertex3f( 0.5,0.03,0.5);                          // Top Right
      glTexCoord2f(1.0,1.0);    glVertex3f( 0.5,0.03,-0.5);                          // Bottom Right
      glTexCoord2f(1,0.0);    glVertex3f(-0.5,0.03,-0.5);
    glEnd();
    glEndList();


}
void chaleira(GLuint id)
{
    GLfloat Ml[]={0,1,0,1};
    glNewList(id,GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D,2);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,Ml);
    glPushMatrix();
    glTranslatef(0,0.15,0.35);
    glScalef(0.5,0.5,0.5);
    glutSolidTeapot(0.25);
    glPopMatrix();
    glPopAttrib();
    glEndList();
}
void copo(GLuint id)
{
    GLfloat Ml[]={0,1,0,1};
    glNewList(id,GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D,2);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,Ml);
    glPushMatrix();
    glTranslatef(0,0.15,0);
    glutSolidTeacup(0.25);
    glPopMatrix();
    glPopAttrib();
    glEndList();

}
void interior()
{
    espin();
    GLfloat Pos[]={0,1,0,1};
    GLfloat Col[]={1,0,0,1};
    GLfloat Ml[]={0,1,0,1};

    glLoadIdentity();
    glLightfv(GL_LIGHT0,GL_POSITION,Pos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,Col);
    gluLookAt(0,1,3,0,0,0,0,1,0);
    glRotatef(T,0,1,0);
    socorro(0);

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


    copo(0);

    chaleira(0);

}

void inicializar (void)
{
    angulo=60;
    glLineWidth(2.0);
}

double rotacao(){
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    return a;
}

void Telhado(GLint tam, double a)
{
    glTranslated(movz, movy, movx);
    glRotated(90,1,0,0);
    glRotated(sent*(a),0,0,1);
    glColor3f(1,0,0);
    if(view == 0)
    {
        glutSolidCone(-tam,-tam,slices,stacks);
    }
    else if (view == 1)
    {
        glutWireCone(-tam,-tam,slices,stacks);
    }
}

void cubo(GLint tam, double a)
{
    glTranslated(movz2, movy2/20, movx2);
    glRotated(360,1,0,0);
    glRotated(sent*(a),0,0,1);
    glColor3f(0.5, 0.5, 0.5);
    if(view == 0)
    {
        glutSolidCube(tam*1.2);
    }
    else if (view == 1)
    {
        glutWireCube(tam*1.2);
    }
}

void Cubo2(GLint tam, GLint tz,GLint ty,GLint tx)
{
    glTranslated(movz2+tz, (movy2/20)-ty, movx2-tx);
    if(view == 0)
    {
        glutSolidCube(tam);
    }
    else if (view == 1)
    {
        glutWireCube(tam);
    }
}

void esfera(GLint tam, GLint tz,GLint ty,GLint tx,GLint slices,GLint stacks){
    glTranslated(movz2+tz, (movy2/20)-ty, movx2-tx);
    glColor3f(0,0,0);
    if(view == 0)
    {
        glutSolidSphere(tam,slices,stacks);
    }
    else if (view == 1)
    {
        glutWireSphere(tam,slices,stacks);
    }
}

void janela(GLint tam, GLint tz,GLint ty,GLint tx)
{
    glColor3f(0.75, 0.75, 0.75);
    Cubo2(tam,tz,ty,tx);
}

void porta(GLint tam, GLint tz,GLint ty,GLint tx)
{
    glColor3f(1,1,1);
    Cubo2(tam,tz,ty,tx);
}

void massaneta(GLint tam,GLint slices,GLint stacks){
    esfera(tam,1.2,1,6,slices,stacks);
}

void janelas(GLint tam2)
{
    janela(tam2,7,6,10);
    janela(tam2,0,-12,8);
}

void madeiras(GLint tam2){
    porta(tam2,0,6,0);
    porta(tam2,0,0,12);
}

void casa(GLint tam,GLint tam2,double a,GLint tam3,GLint slices,GLint stacks){
    Telhado(tam,a);
    cubo(tam,a);
    janelas(tam2);
    madeiras(tam2);
    massaneta(tam3,slices,stacks);
}

void Geo(GLint tam,GLint tam2,GLint tam3,GLint slices,GLint stacks)
{
    double a = rotacao();
    glPushMatrix();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    casa(tam,tam2,a,tam3,slices,stacks);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHT0);
    glDisable(GL_NORMALIZE);
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}

void desenhar(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(viewInt==0){
       glClearColor(1.0,1.0,1.0,1.0);
       Geo(tamC,tamE,tamM,slices,stacks);
    }else{
        glClearColor(0.75, 0.75, 0.75,1.0);
        interior();
    }

    glutSwapBuffers();
}

void especificaParametrosVisualizacao(void)
{
    if(viewInt==1){
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glGenTextures(1,&tex_id);
    glGenTextures(2,&tex_i);
    carregatextura(tex_id,dir()+"\\img\\madeira.jpg");
    carregatextura(tex_i,dir()+"\\img\\floral2.jpg");
    }else{
        glDisable(GL_TEXTURE_2D);
        glDeleteTextures(1,&tex_id);
        glDeleteTextures(2,&tex_i);
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angulo, aspecto, 0.1, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex,eyey,eyez,centerx,centery,centerz,upx,upy,upz);
}

void alteraTamanhoJanela(GLsizei w,GLsizei h)
{
    if(h==0)
        h=1;
    aspecto = (GLfloat)w/(GLfloat)h;
    glViewport(0,0,w,h);
    especificaParametrosVisualizacao();
}

void EventoMouse(int button, int state, int x, int y)
{
    especificaParametrosVisualizacao();
    glutPostRedisplay();
}

void colisao()
{
    if (sentido == 'A')
    {
        if (movz == (marge* -1) - tamC)
        {
            sentido = 'B';
            movz+= Vel;
        }
        else
            movz-= Vel;
    }
    else if (sentido == 'B')
    {
        if (movz == marge- tamC)
            sentido = 'C';
        else
            movz+= Vel;
    }
    else if (sentido == 'C')
    {
        if (movx != marge - tamC)
        {
            movz-= Vel;
            movx+= Vel;
            if(movx2 != movx + 8)
                movx2 += Vel2;
        }
        else
            sentido = 'D';
    }
    else if (sentido == 'D')
    {
        if (movx == (marge * -1) + tamC)
            sentido = 'E';
        else
        {
            movx-= Vel;
            if(movx2 != movx + 8 && movx2 != (marge * -1) + tamC)
                movx2 -= Vel2;
        }
    }
    else if (sentido == 'E')
    {
        if (movz != (marge*-1) + tamC)
        {
            movz -= Vel;
            movx += Vel;
            if(movx2 != movx + 8)
                movx2 += Vel2;
        }
        else
            sentido = 'H';
    }
    else if (sentido == 'H')
    {
        if (movy != (marge * -1) + tamC)
        {
            movy -= Vel;
            movz += Vel;
        }
        else
            sentido = 'I';
    }
    else if (sentido == 'I')
    {
        if (movz != marge - tamC)
        {
            movy += Vel;
            movz += Vel;
        }
        else
            sentido = 'J';
    }
    else if (sentido == 'J')
    {
        if (movy != marge - tamC)
        {
            movy += Vel;
            movz -= Vel;
        }
        else
            sentido = 'K';
    }
    else if (sentido == 'K')
    {
        if (movz != (marge * -1) + tamC)
        {
            movy -= Vel;
            movz -= Vel;
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

void responderTeclado(unsigned char key,int x,int y)
{
    switch (key)
    {
    case '1':
        if(viewInt==0)
            viewInt=1;
        else if(viewInt==1)
            viewInt=0;
        break;
    case 'u':
        if(sent==1)
            sent=-1;
        else if(sent==-1)
            sent=1;
        break;
    case 'j':
        if(view==0)
            view=1;
        else if(view==1)
            view=0;
        break;
    case 'w':
        centerx +=10;
        break;
    case 's':
        centerx -=10;
        break;
    case 'q':
        centery +=10;
        break;
    case 'a':
        centery -=10;
        break;
    case 'e':
        centerz+=10;
        break;
    case 'd':
        centerz-=10;
        break;
    case 'r':
        eyex += 10;
        break;
    case 'f':
        eyex -= 10;
        break;
    case 't':
        eyey += 10;
        break;
    case 'g':
        eyey -= 10;
        break;
    case 'y':
        eyez += 10;
        break;
    case 'h':
        eyez -= 10;
        break;
    }
    especificaParametrosVisualizacao();
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1600, 1200);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Descanco de tela");
    glutDisplayFunc(desenhar);
    glutTimerFunc(30, Timer, 1);
    glutReshapeFunc(alteraTamanhoJanela);
    glutKeyboardFunc(responderTeclado);
    glutMouseFunc(EventoMouse);
    inicializar();
    glutMainLoop();
    return 0;
}
