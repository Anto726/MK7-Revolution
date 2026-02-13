#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/game/kart/unit.hpp>

#include <Kart/Vehicle/Vehicle.hpp>

namespace base
{
    void features::kart::future_fly::calc(game::kart::unit *_this)
    {
        if (g_menu->m_future_fly_entry->IsActivated())
        {            
            if (auto const &veh = _this->m_vehicle; veh->m_is_master && !veh->m_is_net_recv)
            {
                auto const &future_fly = g_settings.m_options.kart.future_fly;

                veh->m_status_flags.ground_camera = true;

                // Stay frozen in place
                veh->m_forward_speed = 0.f;
                veh->m_velocity = sead::Vector3f::zero;

                // Allow yaw rotation
                veh->m_yaw_strength = veh->m_cpad_x * (!veh->m_controls.accelerate_backwards ? -future_fly.yaw_strength : future_fly.yaw_strength);

                // Allow pitch rotation
                auto const pitch = veh->m_cpad_y * future_fly.pitch_limit;
                veh->m_front_pitch = sead::Vector3f{ pitch * veh->m_angle->m_up.x, future_fly.pitch_keep ? pitch * veh->m_angle->m_up.y : veh->m_front_pitch.y, pitch * veh->m_angle->m_up.z };
                
                // Allow movement
                if (veh->m_controls.accelerate_forwards || veh->m_controls.accelerate_backwards)
                    *veh->m_position += veh->m_angle->m_up * (!veh->m_controls.accelerate_backwards ? future_fly.speed_forward : -future_fly.speed_backward);
            }
        }
    }

    bool features::kart::future_fly::velocity(Kart::Rigid *_this)
    {
        // TODO: unsafe as it invalidates the inheritance chain, but bail with it
        auto const vehicle = reinterpret_cast<Kart::VehicleBase *>(_this);

        return g_menu->m_future_fly_entry->IsActivated() && vehicle->m_is_master && !vehicle->m_is_net_recv;
    }
}