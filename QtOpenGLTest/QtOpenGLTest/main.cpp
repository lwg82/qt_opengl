#include "QtOpenGLTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtOpenGLTest w;
	w.show();
	return a.exec();
}
