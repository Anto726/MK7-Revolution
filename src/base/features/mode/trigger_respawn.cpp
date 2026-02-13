#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

#include <base/game/kart/unit.hpp>

#include <Kart/Vehicle/Vehicle.hpp>

namespace base
{
    void features::mode::trigger_respawn(game::kart::unit *_this)
    {
        using namespace CTRPluginFramework;

        if (g_menu->m_trigger_respawn_entry->IsActivated() && _this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
            if (Controller::IsKeysDown(Key::Start | Key::R | Key::L))
                g_pointers->m_Kart_Unit_startJugemRecover(_this, Kart::EJugemRecoverType::Default);
    }
}