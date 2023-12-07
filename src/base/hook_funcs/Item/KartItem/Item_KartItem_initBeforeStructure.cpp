#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
    void hook_funcs::Item_KartItem_initBeforeStructure(Item::KartItem *_this)
    {
        features::item::item_wheel_init(_this);

        g_hooks->m_Item_KartItem_hook.get_original<decltype(&Item_KartItem_initBeforeStructure)>(hook_funcs::Item_KartItem_initBeforeStructure_index)(_this);
    }
}
