// Exercise Q18 — Keyboard-Controlled Two-Joint Arm [Hard] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

// separate the angles for the two joints
float baseAngle = 0.0f;
float jointAngle = 0.0f;

// draw one arm segment
void drawSegment()
{
    glBegin(GL_QUADS);

    glColor3f(0.2f, 0.6f, 1.0f);

    glVertex2f(-0.12f, 0.0f);
    glVertex2f( 0.12f, 0.0f);
    glVertex2f( 0.12f, 1.0f);
    glVertex2f(-0.12f, 1.0f);

    glEnd();
}

// draw the hierarchical arm
void drawArm()
{
    // draw the base segment
    glPushMatrix();

    glRotatef(baseAngle, 0.0f, 0.0f, 1.0f);
    drawSegment();

    glTranslatef(0.0f, 1.0f, 0.0f);

    // draw the second segment
    glPushMatrix();

    glRotatef(jointAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 0.5f, 0.0f);
    drawSegment();

    glPopMatrix();

    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawArm();
    glutSwapBuffers();
}

void monitorKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        // increase base angle
        case 'a':
            baseAngle += 5.0f;
            break;

        // decrease base angle
        case 'A':
            baseAngle -= 5.0f;
            break;

        // increase second joint angle
        case 's':
            jointAngle += 5.0f;
            break;

        // decrease second joint angle
        case 'S':
            jointAngle -= 5.0f;
            break;

        // exit program
        case 27:
            exit(0);
            break;
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.5, 2.5, -1.5, 3.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q18 - Keyboard-Controlled Two-Joint Arm");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(monitorKeyboard);

    glutMainLoop();

    return 0;
}