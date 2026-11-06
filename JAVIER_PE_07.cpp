// Exercise Q07 — Animate a Rotating Quad [Easy] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

// rotation angle
float angle = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.7f, 1.0f);

    glBegin(GL_QUADS);

        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);

    glEnd();

    glutSwapBuffers();
}

void animateQuad(int value)
{
    angle += 5.0f;

    if (angle >= 360.0f)
    {
        angle = 0.0f;
    }

    glutPostRedisplay();

    glutTimerFunc(50, animateQuad, 0);
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Exercise Q07 - Animate a Rotating Quad");

    init();

    glutDisplayFunc(display);

    glutTimerFunc(50, animateQuad, 0);

    glutMainLoop();

    return 0;
}