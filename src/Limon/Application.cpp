#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Application.h"
#include "Brush.h"
#include "Color.h"

#define LIMON_OUT(x) std::cout<< x <<std::endl;
#define LIMON_ERR(x) std::cerr<< x <<std::endl;

limon::Application::Application() {
	m_MouseData = new double[4];
}

void limon::Application::Init(int argc, char** argv) {
	LIMON_OUT("Limon started.");
	if (argc == 2) {
		LoadImage(argv[1]);
	} else {
		NewImage(128, 128);
	}
	m_Camera.scale = 1;

	//m_WindowIcon = LoadImage
}

limon::Application::~Application() {
	delete m_Texture;
	delete m_Image;
	delete m_MouseData;
	LIMON_OUT("Limon stopped.");
}

void limon::Application::Update() {
	m_Camera.Begin();
	m_Texture->Draw();
	m_Camera.End();
}

void limon::Application::NewImage(size_t width, size_t height) {
	delete m_Image;
	delete m_Texture;

	m_Image = new Image(width, height);
	brush::Fill(*m_Image, Color());

	m_Texture = new Texture(m_Image);

	LIMON_OUT("Image Created. Width: " << width << " Height: " << height);
}

bool limon::Application::LoadImage(const std::string& path) {
	int width, height, channels;

	uint8_t* data = stbi_load(path.c_str(), &width, &height, &channels, STBI_rgb_alpha);
	if (data != nullptr) {
		delete m_Image;
		delete m_Texture;

		m_Image = new Image(width, height, channels, data);
		m_Texture = new Texture(m_Image);

		m_ImagePath.assign(path);

		LIMON_OUT("Image loaded from: " << path);
		return true;
	}
	return false;
}

void limon::Application::OnMousePress(int button) {
	double wx = m_MouseData[0];
	double wy = m_MouseData[1];

	m_Camera.ScreenToWorld(wx, wy);
	LIMON_OUT(wx << " - " << wy);
}

void limon::Application::OnMouseRelease(int button) {

}

void limon::Application::OnMouseMove(double x, double y) {
	m_MouseData[0] = x;
	m_MouseData[1] = y;
}

void limon::Application::OnScrollChange(double x, double y) {
	m_MouseData[2] = x;
	m_MouseData[3] = y;

	m_Camera.scale += y * 0.05f;
	if (m_Camera.scale < 0.05f) {
		m_Camera.scale = 0.05f;
	}

	LIMON_OUT("SCALE: " << m_Camera.scale);
}

void limon::Application::OnWindowResize(int w, int h) {
	m_Camera.position.x = ((float) w) / 2;
	m_Camera.position.y = ((float) h) / 2;
	m_Camera.size.x = ((float) w);
	m_Camera.size.y = ((float) h);
}

bool limon::Application::OnWindowDrop(int count, const char** paths) {
	return LoadImage(paths[0]);
}
