#pragma once
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
}