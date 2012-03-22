#include "opengl.h"

OpenGL::OpenGL(QWidget *parent) :
    QGLWidget(parent)
{
}

OpenGL::~OpenGL()
{
}

void OpenGL::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void OpenGL::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);

    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void OpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0.1, 0.1);
    glVertex2d(0.9, 0.1);
    glVertex2d(0.5, 0.9);
    glEnd();
}
