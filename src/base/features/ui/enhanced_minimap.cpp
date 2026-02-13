#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/Vehicle/Vehicle.hpp>
#include <UI/BgRaceMapCharaControl.hpp>

namespace base
{
    RaceSys::ERaceRuleMode features::ui::enhanced_minimap::battle_zoom(RaceSys::CRaceInfo *race_info)
    {
        if (g_menu->m_enhanced_minimap_entry->IsActivated())
        {
            auto const &enhanced_minimap = g_settings.m_options.ui.enhanced_minimap;

            switch (enhanced_minimap.battle_zoom)
            {
            case decltype(enhanced_minimap.battle_zoom)::Default:
                break;
            case decltype(enhanced_minimap.battle_zoom)::Enabled:
                return RaceSys::ERaceRuleMode::Battle;
            case decltype(enhanced_minimap.battle_zoom)::Disabled:
                return RaceSys::ERaceRuleMode::GrandPrix;
            }
        }

        return race_info->m_race_mode.m_rule_mode;
    }

    bool features::ui::enhanced_minimap::directed_heads(UI::BgRaceMapCharaControl *_this, Kart::Vehicle *vehicle)
    {
        if (g_menu->m_enhanced_minimap_entry->IsActivated() && g_settings.m_options.ui.enhanced_minimap.directed_heads)
            if (!vehicle->m_status_flags.accident_1)
                return true;

        return _this->m_killer_facing;
    }
}