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
            auto const settings = g_settings.m_options["item"]["item_rain"];

            // Check that <delay> frames have passed
            if (!data->items.empty() && ++data->count > settings["delay"].get<u64>())
            {
                data->count = 0;

                auto const units = reinterpret_cast<Object::CharacterEngine *>(g_pointers->m_root_system->m_scene_manager->m_root_scene->get_engine(Object::EEngineType::Character))->m_collection->m_kart_director->m_units;
                
                // Lambda to spawn a randomized item
                auto const spawn_item = [data, settings](auto const unit)
                {
                    // Randomly choose one of the items
                    auto const item = data->items[g_pointers->m_random->getU32(data->items.size())];

                    // Randomly generate a horizontal offset
                    auto const height = settings["height"].get<double>();
                    auto const width = settings["width"].get<double>();
                    auto const position = *unit->m_vehicle->m_position + sead::Vector3f(g_pointers->m_random->getF32Range(-width, width), height, g_pointers->m_random->getF32Range(-width, width));

                    // Sets velocity to (0, -1, 0), that way items don't pop up before falling down
                    utils::emit_item(unit, item, position, -sead::Vector3f::ey);
                };

                if (settings["multi"])
                {
                    for (auto const &unit : units)
                        spawn_item(unit);
                }
                else
                {
                    auto const unit = units.getBufferPtr()[g_pointers->m_random->getU32(units.size())];
                    spawn_item(unit);
                }
            }
        }
    }
}