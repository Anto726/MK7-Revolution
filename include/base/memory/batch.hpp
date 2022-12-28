#pragma once

#include "pattern.hpp"

#include <string>
#include <functional>
#include <vector>

namespace base::memory
{
	class batch
	{
	public:
		explicit batch() = default;
		~batch() noexcept = default;

		void add(std::string name, pattern pattern, std::function<void(handle)> callback);
		void run(range range);
	
		struct entry
		{
			std::string m_name;
			pattern m_pattern;
			std::function<void(handle)> m_callback;

			explicit entry(std::string name, pattern pattern, std::function<void(handle)> callback)
			:
				m_name(std::move(name)),
				m_pattern(std::move(pattern)),
				m_callback(std::move(callback))
			{}
		};
	
	private:
		std::vector<entry> m_entries;
	};
}