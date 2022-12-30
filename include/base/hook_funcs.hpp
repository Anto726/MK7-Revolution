#pragma once
#include <fwddec.hpp>

// mk7
#include <Kart/VehicleReact.hpp> // Kart::VehicleReact::EAcdType, Kart::VehicleReact::ECallType
#include <RaceSys/LapRankChecker.hpp> // RaceSys::LapRankChecker::KartInfo

// sead
#include <math/seadVectorFwd.h>

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

        static void Kart_VehicleMove_calcMoveControlCommon(Kart::VehicleMove *);
        static void Kart_VehicleReact_calcReact(Kart::VehicleReact *);
        static void Kart_VehicleReact_reactAccidentCommon(Kart::VehicleReact *, Kart::VehicleReact::ECallType, int, int, Kart::VehicleReact::EAcdType, sead::Vector3f *, sead::Vector3f *);

        static void RaceSys_LapRankChecker_calcLapPosition(RaceSys::LapRankChecker *, RaceSys::LapRankChecker::KartInfo *);
    };
}