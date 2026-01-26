#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <base/game/item/kart_item.hpp>
#include <base/game/kart/unit.hpp>

#include <Item/KartItemProxy.hpp>

namespace base
{
    UI::RaceItemBoxControl::Animation features::item::item_wheel::anim(Item::KartItemProxy *kart_item_proxy)
    {
        if (g_menu->m_item_wheel_entry->IsActivated() && static_cast<game::item::kart_item *>(kart_item_proxy->m_kart_item)->m_item_wheel.index != SIZE_MAX)
        {
            auto const &item_wheel = g_settings.m_options.item.item_wheel;

            switch (item_wheel.decide_anim)
            {
            case decltype(item_wheel.decide_anim)::Default:
                break;
            case decltype(item_wheel.decide_anim)::None:
                return UI::RaceItemBoxControl::Animation_None;
            case decltype(item_wheel.decide_anim)::Use:
                return UI::RaceItemBoxControl::Animation_Use;
            }
        }

        return UI::RaceItemBoxControl::Animation_Receive;
    }

	void features::item::item_wheel::calc(game::item::kart_item *_this)
	{
		using namespace CTRPluginFramework;

        if (g_menu->m_item_wheel_entry->IsActivated() && _this->isMaster() && !_this->isNetRecv())
        {
            auto const &item_wheel = g_settings.m_options.item.item_wheel;

            if (!item_wheel.items.empty())
            {
                if (item_wheel.cycler.enabled)
                {
                    if (++_this->m_item_wheel.count > item_wheel.cycler.delay)
                    {
                        _this->m_item_wheel.count = 0;
                        _this->m_item_wheel.index = utils::random_u32(item_wheel.items.size());
                    }
                }
                else
                {
                    // Don't switch items when changing Stalking target on the same frame
                    auto const &unit = static_cast<game::kart::unit *>(_this->m_info_proxy->m_vehicle->m_director->m_units[_this->m_player_id]);

                    if (!unit->m_stalking.changed)
                    {
                        if (Controller::IsKeyPressed(Key::DPadLeft))
                            _this->m_item_wheel.index = (_this->m_item_wheel.index == SIZE_MAX ? item_wheel.items.size() - 1 : _this->m_item_wheel.index - 1);
                        if (Controller::IsKeyPressed(Key::DPadRight))
                            _this->m_item_wheel.index = (_this->m_item_wheel.index == item_wheel.items.size() - 1 ? SIZE_MAX : _this->m_item_wheel.index + 1);
                        if (Controller::IsKeyPressed(Key::DPadDown))
                            _this->m_item_wheel.index = SIZE_MAX;
                    }
                }

                if (_this->m_item_wheel.index < item_wheel.items.size())
                {
                    auto const item = *std::next(item_wheel.items.begin(), _this->m_item_wheel.index);

                    if (_this->m_stock_item != item || _this->m_stock_item_amount == 0)
                        g_pointers->m_Item_KartItem_setItemForce(_this, item);
                }
            }
        }
	}

    RaceSys::ERaceRuleMode features::item::item_wheel::sound(RaceSys::CRaceInfo *race_info, Item::KartItemProxy *kart_item_proxy)
    {
        if (g_menu->m_item_wheel_entry->IsActivated() && static_cast<game::item::kart_item *>(kart_item_proxy->m_kart_item)->m_item_wheel.index != SIZE_MAX)
        {
            auto const &item_wheel = g_settings.m_options.item.item_wheel;

            switch (item_wheel.decide_sound)
            {
            case decltype(item_wheel.decide_sound)::Default:
                break;
            case decltype(item_wheel.decide_sound)::Enabled:
                return RaceSys::ERaceRuleMode::GrandPrix;
            case decltype(item_wheel.decide_sound)::Disabled:
                return RaceSys::ERaceRuleMode::TimeTrials;
            }
        }

        return race_info->m_race_mode.m_rule_mode;
    }
}