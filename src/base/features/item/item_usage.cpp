#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/Vehicle/Vehicle.hpp>

namespace base
{
    s32 features::item::item_usage::dokan(Kart::Vehicle *_this)
    {
        using type = settings::options::item::item_usage::type;

        auto dokan_warp = _this->m_dokan_warp;

        if (g_menu->m_item_usage_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
        {
            if (g_settings.m_options.item.item_usage.toggles.at(type::Dokan))
                dokan_warp = 0xFF;
        }

        return dokan_warp;
    }

    bool features::item::item_usage::goal(Kart::Vehicle *_this)
    {
        using type = settings::options::item::item_usage::type;

        auto is_fake_goal = _this->m_is_fake_goal;

        if (g_menu->m_item_usage_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
        {
            if (g_settings.m_options.item.item_usage.toggles.at(type::Goal))
                is_fake_goal = false;
        }

        return is_fake_goal;
    }
    
    Kart::VehicleMove::StatusFlags features::item::item_usage::statuses(Kart::Vehicle *_this)
    {
        using type = settings::options::item::item_usage::type;

        auto status_flags = _this->m_status_flags;

        if (g_menu->m_item_usage_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
        {
            auto const &item_usage = g_settings.m_options.item.item_usage;

            if (item_usage.toggles.at(type::Accident))
                status_flags.accident_1 = false;

            if (item_usage.toggles.at(type::Recover))
                status_flags.jugem_recover = status_flags.jugem_recover_ai_oob = status_flags.battle_restart = false;

            if (item_usage.toggles.at(type::Vanish))
                status_flags.vanish_start = false;

            if (item_usage.toggles.at(type::Killer))
                status_flags.killer = false;
        }

        return status_flags;
    }
}