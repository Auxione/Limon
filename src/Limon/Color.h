#pragma once
#include <cstdint>

namespace limon {
	/// <summary>
	/// This struct represents 32 bit colors. It uses RGBA order to store color value.
	/// </summary>
	struct Color {
	public:
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;

	public:
		/// <summary>
		/// Creates new white color. (255, 255, 255, 255)
		/// </summary>
		Color();

		/// <summary>
		/// Creates new color from given uint32_t color.
		/// </summary>
		/// <param name="val">: the uint32_t color.</param>
		Color(const uint32_t val);

		/// <summary>
		/// Creates new color value from given params. The alpha channel of the color will be 255.
		/// </summary>
		/// <param name="red">:	red channel of the color.</param>
		/// <param name="green">: green channel of the color.</param>
		/// <param name="blue">: blue channel of the color.</param>
		Color(const uint8_t red, const uint8_t green, const uint8_t blue);

		/// <summary>
		/// Creates new color value from given params.
		/// </summary>
		/// <param name="red">:	red channel of the color.</param>
		/// <param name="green">: green channel of the color.</param>
		/// <param name="blue">: blue channel of the color.</param>
		/// <param name="alpha">: alpha channel of the color.</param>
		Color(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha);

	public:
		void Set(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha);
		void Set32Bit(const uint32_t val);
		uint32_t Get32Bit()const;

	public:
		bool operator== (const Color& other);
		Color& operator= (const Color& other);
		operator uint32_t() const;
	};
}