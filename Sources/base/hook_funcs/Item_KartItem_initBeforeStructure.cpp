#include <base/hooks.hpp>

#include <base/menu.hpp>
#include <MenuEntryHelpers.hpp>

#include <Item/KartItem.hpp>

namespace base
{
    void hook_funcs::Item_KartItem_initBeforeStructure(Item::KartItem *_this)
    {
        if (g_menu->m_item_wheel_entry->IsActivated())
            if (_this->isMaster() && !_this->isNetRecv())
                CTRPluginFramework::GetArg<menu::item_wheel_data_t>(g_menu->m_item_wheel_entry)->index = SIZE_MAX;

        g_hooks->m_Item_KartItem.get_original<decltype(&Item_KartItem_initBeforeStructure)>(hook_funcs::Item_KartItem_initBeforeStructure_index)(_this);
    }
}
