#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
    void hook_funcs::Effect_KartEffect_calcTireEffectWheelSpin(Effect::KartEffect *_this)
    {
        auto drive_during_countdown = features::mode::drive_during_countdown_before(nullptr);

        g_hooks->m_Effect_KartEffect_calcTireEffectWheelSpin.call_original<void>(_this);

        features::mode::drive_during_countdown_after(nullptr, drive_during_countdown);
    }
}