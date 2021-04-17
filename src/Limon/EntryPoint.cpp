// Limon.cpp : Defines the entry point for the application.

#include "Application.h"
#include <Windows.h>
 
int main(int argc, char** argv) {
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	limon::Application app;
	if (app.Run(argc, argv) == -1) {
		::ShowWindow(::GetConsoleWindow(), SW_SHOW);
		std::cin.get();
	}
	return 0;
}
