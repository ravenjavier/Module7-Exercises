// Exercise Q05 — Non-Symmetric glOrtho [Easy]
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

    glColor3f(0.0f, 0.7f, 1.0f);

    glBegin(GL_TRIANGLES);

        glVertex2f(2.0f, 2.3f);
        glVertex2f(1.2f, 0.8f);
        glVertex2f(2.8f, 0.8f);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 4.0, 0.0, 3.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q05 - Non-Symmetric glOrtho");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}