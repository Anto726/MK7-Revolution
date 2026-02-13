#include <base/features.hpp>

#include <base/menu.hpp>

#include <base/game/kart/director.hpp>
#include <base/game/kart/unit.hpp>

#include <Kart/Vehicle/Vehicle.hpp>

namespace base
{
    void features::mode::stalking(game::kart::unit *_this)
    {
        using namespace CTRPluginFramework;

        if (g_menu->m_stalking_entry->IsActivated() && _this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
        {
            auto const &units = static_cast<game::kart::director *>(_this->m_vehicle->m_director)->m_opponent_units;

            if (units.size() != 0)
            {
                _this->m_stalking.changed = false;

                if (Controller::IsKeyDown(Key::R))
                {
                    if (Controller::IsKeyPressed(Key::DPadLeft))
                    {
                        _this->m_stalking.index = (_this->m_stalking.index == -1 ? units.size() - 1 : _this->m_stalking.index - 1);
                        _this->m_stalking.changed = true;
                    }
                    if (Controller::IsKeyPressed(Key::DPadRight))
                    {
                        _this->m_stalking.index = (_this->m_stalking.index == units.size() - 1 ? -1 : _this->m_stalking.index + 1);
                        _this->m_stalking.changed = true;
                    }
                    if (Controller::IsKeyPressed(Key::DPadDown))
                    {
                        _this->m_stalking.index = -1;
                        _this->m_stalking.changed = true;
                    }
                }

                if (_this->m_stalking.index != -1)
                {
                    auto const &unit = units[_this->m_stalking.index];

                    *_this->m_vehicle->m_angle = *unit->m_vehicle->m_angle;
                    *_this->m_vehicle->m_position = *unit->m_vehicle->m_position;
                }
            }
        }
    }
}