// Exercise Q20 — Capstone: Color VBO Base + Animated Hierarchical Arm [Hard]
#define GL_SILENCE_DEPRECATION
#include <GL/glew.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <GL/freeglut.h>
using namespace std;

GLuint VBO;
float baseAngle = 0.0f;
float jointAngle = 0.0f;

// cube positions for the fixed base
GLfloat vertices[] = {
    // front face
    -1.0f, -0.5f,  1.0f,
     1.0f, -0.5f,  1.0f,
     1.0f,  0.5f,  1.0f,
    -1.0f,  0.5f,  1.0f,

    // back face
    -1.0f, -0.5f, -1.0f,
    -1.0f,  0.5f, -1.0f,
     1.0f,  0.5f, -1.0f,
     1.0f, -0.5f, -1.0f,

    // top face
    -1.0f,  0.5f, -1.0f,
    -1.0f,  0.5f,  1.0f,
     1.0f,  0.5f,  1.0f,
     1.0f,  0.5f, -1.0f,

    // bottom face
    -1.0f, -0.5f, -1.0f,
     1.0f, -0.5f, -1.0f,
     1.0f, -0.5f,  1.0f,
    -1.0f, -0.5f,  1.0f,

    // right face
     1.0f, -0.5f, -1.0f,
     1.0f,  0.5f, -1.0f,
     1.0f,  0.5f,  1.0f,
     1.0f, -0.5f,  1.0f,

    // left face
    -1.0f, -0.5f, -1.0f,
    -1.0f, -0.5f,  1.0f,
    -1.0f,  0.5f,  1.0f,
    -1.0f,  0.5f, -1.0f
};

// colors for each cube face
GLfloat colors[] = {
    // front - red
    1,0,0, 1,0,0, 1,0,0, 1,0,0,

    // back - green
    0,1,0, 0,1,0, 0,1,0, 0,1,0,

    // top - blue
    0,0,1, 0,0,1, 0,0,1, 0,0,1,

    // bottom - yellow
    1,1,0, 1,1,0, 1,1,0, 1,1,0,

    // right - orange
    1,0.5f,0, 1,0.5f,0, 1,0.5f,0, 1,0.5f,0,

    // left - purple
    1,0,1, 1,0,1, 1,0,1, 1,0,1
};

// opengl debug callback
void APIENTRY debugCallback(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{
    cout << "\n========== opengl debug message ==========" << endl;
    cout << "message: " << message << endl;
    cout << "error id: " << id << endl;
    cout << "===========================================" << endl;
}

void setupDebugCallback()
{
    if (GLEW_KHR_debug || GLEW_VERSION_4_3)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

        glDebugMessageCallback(debugCallback, NULL);

        cout << "opengl debug callback registered." << endl;
    }
    else
    {
        cout << "opengl debug callback is not supported." << endl;
    }
}

// create the vbo base
void initVBO()
{
    GLsizeiptr positionSize = sizeof(vertices);
    GLsizeiptr colorSize = sizeof(colors);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, positionSize + colorSize, NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, positionSize, vertices);
    glBufferSubData(GL_ARRAY_BUFFER, positionSize, colorSize, colors);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, (void*)0);

    glColorPointer(
        3,
        GL_FLOAT,
        0,
        reinterpret_cast<void*>(static_cast<uintptr_t>(positionSize))
    );

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void drawBase()
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glBegin(GL_QUADS);

    for (int i = 0; i < 24; i++)
    {
        glArrayElement(i);
    }

    glEnd();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// draw one rectangular arm segment
void drawSegment()
{
    float w = 0.15f;
    float h = 1.2f;
    float d = 0.15f;

    glBegin(GL_QUADS);

    // front face
    glVertex3f(-w, 0.0f, d);
    glVertex3f( w, 0.0f, d);
    glVertex3f( w, h, d);
    glVertex3f(-w, h, d);

    // back face
    glVertex3f(-w, 0.0f, -d);
    glVertex3f(-w, h, -d);
    glVertex3f( w, h, -d);
    glVertex3f( w, 0.0f, -d);

    // top face
    glVertex3f(-w, h, -d);
    glVertex3f(-w, h,  d);
    glVertex3f( w, h,  d);
    glVertex3f( w, h, -d);

    // bottom face
    glVertex3f(-w, 0.0f, -d);
    glVertex3f( w, 0.0f, -d);
    glVertex3f( w, 0.0f,  d);
    glVertex3f(-w, 0.0f,  d);

    // right face
    glVertex3f(w, 0.0f, -d);
    glVertex3f(w, h, -d);
    glVertex3f(w, h, d);
    glVertex3f(w, 0.0f, d);

    // left face
    glVertex3f(-w, 0.0f, -d);
    glVertex3f(-w, 0.0f, d);
    glVertex3f(-w, h, d);
    glVertex3f(-w, h, -d);

    glEnd();
}

// draw the hierarchical arm
void drawArm()
{
    glPushMatrix();

    // attach the arm above the base cube
    glTranslatef(0.0f, 0.5f, 0.0f);

    // rotate the first segment
    glRotatef(baseAngle, 0.0f, 0.0f, 1.0f);

    // draw the first segment
    glColor3f(0.0f, 0.8f, 1.0f);
    drawSegment();

    // move to the end of the first segment
    glTranslatef(0.0f, 1.2f, 0.0f);

    glPushMatrix();
    glRotatef(jointAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.5f, 0.0f);
    drawSegment();

    glPopMatrix();

    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(
        5.0f, 5.0f, 8.0f,
        0.0f, 1.5f, 0.0f,
        0.0f, 1.0f, 0.0f
    );

    drawBase();

    drawArm();

    glutSwapBuffers();
}

void timer(int value)
{
    baseAngle += 1.0f;
    jointAngle += 2.0f;

    if (baseAngle >= 360.0f)
        baseAngle -= 360.0f;

    if (jointAngle >= 360.0f)
        jointAngle -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

// projection and viewport setup
void reshape(int width, int height)
{
    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void monitorKeyboard(unsigned char key, int x, int y)
{
    if (key == 27)
    {
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &VBO);

        cout << "vbo deleted. program terminated." << endl;

        exit(0);
    }
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    initVBO();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 700);
    glutCreateWindow("Exercise Q20 - Capstone: Color VBO Base + Animated Hierarchical Arm ");
    
    GLenum err = glewInit();

    if (err != GLEW_OK)
    {
        cout << "glew initialization failed!" << endl;
        return 1;
    }

    setupDebugCallback();

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(monitorKeyboard);
    glutTimerFunc(30, timer, 0);

    glutMainLoop();

    return 0;
}