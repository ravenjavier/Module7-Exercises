// Exercise Q11 — An Asymmetric glFrustum [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

// true = asymmetric, false = symmetric
bool asymmetric = true;

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

    if (asymmetric)
    {
        // asymmetric frustum
        glFrustum(-0.5, 1.5, -1.0, 1.0, 1.0, 10.0);
    }
    else
    {
        // symmetric frustum
        glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -3.0f);

    drawCube();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'a' || key == 'A')
    {
        asymmetric = true;
        cout << "Asymmetric Frustum: left=-0.5, right=1.5" << endl;
        glutPostRedisplay();
    }
    else if (key == 's' || key == 'S')
    {
        asymmetric = false;
        cout << "Symmetric Frustum: left=-1.0, right=1.0" << endl;
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
    glutCreateWindow("Exercise Q11 - An Asymmetric glFrustum");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}