#include <base/memory/batch.hpp>

#include <base/logger.hpp>

namespace base::memory
{
	void batch::add(std::string name, pattern pattern, std::function<void (handle)> callback)
	{
		m_entries.emplace_back(std::move(name), std::move(pattern), std::move(callback));
	}

	void batch::run(range range)
	{
		bool failed = false;

		std::vector<task_arg> task_args;
		std::vector<CTRPluginFramework::Task> tasks;

		task_args.reserve(m_entries.size());
		tasks.reserve(task_args.size());

		for (auto const &entry : m_entries)
		{
			task_args.emplace_back(range, entry);
			tasks.emplace_back(task_func, &task_args.back());
		}

		for (auto const &task : tasks)
			task.Start();

		for (auto const &task : tasks)
			failed |= task.Wait();

		m_entries.clear();

		if (failed)
			abort();
	}

	s32 batch::task_func(void *p)
	{
		auto arg = static_cast<task_arg *>(p);

		if (auto handle = arg->m_range.scan(arg->m_entry.m_pattern))
		{
			if (arg->m_entry.m_callback)
			{
				std::invoke(std::move(arg->m_entry.m_callback), handle);

				g_logger.debug("Batch entry '{}' ({}) found.", arg->m_entry.m_name, handle.as<void *>());
				return EXIT_SUCCESS;
			}
		}

		g_logger.info("Failed to find batch entry '{}'.", arg->m_entry.m_name);
		return EXIT_FAILURE;
	}
}