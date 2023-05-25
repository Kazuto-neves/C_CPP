#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/* A simple ping pong game using opengl library and glut
   The game starts on left mouse click, and stops on middle mouse click
   Player 1 can control the game using the keys q and a
   Player 2 can control the game using the keys o and l
*/

// global variables
static GLint windowSizeX = 800, windowSizeY = 1200;
static GLint orthoSizeX = 600, orthoSizeY = 400;

// game variables
static char placar1[20], placar2[20];
static GLint Jogador1_Placar = 0, Jogador2_Placar = 0;
static GLint Limite_Raquete = 350, Altura_Raquete = 100, Velocidade_Raquete = 8.0;
static GLint Jogador1_Raquete = 0, Jogador2_Raquete = 0, Raquete = 595;
static GLfloat Velocidade_Bola_X = 0, Velocidade_Bola_Y = 0, Aumento_Velocidade = 0.5;
static GLint Bola_X = 0, Bola_Y = 0, Eixo_Bola = 20;

void init(void) {
    // initalise display with black colors
    glClearColor (0, 0.2, 0, 0.0);
    glShadeModel (GL_FLAT);

    srand(time(NULL));   // should only be called once
}

// draw text on screen
void DPlacar(char*string, int x, int y, int z)
{
    char *c;
    glPushMatrix();
    glTranslatef(x, y+8,z);
    // glScalef(0.09f,-0.08f,z);
    for (c=string; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
    }
    glPopMatrix();
}

void Quadradros(float a, float b, float c, float d){
    glBegin(GL_QUADS);
    glColor3f(0, 1.0, 0);
    glVertex2f(a , b);
    glVertex2f(c , b);
    glVertex2f(c , d);
    glVertex2f(a , d);
    glEnd();
}

// draw the center lines spaces 20 pixels apart and with a width of 4 px
void DCentro() {
    // center lines start
    Quadradros(-2,-410,2,-390);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -410);
    glVertex2f(2 , -410);
    glVertex2f(2 , -390);
    glVertex2f(-2 , -390);
    glEnd();*/

    Quadradros(-2,-370,2,-350);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -370);
    glVertex2f(2 , -370);
    glVertex2f(2 , -350);
    glVertex2f(-2 , -350);
    glEnd();*/

    Quadradros(-2,-330,2,-310);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -330);
    glVertex2f(2 , -330);
    glVertex2f(2 , -310);
    glVertex2f(-2 , -310);
    glEnd();*/

    Quadradros(-2,-290,2,-270);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -290);
    glVertex2f(2 , -290);
    glVertex2f(2 , -270);
    glVertex2f(-2 , -270);
    glEnd();*/

    Quadradros(-2,-250,2,-230);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -250);
    glVertex2f(2 , -250);
    glVertex2f(2 , -230);
    glVertex2f(-2 , -230);
    glEnd();*/

    Quadradros(-2,-210,2,-190);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -210);
    glVertex2f(2 , -210);
    glVertex2f(2 , -190);
    glVertex2f(-2 , -190);
    glEnd();*/

    Quadradros(-2,-170,2,-150);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -170);
    glVertex2f(2 , -170);
    glVertex2f(2 , -150);
    glVertex2f(-2 , -150);
    glEnd();*/

    Quadradros(-2,-130,2,-110);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -130);
    glVertex2f(2 , -130);
    glVertex2f(2 , -110);
    glVertex2f(-2 , -110);
    glEnd();*/

    Quadradros(-2,-90,2,-70);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -90);
    glVertex2f(2 , -90);
    glVertex2f(2 , -70);
    glVertex2f(-2 , -70);
    glEnd();*/

    Quadradros(-2,-50,2,-30);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -50);
    glVertex2f(2 , -50);
    glVertex2f(2 , -30);
    glVertex2f(-2 , -30);
    glEnd();*/

    Quadradros(-2,-10,2,10);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , -10);
    glVertex2f(2 , -10);
    glVertex2f(2 , 10);
    glVertex2f(-2 , 10);
    glEnd();*/

    Quadradros(-2,30,2,50);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 30);
    glVertex2f(2 , 30);
    glVertex2f(2 , 50);
    glVertex2f(-2 , 50);
    glEnd();*/

    Quadradros(-2,70,2,90);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 70);
    glVertex2f(2 , 70);
    glVertex2f(2 , 90);
    glVertex2f(-2 , 90);
    glEnd();*/

    Quadradros(-2,110,2,130);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 110);
    glVertex2f(2 , 110);
    glVertex2f(2 , 130);
    glVertex2f(-2 , 130);
    glEnd();*/

    Quadradros(-2,150,2,170);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 150);
    glVertex2f(2 , 150);
    glVertex2f(2 , 170);
    glVertex2f(-2 , 170);
    glEnd();*/

    Quadradros(-2,190,2,210);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 190);
    glVertex2f(2 , 190);
    glVertex2f(2 , 210);
    glVertex2f(-2 , 210);
    glEnd();*/

    Quadradros(-2,230,2,250);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 230);
    glVertex2f(2 , 230);
    glVertex2f(2 , 250);
    glVertex2f(-2 , 250);
    glEnd();*/

    Quadradros(-2,270,2,290);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 270);
    glVertex2f(2 , 270);
    glVertex2f(2 , 290);
    glVertex2f(-2 , 290);
    glEnd();*/

    Quadradros(-2,310,2,330);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 310);
    glVertex2f(2 , 310);
    glVertex2f(2 , 330);
    glVertex2f(-2 , 330);
    glEnd();*/

    Quadradros(-2,350,2,370);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 350);
    glVertex2f(2 , 350);
    glVertex2f(2 , 370);
    glVertex2f(-2 , 370);
    glEnd();*/

    Quadradros(-2,390,2,410);
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-2 , 390);
    glVertex2f(2 , 390);
    glVertex2f(2 , 410);
    glVertex2f(-2 , 410);
    glEnd();*/
    // center lines end
}

