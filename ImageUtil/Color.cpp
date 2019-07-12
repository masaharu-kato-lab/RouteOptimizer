#include "Color.h"
using namespace ro::iu;

Color::Color() noexcept = default;

Color::Color(Level r, Level g, Level b, Level a) noexcept
	: value((((((a << 8) | r) << 8) | g) << 8) | b)
//	: value((uint32_t)a * 16777216 + (uint32_t)r * 65536 + (uint32_t)g * 256 + (uint32_t)b)
//	: value(r * 65536 + g * 256 + b)
{}

auto Color::getR() const noexcept -> Level {
	return value & 0xFF;
}

auto Color::getG() const noexcept -> Level {
	return value >> 8 & 0xFF;
}

auto Color::getB() const noexcept -> Level {
	return value >> 16 & 0xFF;
}

auto Color::getA() const noexcept -> Level {
	return value >> 24 & 0xFF;
}