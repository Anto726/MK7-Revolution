#pragma once

#include "hooking/detour_hook.hpp"
#include "hooking/vmt_hook.hpp"

#include "hook_funcs.hpp"

#include <fwddec.hpp>

namespace base
{
    class hooks
    {
        friend hook_funcs;

	public:
		explicit hooks();
		~hooks();

        void enable();
		void disable();

    private:
        hooking::vmt_hook m_Item_KartItem;

        hooking::detour_hook m_Kart_VehicleReact_calcReact;
    };

    inline hooks *g_hooks{};
}