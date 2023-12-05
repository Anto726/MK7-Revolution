#include <base/features.hpp>

#include <base/menu.hpp>

#include <limits>

namespace base
{
    void features::network::high_data_rate(u32 *player_id)
    {
        if (g_menu->m_high_data_rate_entry->IsActivated())
            *player_id = std::numeric_limits<std::remove_pointer_t<decltype(player_id)>>::max();
    }
}