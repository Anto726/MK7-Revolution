#include <base/memory/batch.hpp>

#include <base/memory/range.hpp>
#include <base/logger.hpp>

namespace base::memory
{
	void batch::add(std::string name, pattern pattern, std::function<void(handle)> callback)
	{
		m_entries.emplace_back(std::move(name), std::move(pattern), std::move(callback));
	}

	void batch::run(range range)
	{
		using namespace CTRPluginFramework;

		bool all_found = true;

		for (auto const &e : m_entries)
		{
			if (auto result = range.scan(e.m_pattern))
			{
				if (e.m_callback)
				{
					std::invoke(std::move(e.m_callback), result);
					g_logger->log_now(Utils::Format("Found '%s' (0x%X).", e.m_name.c_str(), &result.as<u32 &>()));
					
					continue;
				}
			}

			all_found = false;
			g_logger->log_now(Utils::Format("Failed to find '%s'.", e.m_name.c_str()));
		}

		m_entries.clear();

		if (!all_found)
		{
			g_logger->log_now("Failed to find some patterns. Aborting.");
			abort();
		}
	}
}
