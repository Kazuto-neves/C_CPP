#include <GL/glut.h>
#include <cmath>

#define M_PI       3.14159265358979323846

float escalaX=1.0, escalaY=1.0, angulo=0, posX=0.300, posY=0;
int i=0;

void TeclaPressionada(unsigned char tecla, int x, int y) {
    switch (tecla) {
    case 'a': //<-
    case 'A':
        if(posX > 0.40){
            posX -= 0.10;
        }
        break;
    case 'w': //cima
    case 'W':
        if(posY <= 0.60){
            posY += 0.10;
        }
        break;
    case 'd': //->
    case 'D':
        if(posX <= 1.40){
            posX += 0.10;
        }
        break;
    case 's': //baixo
    case 'S':
        if(posY> -0.40){
            posY -= 0.10;
        }
        break;
    case '+'://+
        if(escalaX <=1.20){
            escalaX += 0.1;
            escalaY += 0.1;
        }
        break;
    case '-'://-
        if(escalaX >0.00){
            escalaX -= 0.1;
            escalaY -= 0.1;
        }
        break;
    case 't'://esquerda_GIRO
    case 'T':
        angulo += 10;
        if(angulo >=360) angulo=0;
        break;
    case 'r':
    case 'R':
        angulo -= 10;
        if(angulo <0) angulo=359;
        break;
    case 'e'://direita_cima
    case 'E'://direita_cima
        posX+=0.10;
        posY+=0.10;
        break;
    case 'q'://esqueda_baixo
    case 'Q'://esqueda_baixo
        posX-=0.10;
        posY+=0.10;
        break;
    case 'z'://esquerda_cima
    case 'Z'://esquerda_cima
        posX-=0.10;
        posY-=0.10;
        break;
    case 'x'://esquerda_cima
    case 'X'://esquerda_cima
        posX+=0.10;
        posY-=0.10;
        break;
    case '1'://noite
        glClearColor(0.0f,0.5f,1.0f,0.0f);
        i=1;
        break;
    case '2'://dia
        glClearColor(0.0f,01.0f,1.0f,0.0f);
        i=0;
        break;
    case 27://ESC
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void circulo(float sx,float sy,float tx,float ty,float a,float r,float g,float b)
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(tx,ty,0.0f);
    glScalef(sx,sy,0.0f);
    glRotatef(a,0,0, 1);
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

void circulo(float R, float G, float B,int line ,int t, float xa , float yb, float a, float b){
    GLfloat x, y, ang;
    glColor3f(R,G,B);
    glLineWidth(line);
    t==0?glBegin(GL_LINE_LOOP):glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            ang = (i * M_PI) / 180;
            x = a + (cos(ang) * xa);
            y = b + (sin(ang) * yb);

            glVertex2f(x, y);
        }

    glEnd();
}

void inicia()
{
    glClearColor(0.0f,01.0f,1.0f,0.0f);
}

void backf()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void casco(){
    glColor4ub(43,180,6,255);
    glBegin(GL_POLYGON);

    glVertex2f(-1.22f, -0.07f);
    glVertex2f(-1.22f, 0.14f);
    glVertex2f(-1.1f, 0.0f);
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.6f,-0.1f);
    glVertex2f(-1.0f,-0.1f);
    glEnd();
}

void style(){
    glColor4ub(60, 247, 8,255);

    glBegin(GL_QUADS);
    glVertex2f(-0.90f, -0.09f);
    glVertex2f(-0.91f, -0.09f);
    glVertex2f(-0.93f,-0.4f);
    glVertex2f(-0.94f,-0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.90f,0.001f);
    glVertex2f(-0.91f,0.001f);
    glVertex2f(-0.93f,0.2f);
    glVertex2f(-0.94f,0.2f);
    glEnd();
}

void nariz(){
    glColor4ub(43,180,6,255);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f, -0.1f);
    glVertex2f(-0.5f, -0.05f);
    glVertex2f(-0.6f, 0.001f);
    glEnd();
}

void asas(){
    glColor4ub(43,180,6,255);
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, 0.0f);
    glVertex2f(-0.9f, 0.0f);
    glVertex2f(-0.94f,-0.4f);
    glVertex2f(-0.9f,-0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.8f, 0.0f);
    glVertex2f(-0.9f, 0.0f);
    glVertex2f(-0.94f,0.2f);
    glVertex2f(-0.9f,0.2f);
    glEnd();
}

void moon(int i){
    if(i==0){
        circulo(0.12,0.17,0.35f,0.75f,angulo,1, 0.94, 0.26);
        circulo(0.12,0.17,0.09f,0.75f,angulo,0.0,01.0,1.0);
    } else {
        circulo(0.12,0.17,0.35f,0.75f,angulo,1, 0.94, 0.26);
        circulo(0.12,0.17,0.42f,0.75f,angulo,0.0,0.5,1.0);
    }
}

void janela(float a, float b)
{
    //traco janela
    circulo(0.0,0.0,0.0,3,0,0.020,0.020,a,b);
    //enchimento janela
    circulo(1.0,1.0,1.0,1,1,0.020,0.020,a,b);

}

void jcapitan(){
    glColor4ub(255,180,6,255);
    glBegin(GL_POLYGON);

    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.65f, 0.0f);
    glVertex2f(-0.65f,-0.05f);
    glVertex2f(-0.5f,-0.05f);
    glEnd();

    glPopMatrix();
    glFlush();
}

void Aviao(){
    glPushMatrix();
    glLoadIdentity();
    glScalef(escalaX,escalaY,1.0);
    glRotatef(angulo, 0, 0, 1);
    glTranslatef(posX, posY, 1);

    casco();
    nariz();
    asas();
    style();
    for(int i =2; i < 6; i++)
        janela(-1.20 + (0.090 * i), -0.05);
    jcapitan();

    glPopMatrix();
    glFlush();
}

void desenha(){
    backf();
    moon(i);
    Aviao();
    glFlush();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Aviao");
    glutKeyboardFunc(TeclaPressionada);
    glutDisplayFunc(desenha);
    inicia();
    glutMainLoop();
    return 0;
}
