#include <base/hooks.hpp>
#include <base/features.hpp>

#include <Item/ItemDirector.hpp>

namespace base
{
    void hook_funcs::Item_ItemDirector_calcBeforeStructure(Item::ItemDirector *_this)
    {
        auto drive_during_countdown = features::mode::drive_during_countdown_before(_this->m_mode_manager_base);

        g_hooks->m_Item_ItemDirector_hook.get_original<decltype(&Item_ItemDirector_calcBeforeStructure)>(hook_funcs::Item_ItemDirector_calcBeforeStructure_index)(_this);

        features::mode::drive_during_countdown_after(_this->m_mode_manager_base, drive_during_countdown);
    }
}