#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_Director_calcBeforeStructure(Kart::Director *_this)
    {
        auto drive_during_sync = features::mode::drive_during_sync_before(nullptr);

        g_hooking->m_Kart_Director_hook.get_original<decltype(&Kart_Director_calcBeforeStructure)>(hooks::Director_calcBeforeStructure_index)(_this);

        features::mode::drive_during_sync_after(nullptr, drive_during_sync);
    }
}