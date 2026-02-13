#pragma once

#include <types.h>

#include <forward.hpp>

#include <Item/eItemSlot.hpp>
#include <Kart/Vehicle/VehicleReact.hpp> // Kart::VehicleReact::EAcdType, Kart::VehicleReact::ECallType
#include <Net/NetworkItemEventDataMgr.hpp> // Net::NetworkItemEventDataMgr::SlotData
#include <Net/NetworkItemSlotMgr.hpp> // Net::NetworkItemSlotMgr::Buffer
#include <RaceSys/LapRankChecker.hpp> // RaceSys::LapRankChecker::KartInfo
#include <UI/Control.hpp> // UI::Control::CreateArg

#include <container/seadPtrArray.h>
#include <gfx/seadColor.h>
#include <math/seadVectorFwd.h>
#include <prim/seadSafeString.h>

#include <base/game/forward.hpp>

namespace base
{
    struct hooks
    {
        // Callbacks
        static constexpr size_t ItemObjBomhei_stateInitBurst_index = 4;
        static constexpr size_t ItemObjKouraB_stateInitBurst_index = 6;

        // VMT indexes
        static constexpr size_t Director_count = 34;
        static constexpr size_t Director_createBeforeStructure_index = 18;
        static constexpr size_t Director_calcBeforeStructure_index = 22;
        static constexpr size_t ItemObjBase_count = 68;
        static constexpr size_t ItemObjBase_createInner_index = 30;
        static constexpr size_t ItemObjBase_initEntryInnerBefore_index = 31;
        static constexpr size_t ItemObjBase_stateInitSelfMoveImpl_index = 41;
        static constexpr size_t ItemObjBase_stateEquipHang_index = 55;
        static constexpr size_t ItemObjBase_stateInitUse_index = 64;
        static constexpr size_t ItemObjBase_stateUse_index = 65;
        static constexpr size_t ItemObjBase_stateInitAttacked_index = 66;
        static constexpr size_t ItemObjKoura_count = 87;
        static constexpr size_t ItemObjKoura_calcStripe_index = 69;
        static constexpr size_t ItemObjKoura_getStripeColor_index = 70;
        static constexpr size_t ItemObjKoura_stateInitComeBackDown_index = 80;
        static constexpr size_t Sequence_Page_onPagePreStep_index = 43;
        static constexpr size_t Sequence_Page_initControl_index = 58;
        static constexpr size_t UI_Control_count = 33;
        static constexpr size_t UI_Control_onCreate_index = 19;
        
        // VMT hooks
        static void Item_ItemDirector_calcBeforeStructure(Item::ItemDirector *);
        static void Item_ItemObjGesso_initEntryInnerBefore(Item::ItemObjGesso *);
        static void Item_ItemObjKiller_stateInitUse(Item::ItemObjKiller *);
        static void Item_ItemObjKouraB_getStripeColor(sead::Color4f *);
        static void Item_ItemObjKouraG_getStripeColor(sead::Color4f *);
        static void Item_ItemObjKouraR_getStripeColor(sead::Color4f *);
        static void Item_ItemObjStar_initEntryInnerBefore(Item::ItemObjStar *);
        static void Item_KartItem_calcBeforeStructure(game::item::kart_item *);
        static void Kart_Director_calcBeforeStructure(Kart::Director *);
        static void UI_TimeControl_onCreate(UI::TimeControl *, UI::Control::CreateArg *);

