#include <base/hooking/detour_hook.hpp>

#include <base/logger.hpp>

namespace base::hooking
{
    using namespace CTRPluginFramework;
    
	detour_hook::detour_hook(std::string name, void *target, void *detour)
    :
		m_name(std::move(name)),
        m_hook(std::move(Hook().InitializeForMitm(reinterpret_cast<u32>(target), reinterpret_cast<u32>(detour))))
	{
        g_logger->log_debug(Utils::Format("Detour hook '%s' created.", m_name.c_str()));
	}

	detour_hook::~detour_hook()
	{
        g_logger->log_debug(Utils::Format("Detour hook '%s' deleted.", m_name.c_str()));
	}

	void detour_hook::enable()
	{
        if (auto result = m_hook.Enable(); result == HookResult::Success)
            g_logger->log_debug(Utils::Format("Detour hook '%s' enabled.", m_name.c_str()));
        else
        {
            g_logger->log(Utils::Format("Failed to enable Detour hook '%s' at 0x%X (result: %u).", m_name.c_str(), m_hook.GetContext().callbackAddress, result));
            abort();
        }
	}

	void detour_hook::disable()
	{
        if (auto result = m_hook.Disable(); result == HookResult::Success)
            g_logger->log_debug(Utils::Format("Detour hook '%s' disabled.", m_name.c_str()));
        else
        {
            g_logger->log(Utils::Format("Failed to disable Detour hook '%s' at 0x%X (result: %u).", m_name.c_str(), m_hook.GetContext().callbackAddress, result));
            abort();
        }
	}
}