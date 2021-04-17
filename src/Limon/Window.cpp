#include "Window.h"
#include <iostream>

limon::Window::Window(const std::string& title, const uint16_t width, const uint16_t height) {
	if (s_WindowCount == 0) {
		if (glfwInit() == GLFW_FALSE) {
			std::cerr << "Failed to initialize GLFW." << std::endl;
		}
	}

	m_NativePtr = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (m_NativePtr == nullptr) {
		std::cerr << "Failed to create GLFW window." << std::endl;
		return;
	}

	glfwSetWindowSizeCallback(m_NativePtr, [](GLFWwindow* window, int width, int height) {
		Camera* camera = static_cast<Camera*>(glfwGetWindowUserPointer(window));
		camera->x = width / 2;
		camera->y = height / 2;
		camera->width = width;
		camera->height = height;
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

void limon::Window::SetCamera(Camera* camera) {
	m_Camera = camera;
	glfwSetWindowUserPointer(m_NativePtr, m_Camera);
}
