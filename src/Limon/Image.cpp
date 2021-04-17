#include "Image.h"


limon::Image::Image(const size_t width, const size_t height)
	: m_Width(width)
	, m_Height(height)
	, m_Channels(4)
	, m_Pixels(new uint8_t[m_Width * m_Height * 4]) {}

limon::Image::Image(const size_t width, const size_t height, const size_t channels, uint8_t* pixels)
	: m_Width(width)
	, m_Height(height)
	, m_Channels(channels)
	, m_Pixels(pixels) {}

limon::Image::~Image() {
	delete[] m_Pixels;
}

limon::Image::Image(const Image& other)
	: m_Width(other.m_Width)
	, m_Height(other.m_Height)
	, m_Channels(other.m_Channels)
	, m_Pixels(new uint8_t[m_Width * m_Height * 4]) {

	std::copy(other.m_Pixels, other.m_Pixels + m_Width * m_Height * 4, m_Pixels);
}

limon::Image& limon::Image::operator=(const Image& other) {
	if (this != &other) {
		delete[] m_Pixels;

		m_Width = other.m_Width;
		m_Height = other.m_Height;
		m_Channels = other.m_Channels;
		m_Pixels = new uint8_t[m_Width * m_Height * 4];
		std::copy(other.m_Pixels, other.m_Pixels + m_Width * m_Height * 4, m_Pixels);
	}
	return *this;
}

const void limon::Image::SetPixel(const size_t x, const size_t y, const uint32_t color)const {
	//static_assert(!(x >= 0 && x < m_Width&& y >= 0 && y < m_Height), "Coordinates out of bounds.");
	//convert coordinates to index
	size_t index = (x + y * m_Width) * 4;

	//set pixel channels to given color 
	m_Pixels[index + 0] = color >> 24;
	m_Pixels[index + 1] = color >> 16;
	m_Pixels[index + 2] = color >> 8;
	m_Pixels[index + 3] = color >> 0;
	return;
}

const uint32_t limon::Image::GetPixel(const size_t x, const size_t y) const {
	//static_assert(!(x >= 0 && x < m_Width&& y >= 0 && y < m_Height), "Coordinates out of bounds.");

	//convert coordinates to index
	size_t index = (x + y * m_Width) * 4;

	uint32_t color;
	color = m_Pixels[index + 0] << 24;
	color += m_Pixels[index + 1] << 16;
	color += m_Pixels[index + 2] << 8;
	color += m_Pixels[index + 3] << 0;

	return color;
}