// x, y is the top left corodinate of the paddle
void DRaquete(int x, int y) {
    glPushMatrix();

    glTranslatef(x, y, 0);

    glBegin(GL_QUADS);
    glColor3f(0, 1.0,0);
    int Altura = Altura_Raquete / 2;
    glVertex2f(-5 , Altura);
    glVertex2f(5 , Altura);
    glVertex2f(5 , -Altura);
    glVertex2f(-5, -Altura);
    glEnd();

    glPopMatrix();
}

void DBola(int x, int y) {
    glPushMatrix();

    glTranslatef(x, y, 0);
    glColor3f(0, 1.0,0);
    glutSolidSphere (Eixo_Bola, 20, 16);

    glPopMatrix();
}

// main display functions
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // create center lines
    DCentro();

    // draw left paddle at (-Raquete, Jogador1_Raquete)
    DRaquete(-Raquete, Jogador1_Raquete);
    // draw right paddle at (Raquete, Jogador2_Raquete)
    DRaquete(Raquete, Jogador2_Raquete);

    // draw the ball (Bola_X, Bola_Y) - varies in each frame
    DBola(Bola_X, Bola_Y);

    // draw the score on the left for player 1
    snprintf (placar1, sizeof(placar1), "%d", Jogador1_Placar);
    DPlacar(placar1, -300, 200, 0);

    // draw the score on the left for player 1
    snprintf (placar2, sizeof(placar2), "%d", Jogador2_Placar);
    DPlacar(placar2, 200, 200, 0);

    // swap the current frame with the drawn frame
    glutSwapBuffers();
    glFlush();
}

