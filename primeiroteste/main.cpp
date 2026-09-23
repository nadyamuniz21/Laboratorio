#include<GL/freeglut.h>
#include<iostream>
void desenha (void) {
    glClear(GL_COLOR_BUFFER_BIT );
    gluOrtho2D(-6, 6, -6, 6);
    glBegin (GL_LINES);
    //glColor3f(1, 0, 0);
    glVertex2f(-2,0);
    glVertex2f(2,0);


    //glColor3f(0, 1, 0);
    //glLineWidth(25);
    glVertex2f(0,-2);
    glVertex2f(0,2);
    glEnd();
    glFlush();
}        //(  A função main deve ser declarado com essa assinatura)
int main(int argc, char* argv[]){

  // Passa as informações da janela sobre o tamanho dela, tem que chamá-la sempre que fizer uma janela.
    glutInit(&argc, argv);

 //   Define o modo de operação do display, do monitor para visualizar as informações,Glut_SINGLE define que e estou utilizando um frame buffer único(memória de vídeo, é um quadro, uma matriz, só conseguimos ver por causa da matriz), frame buffer permite eu ver os vídeos na tela.GLUT_RGB modelo de cor.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

 //  Tamanho da janela, primeiro a coluna(x), depois a linha(y).
    glutInitWindowSize (800,600);

  //  Posição que ela vai aparecer.
    glutInitWindowPosition (300, 100);

  //  É o título  que vai aparecer no inicio a janela.
    glutCreateWindow("Ola Glut");

  //  Chamada de função
    glutDisplayFunc (desenha);

  //  Define a cor que será utilizado   0.0: Totalmente transparente. 1.0: Totalmente opaco.

    glClearColor( 0, 0, 1, 0);

   // Faz com que a janela continue exibindo na tela o valor que está sendo projetado no buffer.
    glutMainLoop ();
    return 0;
}
