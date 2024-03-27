#include <base/hooking.hpp>
#include <base/features.hpp>

#include <Item/ItemDirector.hpp>

namespace base
{
    void hooks::Item_ItemDirector_calcBeforeStructure(Item::ItemDirector *_this)
    {
        auto drive_during_sync = features::mode::drive_during_sync_before(_this->m_mode_manager_base);

        g_hooking->m_Item_ItemDirector_hook.get_original<decltype(&Item_ItemDirector_calcBeforeStructure)>(hooks::Director_calcBeforeStructure_index)(_this);

        features::mode::drive_during_sync_after(_this->m_mode_manager_base, drive_during_sync);
    }
}