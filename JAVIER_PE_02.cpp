// Exercise Q02 — Rotate Around the X Axis [Easy]
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -3.0f);

    glRotatef(60.0f, 1.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 0.0f);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 0.0f);

    glEnd();

    glutSwapBuffers();
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        45.0,
        800.0 / 600.0,
        0.1,
        100.0
    );

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q02 - Rotate Around the X Axis");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}