#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


float r, g, b, x, y;
bool check = true;


GLfloat escalay = 1.0f;
GLfloat escalax = 1.0f;
GLfloat anguloes = 1;
GLfloat angulodi = 1;

void mouse(int button, int state, int mousex, int mousey) {
    if (button == GLUT_LEFT_BUTTON) {

        check = true;
        x = mousex;
        y = 480 - mousey;
        r = (rand() % 10) / 10.0;
        g = (rand() % 10) / 10.0;
        b = (rand() % 10) / 10.0;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glClearColor(1, 1, 1, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;
    }
    glutPostRedisplay();
}

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    gluOrtho2D(0.0, 640.0, 0.0, 480.0);


    glScalef(escalax, escalay, 0);
    glTranslated(escalax, escalay, 0);
    glRotatef(50, anguloes, angulodi, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (check) {
        glColor3f(r, g, b);
        glPointSize(50);
        glBegin(GL_POINTS);
            glVertex2i(x, y);
        glEnd();
    }


    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_LINES);
        glVertex2f(50, 50);
        glVertex2f(50, 100);

        glVertex2f(50, 100);
        glVertex2f(80, 50);

        glVertex2f(80, 50);
        glVertex2f(80, 100);
    glEnd();

    // Letra A
    glBegin(GL_LINES);
        glVertex2f(90, 50);
        glVertex2f(110, 100);

        glVertex2f(110, 100);
        glVertex2f(125, 50);

        glVertex2f(102, 80);
        glVertex2f(116, 80);
    glEnd();

    // Letra D
    glBegin(GL_LINES);
        glVertex2f(135, 50);
        glVertex2f(135, 100);

        glVertex2f(135, 100);
        glVertex2f(155, 85);

        glVertex2f(155, 85);
        glVertex2f(155, 65);

        glVertex2f(155, 65);
        glVertex2f(135, 50);
    glEnd();

    // Letra Y
    glBegin(GL_LINES);
        glVertex2f(180, 50);
        glVertex2f(180, 70);

        glVertex2f(180, 70);
        glVertex2f(170, 100);

        glVertex2f(180, 70);
        glVertex2f(190, 100);
    glEnd();

    // Letra A
    glBegin(GL_LINES);
        glVertex2f(205, 50);
        glVertex2f(220, 100);

        glVertex2f(220, 100);
        glVertex2f(235, 50);

        glVertex2f(214, 80);
        glVertex2f(226, 80);
    glEnd();

    glFlush();
}

void listeningKey(unsigned char tecla, GLint x, GLint y) {
    switch (tecla) {
        case '+': escalay = escalay + 0.5;
            break;
        case '-': escalay--;
            break;
        case 'i':
            escalax = escalax + 0.5;
            break;
        case 'k':
            escalax--;
            break;
        case '1':
            escalax = escalax + 0.5;
            break;
        case '2':
            escalax--;
            break;
        case 'a':
            anguloes += 0.9;
            break;
        case 'b':
            angulodi -= 0.9;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {

    srand(time(NULL));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Interacao via Mouse e Teclado");


    glutKeyboardFunc(listeningKey);
    glutMouseFunc(mouse);
    glutDisplayFunc(desenha);

    glClearColor(0, 0, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutMainLoop();
    return 0;
}
