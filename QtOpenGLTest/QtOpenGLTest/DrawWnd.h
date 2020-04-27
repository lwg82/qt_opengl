#pragma once

#include <QOpenGLWidget>

#include "drawwndfunction.h"

/*
https://blog.csdn.net/qq21497936/article/details/78888286

https://github.com/Kylewlk/OpenGL-Programming-Guide-8th-Edition-Code/blob/master/Chapter01-OG/Triangle/Triangle.cpp

https://www.jianshu.com/p/bccc565b5248

*/

class DrawWnd : public QOpenGLWidget
{
	Q_OBJECT

public:
	DrawWnd(QWidget *parent);
	~DrawWnd();


	virtual void 	initializeGL() Q_DECL_OVERRIDE;
	virtual void 	paintGL() Q_DECL_OVERRIDE;
	virtual void 	resizeGL(int w, int h) Q_DECL_OVERRIDE;

	DrawWndFunction m_Function;
};
