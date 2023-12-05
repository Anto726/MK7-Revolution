#pragma once
#include <forward.hpp>

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
        static constexpr size_t Item_ItemDirector_count = 34;
        static constexpr size_t Item_ItemDirector_calcBeforeStructure_index = 22;
        static constexpr size_t Item_KartItem_count = 34;
        static constexpr size_t Item_KartItem_initBeforeStructure_index = 20;
        static constexpr size_t Item_KartItem_calcBeforeStructure_index = 22;
        static constexpr size_t Kart_Director_count = 34;
        static constexpr size_t Kart_Director_calcBeforeStructure_index = 22;
        static void Item_ItemDirector_calcBeforeStructure(Item::ItemDirector *);
        static void Item_KartItem_calcBeforeStructure(Item::KartItem *);
        static void Item_KartItem_initBeforeStructure(Item::KartItem *);
        static void Kart_Director_calcBeforeStructure(Kart::Director *);

        // Detour hooks
        static void Item_ItemObjBase_setStateSelfMove(Item::ItemObjBase *, sead::Vector2f *);
        static void Effect_KartEffect_calcTireEffectWheelSpin(Effect::KartEffect *);
        static void Kart_Unit_calcMove(Kart::Unit *, bool, bool);
        static void Kart_Unit_calcReact(Kart::Unit *);
        static void Kart_VehicleReact_reactAccidentCommon(Kart::VehicleReact *, Kart::VehicleReact::ECallType, int, int, Kart::VehicleReact::EAcdType, sead::Vector3f *, sead::Vector3f *);
        static void Net_NetworkEngine_sendUnreliableCore(Net::NetworkEngine *, u32, Net::NetworkBuffer *);
        static void RaceSys_LapRankChecker_calcLapPosition(RaceSys::LapRankChecker *, RaceSys::LapRankChecker::KartInfo *);
    };
}