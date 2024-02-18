#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_KartItem_calcBeforeStructure(Item::KartItem *_this)
    {
        features::item::item_rain(_this);
        features::item::item_wheel_calc(_this);

        g_hooking->m_Item_KartItem_hook.get_original<decltype(&Item_KartItem_calcBeforeStructure)>(hooks::Item_KartItem_calcBeforeStructure_index)(_this);
    }
}