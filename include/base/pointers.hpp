#pragma once

#include <forward.hpp>
#include <types.hpp>

#include <RaceSys/EGrandPrixID.hpp>

#include <random/seadGlobalRandom.h>

#include "game/methods.hpp"

namespace base
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();

		Net::NetworkEngine **m_network_engine;
		sead::GlobalRandom **m_global_random;
		
		System::SystemSaveData *m_system_save_data{};

		void *m_Item_ItemDirector;
		void *m_Item_ItemObjGesso;
		void *m_Item_ItemObjKiller;
		void *m_Item_ItemObjKouraB;
		void *m_Item_ItemObjKouraG;
		void *m_Item_ItemObjKouraR;
		void *m_Item_ItemObjStar;
		void *m_Item_KartItem;
		void *m_Kart_Director;
		void *m_UI_TimeControl;

		void *m_sead_SafeString_vtbl;

		game::methods::operator_new_t m_operator_new;
		game::methods::Item_ItemDirector_dropEquip_t m_Item_ItemDirector_dropEquip;
		game::methods::Item_ItemObjBase_stateEquipHang_t m_Item_ItemObjBase_stateEquipHang;
		game::methods::Item_ItemObjDirectorBase_emitItemImpl_t m_Item_ItemObjDirectorBase_emitItemImpl;
		game::methods::Item_ItemObjDirectorBase_entryUse_t m_Item_ItemObjDirectorBase_entryUse;
		game::methods::Item_KartItem_setItemForce_t m_Item_KartItem_setItemForce;
		game::methods::Kart_Unit_startJugemRecover_t m_Kart_Unit_startJugemRecover;
		game::methods::Kart_VehicleMove_endKiller_t m_Kart_VehicleMove_endKiller;
		game::methods::Sequence_BaseRacePage_initTime_t m_Sequence_BaseRacePage_initTime;
		game::methods::UI_MessageData_getMessage_t m_UI_MessageData_getMessage;
		game::methods::UI_MessageIDConverter_getMessageData_t m_UI_MessageIDConverter_getMessageData;
		game::methods::Util_Math_CopyRotate m_Util_Math_CopyRotate;

		void *m_Effect_GPUPtclStripe_GPUPtclStripe_0x2D0;
		void *m_Effect_KartEffect_calcTireEffectWheelSpin;
		void *m_Item_GetExtraItemNum;
		void *m_Item_GetNumInItemType;
		void *m_Item_GetNumInItemTypeNet;
		void *m_Item_ItemDirector_calcKeyInputEachPlayer_0x34;
		void *m_Item_ItemDirector_calcKeyInputEachPlayer_0x58;
		void *m_Item_ItemDirector_calcKeyInputEachPlayer_0x64;
		void *m_Item_ItemDirector_calcKeyInputEachPlayer_0x78;
		void *m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8;
		void *m_Item_ItemDirector_clearItem;
		void *m_Item_ItemDirector_createBeforeStructure_0x548;
		void *m_Item_ItemDirector_entryItem;
		void *m_Item_ItemDirector_itemEventRecvHandler;
		void *m_Item_ItemObjBase_calc;
		void *m_Item_ItemObjBase_setStateSelfMove;
		void *m_Item_ItemObjBase_stateEquipMulti_0x4F8;
		void *m_Item_ItemObjFlower_stateEquipHang;
		void *m_Item_ItemObjGesso_stateUse_0x28;
		void *m_Item_ItemObjKouraB_stateEquipHang;
		void *m_Item_ItemObjKouraG_calcStripe_0x34;
		void *m_Item_ItemObjKouraG_calcStripe_0xC4;
		void *m_Item_ItemObjKouraG_stateInitSelfMoveImpl;
		void *m_Item_ItemObjKouraR_stateInitComeBackDown;
		void *m_Item_ItemObjThunder_stateInitAttacked_0x17C;
		void *m_Item_ItemObjThunderDirector_entryOtherThunder;
		void *m_Item_ItemSlot_isStock;
		void *m_Item_KartItem_KartItem;
		void *m_Kart_Director_createBeforeStructure_0x284;
		void *m_Kart_Driver_calcApply_0x180;
		void *m_Kart_Driver_calcApply_0x1F4;
		void *m_Kart_Driver_calcApply_0x22C;
		void *m_Kart_NetData_read;
		void *m_Kart_NetData_send;
		void *m_Kart_Rigid_updateVel;
		void *m_Kart_Unit_calcMove;
		void *m_Kart_Unit_startStarColor_0x4;
		void *m_Kart_Unit_updateStarColor_0x4;
		void *m_Kart_Unit_startJugemRecover_0x60;
		void *m_Kart_Unit_Unit;
		void *m_Kart_VehicleMove_calcMoveControlCommon_0x7EC;
		void *m_Kart_VehicleMove_calcMoveControlGnd_0x18;
		void *m_Kart_VehicleMove_isMiniTurboOverLv1_0x8;
		void *m_Kart_VehicleMove_startKillerImpl;
		void *m_Kart_VehicleMove_startPress_0x20;
		void *m_Kart_VehicleMove_startThunder_0x14;
		void *m_Kart_VehicleReact_calcReact_0x20;
		void *m_Kart_VehicleReact_calcReact_0x4C;
		void *m_Kart_VehicleReact_reactAccidentCommon;
		void *m_Kart_VehicleReact_reactAccidentCommon_0x98;
		void *m_Kart_VehicleReact_reactAccidentCommon_0xAC;
		void *m_Menu3D_GarageDirector_isEndMiiIntroduction;
		void *m_Mii_MiiEngine_createMiiFace_0x128;
		void *m_Mii_MiiEngine_createMiiFace_0x168;
		void *m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived;
		void *m_Net_NetworkEngine_sendUnreliableCore;
		void *m_Net_NetworkEventModule_calc_0xB4;
		void *m_Net_NetworkFriendsManager_updateFriendInfo;
		void *m_Net_NetworkGameMgr_requestGoal_0x4;
		void *m_Net_NetworkItemSlotMgr_Buffer_setEquipItemType;
		void *m_Object_CharacterEngine_creator_2_0x184;
		void *m_Object_CharacterEngine_creator_6_0x184;
		void *m_RaceSys_LapRankChecker_calcLapPosition;
		void *m_RaceSys_ModeManagerRace_calcCountDown_0x18;
		void *m_sead_BufferedSafeString_format;
		void *m_sead_PtrArrayImpl_allocBuffer;
		void *m_Sequence_BaseRacePage_drawItemIcon_0x44;
		void *m_Sequence_BaseRacePage_drawItemIcon_0x28C;
		void *m_Sequence_BaseRacePage_initMapIcon_0x584;
		void *m_Sequence_BaseRacePage_initRankBoard_0x7A8;
		void *m_Sequence_BaseRacePage_subBombBlue_0x4;
		void *m_Sequence_BaseRacePage_subBombRed_0x4;
		void *m_Sequence_BaseRacePage_subEquipItem_0xAC;
		void *m_Sequence_MenuMultiCourseVote_onPagePreStep_0x344;
		void *m_Sequence_RacePage_genRaceGP_0x7C;
		void *m_Sequence_RacePage_resEnter_0xD0;
		void *m_System_KDPadInputer_calcInput;
		void *m_System_SystemSaveData_initCecComment;
		void *m_System_SystemSaveData_set;
		void *m_UI_BgRaceMapCharaControl_onCalc_0x14;
		void *m_UI_BgRaceZoomMapControl_onCreate_0x20;
		void *m_UI_MessageWriter_buildNumString_0x8;
		void *m_UI_MessageWriter_buildNumString_0x11C;
		void *m_UI_MessageWriter_buildNumString_0x124;
		void *m_UI_RaceItemBoxControl_onCalc_0x23C;
		void *m_UI_RaceItemBoxControl_onCalc_0x254;

		void *m_set_bar_tex_worldwide_0x18;

		std::size_t *m_network_buffer_sizes;

		s32 *m_grand_prix_flags;

		float *m_miniturbo_blue_threshold;
		float *m_miniturbo_red_threshold;
		s32 *m_invincibility_frames_invisible_amount;
		s32 *m_invincibility_frames_visible_amount;
		float *m_star_acceleration;
		float *m_press_frames_kart_size;
	};

	inline pointers *g_pointers{};
}