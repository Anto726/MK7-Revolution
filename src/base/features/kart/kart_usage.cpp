#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/Vehicle/Vehicle.hpp>

namespace base
{
    Kart::VehicleMove::StatusFlags features::kart::kart_usage(Kart::Vehicle *_this)
    {
        using type = settings::options::kart::kart_usage::type;

        auto status_flags = _this->m_status_flags;

        if (g_menu->m_kart_usage_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
        {
            auto const &kart_usage = g_settings.m_options.kart.kart_usage;

            if (kart_usage.toggles.at(type::Accident))
                status_flags.accident_1 = status_flags.accident_2 = false;
        }

        return status_flags;
    }
}