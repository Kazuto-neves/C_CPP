#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static void teclaPressionado(unsigned char tecla,int posicaoX,int posicaoY)
{
    switch(tecla){
case 25:
case 'q':
case 'Q':
    exit(0);
    break;
    }
    glutPostRedisplay();
}

static void mouseMov(int botao,int estado, int posicaoX ,int posicaoY){
    if(botao == GLUT_LEFT_BUTTON && estado == GLUT_UP){
        exit(0);
    }
glutPostRedisplay();
}

static void janelaR(int largura,int altura){
glutPostRedisplay();
}

static void janelaO(){
glutPostRedisplay();
}

static void teclaEP(int tecla, int x, int y){
    if(tecla == GLUT_KEY_F1){
        exit(0);
    }
glutPostRedisplay();
}

static void desenhar(){
    glClearColor(0.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    glutPostRedisplay();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(desenhar);
    glutKeyboardFunc(teclaPressionado);
    glutMouseFunc(mouseMov);
    glutReshapeFunc(janelaR);
    glutIdleFunc(janelaO);
    glutSpecialFunc(teclaEP);

    glutMainLoop();

    return 0;
}
