#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

GLfloat escalay = 1.0f;
GLfloat escalax = 1.0f;
const GLfloat ESCALA_MIN = 0.5f;
float angulo = 0.0f;
float pivoX = 320.0f;
float pivoY = 240.0f;

struct Botao {
    float x1, y1, x2, y2;
    float corAtivaR, corAtivaG, corAtivaB;
    bool aceso;
    char rotulo;
};

Botao botoes[3] = {
    {210, 20, 270, 60, 1.0f, 0.0f, 0.0f, false, 'X'},
    {290, 20, 350, 60, 0.0f, 1.0f, 0.0f, false, 'Y'},
    {370, 20, 430, 60, 0.0f, 0.0f, 1.0f, false, 'Z'}
};



bool dentroBotao(Botao bt, int mx, int my) {
    return (mx >= bt.x1 && mx <= bt.x2 && my >= bt.y1 && my <= bt.y2);
}

void desenhaTexto(float px, float py, char c) {
    glRasterPos2f(px, py);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

void desenhaBotoes() {
    for (int i = 0; i < 3; i++) {
        if (botoes[i].aceso)
            glColor3f(botoes[i].corAtivaR, botoes[i].corAtivaG, botoes[i].corAtivaB);
        else
            glColor3f(0.7f, 0.7f, 0.7f);
        glBegin(GL_QUADS);
            glVertex2f(botoes[i].x1, botoes[i].y1);
            glVertex2f(botoes[i].x2, botoes[i].y1);
            glVertex2f(botoes[i].x2, botoes[i].y2);
            glVertex2f(botoes[i].x1, botoes[i].y2);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        desenhaTexto((botoes[i].x1 + botoes[i].x2) / 2 - 5, (botoes[i].y1 + botoes[i].y2) / 2 - 5, botoes[i].rotulo);
    }
}

void mouse(int button, int state, int mousex, int mousey) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int my = 480 - mousey;

        for (int i = 0; i < 3; i++) {
            if (dentroBotao(botoes[i], mousex, my)) {
                for (int j = 0; j < 3; j++)
                    botoes[j].aceso = false;
                botoes[i].aceso = true;
            }
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glClearColor(1, 1, 1, 0);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glutPostRedisplay();
}

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glScalef(escalax, escalay, 0);



       glPushMatrix();
        glTranslatef(pivoX, pivoY, 0);
        glRotatef(angulo, 0, 0, 1);
        glTranslatef(-pivoX, -pivoY, 0);

        glColor3f(1.0f, 1.0f, 1.0f);

        // Letra N
        glBegin(GL_LINES);
            glVertex2f(135, 190);
            glVertex2f(135, 290);

            glVertex2f(135, 290);
            glVertex2f(195, 190);

            glVertex2f(195, 190);
            glVertex2f(195, 290);
        glEnd();

        // Letra A
        glBegin(GL_LINES);
            glVertex2f(215, 190);
            glVertex2f(255, 290);

            glVertex2f(255, 290);
            glVertex2f(285, 190);

            glVertex2f(239, 250);
            glVertex2f(267, 250);
        glEnd();

        // Letra D
        glBegin(GL_LINES);
            glVertex2f(305, 190);
            glVertex2f(305, 290);

            glVertex2f(305, 290);
            glVertex2f(345, 260);

            glVertex2f(345, 260);
            glVertex2f(345, 220);

            glVertex2f(345, 220);
            glVertex2f(305, 190);
        glEnd();

        // Letra Y
        glBegin(GL_LINES);
            glVertex2f(395, 190);
            glVertex2f(395, 230);

            glVertex2f(395, 230);
            glVertex2f(375, 290);

            glVertex2f(395, 230);
            glVertex2f(415, 290);
        glEnd();

        // Letra A
        glBegin(GL_LINES);
            glVertex2f(445, 190);
            glVertex2f(475, 290);

            glVertex2f(475, 290);
            glVertex2f(505, 190);

            glVertex2f(463, 250);
            glVertex2f(487, 250);
        glEnd();
    glPopMatrix();

    desenhaBotoes();

    glFlush();
}

void listeningKey(unsigned char tecla, GLint x, GLint y) {
    switch (tecla) {
             case '+':
            escalax = escalax + 0.5;
            escalay = escalay + 0.5;
            break;
            case '-':
            escalax--;
            escalay--;
        case 'a': escalax = escalax + 0.5; break;
        case 'b': escalax--; break;
        case 'w': escalay = escalay + 0.5; break;
        case 's': escalay--; break;
        case 'q': angulo += 5.0f; break;
        case 'e': angulo -= 5.0f; break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Meu nome");

    glutKeyboardFunc(listeningKey);
    glutMouseFunc(mouse);
    glutDisplayFunc(desenha);

    glClearColor(0, 0, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutMainLoop();
    return 0;
}
