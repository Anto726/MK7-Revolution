#pragma once

#include "hook_types/all.hpp"

#include "hooks.hpp"

namespace base
{
    class hooking
    {
	public:
		explicit hooking();
		~hooking();

        inline bool is_enabled() const { return m_enabled; }

        void enable();
		void disable();

    private:
        friend hooks;

        bool m_enabled{};

        hook_types::vmt_hook m_Item_ItemDirector_hook;
        hook_types::vmt_hook m_Item_ItemObjGesso_hook;
        hook_types::vmt_hook m_Item_ItemObjKiller_hook;
        hook_types::vmt_hook m_Item_ItemObjKouraB_hook;
        hook_types::vmt_hook m_Item_ItemObjKouraG_hook;
        hook_types::vmt_hook m_Item_ItemObjKouraR_hook;
        hook_types::vmt_hook m_Item_ItemObjStar_hook;
        hook_types::vmt_hook m_Item_KartItem_hook;
        hook_types::vmt_hook m_Kart_Director_hook;
        hook_types::vmt_hook m_UI_TimeControl_hook;

        hook_types::detour_hook m_Effect_KartEffect_calcTireEffectWheelSpin_hook;
        hook_types::detour_hook m_Item_ItemDirector_clearItem_hook;
        hook_types::detour_hook m_Item_ItemDirector_entryItem_hook;
        hook_types::detour_hook m_Item_ItemDirector_itemEventRecvHandler_hook;
        hook_types::detour_hook m_Item_ItemObjBase_calc_hook;
        hook_types::detour_hook m_Item_ItemObjBase_setStateSelfMove_hook;
        hook_types::detour_hook m_Item_ItemObjFlower_stateEquipHang_hook;
        hook_types::detour_hook m_Item_ItemObjKouraB_stateEquipHang_hook;
        hook_types::detour_hook m_Item_ItemObjKouraG_stateInitSelfMoveImpl_hook;
        hook_types::detour_hook m_Item_ItemObjKouraR_stateInitComeBackDown_hook;
        hook_types::detour_hook m_Item_ItemObjThunderDirector_entryOtherThunder_hook;
        hook_types::detour_hook m_Item_ItemSlot_isStock_hook;
        hook_types::detour_hook m_Item_KartItem_KartItem_hook;
        hook_types::detour_hook m_Kart_NetData_read_hook;
        hook_types::detour_hook m_Kart_NetData_send_hook;
        hook_types::detour_hook m_Kart_Rigid_updateVel_hook;
        hook_types::detour_hook m_Kart_Unit_calcMove_hook;
        hook_types::detour_hook m_Kart_Unit_Unit_hook;
        hook_types::detour_hook m_Kart_VehicleMove_startKillerImpl_hook;
        hook_types::detour_hook m_Kart_VehicleReact_reactAccidentCommon_hook;
        hook_types::detour_hook m_Menu3D_GarageDirector_isEndMiiIntroduction_hook;
        hook_types::detour_hook m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived_hook;
        hook_types::detour_hook m_Net_NetworkEngine_sendUnreliableCore_hook;
        hook_types::detour_hook m_Net_NetworkFriendsManager_updateFriendInfo_hook;
        hook_types::detour_hook m_Net_NetworkGameMgr_requestGoal_0x4_hook;
        hook_types::detour_hook m_Net_NetworkItemSlotMgr_Buffer_setEquipItemType_hook;
        hook_types::detour_hook m_RaceSys_LapRankChecker_calcLapPosition_hook;
        hook_types::detour_hook m_sead_BufferedSafeString_format_hook;
        hook_types::detour_hook m_sead_PtrArrayImpl_allocBuffer_hook;
        hook_types::detour_hook m_System_KDPadInputer_calcInput_hook;
        hook_types::detour_hook m_System_SystemSaveData_initCecComment_hook;
        hook_types::detour_hook m_System_SystemSaveData_set_hook;

        hook_types::naked_hook m_Item_GetExtraItemNum_hook;
        hook_types::naked_hook m_Item_GetNumInItemType_hook;
        hook_types::naked_hook m_Item_GetNumInItemTypeNet_hook;
        hook_types::naked_hook m_Item_ItemDirector_calcKeyInputEachPlayer_0x34_hook;
        hook_types::naked_hook m_Item_ItemDirector_calcKeyInputEachPlayer_0x58_hook;
        hook_types::naked_hook m_Item_ItemDirector_calcKeyInputEachPlayer_0x64_hook;
        hook_types::naked_hook m_Item_ItemDirector_calcKeyInputEachPlayer_0x78_hook;
        hook_types::naked_hook m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8_hook;
        hook_types::naked_hook m_Item_ItemDirector_createBeforeStructure_0x548_hook;
        hook_types::naked_hook m_Item_ItemObjBase_stateEquipMulti_0x4F8_hook;
        hook_types::naked_hook m_Item_ItemObjGesso_stateUse_0x28_hook;
        hook_types::naked_hook m_Kart_Director_createBeforeStructure_0x284_hook;
        hook_types::naked_hook m_Kart_Unit_startStarColor_0x4_hook;
        hook_types::naked_hook m_Kart_Unit_updateStarColor_0x4_hook;
        hook_types::naked_hook m_Kart_VehicleMove_calcMoveControlCommon_0x7EC_hook;
        hook_types::naked_hook m_Kart_VehicleMove_calcMoveControlGnd_0x18_hook;
        hook_types::naked_hook m_Kart_VehicleMove_isMiniTurboOverLv1_0x8_hook;
        hook_types::naked_hook m_Kart_VehicleMove_startPress_0x20_hook;
        hook_types::naked_hook m_Kart_VehicleMove_startThunder_0x14_hook;
        hook_types::naked_hook m_Kart_VehicleReact_calcReact_0x20_hook;
        hook_types::naked_hook m_Kart_VehicleReact_calcReact_0x4C_hook;
        hook_types::naked_hook m_Kart_VehicleReact_reactAccidentCommon_0x98_hook;
        hook_types::naked_hook m_Kart_VehicleReact_reactAccidentCommon_0xAC_hook;
        hook_types::naked_hook m_Net_NetworkEventModule_calc_0xB4_hook;
        hook_types::naked_hook m_Object_CharacterEngine_creator_2_0x184_hook;
        hook_types::naked_hook m_Object_CharacterEngine_creator_6_0x184_hook;
        hook_types::naked_hook m_RaceSys_ModeManagerRace_calcCountDown_0x18_hook;
        hook_types::naked_hook m_Sequence_BaseRacePage_subBombBlue_0x4_hook;
        hook_types::naked_hook m_Sequence_BaseRacePage_subBombRed_0x4_hook;
        hook_types::naked_hook m_Sequence_BaseRacePage_subEquipItem_0xAC_hook;
        hook_types::naked_hook m_Sequence_MenuMultiCourseVote_onPagePreStep_0x344_hook;
        hook_types::naked_hook m_Sequence_RacePage_genRaceGP_0x7C_hook;
        hook_types::naked_hook m_UI_BgRaceMapCharaControl_onCalc_0x14_hook;
        hook_types::naked_hook m_UI_BgRaceZoomMapControl_onCreate_0x20_hook;
        hook_types::naked_hook m_UI_RaceItemBoxControl_onCalc_0x23C_hook;
        hook_types::naked_hook m_UI_RaceItemBoxControl_onCalc_0x254_hook;
    };

    inline hooking *g_hooking{};
}