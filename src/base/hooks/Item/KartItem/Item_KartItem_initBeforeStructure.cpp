#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_KartItem_initBeforeStructure(Item::KartItem *_this)
    {
        features::item::item_wheel_init(_this);

        g_hooking->m_Item_KartItem_hook.get_original<decltype(&Item_KartItem_initBeforeStructure)>(hooks::Director_initBeforeStructure_index)(_this);
    }
}
