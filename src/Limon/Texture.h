#pragma once
#include <cstdint>
#include "Image.h"
#include "Color.h"

namespace limon {
	class Texture {
	public:
		Color color;
	private:
		const Image* m_ImagePtr;
		uint32_t m_RendererID;
	public:
		Texture(const Image* img);
		~Texture();

		void Draw();
		void Send();

	public:
		const Image* GetImage() { return m_ImagePtr; }
	};
}