#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    bool hooks::Net_NetworkSystemInfo_onReceivedCore(Net::NetworkSystemInfo *_this, Net::NetworkReceivedInfo *info)
    {
        if (features::network::protections_system_info(info))
            return false; // Drop the received data

        return g_hooking->m_Net_NetworkSystemInfo_onReceivedCore_hook.call_original<bool>(_this, info);
    }
}