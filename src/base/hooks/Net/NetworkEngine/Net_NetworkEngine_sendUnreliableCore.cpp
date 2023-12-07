#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Net_NetworkEngine_sendUnreliableCore(Net::NetworkEngine *_this, u32 player_id, Net::NetworkBuffer *buf)
    {
        features::network::high_data_rate(&player_id);

        g_hooking->m_Net_NetworkEngine_sendUnreliableCore_hook.call_original<void>(_this, player_id, buf);
    }
}