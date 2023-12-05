#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
    void hook_funcs::Net_NetworkEngine_sendUnreliableCore(Net::NetworkEngine *_this, u32 player_id, Net::NetworkBuffer *buf)
    {
        features::network::high_data_rate(&player_id);

        g_hooks->m_Net_NetworkEngine_sendUnreliableCore.call_original<void>(_this, player_id, buf);
    }
}