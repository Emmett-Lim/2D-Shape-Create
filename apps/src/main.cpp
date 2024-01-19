#include "application.h"

int main(int argc, char* argv[]) {

	Application app;

	if (app.ApplicationInit()) { app.ApplicationLoop(); }

	app.ApplicationClose();

	return 0;
}