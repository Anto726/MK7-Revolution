#include <base/hooking/detour_hook.hpp>

#include <base/logger.hpp>

#include <utility>

namespace base::hooking
{
    using namespace CTRPluginFramework;
    
	detour_hook::detour_hook(std::string name, void *target, void *detour)
    :
		m_name(std::move(name)),
        m_hook(std::move(Hook().InitializeForMitm(reinterpret_cast<u32>(target), reinterpret_cast<u32>(detour))))
	{
        g_logger.log_debug("Detour hook '{}' created.", m_name);
	}

	detour_hook::~detour_hook()
	{
        g_logger.log_debug("Detour hook '{}' deleted.", m_name);
	}

	void detour_hook::enable()
	{
        if (auto result = m_hook.Enable(); result == HookResult::Success)
            g_logger.log_debug("Detour hook '{}' enabled.", m_name);
        else
        {
            g_logger.log("Failed to enable Detour hook '{}' at {} with result {}.", m_name, reinterpret_cast<void *>(m_hook.GetContext().callbackAddress), std::to_underlying(result));
            abort();
        }
	}

	void detour_hook::disable()
	{
        if (auto result = m_hook.Disable(); result == HookResult::Success)
            g_logger.log_debug("Detour hook '{}' disabled.", m_name);
        else
        {
            g_logger.log("Failed to disable Detour hook '{}' at {} with result {}.", m_name, reinterpret_cast<void *>(m_hook.GetContext().callbackAddress), std::to_underlying(result));
            abort();
        }
	}
}