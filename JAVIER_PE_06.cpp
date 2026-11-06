// Exercise Q06 — gluOrtho2D With Pixel-Style Coordinates [Easy] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(5.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);

        glVertex2f(300.0f, 200.0f);
        glVertex2f(500.0f, 200.0f);
        glVertex2f(500.0f, 400.0f);
        glVertex2f(300.0f, 400.0f);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q06 - gluOrtho2D With Pixel-Style Coordinates");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}