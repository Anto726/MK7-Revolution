#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/menu_types.hpp>
#include <MenuEntryHelpers.hpp>

#include <Item/ItemSlot.hpp>
#include <Item/KartItem.hpp>

namespace base
{
	void features::item::item_wheel_calc(Item::KartItem *_this)
	{
		using namespace CTRPluginFramework;

        if (g_menu->m_item_wheel_entry->IsActivated())
        {
            if (_this->isMaster() && !_this->isNetRecv())
            {
                auto item_wheel_data = GetArg<menu_types::item_wheel_data_t>(g_menu->m_item_wheel_entry);

                // Cycle items with the D-Pad
                if (Controller::IsKeyPressed(Key::DPadLeft))
                    item_wheel_data->index = (item_wheel_data->index == SIZE_MAX ? item_wheel_data->items.size() - 1 : item_wheel_data->index - 1);
                if (Controller::IsKeyPressed(Key::DPadRight))
                    item_wheel_data->index = (item_wheel_data->index == item_wheel_data->items.size() - 1 ? SIZE_MAX : item_wheel_data->index + 1);
                
                // Check that the index is in range
                if (item_wheel_data->index < item_wheel_data->items.size())
                {
                    auto item = item_wheel_data->items[item_wheel_data->index];
                    auto item_value = std::underlying_type_t<Item::eItemSlot>(item);
                    auto item_slot = _this->m_item_slot;

                    if (item_slot->m_selected_item != item_value)
                    {
                        // Need to be written regardless
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
}