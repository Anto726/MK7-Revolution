#include <base/features.hpp>

#include <base/menu.hpp>

#include <Item/ItemObjBase.hpp>
#include <Kart/InfoProxy.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
    void features::item::drop_items(Item::ItemObjBase *_this)
    {
        if (g_menu->m_drop_items_entry->IsActivated() && _this->m_info_proxy->m_vehicle->m_is_master && !_this->m_info_proxy->m_vehicle->m_is_net_recv)
            _this->m_is_dropped = true;
    }
}