// Exercise Q08 — Scale-Then-Translate vs. Translate-Then-Scale [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

void drawSquare()
{
    glBegin(GL_QUADS);

        glVertex2f(-0.3f, -0.3f);
        glVertex2f( 0.3f, -0.3f);
        glVertex2f( 0.3f,  0.3f);
        glVertex2f(-0.3f,  0.3f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // first square - translate then Scale
    glPushMatrix();

        glTranslatef(-0.8f, 0.0f, 0.0f);
        glScalef(1.5f, 1.5f, 1.0f);

        glColor3f(1.0f, 0.0f, 0.0f);
        drawSquare();

    glPopMatrix();

    // second square - scale then translate
    glPushMatrix();

        glScalef(1.5f, 1.5f, 1.0f);
        glTranslatef(0.8f, 0.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        drawSquare();

    glPopMatrix();

    glutSwapBuffers();
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -1.5, 1.5);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q08 - Scale-Then-Translate vs. Translate-Then-Scale");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}