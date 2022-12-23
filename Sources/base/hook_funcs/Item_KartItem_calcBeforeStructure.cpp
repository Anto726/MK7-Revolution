#include <base/hooks.hpp>

#include <base/menu.hpp>
#include <MenuEntryHelpers.hpp>

#include <Item/ItemSlot.hpp>
#include <Item/KartItem.hpp>

namespace base
{
    void hook_funcs::Item_KartItem_calcBeforeStructure(Item::KartItem *_this)
    {
        using namespace CTRPluginFramework;

        if (g_menu->m_item_wheel_entry->IsActivated())
        {
            if (_this->isMaster() && !_this->isNetRecv())
            {
                auto item_wheel_data = GetArg<menu::item_wheel_data_t>(g_menu->m_item_wheel_entry);

                // Cycle items with the D-Pad
                if (Controller::IsKeyPressed(Key::DPadLeft))
                    item_wheel_data->index = (item_wheel_data->index == SIZE_MAX ? item_wheel_data->items.size() - 1 : item_wheel_data->index - 1);
                if (Controller::IsKeyPressed(Key::DPadRight))
                    item_wheel_data->index = (item_wheel_data->index == item_wheel_data->items.size() - 1 ? SIZE_MAX : item_wheel_data->index + 1);
                
                // Check that the index is in range
                if (item_wheel_data->index >= 0 && item_wheel_data->index < item_wheel_data->items.size())
                {
                    auto item = item_wheel_data->items[item_wheel_data->index];
                    auto item_slot = _this->m_item_slot;

                    if (item_slot->m_item != item)
                    {
                        // Need to be written regardless
                        item_slot->m_0x12 = 1;
                        item_slot->m_0x24 = 0;

                        if (item != ::Item::eItemSlot::Empty)
                        {
                            item_slot->m_0x11 = 0;
                            item_slot->m_0x10 = 1;
                            item_slot->m_frames_to_spin = 180;

                            item_slot->m_item = item;
                            item_slot->m_0x3C = 1.0f;

                            _this->_setStockItem(item_slot->m_item);
                        }
                        else
                        {
                            item_slot->m_0x11 = 3;
                            item_slot->m_0x10 = 0;
                            item_slot->m_frames_to_spin = -1;
                        }
                    }
                }
            }
        }

        g_hooks->m_Item_KartItem.get_original<decltype(&Item_KartItem_calcBeforeStructure)>(hook_funcs::Item_KartItem_calcBeforeStructure_index)(_this);
    }
}