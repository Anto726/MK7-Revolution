#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjBase_calc(Item::ItemObjBase *_this)
    {
        g_hooking->m_Item_ItemObjBase_calc_hook.call_original<void>(_this);

        features::item::item_billboard::calc(_this);
    }
}