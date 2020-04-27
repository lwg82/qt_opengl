#include "DrawWnd.h"

DrawWnd::DrawWnd(QWidget *parent)
	: QOpenGLWidget(parent)
{
}

DrawWnd::~DrawWnd()
{
}




void 	DrawWnd::initializeGL()
{
	m_Function.initializeOpenGLFunctions();

	m_Function.initializeOpenGL();
}

void 	DrawWnd::paintGL()
{
	m_Function.glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	m_Function.glClear(GL_COLOR_BUFFER_BIT);

	m_Function.m_ShaderProgram.bind();

	m_Function.glBindVertexArray(m_Function.m_VAOs[0]);
	m_Function.glDrawArrays(GL_TRIANGLES, 0, 3); // »æÍ¼

	m_Function.m_ShaderProgram.release();
}

void 	DrawWnd::resizeGL(int w, int h)
{
	m_Function.glViewport(0, 0, w, h);
}
