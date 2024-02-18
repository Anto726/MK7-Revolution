#include <base/features.hpp>

#include <base/menu.hpp>

#include <Item/ItemObj/ItemObjKouraR.hpp>

namespace base
{
    bool features::item::blue_shell_battle_crash_fix(Item::ItemObjKouraR *_this)
    {
        return g_menu->m_blue_shell_battle_crash_fix_entry->IsActivated() && _this->m_lap_rank_checker == nullptr;
    }
}