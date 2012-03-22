#ifndef OPENGL_H
#define OPENGL_H

#include <QGLWidget>

class OpenGL : public QGLWidget
{
    Q_OBJECT

public:
    OpenGL(QWidget *parent = 0);
    ~OpenGL();

public:
    virtual void initializeGL();
    virtual void resizeGL(int width, int height);
    virtual void paintGL();
};

#endif // OPENGL_H
