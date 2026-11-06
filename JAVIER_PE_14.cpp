// Exercise Q14 — Depth Testing With Three Triangles [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

// depth testing state
bool depthTest = true;

// draw three overlapping triangles
void drawTriangles()
{
    // triangle 1 - red (z = -0.5)
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLES);

        glVertex3f(-0.8f, -0.6f, -0.5f);
        glVertex3f( 0.8f, -0.6f, -0.5f);
        glVertex3f( 0.0f,  0.8f, -0.5f);

    glEnd();

    // triangle 2 - green (z = 0.0)
    glColor3f(0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);

        glVertex3f(-0.8f, -0.6f, 0.0f);
        glVertex3f( 0.8f, -0.6f, 0.0f);
        glVertex3f( 0.0f,  0.8f, 0.0f);

    glEnd();

    // triangle 3 - blue (z = 0.5)
    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);

        glVertex3f(-0.8f, -0.6f, 0.5f);
        glVertex3f( 0.8f, -0.6f, 0.5f);
        glVertex3f( 0.0f,  0.8f, 0.5f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (depthTest)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawTriangles();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        depthTest = !depthTest;

        if (depthTest)
            cout << "Depth Testing: ON" << endl;
        else
            cout << "Depth Testing: OFF" << endl;

        glutPostRedisplay();
    }
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, -2.0, 2.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q14 - Depth Testing With Three Triangles");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}