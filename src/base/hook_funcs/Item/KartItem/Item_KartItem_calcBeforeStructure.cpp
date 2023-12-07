#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
    void hook_funcs::Item_KartItem_calcBeforeStructure(Item::KartItem *_this)
    {
        features::item::item_wheel_calc(_this);

        g_hooks->m_Item_KartItem_hook.get_original<decltype(&Item_KartItem_calcBeforeStructure)>(hook_funcs::Item_KartItem_calcBeforeStructure_index)(_this);
    }
}