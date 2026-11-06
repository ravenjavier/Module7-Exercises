// Exercise Q12 — Orbiting Camera via Animated gluLookAt [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
#include <GL/freeglut.h>
using namespace std;

float angle = 0.0f;

float radius = 6.0f;

void drawQuad()
{
    glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.0f); // red
        glVertex3f(-2.0f, 0.0f, -2.0f);

        glColor3f(0.0f, 1.0f, 0.0f); // green
        glVertex3f( 2.0f, 0.0f, -2.0f);

        glColor3f(0.0f, 0.0f, 1.0f); // blue
        glVertex3f( 2.0f, 0.0f,  2.0f);

        glColor3f(1.0f, 1.0f, 0.0f); // yellow
        glVertex3f(-2.0f, 0.0f,  2.0f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float eyeX = radius * sinf(angle);
    float eyeY = 3.0f;
    float eyeZ = radius * cosf(angle);

    gluLookAt(
        eyeX, eyeY, eyeZ,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    );

    drawQuad();

    glutSwapBuffers();
}

void animateCamera(int value)
{
    angle += 0.02f;
    if (angle >= 2.0f * 3.14159f)
        angle = 0.0f;

    glutPostRedisplay();

    glutTimerFunc(30, animateCamera, 0);
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q12 - Orbiting Camera via Animated gluLookAt");

    init();

    glutDisplayFunc(display);

    glutTimerFunc(30, animateCamera, 0);

    glutMainLoop();

    return 0;
}