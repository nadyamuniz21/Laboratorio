#include <gl/freeglut.h>
#include <stdio.h>


void desenhaTriangulo();
void desenhaLinha();
void desenha();
void desenha() {
    glClear (GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3, 3, -3, 3);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    desenhaLinha();
    desenhaTriangulo();
    glFlush();
    }
void desenhaLinha(){
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-2.0f, -1.0f);
    glVertex2f(2.0f, -1.0f);
    glEnd();
    }
void desenhaTriangulo(){
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(2.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 2.0f);
    glEnd();
    }
int main (int argc , char* argv []) {
    printf("Valor argc: %d", argc);
    printf("\nValor argv pos. 0: %s", argv[0]);
    printf("\nValor argv pos. 1: %s", argv[1]);
    glutInit (&argc , argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize (800, 600);
    glutCreateWindow ("Ola Glut");
    glutDisplayFunc (desenha);
    glClearColor ( 0, 0, 1, 0);
    glutMainLoop();
    return 0;
}
