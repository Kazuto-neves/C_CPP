#include <GL/glut.h>
#include <cmath>

#define M_PI       3.14159265358979323846
#define ESPESSURA 3

float escalaX, escalaY, angulo, posX, posY;

void inicializar() {
    GLclampf r, g, b, o;
    r = 0.2; g = 0.3; b = 0.2; o = 1.0;
    glClearColor(r, g, b, o);
    gluOrtho2D(-1000, 1000, -1000,1000);
}

void partsBuilder(int pt_0[2], float part_scale, bool right) {

    int xi = pt_0[0];
    int yi = pt_0[1];
    int tx1 = 200;
    int tx2 = 300;
    int tx3 = 220;
    int ty = 500;

    if(!right){
        xi = xi -220;
        tx3 = 0;
        ty = -ty;
    }

    int pt_1[2] = { (xi+tx1), part_scale * (yi+ty)};

    int pt_2[2] = { (xi+tx2), part_scale * (yi+ty)};

    int pt_3[2] = { (xi+tx3),yi};

    glLineWidth(ESPESSURA);
    glBegin(GL_LINES);

    if(right){
        glVertex2iv(pt_0);
        glVertex2iv(pt_1);
        glVertex2iv(pt_2);
        glVertex2iv(pt_3);
    }
    else{



        glVertex2iv(pt_0);
        glVertex2iv(pt_2);
        glVertex2iv(pt_1);
        glVertex2iv(pt_3);

    }

}

void desenhar() {

    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT);
    glScalef(escalaX,escalaY,1.0);
    glRotatef(angulo, 0, 0, 1);
    glTranslatef(posX, posY, 1);

    // Declarando pontos de referência
    int centroNariz[2] = { 0, 0 };
    int raio_nariz = 100;
    int pt_lateral_dir[2] = { 0, raio_nariz };
    int pt_asa_dir[2] = { 300, raio_nariz };
    int pt_cauda_dir[2] = { 800, raio_nariz };
    int pt_cauda_esq[2] = { 1020, -raio_nariz };
    int pt_asa_esq[2] = { 525,-raio_nariz };

    //Nariz
    GLfloat x, y, ang;
    glColor3f(255, 255, 255);
    glLineWidth(ESPESSURA);

    glBegin(GL_LINE_LOOP);

        for (int i = 270; i > 89; i--) {
            ang = (i * M_PI) / 180;
            x = centroNariz[0] + (cos(ang) * raio_nariz);
            y = centroNariz[1] + (sin(ang) * raio_nariz);
            glVertex2f(x, y);
        }

        // Inicio

        glVertex2iv(pt_lateral_dir);

        // Asa Direita
        partsBuilder(pt_asa_dir, 1, true);

        // Cauda Direita
        partsBuilder(pt_cauda_dir, 0.50, true);

        // Cauda Esquerda
        partsBuilder(pt_cauda_esq, 0.50, false);

        // Asa Esquerda
        partsBuilder(pt_asa_esq, 1, false);


    glEnd();

    glPopMatrix();
    glFlush();
}

void TeclaPressionada(unsigned char tecla, int x, int y) {
    switch (tecla) {
    case 'a': //<-
        posX -= 10;
        break;
    case 'w': //cima
        posY += 10;
        break;
    case 'd': //->
        posX += 10;
        break;
    case 's': //baixo
        posY -= 10;
        break;
    case '+'://+
        escalaX += 0.1;
        escalaY += 0.1;
        break;
    case '-'://-
        escalaX -= 0.1;
        escalaY -= 0.1;
        break;
    case 'z':
        angulo += 10;
        break;
    case 'x':
        angulo -= 10;
        break;
    case 27://ESC
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    escalaX = 1.0;
    escalaY = 1.0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Aviao");
    glutKeyboardFunc(TeclaPressionada);
    glutDisplayFunc(desenhar);
    inicializar();

    glutMainLoop();

    return 0;
}
