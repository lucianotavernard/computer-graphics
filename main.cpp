/**
 * Projeto da Unidade 3 de Computação Gráfica
 *
 * @date 18/11/2017
 * @author luciano tavernard <lucianotavernard@unp.edu.br>
 * @author danilo wesley <email@unp.edu.br>
 * @author janderson fonseca <email@unp.edu.br>
 * @author laudeine batista <email@unp.edu.br>
 */
#include <GL/glut.h>
#include <iostream>
#include "Face.h"

GLfloat xSpeed = 0.02f;
GLfloat ySpeed = 0.007f;
GLfloat zSpeed = 0.01f;
GLfloat aSpeed = 45.0f;
GLfloat tSpeed = 0.05;

GLfloat angle = 45.0f;
GLfloat ballX = 0.0f;
GLfloat ballY = -0.5f;
GLfloat ballZ = 2.3f;
GLfloat ballRadius = 0.05f;

GLfloat triangleX = 0.0f;
GLfloat triangleXSpeed = 0.01f;
GLfloat triangleXMax, triangleXMin;

unsigned int refresMillis = 30;

GLdouble clipAreaXleft, clipAreaXRight;

void init();
void reshape(GLsizei width, GLsizei height);
void displayTriangle(float z);
void displayBall();
void display();
void timer(int value);
void keyPress(int key, int x, int y);

int main(int argc, char** argv) {

    /* Inicializa o GLUT */
    glutInit(&argc, argv);

    /* Habilita o modo de buffer duplo */
    glutInitDisplayMode(GLUT_DOUBLE);

    /* Define a largura e altura inicial da janela */
    glutInitWindowSize(640, 480);

    /* Posiciona a janela inicial */
    glutInitWindowPosition(50, 50);

    /* Cria uma janela com título */
    glutCreateWindow("Computação Gráfica");

    /* Registra uma callback para o evento de re-pintura da janela */
    glutDisplayFunc(display);

    /* Registra uma callback para o evento de */
    glutSpecialFunc(keyPress);

    /* Registra uma callback para o evento de rezise da janela */
    glutReshapeFunc(reshape);

    /* First timer call immediately */
    glutTimerFunc(0, timer, 0);

    /* Inicializa o OpenGL */
    init();

    /* Cria um evento de loop infinito */
    glutMainLoop();

    return 0;
}

void init() {
    /* Define cor de fundo para preto e opaco */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    /* Define a profundidade do fundo para mais distante */
    glClearDepth(1.0f);

    /* Habilita teste de profundidade para o z-culling */
    glEnable(GL_DEPTH_TEST);

    /* Define o tipo de teste de profundidade */
    glDepthFunc(GL_LEQUAL);

    /* Permite o sombreamento suave */
    glShadeModel(GL_SMOOTH);

    /* Faz correções de perspectiva */
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void reshape(GLsizei width, GLsizei height) {

    /**
     * Calcula a relação de aspecto da nova janela
     * Previne a divisão por 0
     */
    if (height == 0) {
        height = 1;
    };

    GLfloat aspect = (GLfloat) width / (GLfloat) height;
    GLfloat aspectRoom = (GLfloat) (width - 380) / (GLfloat) height;

    /**
     * Define a viewport para a nova janela
     */
    glViewport(0, 0, width, height);

    /**
     * Define a proporção do volume de corte para coincidir com a viewport
     * Define a matriz de projeção
     */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width >= height) {
        clipAreaXleft = -1.0 * aspectRoom;
        clipAreaXRight = 1.0 * aspectRoom;
    } else {
        clipAreaXleft = -1.0;
        clipAreaXRight = 1.0;
    }

    /**
     * Habilita a projeção da perspectiva com fovy, aspect, zNear e zFar
     */
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);

    triangleXMin = (GLfloat) clipAreaXleft + tSpeed;
    triangleXMax = (GLfloat) clipAreaXRight - tSpeed;
}

void displayTriangle(float z) {
    glPushMatrix();
    glTranslatef(triangleX, -0.5f, 2.3f);

    // R G B
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.3f, -0.3f, -3.5f + z);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-0.3f, -0.3f, -3.5f + z);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-0.3f, 0.3f, -3.5f + z);
    glEnd();
    glPopMatrix();
}

