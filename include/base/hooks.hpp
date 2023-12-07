#pragma once

#include "hooking/detour_hook.hpp"
#include "hooking/vmt_hook.hpp"

#include "hook_funcs.hpp"

namespace base
{
    class hooks
    {
        friend hook_funcs;

	public:
		explicit hooks();
		~hooks();

        inline bool is_enabled() const { return m_enabled; }

        void enable();
		void disable();

    private:
        bool m_enabled{};
        
        hooking::vmt_hook m_Item_ItemDirector_hook;
        hooking::vmt_hook m_Item_KartItem_hook;
        hooking::vmt_hook m_Kart_Director_hook;

        hooking::detour_hook m_Item_ItemObjBase_setStateSelfMove_hook;
        hooking::detour_hook m_Effect_KartEffect_calcTireEffectWheelSpin_hook;
        hooking::detour_hook m_Kart_Unit_calcMove_hook;
        hooking::detour_hook m_Kart_Unit_calcReact_hook;
        hooking::detour_hook m_Kart_VehicleReact_reactAccidentCommon_hook;
        hooking::detour_hook m_Net_NetworkEngine_sendUnreliableCore_hook;
        hooking::detour_hook m_RaceSys_LapRankChecker_calcLapPosition_hook;
    };

    inline hooks *g_hooks{};
}