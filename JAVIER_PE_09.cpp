// Exercise Q09 — Three-Segment Hierarchical Chain [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

// rotation angle for each segment
float baseAngle = -25.0f;
float middleAngle = 35.0f;
float tipAngle = -20.0f;

void drawSegment()
{
    glBegin(GL_QUADS);

        glVertex2f(-0.15f, 0.0f);
        glVertex2f( 0.15f, 0.0f);
        glVertex2f( 0.15f, 1.0f);
        glVertex2f(-0.15f, 1.0f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // BASE SEGMENT
    glPushMatrix();

        glRotatef(baseAngle, 0.0f, 0.0f, 1.0f);

        glColor3f(1.0f, 0.0f, 0.0f); // Red
        drawSegment();

        // MIDDLE SEGMENT
        glPushMatrix();

            glTranslatef(0.0f, 1.0f, 0.0f);

            glRotatef(middleAngle, 0.0f, 0.0f, 1.0f);

            glColor3f(0.0f, 1.0f, 0.0f); // Green
            drawSegment();

            // TIP SEGMENT
            glPushMatrix();

                glTranslatef(0.0f, 1.0f, 0.0f);

                glRotatef(tipAngle, 0.0f, 0.0f, 1.0f);

                glColor3f(0.0f, 0.5f, 1.0f);
                drawSegment();

            glPopMatrix(); // end tip

        glPopMatrix(); // end middle

    glPopMatrix(); // end base

    glutSwapBuffers();
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-2.5, 2.5, -1.0, 3.5);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q09 - Three-Segment Hierarchical Chain");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}