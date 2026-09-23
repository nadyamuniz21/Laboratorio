#include<GL/glut.h>
#include<iostream>

GLfloat escala = 1;

void desenha(void) {
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 300, 0, 300);

    glScalef(escala, escala, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Letra N
    glBegin (GL_LINES);
    glVertex2f(50,50);
    glVertex2f(50,100);

    glVertex2f(50,100);
    glVertex2f(80,50);

    glVertex2f(80,50);
    glVertex2f(80,100);
    glEnd();

    // Letra A
    glBegin (GL_LINES);
    glVertex2f(90,50);
    glVertex2f(110,100);

    glVertex2f(110,100);
    glVertex2f(125,50);

    glVertex2f(102,80);
    glVertex2f(116,80);
    glEnd();

    // Letra D
    glBegin (GL_LINES);
    glVertex2f(135,50);
    glVertex2f(135,100);

    glVertex2f(135,100);
    glVertex2f(155,85);

    glVertex2f(155,85);
    glVertex2f(155,65);

    glVertex2f(155,65);
    glVertex2f(135,50);
    glEnd();

    // Letra Y
    glBegin (GL_LINES);
    glVertex2f(180,50);
    glVertex2f(180,70);

    glVertex2f(180,70);
    glVertex2f(170,100);

    glVertex2f(180,70);
    glVertex2f(190,100);
    glEnd();

    // Letra A
    glBegin (GL_LINES);
    glVertex2f(205,50);
    glVertex2f(220,100);

    glVertex2f(220,100);
    glVertex2f(235,50);

    glVertex2f(214,80);
    glVertex2f(226,80);
    glEnd();

    glFlush();
}

void listeningKey (unsigned char tecla, GLint x, GLint y) {
    switch (tecla) {
    case '+': escala++;
        break;
    case '-': escala--;
        break;
    }
    desenha();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(400,400);
    glutInitWindowPosition(300,100);
    glutCreateWindow("Ola Glut");
    glutKeyboardFunc(listeningKey);
    glutDisplayFunc(desenha);
    glClearColor( 0, 0, 1, 0);
    glutMainLoop();
    return 0;
}



