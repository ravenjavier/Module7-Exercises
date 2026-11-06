// Exercise Q13 — Static Color Quad via glBufferSubData + glArrayElement [Medium] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
using namespace std;

GLuint VBO;

// four vertices with three coordinates each
GLfloat vertices[] =
{
    -0.5f, -0.5f, 0.0f,  // bottom-left
     0.5f, -0.5f, 0.0f,  // bottom-right
     0.5f,  0.5f, 0.0f,  // top-right
    -0.5f,  0.5f, 0.0f   // top-left
};

// one rgb color for each vertex
GLfloat colors[] =
{
    1.0f, 0.0f, 0.0f,  // red
    0.0f, 1.0f, 0.0f,  // green
    0.0f, 0.0f, 1.0f,  // blue
    1.0f, 1.0f, 0.0f   // yellow
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

    cout << "VBO successfully initialized." << endl;
    cout << "Position data: " << positionSize << " bytes" << endl;
    cout << "Color data: " << colorSize << " bytes" << endl;
    cout << "Total VBO size: " << totalSize << " bytes" << endl;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBegin(GL_QUADS);

        for (int i = 0; i < 4; i++)
        {
            glArrayElement(i);
        }

    glEnd();

    glutSwapBuffers();
}

void init()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q13 - Static Color Quad via glBufferSubData + glArrayElement");
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        cout << "GLEW initialization failed!" << endl;
        return 1;
    }

    init();
    initVBO();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}