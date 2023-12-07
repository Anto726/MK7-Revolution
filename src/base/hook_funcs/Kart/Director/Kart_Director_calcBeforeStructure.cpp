#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
    void hook_funcs::Kart_Director_calcBeforeStructure(Kart::Director *_this)
    {
        auto drive_during_countdown = features::mode::drive_during_countdown_before(nullptr);

        g_hooks->m_Kart_Director.get_original<decltype(&Kart_Director_calcBeforeStructure)>(hook_funcs::Kart_Director_calcBeforeStructure_index)(_this);

        features::mode::drive_during_countdown_after(nullptr, drive_during_countdown);
    }
}