#pragma once
#include <cstdint>

namespace ro::iu {

	//	êFÉNÉâÉX
	class /*alignas(4)*/ Color {
	public:
		using Level = unsigned __int8;

		Color() noexcept;
		Color(Level r, Level g, Level b, Level a = 255) noexcept;

		Level getR() const noexcept;
		Level getG() const noexcept;
		Level getB() const noexcept;
		Level getA() const noexcept;

	private:
		uint32_t value;
	};

}