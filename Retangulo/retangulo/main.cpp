#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

static float pontosRetX[2000];
static float pontosRetY[2000];
static int totalPontosRetangulo = 0;

static float pontosJanX[2000];
static float pontosJanY[2000];
static int totalPontosJanela = 0;

static int contadorCliquesRetangulo = 0;
static int contadorCliquesJanela = 0;

void desenhaQuadrado(float x, float y, float meiaLado) {
    glBegin(GL_QUADS);
        glVertex2f(x - meiaLado, y - meiaLado);
        glVertex2f(x + meiaLado, y - meiaLado);
        glVertex2f(x + meiaLado, y + meiaLado);
        glVertex2f(x - meiaLado, y + meiaLado);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.4f, 0.9f);
    glBegin(GL_QUADS);
        glVertex2f(250.0f, 150.0f);
        glVertex2f(550.0f, 150.0f);
        glVertex2f(550.0f, 450.0f);
        glVertex2f(250.0f, 450.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    for (int i = 0; i < totalPontosRetangulo; i++) {
        desenhaQuadrado(pontosRetX[i], pontosRetY[i], 6.0f);
    }

    glColor3f(1.0f, 0.1f, 0.1f);
    for (int i = 0; i < totalPontosJanela; i++) {
        desenhaQuadrado(pontosJanX[i], pontosJanY[i], 6.0f);
    }

    glutSwapBuffers();
}

int dentroDoRetangulo(float x, float y) {
    return (x >= 250.0f && x <= 550.0f && y >= 150.0f && y <= 450.0f);
}

void mouse(int button, int state, int x, int y) {
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN) {
        return;
    }

    float worldX = (float)x;
    float worldY = (float)(600 - y);

    if (dentroDoRetangulo(worldX, worldY)) {
        if (totalPontosRetangulo < 2000) {
            pontosRetX[totalPontosRetangulo] = worldX;
            pontosRetY[totalPontosRetangulo] = worldY;
            totalPontosRetangulo++;
        }
        contadorCliquesRetangulo++;
        printf("Clique no RETANGULO   -> total retangulo: %d | total janela: %d\n",
               contadorCliquesRetangulo, contadorCliquesJanela);
    } else {
        if (totalPontosJanela < 2000) {
            pontosJanX[totalPontosJanela] = worldX;
            pontosJanY[totalPontosJanela] = worldY;
            totalPontosJanela++;
        }
        contadorCliquesJanela++;
        printf("Clique na JANELA      -> total retangulo: %d | total janela: %d\n",
               contadorCliquesRetangulo, contadorCliquesJanela);
    }

    glutPostRedisplay();
}

void inicializaOpenGL(void) {
    glClearColor(0.95f, 0.95f, 0.95f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Retangulo + Mini Quadrados");

    inicializaOpenGL();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
