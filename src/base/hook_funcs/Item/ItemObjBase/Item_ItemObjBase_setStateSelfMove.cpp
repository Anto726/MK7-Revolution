#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
    void hook_funcs::Item_ItemObjBase_setStateSelfMove(Item::ItemObjBase *_this, sead::Vector2f *a2)
    {
        features::item::drop_items(_this);

        g_hooks->m_Item_ItemObjBase_setStateSelfMove.call_original<void>(_this, a2);
    }
}