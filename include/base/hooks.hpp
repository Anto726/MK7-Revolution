#pragma once

#include <forward.hpp>

#include <Kart/VehicleReact.hpp> // Kart::VehicleReact::EAcdType, Kart::VehicleReact::ECallType
#include <RaceSys/LapRankChecker.hpp> // RaceSys::LapRankChecker::KartInfo

#include <math/seadVectorFwd.h>

namespace base
{
    struct hooks
    {
        // VMT hooks
        static constexpr size_t Director_count = 34;
        static constexpr size_t Director_initBeforeStructure_index = 20;
        static constexpr size_t Director_calcBeforeStructure_index = 22;
        static void Item_ItemDirector_calcBeforeStructure(Item::ItemDirector *);
        static void Item_KartItem_calcBeforeStructure(Item::KartItem *);
        static void Item_KartItem_initBeforeStructure(Item::KartItem *);
        static void Kart_Director_calcBeforeStructure(Kart::Director *);

        // Naked hooks
        static NAKED void Kart_VehicleReact_calcReact_0x20();

        // Detour hooks
        static void Item_ItemObjBase_setStateSelfMove(Item::ItemObjBase *, sead::Vector2f *);
		static void Item_ItemObjKouraR_stateInitComeBackDown(Item::ItemObjKouraR *);
        static void Effect_KartEffect_calcTireEffectWheelSpin(Effect::KartEffect *);
        static void Kart_Unit_calcMove(Kart::Unit *, bool, bool);
        static bool Kart_VehicleReact_reactAccidentCommon(Kart::VehicleReact *, Kart::VehicleReact::ECallType, int, int, Kart::VehicleReact::EAcdType, sead::Vector3f *, sead::Vector3f *);
        static void Net_NetworkEngine_sendUnreliableCore(Net::NetworkEngine *, u32, Net::NetworkBuffer *);
        static bool Net_NetworkSystemInfo_onReceivedCore(Net::NetworkSystemInfo *, Net::NetworkReceivedInfo *);
        static void RaceSys_LapRankChecker_calcLapPosition(RaceSys::LapRankChecker *, RaceSys::LapRankChecker::KartInfo *);
    };
}