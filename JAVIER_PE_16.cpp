// Exercise Q16 — Split Screen: Orthographic vs. Perspective
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

void drawCube()
{
    glBegin(GL_QUADS);

    // front face - red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    // back face - green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // top face - blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    // bottom face - yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    // right face - orange
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);

    // left face - purple
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    glEnd();
}

void drawScene()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(25.0f, 1.0f, 1.0f, 0.0f);

    drawCube();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    int halfWidth = width / 2;

    // left viewport - orthographic
    glViewport(0, 0, halfWidth, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspectLeft = (float)halfWidth / height;

    if (aspectLeft >= 1.0f)
    {
        glOrtho(-3.0f * aspectLeft, 3.0f * aspectLeft,
                -3.0f, 3.0f, 1.0f, 20.0f);
    }
    else
    {
        glOrtho(-3.0f, 3.0f,
                -3.0f / aspectLeft, 3.0f / aspectLeft,
                1.0f, 20.0f);
    }

    drawScene();

    // right viewport - perspective
    glViewport(halfWidth, 0, width - halfWidth, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspectRight = (float)(width - halfWidth) / height;

    gluPerspective(60.0, aspectRight, 1.0, 20.0);
    drawScene();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glutPostRedisplay();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Exercise Q16 - Split Screen: Orthographic vs. Perspective");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}