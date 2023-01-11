#include <base/hooking/vmt_hook.hpp>

#include <base/logger.hpp>

namespace base::hooking
{
	using namespace CTRPluginFramework;
	
    vmt_hook::vmt_hook(std::string name, void *obj, size_t num_funcs)
    :
		m_name(std::move(name)),
		m_object(static_cast<void ***>(obj)),
		m_num_funcs(num_funcs + 1),
		m_original_table(*m_object),
		m_new_table(std::make_unique<void *[]>(m_num_funcs))
	{
		std::copy_n(m_original_table - 1, m_num_funcs, m_new_table.get());

		g_logger->log_debug(Utils::Format("VMT hook '%s' created.", m_name.c_str()));
	}

	vmt_hook::~vmt_hook()
	{
        g_logger->log_debug(Utils::Format("VMT hook '%s' deleted.", m_name.c_str()));
	}

	void vmt_hook::hook(size_t index, void *func)
	{
		m_new_table[index + 1] = func;

		g_logger->log_debug(Utils::Format("VMT hook member '%s[%zu]' hooked.", m_name.c_str(), index));
	}

	void vmt_hook::unhook(size_t index)
	{
		m_new_table[index + 1] = m_original_table[index];

		g_logger->log_debug(Utils::Format("VMT hook member '%s[%zu]' unhooked.", m_name.c_str(), index));
	}

	void vmt_hook::enable()
	{
		*m_object = m_new_table.get() + 1;

		g_logger->log_debug(Utils::Format("VMT hook '%s' enabled.", m_name.c_str()));
	}

	void vmt_hook::disable()
	{
		*m_object = m_original_table;

		g_logger->log_debug(Utils::Format("VMT hook '%s' disabled.", m_name.c_str()));
	}
}