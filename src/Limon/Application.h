#pragma once
#include "Image.h"
#include "Texture.h"
#include "Window.h"
#include "Camera.h"

namespace limon {
	class Application {
	public:
		Application() = default;
		~Application() = default;

	public:
		int Run(int argc, char** argv);

		/// <summary>
		/// Loads an image file from path.
		/// </summary>
		/// <param name="path">: the image file path.</param>
		void Load(const std::string& path);

	private:
		std::string	m_Path;
		Camera m_Camera;

		Image* m_Image = nullptr;
		Window* m_Window = nullptr;
		Texture* m_Texture = nullptr;
	};
}