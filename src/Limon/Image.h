#pragma once

#include <string>
#include <iostream>

#include "Raster.h"

namespace limon {
	/// <summary>
	/// This class represents textures that can be modified in CPU side.
	/// </summary>
	class Image : public IRaster {
	private:
		size_t m_Width = 0;
		size_t m_Height = 0;
		size_t m_Channels = 0;
		uint8_t* m_Pixels = nullptr;

	public:
		/// <summary>
		/// Creates and allocates image. The size of the image is determined by width and height params.
		/// </summary>
		/// <param name="width">: the width of the image.</param>
		/// <param name="height">: the height of the image.</param>
		Image(const size_t width, const size_t height);

		/// <summary>
		/// Creates image with given data.
		/// </summary>
		/// <param name="width">: the width of the assigned pixel array.</param>
		/// <param name="height">: the height of the assigned pixel array.</param>
		/// <param name="channels">: the channels of the color in pixel array.</param>
		/// <param name="pixels">: the pixel array to assign.</param>
		Image(const size_t width, const size_t height, const size_t channels, uint8_t* pixels);
		~Image();

	public:
		Image(const Image& other);
		Image& operator=(const Image& other);

	public:
		/// <summary>
		/// Sets the color of the pixel in given coordinates. This function will not check if the given position is out of bounds of the image.
		/// </summary>
		/// <param name="x">: the x axis value of the coordinate.</param>
		/// <param name="y">: the y axis value of the coordinate.</param>
		/// <param name="color">: the color to replace.</param>
		const void SetPixel(const size_t x, const size_t y, const uint32_t color)const override;

		/// <summary>
		/// Retrieves the color of the pixel in given coordinates. This function will not check if the given position is out of bounds of the image.
		/// </summary>
		/// <param name="x">: the x axis value of the coordinate.</param>
		/// <param name="y">: the y axis value of the coordinate.</param>
		/// <returns>the color of the pixel.</returns>
		const uint32_t GetPixel(const size_t x, const size_t y)const override;

	public:

		///<returns> True if the image is allocated otherwise false.</returns>
		const bool IsAllocated() const { return m_Pixels != nullptr; }

		///<returns> The width of the image or 0 if image is not allocated.</returns>
		const size_t GetWidth()const override { return m_Width; }

		///<returns> The height of the image or 0 if image is not allocated.</returns>
		const size_t GetHeight()const override { return m_Height; }

		///<returns> The number of color channels per pixel.</returns>
		const size_t GetChannels() const { return m_Channels; }

		///<returns> The color array of the image.</returns>
		const uint8_t* GetPixels()const { return m_Pixels; }
	};
}