void displayBall() {
    glPushMatrix();
    glTranslatef(ballX, ballY, ballZ);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 1.0f);
    glutSolidSphere(ballRadius, 100, 100);
    glPopMatrix();
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

    // Render a color-cube consisting of 6 quads with different colors
    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(0.0f, 0.0f, -7.0f);  // Move right and into the screen
    glScalef(1.6f, 1.6f, 2.0f);

    Face top, bottom, front, back, left, right, quad, tapete, light;

    /**
     * Os vértices estão setados no sentido anti-horário
     *
     * top face (y = 1.0f)
     * green color
     */
    glColor3f(0.5f, 0.5f, 0.5f);
    top.draw(new Point(1.0f, 1.0f, -1.0f), new Point(-1.0f, 1.0f, -1.0f), new Point(-1.0f, 1.0f, 1.5f), new Point(1.0f, 1.0f, 1.5f));

    /**
     * bottom face (y = -1.0f)
     * orange color
     */
    glColor3f(0.37f, 0.37f, 0.37f);
    bottom.draw(new Point(1.0f, -1.0f, 1.5f), new Point(-1.0f, -1.0f, 1.5f), new Point(-1.0f, -1.0f, -1.0f), new Point(1.0f, -1.0f, -1.0f));

    /**
     * front face (z = 1.5f)
     * red color
     */

    //glColor3f(1.0f, 0.0f, 0.0f);
    //front.draw(new Point(1.0f, 1.0f, 1.5f), new Point(-1.0f, 1.0f, 1.5f), new Point(-1.0f, -1.0f, 1.5f), new Point(1.0f, -1.0f, 1.5f));

    /**
     * back face (z = -1.0f)
     * yellow color
     */
    glColor3f(1.0f, 1.0f, 0.0f);
    back.draw(new Point(1.0f, -1.0f, -1.0f), new Point(-1.0f, -1.0f, -1.0f), new Point(-1.0f, 1.0f, -1.0f), new Point(1.0f, 1.0f, -1.0f));

    /**
     * quad in back face
     * gray color
     */

    glPushMatrix();
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glColor3f(0.2f, 0.2f, 0.2f);
    quad.draw(new Point(0.4f, -0.4f, -0.4f), new Point(-0.4f, -0.4f, -0.4f), new Point(-0.4f, 0.4f, -0.4f), new Point(0.4f, 0.4f, -0.4f));
    glPopMatrix();

    /**
     * left face (x = -1.0f)
     * blue color
     */
    glColor3f(0.0f, 0.0f, 1.0f);
    left.draw(new Point(-1.0f, 1.0f, 1.5f), new Point(-1.0f, 1.0f, -1.0f), new Point(-1.0f, -1.0f, -1.0f), new Point(-1.0f, -1.0f, 1.5f));

    /**
     * right face (x = 1.0f)
     * magenta color
     */
    glColor3f(1.0f, 0.0f, 1.0f);
    right.draw(new Point(1.0f, 1.0f, -1.0f), new Point(1.0f, 1.0f, 1.5f), new Point(1.0f, -1.0f, 1.5f), new Point(1.0f, -1.0f, -1.0f));

    for (int i = 1; i <= 2; ++i) {
        displayTriangle(i * 1.5);
    }

    displayBall();

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

    triangleX += triangleXSpeed;
    if (triangleX > triangleXMax) {
        triangleX = triangleXMax;
        triangleXSpeed = -triangleXSpeed;
    } else if (triangleX < triangleXMin) {
        triangleX = triangleXMin;
        triangleXSpeed = -triangleXSpeed;
    }
}

/* Press Key */
void keyPress(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            ballZ -= (ballZ > 1.1) ? zSpeed : 0;
            break;
        case GLUT_KEY_DOWN:
            ballZ += (ballZ < 2.38) ? zSpeed : 0;
            break;
        case GLUT_KEY_RIGHT:
            ballX += (ballX < 0.5) ? xSpeed : 0;
            angle -= aSpeed;

            break;
        case GLUT_KEY_LEFT:
            ballX -= (ballX > -0.5) ? xSpeed : 0;;
            angle += aSpeed;
            break;
        default:
            std::cout << "Tecla: " << key << std::endl;
    }

    glutPostRedisplay();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(refresMillis, timer, 0);
}