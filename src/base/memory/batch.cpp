#include <base/memory/batch.hpp>

#include <base/memory/range.hpp>
#include <base/logger.hpp>

namespace base::memory
{
	void batch::add(std::string name, pattern pattern, std::function<void (handle)> callback)
	{
		m_entries.emplace_back(std::move(name), std::move(pattern), std::move(callback));
	}

	void batch::run(range range)
	{
		bool all_found = true;

		for (auto const &e : m_entries)
		{
			if (auto handle = range.scan(e.m_pattern))
			{
				if (e.m_callback)
				{
					std::invoke(std::move(e.m_callback), handle);
					g_logger.log_debug("Batch entry '{}' ({}) found.", e.m_name, handle.as<void *>());
					
					continue;
				}
			}

			all_found = false;
			g_logger.log("Failed to find batch entry '{}'.", e.m_name);
		}

		m_entries.clear();

		if (!all_found)
			abort();
	}
}
