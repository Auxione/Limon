#include "Window.h"
#include <iostream>

limon::Window::Window(Application* app, const uint16_t width, const uint16_t height) {
	if (s_WindowCount == 0) {
		if (glfwInit() == GLFW_FALSE) {
			std::cerr << "Failed to initialize GLFW." << std::endl;
		}
	}

	m_NativePtr = glfwCreateWindow(width, height, "Limon", NULL, NULL);
	if (m_NativePtr == nullptr) {
		std::cerr << "Failed to create GLFW window." << std::endl;
		return;
	}

	m_Application = app;
	app->OnWindowResize(width, height);
	glfwSetWindowUserPointer(m_NativePtr, this);

	glfwSetWindowSizeCallback(m_NativePtr, [](GLFWwindow* window, int width, int height) {
		Application* app = static_cast<Window*>(glfwGetWindowUserPointer(window))->m_Application;
		app->OnWindowResize(width, height);
							  });

	glfwSetDropCallback(m_NativePtr, [](GLFWwindow* window, int  count, const char** path) {
		Application* app = static_cast<Window*>(glfwGetWindowUserPointer(window))->m_Application;
		app->OnWindowDrop(count, path);
						});

	glfwSetCursorPosCallback(m_NativePtr, [](GLFWwindow* window, double x, double y) {
		Application* app = static_cast<Window*>(glfwGetWindowUserPointer(window))->m_Application;
		app->OnMouseMove(x, y);
							 });

	glfwSetScrollCallback(m_NativePtr, [](GLFWwindow* window, double x, double y) {
		Application* app = static_cast<Window*>(glfwGetWindowUserPointer(window))->m_Application;
		app->OnScrollChange(x, y);
						  });

	glfwSetMouseButtonCallback(m_NativePtr, [](GLFWwindow* window, int button, int action, int mods) {
		Application* app = static_cast<Window*>(glfwGetWindowUserPointer(window))->m_Application;
		if (action == GLFW_PRESS) {
			app->OnMousePress(button);
		}

		if (action == GLFW_RELEASE) {
			app->OnMouseRelease(button);
		}
							   });

	glfwMakeContextCurrent(m_NativePtr);
	s_WindowCount++;
}

limon::Window::~Window() {
	glfwDestroyWindow(m_NativePtr);

	s_WindowCount--;
	if (s_WindowCount == 0) {
		glfwTerminate();
	}
}

void limon::Window::Update() const {
	glfwSwapBuffers(m_NativePtr);
	glfwWaitEvents();
}

bool limon::Window::CloseRequest()const {
	return glfwWindowShouldClose(m_NativePtr);
}

void limon::Window::SetTitle(const std::string& title) {
	glfwSetWindowTitle(m_NativePtr, title.c_str());
}

void limon::Window::SetIcon(const Image* icon) {
	GLFWimage* img = new GLFWimage();
	img->pixels = (unsigned char*) icon->GetPixels();
	img->width = icon->GetWidth();
	img->height = icon->GetHeight();

	glfwSetWindowIcon(m_NativePtr, 1, img);
}
