#include <base/hook_types/naked_hook.hpp>

#include <base/logger.hpp>

#include <utility>

namespace base::hook_types
{
    using namespace CTRPluginFramework;
    
	naked_hook::naked_hook(std::string_view name, void *target, void *callback, u32 flags)
    :
		m_name(std::move(name)),
        m_hook(std::move(Hook().Initialize(reinterpret_cast<u32>(target), reinterpret_cast<u32>(callback)).SetFlags(flags)))
	{
        g_logger.debug("Naked hook '{}' created.", m_name);
	}

	naked_hook::~naked_hook()
	{
        g_logger.debug("Naked hook '{}' deleted.", m_name);
	}

	void naked_hook::enable()
	{
        if (auto result = m_hook.Enable(); result == HookResult::Success)
            g_logger.debug("Naked hook '{}' enabled.", m_name);
        else
        {
            g_logger.info("Failed to enable Naked hook '{}' at {} with result {}.", m_name, reinterpret_cast<void *>(m_hook.GetContext().callbackAddress), std::to_underlying(result));
            abort();
        }
	}

	void naked_hook::disable()
	{
        if (auto result = m_hook.Disable(); result == HookResult::Success)
            g_logger.debug("Naked hook '{}' disabled.", m_name);
        else
        {
            g_logger.info("Failed to disable Naked hook '{}' at {} with result {}.", m_name, reinterpret_cast<void *>(m_hook.GetContext().callbackAddress), std::to_underlying(result));
            abort();
        }
	}
}