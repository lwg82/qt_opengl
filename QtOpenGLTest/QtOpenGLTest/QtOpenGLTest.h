#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtOpenGLTest.h"

class QtOpenGLTest : public QWidget
{
	Q_OBJECT

public:
	QtOpenGLTest(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtOpenGLTestClass ui;
};
