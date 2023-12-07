#include <base/hook_types/detour_hook.hpp>

#include <base/logger.hpp>

namespace base::hook_types
{
    using namespace CTRPluginFramework;
    
	detour_hook::detour_hook(std::string name, void *target, void *detour)
    :
		m_name(std::move(name)),
        m_hook(std::move(Hook().InitializeForMitm(reinterpret_cast<u32>(target), reinterpret_cast<u32>(detour))))
	{
        g_logger.debug("Detour hook '{}' created.", m_name);
	}

	detour_hook::~detour_hook()
	{
        g_logger.debug("Detour hook '{}' deleted.", m_name);
	}

	void detour_hook::enable()
	{
        if (auto result = m_hook.Enable(); result == HookResult::Success)
            g_logger.debug("Detour hook '{}' enabled.", m_name);
        else
        {
            g_logger.info("Failed to enable Detour hook '{}' at {} with result {}.", m_name, reinterpret_cast<void *>(m_hook.GetContext().callbackAddress), fmt::underlying(result));
            abort();
        }
	}

	void detour_hook::disable()
	{
        if (auto result = m_hook.Disable(); result == HookResult::Success)
            g_logger.debug("Detour hook '{}' disabled.", m_name);
        else
        {
            g_logger.info("Failed to disable Detour hook '{}' at {} with result {}.", m_name, reinterpret_cast<void *>(m_hook.GetContext().callbackAddress), fmt::underlying(result));
            abort();
        }
	}
}