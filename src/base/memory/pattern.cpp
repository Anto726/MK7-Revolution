#include <base/memory/pattern.hpp>

namespace base::memory
{
	pattern::pattern(std::string_view ida_sig)
	{
		auto to_hex = [](char c) -> std::optional<std::uint8_t>
		{
			switch (c)
			{
				case '0': return static_cast<std::uint8_t>(0);
				case '1': return static_cast<std::uint8_t>(1);
				case '2': return static_cast<std::uint8_t>(2);
				case '3': return static_cast<std::uint8_t>(3);
				case '4': return static_cast<std::uint8_t>(4);
				case '5': return static_cast<std::uint8_t>(5);
				case '6': return static_cast<std::uint8_t>(6);
				case '7': return static_cast<std::uint8_t>(7);
				case '8': return static_cast<std::uint8_t>(8);
				case '9': return static_cast<std::uint8_t>(9);
				case 'a': case 'A': return static_cast<std::uint8_t>(10);
				case 'b': case 'B': return static_cast<std::uint8_t>(11);
				case 'c': case 'C': return static_cast<std::uint8_t>(12);
				case 'd': case 'D': return static_cast<std::uint8_t>(13);
				case 'e': case 'E': return static_cast<std::uint8_t>(14);
				case 'f': case 'F': return static_cast<std::uint8_t>(15);
				default: return std::nullopt;
			}
		};

		for (std::size_t i = 0; i < ida_sig.size(); ++i)
		{
			if (ida_sig[i] == ' ')
				continue;

			if (ida_sig[i] != '?')
			{
				if (i != ida_sig.size() - 1)
					if (auto c1 = to_hex(ida_sig[i]), c2 = to_hex(ida_sig[i + 1]); c1 != std::nullopt && c2 != std::nullopt)
						m_bytes.emplace_back(static_cast<std::uint8_t>((*c1 * 0x10) + *c2));
			}
			else
				m_bytes.push_back(std::nullopt);
		}
	}

	pattern::pattern(const void *bytes, std::string_view mask)
	{
		for (std::size_t i = 0; i < mask.size(); ++i)
		{
			if (mask[i] != '?')
				m_bytes.emplace_back(static_cast<std::uint8_t const *>(bytes)[i]);
			else
				m_bytes.push_back(std::nullopt);
		}
	}
}
