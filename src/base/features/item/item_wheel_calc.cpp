#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/menu_types.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>
#include <MenuEntryHelpers.hpp>

#include <Item/eItemSlot.hpp>
#include <Item/KartItem.hpp>

namespace base
{
	void features::item::item_wheel_calc(Item::KartItem *_this)
	{
		using namespace CTRPluginFramework;

        if (g_menu->m_item_wheel_entry->IsActivated() && _this->isMaster() && !_this->isNetRecv())
        {
            auto const data = GetArg<menu_types::item_wheel_data_t>(g_menu->m_item_wheel_entry);
            auto const &items = g_settings.m_options["item"]["item_wheel"]["items"].get<std::vector<Item::eItemSlot>>();

            // Cycle items with the D-Pad
            if (Controller::IsKeyPressed(Key::DPadLeft))
                data->index = (data->index == SIZE_MAX ? items.size() - 1 : data->index - 1);
            if (Controller::IsKeyPressed(Key::DPadRight))
                data->index = (data->index == items.size() - 1 ? SIZE_MAX : data->index + 1);
            
            // Check that the index is in range
            if (data->index < items.size())
            {
                auto const item = items[data->index];

                if (_this->m_item != item || _this->m_item_amount == 0)
                    g_pointers->m_Item_KartItem_setItemForce(_this, item);
            }
        }
	}
}