        // Detour hooks
        static void Effect_KartEffect_calcTireEffectWheelSpin(Effect::KartEffect *);
        static void Item_ItemDirector_clearItem(Item::ItemDirector *, s32);
        static void Item_ItemDirector_entryItem(Item::ItemDirector *, Item::eItemSlot, game::item::kart_item *);
        static bool Item_ItemDirector_itemEventRecvHandler(Item::ItemDirector *, Net::NetworkItemEventDataMgr::SlotData *);
        static void Item_ItemObjBase_setStateSelfMove(Item::ItemObjBase *, sead::Vector2f *);
        static void Item_ItemObjFlower_stateEquipHang(Item::ItemObjFlower *);
        static void Item_ItemObjKouraB_stateEquipHang(Item::ItemObjKouraB *);
        static void Item_ItemObjKouraG_stateInitSelfMoveImpl(Item::ItemObjKouraG *);
		static void Item_ItemObjKouraR_stateInitComeBackDown(Item::ItemObjKouraR *);
        static void Item_ItemObjThunderDirector_entryOtherThunder(Item::ItemObjThunderDirector *, s32);
        static bool Item_ItemSlot_isStock(Item::ItemSlot *);
        static game::item::kart_item *Item_KartItem_KartItem(game::item::kart_item *, s32);
        static void Kart_Director_createBeforeStructure(game::kart::director *, void *);
        static bool Kart_NetData_read(Kart::NetData *, Net::NetworkBuffer *, Kart::NetData **, Kart::NetData **);
        static void Kart_NetData_send(Kart::NetData *, s32);
        static void Kart_Rigid_updateVel(Kart::Rigid *, sead::Vector3f *);
        static void Kart_Unit_calcMove(game::kart::unit *, bool, bool);
        static game::kart::unit *Kart_Unit_Unit(game::kart::unit *, s32, RaceSys::CRaceInfo *, bool);
        static void Kart_VehicleMove_startKillerImpl(Kart::VehicleMove *, bool);
        static bool Kart_VehicleReact_reactAccidentCommon(Kart::VehicleReact *, Kart::VehicleReact::ECallType, int, int, Kart::VehicleReact::EAcdType, sead::Vector3f *, sead::Vector3f *);
        static bool Menu3D_GarageDirector_isEndMiiIntroduction(Menu3D::GarageDirector *);
        static bool Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived(void *, Net::NetworkReceivedInfo *);
        static void Net_NetworkEngine_sendUnreliableCore(Net::NetworkEngine *, u32, Net::NetworkBuffer *);
        static void Net_NetworkFriendsManager_updateFriendInfo(Net::NetworkFriendsManager *);
        static void Net_NetworkGameMgr_requestGoal_0x4(Net::NetworkGameMgr *, s32, u32, void *);
        static void Net_NetworkItemSlotMgr_Buffer_setEquipItemType(Net::NetworkItemSlotMgr::Buffer *, s32, Item::eItemSlot, s32);
        static void RaceSys_LapRankChecker_calcLapPosition(RaceSys::LapRankChecker *, RaceSys::LapRankChecker::KartInfo *);
        static s32 sead_BufferedSafeString_format(sead::BufferedSafeString *, char const *, ...);
        static void sead_PtrArrayImpl_allocBuffer(sead::PtrArrayImpl *, s32, sead::Heap *, s32);
        static void System_KDPadInputer_calcState(System::KDPadInputer *);
        static void System_SystemSaveData_initCecComment(System::SystemSaveData *);
        static bool System_SystemSaveData_set(System::SystemSaveData *, System::SystemSaveData *);

        // Naked hooks
        static NAKED void Item_GetExtraItemNum();
        static NAKED void Item_GetNumInItemType();
        static NAKED void Item_GetNumInItemTypeNet();
        static NAKED void Item_ItemDirector_calcKeyInputEachPlayer_0x34();
        static NAKED void Item_ItemDirector_calcKeyInputEachPlayer_0x58();
        static NAKED void Item_ItemDirector_calcKeyInputEachPlayer_0x64();
        static NAKED void Item_ItemDirector_calcKeyInputEachPlayer_0x78();
        static NAKED void Item_ItemDirector_calcKeyInputEachPlayer_0xE8();
        static NAKED void Item_ItemDirector_createBeforeStructure_0x548();
        static NAKED void Item_ItemObjGesso_stateUse_0x28();
        static NAKED void Kart_Director_createBeforeStructure_0x284();
        static NAKED void Kart_Unit_startStarColor_updateStarColor_0x4();
        static NAKED void Kart_VehicleMove_calcMoveControlCommon_0x7EC();
        static NAKED void Kart_VehicleMove_calcMoveControlGnd_0x18();
        static NAKED void Kart_VehicleMove_isMiniTurboOverLv1_0x8();
        static NAKED void Kart_VehicleMove_startPress_0x20();
        static NAKED void Kart_VehicleMove_startThunder_0x14();
        static NAKED void Kart_VehicleReact_calcReact_0x20();
        static NAKED void Kart_VehicleReact_calcReact_0x4C();
        static NAKED void Kart_VehicleReact_reactAccidentCommon_0x98();
        static NAKED void Kart_VehicleReact_reactAccidentCommon_0xAC();
        static NAKED void Net_NetworkEventModule_calc_0xB4();
        static NAKED void Object_CharacterEngine_creators_2_6_0x184();
        static NAKED void RaceSys_ModeManagerRace_calcCountDown_0x18();
        static NAKED void Sequence_BaseRacePage_subBombBlue_subBombRed_0x4();
        static NAKED void Sequence_BaseRacePage_subEquipItem_0xAC();
        static NAKED void Sequence_MenuMultiCourseVote_onPagePreStep_0x344();
        static NAKED void Sequence_RacePage_genRaceGP_0x7C();
        static NAKED void UI_BgRaceMapCharaControl_onCalc_0x14();
        static NAKED void UI_BgRaceZoomMapControl_onCreate_0x20();
        static NAKED void UI_RaceItemBoxControl_onCalc_0x23C();
        static NAKED void UI_RaceItemBoxControl_onCalc_0x254();
    };
}