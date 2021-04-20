#pragma once
#include "Image.h"
#include "Texture.h"
#include "Camera.h"

namespace limon {
	class Application {
	public:
		Application();
		~Application();

	public:
		void Init(int argc, char** argv);
		void Update();

	public:
		void NewImage(size_t width, size_t height);
		/// <summary>
		/// Loads an image file from path.
		/// </summary>
		/// <param name="path">: the image file path.</param>
		bool LoadImage(const std::string& path);

		const std::string& GetPath() const { return m_ImagePath; };
		const limon::Image* GetWindowIcon() { return m_WindowIcon; };

	public:
		void OnMousePress(int button);
		void OnMouseRelease(int button);
		void OnMouseMove(double x, double y);
		void OnScrollChange(double x, double y);

		void OnWindowResize(int w, int h);
		bool OnWindowDrop(int count, const char** paths);

	private:
		std::string	m_ImagePath;
		Image* m_WindowIcon;

		double* m_MouseData;
		Camera m_Camera;

		Image* m_Image = nullptr;
		Texture* m_Texture = nullptr;
	};
}