#include <Windows.h>

#include "Application.h"
#include "Window.h"

int main(int argc, char** argv) {
	std::unique_ptr<limon::Application> app(new limon::Application());
	std::unique_ptr<limon::Window> window(new limon::Window(app.get(), 640, 640));

	app->Init(argc, argv);

	window->SetTitle("Limon " + app->GetPath()); 

	while (window->CloseRequest() == false) {
		app->Update();
		window->Update();
	}

	return 0;
}
