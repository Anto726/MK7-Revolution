#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/menu_types.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>
#include <MenuEntryHelpers.hpp>

#include <Item/eItemType.hpp>
#include <Item/KartItem.hpp>
#include <Kart/Director.hpp>
#include <Kart/Unit.hpp>
#include <Object/CharacterEngine.hpp>
#include <System/RootScene.hpp>
#include <System/RootSystem.hpp>
#include <System/SceneManager.hpp>

#include <math/seadVector.h>

namespace base
{
    void features::item::item_rain(Item::KartItem *_this)
    {
        if (g_menu->m_item_rain_entry->IsActivated() && _this->isMaster() && !_this->isNetRecv())
        {
            auto const data = GetArg<menu_types::item_rain_data_t>(g_menu->m_item_rain_entry);
            auto const &settings = g_settings.m_options["item"]["item_rain"];

            // Check that <delay> frames have passed
            if (++data->count > settings["delay"].get<u64>())
            {
                data->count = 0;

                auto const units = reinterpret_cast<Object::CharacterEngine *>(g_pointers->m_root_system->m_scene_manager->m_root_scene->get_engine(Object::EEngineType::Character))->m_collection->m_kart_director->m_units;

                // Lambda to spawn a randomized item
                auto const spawn_item = [_this, data, settings](auto const unit)
                {
                    // Choose one of the items
                    if (auto const &items = settings["items"].get<std::vector<Item::eItemType>>(); !items.empty())
                    {
                        auto const player_id = settings["owned"] ? _this->m_info_proxy->m_vehicle->m_player_id : unit->m_vehicle->m_player_id;

                        // Choose a random item
                        auto const item = items[(*g_pointers->m_random)->getU32(items.size())];

                        // Generate a random position
                        auto const height = settings["height"].get<double>();
                        auto const width = settings["width"].get<double>();
                        auto const offset = settings["speed"]["status"] ? (unit->m_vehicle->m_up * unit->m_vehicle->m_forward_speed * settings["speed"]["value"].get<double>()) : sead::Vector3f::zero;
                        auto const position = *unit->m_vehicle->m_position + offset + sead::Vector3f((*g_pointers->m_random)->getF32Range(-width, width), height, (*g_pointers->m_random)->getF32Range(-width, width));

                        // Set velocity to (0, -1, 0) so that items won't pop up before falling down
                        auto const velocity = -sead::Vector3f::ey;

                        utils::emit_item(player_id, item, position, velocity);
                    }
                };

                if (settings["multi"])
                {
                    for (auto const &unit : units)
                        spawn_item(unit);
                }
                else
                {
                    auto const &unit = units[(*g_pointers->m_random)->getU32(units.size())];
                    spawn_item(unit);
                }
            }
        }
    }
}