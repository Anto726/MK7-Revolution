#pragma once

#include "pattern.hpp"
#include "range.hpp"

#include <functional>

#include <CTRPluginFramework.hpp>

namespace base::memory
{
	class batch
	{
	public:
		explicit batch() = default;
		~batch() = default;

		void add(std::string name, pattern pattern, std::function<void (handle)> callback);
		void run(range range);

	private:
		struct entry
		{
			std::string m_name;
			pattern m_pattern;
			std::function<void (handle)> m_callback;
		};
		
		struct task_arg
		{
			range m_range;
			entry m_entry;
		};

		static s32 task_func(void *);

		std::vector<entry> m_entries;
	};
}