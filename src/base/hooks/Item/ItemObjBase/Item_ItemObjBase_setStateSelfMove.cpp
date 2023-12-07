#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjBase_setStateSelfMove(Item::ItemObjBase *_this, sead::Vector2f *a2)
    {
        features::item::drop_items(_this);

        g_hooking->m_Item_ItemObjBase_setStateSelfMove_hook.call_original<void>(_this, a2);
    }
}