// Exercise Q04 — Three Quads, One Rotated [Easy]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

void drawQuad()
{
    glBegin(GL_QUADS);

        glVertex2f(-0.4f, -0.4f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f,  0.4f);
        glVertex2f(-0.4f,  0.4f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // left quad - no rotation
    glPushMatrix();

        glTranslatef(-1.2f, 0.0f, 0.0f);

        glColor3f(1.0f, 0.0f, 0.0f);
        drawQuad();

    glPopMatrix();

    // middle quad - rotated 45 degrees
    glPushMatrix();

        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        drawQuad();

    glPopMatrix();

    // right quad - no rotation
    glPushMatrix();

        glTranslatef(1.2f, 0.0f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        drawQuad();

    glPopMatrix();

    glFlush();
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-2.0, 2.0, -1.5, 1.5);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q04 - Three Quads, One Rotated");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}