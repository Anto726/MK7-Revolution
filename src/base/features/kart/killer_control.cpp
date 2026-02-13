#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Item/ItemObj/ItemObjKiller.hpp>
#include <Kart/InfoProxy.hpp>
#include <Kart/Vehicle/VehicleMove.hpp>

namespace base
{
    void features::kart::killer_control::move(Kart::VehicleMove *_this, float speed)
    {
        if (!g_menu->m_killer_control_entry->IsActivated() || (_this->m_is_master && !_this->m_is_net_recv && !_this->m_status_flags.killer))
            _this->m_forward_speed = speed;
    }

    void features::kart::killer_control::start(Kart::VehicleMove *_this, bool &controllable)
    {
        if (g_menu->m_killer_control_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
            controllable = true;
    }

    bool features::kart::killer_control::toggle(Item::ItemObjKiller *_this)
    {
        if (g_menu->m_killer_control_entry->IsActivated() && g_settings.m_options.kart.killer_control.toggle)
        {
            if (_this->m_info_proxy->isMaster() && !_this->m_info_proxy->isNetRecv() && _this->m_info_proxy->m_vehicle->m_status_flags.killer)
            {
                g_pointers->m_Kart_VehicleMove_endKiller(_this->m_info_proxy->m_vehicle);
                return true;
            }
        }

        return false;
    }
}