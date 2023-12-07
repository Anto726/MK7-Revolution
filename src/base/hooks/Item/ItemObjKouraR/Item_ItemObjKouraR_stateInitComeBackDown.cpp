#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjKouraR_stateInitComeBackDown(Item::ItemObjKouraR *_this)
    {
        if (features::item::blue_shell_battle_crash_fix(_this))
            return;

        g_hooking->m_Item_ItemObjKouraR_stateInitComeBackDown_hook.call_original<void>(_this);
    }
}