void startGame(void) {

    // move the ball
    Bola_X += Velocidade_Bola_X;
    Bola_Y += Velocidade_Bola_Y;

    // ball hits the top or bottom
    if (Bola_Y + Eixo_Bola > orthoSizeY || Bola_Y - Eixo_Bola < -orthoSizeY)
        Velocidade_Bola_Y = -Velocidade_Bola_Y;

    // ball hits the left paddle
    if (Bola_X - Eixo_Bola - 5 < -Raquete && Bola_X - Eixo_Bola < -Raquete)
        if (Bola_Y < Jogador1_Raquete + Altura_Raquete && Bola_Y > Jogador1_Raquete - Altura_Raquete) {
            Velocidade_Bola_X = -Velocidade_Bola_X;
            Velocidade_Bola_X += Aumento_Velocidade;
            Velocidade_Raquete += Aumento_Velocidade;
        }


    // ball hits the right paddle
    if (Bola_X + Eixo_Bola + 5 > Raquete && Bola_X + Eixo_Bola < Raquete)
        if (Bola_Y < Jogador2_Raquete + Altura_Raquete && Bola_Y > Jogador2_Raquete - Altura_Raquete)
            Velocidade_Bola_X = -Velocidade_Bola_X;

    // player 1 scores
    if (Bola_X + Eixo_Bola > orthoSizeX) {
        Jogador1_Placar++;
        printf("Player 1 = %d \n", Jogador1_Placar);
        Velocidade_Bola_X = -Velocidade_Bola_X;
    }

    // player 2 scores
    if (Bola_X - Eixo_Bola < -orthoSizeX) {
        Jogador2_Placar++;
        printf("Player 2 = %d \n", Jogador2_Placar);
        Velocidade_Bola_X = -Velocidade_Bola_X;
    }

    glutPostRedisplay();
}

// reshape the display
void reshape(int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-orthoSizeX, orthoSizeX, -orthoSizeY, orthoSizeY, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// on mouse button click
void mouse(int button, int state, int x, int y) {
    switch (button) {
        // left button - initialize random velocity between (ran(5) - rand(3))
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            Velocidade_Bola_X = (rand() % 5) -  (rand() % 3);
            Velocidade_Bola_Y = (rand() % 5) -  (rand() % 3);

            // keep on calling the callback to move the ball and check boundary conditions
            glutIdleFunc(startGame);
            break;
        // middle button to reset the ball, paddle and score
        case GLUT_MIDDLE_BUTTON:
            // reset ball, paddle and player scores
            Bola_X = Bola_Y = 0;
            Jogador1_Raquete = Jogador2_Raquete = 0;
            Jogador1_Placar = Jogador2_Placar = 0;
            if (state == GLUT_DOWN)
                // remove the call back so that game stops
                glutIdleFunc(NULL);
            break;
        default:
        break;
    }
}


void keyboard (unsigned char key, int x, int y) {
    switch (key) {
        // move player 1 paddile up
        case 'q':
            if (Jogador1_Raquete < Limite_Raquete)
                Jogador1_Raquete += Velocidade_Raquete;
            glutPostRedisplay();
            break;
        // move player 1 paddile down
        case 'a':
            if (Jogador1_Raquete > -Limite_Raquete)
                Jogador1_Raquete -= Velocidade_Raquete;
            glutPostRedisplay();
            break;
        // move player 2 paddile up
        case 'o':
            if (Jogador2_Raquete < Limite_Raquete)
                Jogador2_Raquete += Velocidade_Raquete;
            glutPostRedisplay();
            break;
        // move player 2 paddile down
        case 'l':
            if (Jogador2_Raquete > -Limite_Raquete)
                Jogador2_Raquete -= Velocidade_Raquete;
            glutPostRedisplay();
            break;
        // exit on esc
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

/*
* Request double buffer display mode.
* Register mouse input callback functions
*/
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1200, 800);
    glutInitWindowPosition (10, 10);
    glutCreateWindow (argv[0]);
    init ();

    // call back functions for rendering, reshape
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // callback on mouse click and keyboard input
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
