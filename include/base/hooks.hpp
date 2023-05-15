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
        
        hooking::vmt_hook m_Item_ItemDirector;

        hooking::vmt_hook m_Item_KartItem;

        hooking::vmt_hook m_Kart_Director;

        hooking::detour_hook m_Kart_Unit_calcMove;
        hooking::detour_hook m_Kart_Unit_calcReact;
        
        hooking::detour_hook m_Kart_VehicleReact_reactAccidentCommon;

        hooking::detour_hook m_RaceSys_LapRankChecker_calcLapPosition;
    };

    inline hooks *g_hooks{};
}