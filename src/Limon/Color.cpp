#include "Color.h"

namespace limon {
	Color::Color()
		: red(255)
		, green(255)
		, blue(255)
		, alpha(255) {}

	Color::Color(const uint32_t val) {
		Set32Bit(val);
	}

	Color::Color(const uint8_t red, const uint8_t green, const uint8_t blue)
		: red(red)
		, green(green)
		, blue(blue)
		, alpha(255) {}

	Color::Color(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha)
		: red(red)
		, green(green)
		, blue(blue)
		, alpha(alpha) {}


	void Color::Set(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha) {
		this->red = red;
		this->green = green;
		this->blue = blue;
		this->alpha = alpha;
	}

	void Color::Set32Bit(const uint32_t val) {
		red = val;
		green = val >> 8;
		blue = val >> 16;
		alpha = val >> 24;
	}

	uint32_t Color::Get32Bit()const {
		return red + (green << 8) + (blue << 16) + (alpha << 24);
	}

	Color& Color::operator= (const Color& other) {
		red = other.red;
		green = other.green;
		blue = other.blue;
		alpha = other.alpha;
		return *this;
	}

	bool Color::operator== (const Color& other) {
		return Get32Bit() == other.Get32Bit();
	}

	Color::operator uint32_t() const {
		return Get32Bit();
	}
}