#pragma once

namespace limon {
	/// <summary>
	/// This interface represents readable-writable raster image.
	/// </summary>
	class IRaster {
	public:
		virtual ~IRaster() = default;

	public:
		/// <returns>The width of the raster.</returns>
		virtual const size_t GetWidth()const = 0;

		/// <returns>The height of the raster.</returns>
		virtual const size_t GetHeight()const = 0;

		/// <summary>
		/// Sets the color of the pixel in given coordinates.
		/// </summary>
		/// <param name="x">: the x axis value of the coordinate.</param>
		/// <param name="y">: the y axis value of the coordinate.</param>
		/// <param name="color">: the color to replace.</param>
		virtual const void SetPixel(const size_t x, const size_t y, const uint32_t color)const = 0;

		/// <summary>
		/// Retrieves the color of the pixel in given coordinates.
		/// </summary>
		/// <param name="x">: the x axis value of the coordinate.</param>
		/// <param name="y">: the y axis value of the coordinate.</param>
		/// <returns>the color of the pixel.</returns>
		virtual const uint32_t GetPixel(const size_t x, const size_t y)const = 0;
	};
}