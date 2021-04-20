#pragma once
#include <string>
#include <cstdint>
#include "GLFW/glfw3.h" 

#include "Application.h"

namespace limon {
	static uint32_t s_WindowCount = 0;

	class Window {
	private:
		GLFWwindow* m_NativePtr = nullptr;
		Application* m_Application = nullptr;
	public:
		Window(Application* app, const uint16_t width, const uint16_t height);
		~Window();

		void Update()const;
		bool CloseRequest() const;

	public:
		void SetTitle(const std::string& title);
		void SetIcon(const Image* icon);
	};
}