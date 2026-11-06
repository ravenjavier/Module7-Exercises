// Exercise Q15 — Lecture Pyramid, Rotated on a Different Axis, With Cleanup [Hard]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>
using namespace std;

GLuint VBO;
float angle = 0.0f;

// pyramid position data
GLfloat vertices[] =
{
    // front face
     0.0f,  1.0f,  0.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,

    // right face
     0.0f,  1.0f,  0.0f,
     1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,

    // back face
     0.0f,  1.0f,  0.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,

    // left face
     0.0f,  1.0f,  0.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,

    // bottom face - triangle 1
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,

    // bottom face - triangle 2
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f
};

// color data - one rgb color per vertex
GLfloat colors[] =
{
    // front face - red
    1,0,0,  1,0,0,  1,0,0,

    // right face - green
    0,1,0,  0,1,0,  0,1,0,

    // back face - blue
    0,0,1,  0,0,1,  0,0,1,

    // left face - yellow
    1,1,0,  1,1,0,  1,1,0,

    // bottom face - cyan
    0,1,1,  0,1,1,  0,1,1,
    0,1,1,  0,1,1,  0,1,1
};

void initVBO()
{
    glGenBuffers(1, &VBO);

    GLsizeiptr positionSize = sizeof(vertices);
    GLsizeiptr colorSize = sizeof(colors);
    GLsizeiptr totalSize = positionSize + colorSize;

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, totalSize, NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, positionSize, vertices);
    glBufferSubData(GL_ARRAY_BUFFER, positionSize, colorSize, colors);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, (void*)0);
    glColorPointer(3, GL_FLOAT, 0, (void*)positionSize);

    cout << "VBO initialized successfully." << endl;
    cout << "Total VBO size: " << totalSize << " bytes" << endl;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angle, 1.0f, 0.0f, 0.0f);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glDrawArrays(GL_TRIANGLES, 0, 18);

    glutSwapBuffers();
}

// animation timer
void animatePyramid(int value)
{
    angle += 2.0f;

    if (angle >= 360.0f)
        angle = 0.0f;

    glutPostRedisplay();

    glutTimerFunc(30, animatePyramid, 0);
}

// Clean up the VBO and exit
void monitorKeyboard(unsigned char key, int x, int y)
{
    if (key == 27) // ESC key
    {
        cout << "ESC pressed. Cleaning up VBO..." << endl;

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &VBO);

        cout << "VBO released successfully." << endl;
        cout << "Program terminated." << endl;

        exit(0);
    }
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
    glutCreateWindow("Exercise Q15 - Lecture Pyramid, Rotated on a Different Axis, With Cleanup");

    GLenum err = glewInit();

    if (err != GLEW_OK)
    {
        cout << "GLEW initialization failed!" << endl;
        return 1;
    }

    init();
    initVBO();

    glutDisplayFunc(display);
    glutKeyboardFunc(monitorKeyboard);

    glutTimerFunc(30, animatePyramid, 0);

    glutMainLoop();

    return 0;
}