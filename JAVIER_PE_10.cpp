// Exercise Q10 — Comparing Wide vs. Narrow Field of View [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

// true = Wide FOV and false = Narrow FOV
bool wideFOV = true;

void drawCube()
{
    glBegin(GL_QUADS);

        // front face - red
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f,  0.5f);
        glVertex3f( 0.5f, -0.5f,  0.5f);
        glVertex3f( 0.5f,  0.5f,  0.5f);
        glVertex3f(-0.5f,  0.5f,  0.5f);

        // back face - green
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f,  0.5f, -0.5f);
        glVertex3f( 0.5f,  0.5f, -0.5f);
        glVertex3f( 0.5f, -0.5f, -0.5f);

        // top face - blue
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f,  0.5f);
        glVertex3f( 0.5f, 0.5f,  0.5f);
        glVertex3f( 0.5f, 0.5f, -0.5f);

        // bottom face - yellow
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f( 0.5f, -0.5f, -0.5f);
        glVertex3f( 0.5f, -0.5f,  0.5f);
        glVertex3f(-0.5f, -0.5f,  0.5f);

        // right face - cyan
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glVertex3f(0.5f,  0.5f, -0.5f);
        glVertex3f(0.5f,  0.5f,  0.5f);
        glVertex3f(0.5f, -0.5f,  0.5f);

        // left face - magenta
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f,  0.5f);
        glVertex3f(-0.5f,  0.5f,  0.5f);
        glVertex3f(-0.5f,  0.5f, -0.5f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float fov = wideFOV ? 90.0f : 30.0f;

    gluPerspective(fov, 800.0 / 600.0, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -4.0f);

    drawCube();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'v' || key == 'V')
    {
        wideFOV = !wideFOV;

        if (wideFOV)
            cout << "Wide Field of View: 90 degrees" << endl;
        else
            cout << "Narrow Field of View: 30 degrees" << endl;

        glutPostRedisplay();
    }
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q10 - Comparing Wide vs. Narrow Field of View");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}