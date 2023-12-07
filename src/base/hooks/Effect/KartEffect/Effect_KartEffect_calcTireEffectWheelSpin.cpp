#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Effect_KartEffect_calcTireEffectWheelSpin(Effect::KartEffect *_this)
    {
        auto drive_during_countdown = features::mode::drive_during_countdown_before(nullptr);

        g_hooking->m_Effect_KartEffect_calcTireEffectWheelSpin_hook.call_original<void>(_this);

        features::mode::drive_during_countdown_after(nullptr, drive_during_countdown);
    }
}