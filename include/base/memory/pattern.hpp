#pragma once

#include "fwddec.hpp"

#include <cstdint>
#include <string_view>
#include <vector>
#include <optional>

namespace base::memory
{
	class pattern
	{
		friend batch;
		friend range;

	public:
		pattern(std::string_view ida_sig);
		explicit pattern(const void *bytes, std::string_view mask);
		inline pattern(const char *ida_sig) : pattern(std::string_view(ida_sig)) { }

	private:
		std::vector<std::optional<std::uint8_t>> m_bytes;
	};
}