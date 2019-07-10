/*
#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
*/

#include "app.h"

int main(int argc,char* argv[]) {
	QApplication a(argc, argv);
	app APP;
	APP.init();
	APP.show();
	return a.exec();

}