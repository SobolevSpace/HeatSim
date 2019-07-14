#include "app/app.h"

int main(int argc,char* argv[]) {
	QApplication A(argc,argv);
	app APP;
	APP.init();
	APP.show();
	return A.exec();
}