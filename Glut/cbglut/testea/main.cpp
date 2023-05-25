#include <math.h>
#include <GL/glut.h>

#define PI 3.1415926535

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     float angle, raio_x, raio_y;
     int i, circle_points = 100;

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente é branca
     //         R     G     B
     glColor3f(1.0f, 1.0f, 1.0f);

     // Especifica o tamanho do pixel
     glPointSize(1.0);

     // Desenha um círculo (elipse) preenchido com a cor corrente
     //glBegin(GL_LINE_LOOP);
     glBegin(GL_POLYGON);
               raio_x = 80.0;
               raio_y = 100.0;
               for(i = 0; i < circle_points; i++) {
                 angle = (2*PI*i)/circle_points;
                 glVertex2f(125.0+raio_x*cos(angle),125.0+raio_y*sin(angle));
                 }
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;

                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de seleção (left, right, bottom, top)
                   if (w <= h)
                           gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
                   else
                           gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

int main(int argc, char ** argv) {
 int sizex, sizey;

 sizex = 500;
 sizey = 500;

 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(sizex,sizey);
 glutInitWindowPosition(10,10);
 glutCreateWindow("Círculo");
 glutDisplayFunc(Desenha);
 glutReshapeFunc(AlteraTamanhoJanela);
 Inicializa();
 glutMainLoop();

 return 0;
}
