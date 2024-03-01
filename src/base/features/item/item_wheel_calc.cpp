#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/menu_types.hpp>
#include <base/settings.hpp>
#include <MenuEntryHelpers.hpp>

#include <Item/eItemSlot.hpp>
#include <Item/ItemSlot.hpp>
#include <Item/KartItem.hpp>

#include <utility>

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
                // TODO: networking part; could probably use Item::KartItem::setItemForce instead
                auto const item = items[data->index];
                auto const item_value = std::to_underlying(item);
                auto const item_slot = _this->m_item_slot;

                if (item_slot->m_selected_item != item_value)
                {
                    // Write to these regardless
                    item_slot->m_0x24 = 0;
                    item_slot->m_spinning_frames = -1;

                    if (item != Item::eItemSlot::Empty)
                    {
                        item_slot->m_current_status = 3;

                        item_slot->m_selected_item = item_value;
                        item_slot->m_current_item = item_value;
                        item_slot->m_0x3C = 1.0f;

                        _this->_setStockItem(item);
                    }
                    else
                        item_slot->m_current_status = 0;
                }
            }
        }
	}
}