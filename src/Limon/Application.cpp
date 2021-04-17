#include <iostream>

#include "Application.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int limon::Application::Run(int argc, char** argv) {
	if (argc <= 1) {
		std::cerr << "not enough args." << std::endl;
		return -1;
	}

	//m_Path.assign("C:\\Seftali-Test\\1.png");
	m_Path.assign(argv[1]);

	Load(m_Path);

	if (m_Image == nullptr) {
		std::cerr << "imgptr is null" << std::endl;
		return -1;
	}

	m_Window = new Window(m_Path, 640, 640);
	m_Window->SetCamera(&m_Camera);

	m_Texture = new Texture(m_Image);

	m_Camera.x = 320;
	m_Camera.y = 320;
	m_Camera.width = 640;
	m_Camera.height = 640;

	while (m_Window->CloseRequest() == false) {
		m_Camera.Begin();
		m_Texture->Draw();
		m_Camera.End();

		m_Window->Update();
	}

	delete m_Window;
	delete m_Texture;
	delete m_Image;
	return 0;
}

void limon::Application::Load(const std::string& path) {
	int width, height, channels;

	uint8_t* data = stbi_load(path.c_str(), &width, &height, &channels, STBI_rgb_alpha);
	if (data != nullptr) {
		std::cout << "Image loaded from: " << path << std::endl;
		m_Image = new Image(width, height, channels, data);
	} else {
		std::cout << "Failed to load image from: " << path << std::endl;
		m_Image = nullptr;
	}
}