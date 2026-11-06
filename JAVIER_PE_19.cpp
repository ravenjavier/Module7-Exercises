// Exercise Q19 — Two Viewports, Two Cameras, One Animated [Hard] 
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

float orbitAngle = 0.0f;

// draw the same 3d scene in both viewports
void drawScene()
{
    // draw the ground grid
    glColor3f(0.35f, 0.35f, 0.35f);

    glBegin(GL_LINES);

    for (int i = -5; i <= 5; i++)
    {
        glVertex3f((float)i, -1.2f, -5.0f);
        glVertex3f((float)i, -1.2f,  5.0f);

        glVertex3f(-5.0f, -1.2f, (float)i);
        glVertex3f( 5.0f, -1.2f, (float)i);
    }

    glEnd();

    // draw the center cube
    glPushMatrix();

    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glutSolidCube(2.0);

    glPopMatrix();

    // draw the green sphere on the left
    glPushMatrix();

    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(-3.0f, 0.0f, 0.0f);
    glutSolidSphere(0.8, 30, 30);

    glPopMatrix();

    // draw the blue teapot on the right
    glPushMatrix();

    glColor3f(0.0f, 0.3f, 1.0f);
    glTranslatef(3.0f, 0.0f, 0.0f);
    glutSolidTeapot(0.8);

    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    int halfWidth = width / 2;

    // left viewport - fixed camera
    glViewport(0, 0, halfWidth, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        45.0,
        (double)halfWidth / height,
        0.1,
        100.0
    );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(
        7.0, 5.0, 8.0,  // fixed eye position
        0.0, 0.0, 0.0,  // look at the center
        0.0, 1.0, 0.0   // up direction
    );

    drawScene();

    // right viewport - orbiting camera
    glViewport(halfWidth, 0, width - halfWidth, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        45.0,
        (double)(width - halfWidth) / height,
        0.1,
        100.0
    );

    float radius = 8.0f;

    float eyeX = radius * cosf(orbitAngle);
    float eyeY = 4.0f;
    float eyeZ = radius * sinf(orbitAngle);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(
        eyeX, eyeY, eyeZ,  // animated eye position
        0.0, 0.0, 0.0,     // look at the center
        0.0, 1.0, 0.0      // up direction
    );

    drawScene();

    glutSwapBuffers();
}

void timer(int value)
{
    orbitAngle += 0.01f;

    if (orbitAngle >= 6.283185f)
        orbitAngle -= 6.283185f;

    glutPostRedisplay();

    glutTimerFunc(16, timer, 0);
}

void reshape(int width, int height)
{
    glutPostRedisplay();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Exercise Q19 - Two Viewports, Two Cameras, One Animated");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();

    return 0;
}