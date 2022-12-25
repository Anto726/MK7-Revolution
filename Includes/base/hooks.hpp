#pragma once

#include <base/hooking/detour_hook.hpp>
#include <base/hooking/vmt_hook.hpp>

#include <fwddec.hpp>

namespace base
{
    struct hook_funcs
    {
        // VMT hooks
        static constexpr size_t Item_KartItem_count = 34;
        static constexpr size_t Item_KartItem_initBeforeStructure_index = 20;
        static constexpr size_t Item_KartItem_calcBeforeStructure_index = 22;
        static void Item_KartItem_calcBeforeStructure(Item::KartItem *);
        static void Item_KartItem_initBeforeStructure(Item::KartItem *);

        static void Kart_VehicleReact_calcReact(Kart::VehicleReact *);
    };

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