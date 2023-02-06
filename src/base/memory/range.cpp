#include <base/memory/range.hpp>

#include <base/memory/pattern.hpp>

#include <limits>

namespace base::memory
{
	range::range(handle base, std::size_t size) : m_base(base), m_size(size) {}

	handle range::begin()
	{
		return m_base;
	}

	handle range::end()
	{
		return m_base.add(m_size);
	}

	std::size_t range::size()
	{
		return m_size;
	}

	bool range::contains(handle h)
	{
		return h.as<std::uintptr_t>() >= begin().as<std::uintptr_t>() && h.as<std::uintptr_t>() <= end().as<std::uintptr_t>();
	}

	static handle boyer_moore_horspool(std::optional<std::uint8_t> const *data, std::size_t data_length, handle base, std::size_t base_size)
	{
		auto shift_max = data_length, index_max = data_length - 1, index_wildcard = std::numeric_limits<std::size_t>::max();
		std::size_t shift_table[std::numeric_limits<std::uint8_t>::max() + 1];

		for (auto i = index_max - 1; i >= 0; --i)
			if (!data[i])
			{
				shift_max = index_max - i;
				index_wildcard = i;
				break;
			}

		for (auto &e : shift_table)
			e = shift_max;

		for (auto i = index_wildcard + 1; i < index_max; ++i)
			shift_table[*data[i]] = index_max - i;

		for (std::size_t index_cur = 0; index_cur <= base_size - data_length;)
			for (auto index_sig = index_max; index_sig >= 0; --index_sig)
			{
				if (data[index_sig] && *data[index_sig] != base.add(index_cur + index_sig).as<std::uint8_t &>())
				{
					index_cur += shift_table[base.add(index_cur + index_max).as<std::uint8_t &>()];
					break;
				}
				
				if (index_sig == 0)
					return base.add(index_cur);
			}

		return nullptr;
	}

	handle range::scan(pattern const &sig)
	{
		auto data = sig.m_bytes.data();
		auto length = sig.m_bytes.size();

		return boyer_moore_horspool(data, length, m_base, m_size);
	}
}
