#include "lec.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	Scrabble s(&app, 3, 9);
	return app.exec();
}