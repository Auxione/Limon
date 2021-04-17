#pragma once
#include <string>
#include <cstdint>
#include "GLFW/glfw3.h"
#include "Camera.h"

namespace limon {
	static uint32_t s_WindowCount = 0;

	class Window {
	private:
		GLFWwindow* m_NativePtr = nullptr;
		Camera* m_Camera = nullptr;
	public:
		Window(const std::string& title, const uint16_t width, const uint16_t height);
		~Window();

		void Update()const;
		bool CloseRequest() const;

		void SetCamera(Camera* camera);
	};
}