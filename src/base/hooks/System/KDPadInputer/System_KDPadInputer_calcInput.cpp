#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::System_KDPadInputer_calcState(System::KDPadInputer *_this)
    {
        if (features::mode::drive_during_sync_input(_this))
            return;

        g_hooking->m_System_KDPadInputer_calcInput_hook.call_original<void>(_this);        
    }
}