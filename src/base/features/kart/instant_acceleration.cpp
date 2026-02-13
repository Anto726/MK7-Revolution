#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/game/kart/unit.hpp>

#include <Kart/Vehicle/Vehicle.hpp>

namespace base
{
    void features::kart::instant_acceleration(game::kart::unit *_this)
    {
        if (g_menu->m_instant_acceleration_entry->IsActivated() && _this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
        {
            auto const &instant_acceleration = g_settings.m_options.kart.instant_acceleration;
            
            if (_this->m_vehicle->m_controls.accelerate_forwards && _this->m_vehicle->m_controls.accelerate_backwards)
            {
                _this->m_vehicle->m_forward_speed = {};
                _this->m_vehicle->m_boost_frames = {};
            }
            else if (!_this->m_vehicle->m_controls.accelerate_forwards && !_this->m_vehicle->m_controls.accelerate_backwards)
            {
                if (instant_acceleration.stop)
                {
                    _this->m_vehicle->m_forward_speed = {};
                    _this->m_vehicle->m_boost_frames = {};
                }
            }
            else
            {
                auto const speed = instant_acceleration.custom.enabled ? instant_acceleration.custom.value : _this->m_vehicle->m_speed_max_forward_land_base;

                if (_this->m_vehicle->m_controls.accelerate_forwards)
                    _this->m_vehicle->m_forward_speed = speed;
                if (_this->m_vehicle->m_controls.accelerate_backwards)
                    _this->m_vehicle->m_forward_speed = -speed;
            }
        }
    }
}