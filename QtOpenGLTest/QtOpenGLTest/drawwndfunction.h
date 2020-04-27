#ifndef DRAWWNDFUNCTION_H
#define DRAWWNDFUNCTION_H

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>

class DrawWndFunction : public QOpenGLFunctions_3_3_Core
{

public:
    explicit DrawWndFunction();

    void    initializeOpenGL();


    GLuint    m_VAOs[1];  // 顶点数组对象
    GLuint    m_VBOs[1];  // 顶点缓冲对象

    QOpenGLShaderProgram m_ShaderProgram;
signals:

public slots:
};

#endif // DRAWWNDFUNCTION_H
