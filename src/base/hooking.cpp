#include <base/hooking.hpp>

#include <base/pointers.hpp>

namespace base
{
    hooking::hooking()
	:
		m_Item_ItemDirector_hook("Item::ItemDirector", g_pointers->m_Item_ItemDirector, hooks::Director_count),
		m_Item_ItemObjGesso_hook("Item::ItemObjGesso", g_pointers->m_Item_ItemObjGesso, hooks::ItemObjBase_count),
		m_Item_ItemObjKiller_hook("Item::ItemObjKiller", g_pointers->m_Item_ItemObjKiller, hooks::ItemObjBase_count),
		m_Item_ItemObjKouraB_hook("Item::ItemObjKouraB", g_pointers->m_Item_ItemObjKouraB, hooks::ItemObjKoura_count),
		m_Item_ItemObjKouraG_hook("Item::ItemObjKouraG", g_pointers->m_Item_ItemObjKouraG, hooks::ItemObjKoura_count),
		m_Item_ItemObjKouraR_hook("Item::ItemObjKouraR", g_pointers->m_Item_ItemObjKouraR, hooks::ItemObjKoura_count),
		m_Item_ItemObjStar_hook("Item::ItemObjStar", g_pointers->m_Item_ItemObjStar, hooks::ItemObjBase_count),
		m_Item_KartItem_hook("Item::KartItem", g_pointers->m_Item_KartItem, hooks::Director_count),
		m_Kart_Director_hook("Kart::Director", g_pointers->m_Kart_Director, hooks::Director_count),
		m_UI_TimeControl_hook("UI::TimeControl", g_pointers->m_UI_TimeControl, hooks::UI_Control_count),

		m_Effect_KartEffect_calcTireEffectWheelSpin_hook("Effect::KartEffect::_calcTireEffect_WheelSpin", g_pointers->m_Effect_KartEffect_calcTireEffectWheelSpin, reinterpret_cast<void *>(&hooks::Effect_KartEffect_calcTireEffectWheelSpin)),
		m_Item_ItemDirector_clearItem_hook("Item::ItemDirector::clearItem", g_pointers->m_Item_ItemDirector_clearItem, reinterpret_cast<void *>(&hooks::Item_ItemDirector_clearItem)),
		m_Item_ItemDirector_entryItem_hook("Item::ItemDirector::_entryItem", g_pointers->m_Item_ItemDirector_entryItem, reinterpret_cast<void *>(&hooks::Item_ItemDirector_entryItem)),
		m_Item_ItemDirector_itemEventRecvHandler_hook("Item::ItemDirector::_itemEventRecvHandler", g_pointers->m_Item_ItemDirector_itemEventRecvHandler, reinterpret_cast<void *>(&hooks::Item_ItemDirector_itemEventRecvHandler)),
		m_Item_ItemObjBase_calc_hook("Item::ItemObjBase::calc", g_pointers->m_Item_ItemObjBase_calc, reinterpret_cast<void *>(&hooks::Item_ItemObjBase_calc)),
		m_Item_ItemObjBase_setStateSelfMove_hook("Item::ItemObjBase::setState_SelfMove", g_pointers->m_Item_ItemObjBase_setStateSelfMove, reinterpret_cast<void *>(&hooks::Item_ItemObjBase_setStateSelfMove)),
		m_Item_ItemObjFlower_stateEquipHang_hook("Item::ItemObjFlower::stateEquip_Hang", g_pointers->m_Item_ItemObjFlower_stateEquipHang, reinterpret_cast<void *>(&hooks::Item_ItemObjFlower_stateEquipHang)),
		m_Item_ItemObjKouraB_stateEquipHang_hook("Item::ItemObjKouraB::stateEquip_Hang", g_pointers->m_Item_ItemObjKouraB_stateEquipHang, reinterpret_cast<void *>(&hooks::Item_ItemObjKouraB_stateEquipHang)),
		m_Item_ItemObjKouraG_stateInitSelfMoveImpl_hook("Item::ItemObjKouraG::stateInitSelfMoveImpl", g_pointers->m_Item_ItemObjKouraG_stateInitSelfMoveImpl, reinterpret_cast<void *>(&hooks::Item_ItemObjKouraG_stateInitSelfMoveImpl)),
		m_Item_ItemObjKouraR_stateInitComeBackDown_hook("Item::ItemObjKouraR::stateInitComeBackDown", g_pointers->m_Item_ItemObjKouraR_stateInitComeBackDown, reinterpret_cast<void *>(&hooks::Item_ItemObjKouraR_stateInitComeBackDown)),
		m_Item_ItemObjThunderDirector_entryOtherThunder_hook("Item::ItemObjThunderDirector::entry_OtherThunder", g_pointers->m_Item_ItemObjThunderDirector_entryOtherThunder, reinterpret_cast<void *>(&hooks::Item_ItemObjThunderDirector_entryOtherThunder)),
		m_Item_ItemSlot_isStock_hook("Item::ItemSlot::isStock", g_pointers->m_Item_ItemSlot_isStock, reinterpret_cast<void *>(&hooks::Item_ItemSlot_isStock)),
		m_Item_KartItem_KartItem_hook("Item::KartItem::KartItem", g_pointers->m_Item_KartItem_KartItem, reinterpret_cast<void *>(&hooks::Item_KartItem_KartItem)),
		m_Kart_NetData_read_hook("Kart::NetData::read", g_pointers->m_Kart_NetData_read, reinterpret_cast<void *>(&hooks::Kart_NetData_read)),
		m_Kart_NetData_send_hook("Kart::NetData::send", g_pointers->m_Kart_NetData_send, reinterpret_cast<void *>(&hooks::Kart_NetData_send)),
		m_Kart_Rigid_updateVel_hook("Kart::Rigid::updateVel", g_pointers->m_Kart_Rigid_updateVel, reinterpret_cast<void *>(&hooks::Kart_Rigid_updateVel)),
		m_Kart_Unit_calcMove_hook("Kart::Unit::calcMove", g_pointers->m_Kart_Unit_calcMove, reinterpret_cast<void *>(&hooks::Kart_Unit_calcMove)),
		m_Kart_Unit_Unit_hook("Kart::Unit::Unit", g_pointers->m_Kart_Unit_Unit, reinterpret_cast<void *>(&hooks::Kart_Unit_Unit)),
		m_Kart_VehicleMove_startKillerImpl_hook("Kart::VehicleMove::startKiller_Impl", g_pointers->m_Kart_VehicleMove_startKillerImpl, reinterpret_cast<void *>(&hooks::Kart_VehicleMove_startKillerImpl)),
		m_Kart_VehicleReact_reactAccidentCommon_hook("Kart::VehicleReact::reactAccidentCommon", g_pointers->m_Kart_VehicleReact_reactAccidentCommon, reinterpret_cast<void *>(&hooks::Kart_VehicleReact_reactAccidentCommon)),
		m_Menu3D_GarageDirector_isEndMiiIntroduction_hook("Menu3D::GarageDirector::isEndMiiIntroduction", g_pointers->m_Menu3D_GarageDirector_isEndMiiIntroduction, reinterpret_cast<void *>(&hooks::Menu3D_GarageDirector_isEndMiiIntroduction)),
		m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived_hook("Net::NetworkDataManager<Net::NetworkSystemSendFormat>::onReceived", g_pointers->m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived, reinterpret_cast<void *>(&hooks::Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived)),
		m_Net_NetworkEngine_sendUnreliableCore_hook("Net::NetworkEngine::sendUnreliableCore", g_pointers->m_Net_NetworkEngine_sendUnreliableCore, reinterpret_cast<void *>(&hooks::Net_NetworkEngine_sendUnreliableCore)),
		m_Net_NetworkFriendsManager_updateFriendInfo_hook("Net::NetworkFriendsManager::updateFriendInfo", g_pointers->m_Net_NetworkFriendsManager_updateFriendInfo, reinterpret_cast<void *>(&hooks::Net_NetworkFriendsManager_updateFriendInfo)),
		m_Net_NetworkGameMgr_requestGoal_0x4_hook("Net::NetworkGameMgr::requestGoal+0x4", g_pointers->m_Net_NetworkGameMgr_requestGoal_0x4, reinterpret_cast<void *>(&hooks::Net_NetworkGameMgr_requestGoal_0x4)),
		m_Net_NetworkItemSlotMgr_Buffer_setEquipItemType_hook("Net::NetworkItemSlotMgr::Buffer::setEquipItemType", g_pointers->m_Net_NetworkItemSlotMgr_Buffer_setEquipItemType, reinterpret_cast<void *>(&hooks::Net_NetworkItemSlotMgr_Buffer_setEquipItemType)),
		m_RaceSys_LapRankChecker_calcLapPosition_hook("RaceSys::LapRankChecker::calcLapPosition_", g_pointers->m_RaceSys_LapRankChecker_calcLapPosition, reinterpret_cast<void *>(&hooks::RaceSys_LapRankChecker_calcLapPosition)),
		m_sead_BufferedSafeString_format_hook("sead::BufferedSafeString::format", g_pointers->m_sead_BufferedSafeString_format, reinterpret_cast<void *>(&hooks::sead_BufferedSafeString_format)),
		m_sead_PtrArrayImpl_allocBuffer_hook("sead::PtrArrayImpl::allocBuffer", g_pointers->m_sead_PtrArrayImpl_allocBuffer, reinterpret_cast<void *>(&hooks::sead_PtrArrayImpl_allocBuffer)),
		m_System_KDPadInputer_calcInput_hook("System::KDPadInputer::calcInput", g_pointers->m_System_KDPadInputer_calcInput, reinterpret_cast<void *>(&hooks::System_KDPadInputer_calcState)),
		m_System_SystemSaveData_initCecComment_hook("System::SystemSaveData::initCecComment", g_pointers->m_System_SystemSaveData_initCecComment, reinterpret_cast<void *>(&hooks::System_SystemSaveData_initCecComment)),
		m_System_SystemSaveData_set_hook("System::SystemSaveData::set", g_pointers->m_System_SystemSaveData_set, reinterpret_cast<void *>(&hooks::System_SystemSaveData_set)),

		m_Item_GetExtraItemNum_hook("Item::GetExtraItemNum", g_pointers->m_Item_GetExtraItemNum, reinterpret_cast<void *>(&hooks::Item_GetExtraItemNum), 0),
		m_Item_GetNumInItemType_hook("Item::GetNum_InItemType", g_pointers->m_Item_GetNumInItemType, reinterpret_cast<void *>(&hooks::Item_GetNumInItemType), 0),
		m_Item_GetNumInItemTypeNet_hook("Item::GetNum_InItemType_Net", g_pointers->m_Item_GetNumInItemTypeNet, reinterpret_cast<void *>(&hooks::Item_GetNumInItemTypeNet), 0),
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x34_hook("Item::ItemDirector::_calcKeyInput_EachPlayer+0x34", g_pointers->m_Item_ItemDirector_calcKeyInputEachPlayer_0x34, reinterpret_cast<void *>(&hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x34)),
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x58_hook("Item::ItemDirector::_calcKeyInput_EachPlayer+0x58", g_pointers->m_Item_ItemDirector_calcKeyInputEachPlayer_0x58, reinterpret_cast<void *>(&hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x58)),
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x64_hook("Item::ItemDirector::_calcKeyInput_EachPlayer+0x64", g_pointers->m_Item_ItemDirector_calcKeyInputEachPlayer_0x64, reinterpret_cast<void *>(&hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x64)),
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x78_hook("Item::ItemDirector::_calcKeyInput_EachPlayer+0x78", g_pointers->m_Item_ItemDirector_calcKeyInputEachPlayer_0x78, reinterpret_cast<void *>(&hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x78)),
		m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8_hook("Item::ItemDirector::_calcKeyInput_EachPlayer+0xE8", g_pointers->m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8, reinterpret_cast<void *>(&hooks::Item_ItemDirector_calcKeyInputEachPlayer_0xE8)),
		m_Item_ItemDirector_createBeforeStructure_0x548_hook("Item::ItemDirector::createBeforeStructure+0x548", g_pointers->m_Item_ItemDirector_createBeforeStructure_0x548, reinterpret_cast<void *>(&hooks::Item_ItemDirector_createBeforeStructure_0x548)),
		m_Item_ItemObjBase_stateEquipMulti_0x4F8_hook("Item::ItemObjBase::stateEquip_Multi+0x4F8", g_pointers->m_Item_ItemObjBase_stateEquipMulti_0x4F8, reinterpret_cast<void *>(&hooks::Item_ItemObjBase_stateEquipMulti_0x4F8), CTRPluginFramework::USE_LR_TO_RETURN | CTRPluginFramework::EXECUTE_OI_BEFORE_CB),
		m_Item_ItemObjGesso_stateUse_0x28_hook("Item::ItemObjGesso::stateUse+0x28", g_pointers->m_Item_ItemObjGesso_stateUse_0x28, reinterpret_cast<void *>(&hooks::Item_ItemObjGesso_stateUse_0x28), CTRPluginFramework::USE_LR_TO_RETURN | CTRPluginFramework::EXECUTE_OI_AFTER_CB),
		m_Kart_Director_createBeforeStructure_0x284_hook("Kart::Director::createBeforeStructure+0x284", g_pointers->m_Kart_Director_createBeforeStructure_0x284, reinterpret_cast<void *>(&hooks::Kart_Director_createBeforeStructure_0x284)),
		m_Kart_Unit_startStarColor_0x4_hook("Kart::Unit::startStarColor+0x4", g_pointers->m_Kart_Unit_startStarColor_0x4, reinterpret_cast<void *>(&hooks::Kart_Unit_startStarColor_updateStarColor_0x4), CTRPluginFramework::USE_LR_TO_RETURN | CTRPluginFramework::EXECUTE_OI_AFTER_CB),
		m_Kart_Unit_updateStarColor_0x4_hook("Kart::Unit::updateStarColor+0x4", g_pointers->m_Kart_Unit_updateStarColor_0x4, reinterpret_cast<void *>(&hooks::Kart_Unit_startStarColor_updateStarColor_0x4), CTRPluginFramework::USE_LR_TO_RETURN | CTRPluginFramework::EXECUTE_OI_AFTER_CB),
		m_Kart_VehicleMove_calcMoveControlCommon_0x7EC_hook("Kart::VehicleMove::calcMoveControlCommon+0x7EC", g_pointers->m_Kart_VehicleMove_calcMoveControlCommon_0x7EC, reinterpret_cast<void *>(&hooks::Kart_VehicleMove_calcMoveControlCommon_0x7EC)),
		m_Kart_VehicleMove_calcMoveControlGnd_0x18_hook("Kart::VehicleMove::calcMoveControlGnd+0x18", g_pointers->m_Kart_VehicleMove_calcMoveControlGnd_0x18, reinterpret_cast<void *>(&hooks::Kart_VehicleMove_calcMoveControlGnd_0x18)),
		m_Kart_VehicleMove_isMiniTurboOverLv1_0x8_hook("Kart::VehicleMove::isMiniTurbo_OverLv1+0x8", g_pointers->m_Kart_VehicleMove_isMiniTurboOverLv1_0x8, reinterpret_cast<void *>(&hooks::Kart_VehicleMove_isMiniTurboOverLv1_0x8)),
		m_Kart_VehicleMove_startPress_0x20_hook("Kart::VehicleMove::startPress+0x20", g_pointers->m_Kart_VehicleMove_startPress_0x20, reinterpret_cast<void *>(&hooks::Kart_VehicleMove_startPress_0x20)),
		m_Kart_VehicleMove_startThunder_0x14_hook("Kart::VehicleMove::startThunder+0x14", g_pointers->m_Kart_VehicleMove_startThunder_0x14, reinterpret_cast<void *>(&hooks::Kart_VehicleMove_startThunder_0x14)),
		m_Kart_VehicleReact_calcReact_0x20_hook("Kart::VehicleReact::calcReact+0x20", g_pointers->m_Kart_VehicleReact_calcReact_0x20, reinterpret_cast<void *>(&hooks::Kart_VehicleReact_calcReact_0x20)),
		m_Kart_VehicleReact_calcReact_0x4C_hook("Kart::VehicleReact::calcReact+0x4C", g_pointers->m_Kart_VehicleReact_calcReact_0x4C, reinterpret_cast<void *>(&hooks::Kart_VehicleReact_calcReact_0x4C)),
		m_Kart_VehicleReact_reactAccidentCommon_0x98_hook("Kart::VehicleReact::reactAccidentCommon+0x98", g_pointers->m_Kart_VehicleReact_reactAccidentCommon_0x98, reinterpret_cast<void *>(&hooks::Kart_VehicleReact_reactAccidentCommon_0x98)),
		m_Kart_VehicleReact_reactAccidentCommon_0xAC_hook("Kart::VehicleReact::reactAccidentCommon+0xAC", g_pointers->m_Kart_VehicleReact_reactAccidentCommon_0xAC, reinterpret_cast<void *>(&hooks::Kart_VehicleReact_reactAccidentCommon_0xAC)),
		m_Net_NetworkEventModule_calc_0xB4_hook("Net::NetworkEventModule::calc+0xB4", g_pointers->m_Net_NetworkEventModule_calc_0xB4, reinterpret_cast<void *>(&hooks::Net_NetworkEventModule_calc_0xB4)),
		m_Object_CharacterEngine_creator_2_0x184_hook("Object::CharacterEngine::creator_2+0x184", g_pointers->m_Object_CharacterEngine_creator_2_0x184, reinterpret_cast<void *>(&hooks::Object_CharacterEngine_creators_2_6_0x184)),
		m_Object_CharacterEngine_creator_6_0x184_hook("Object::CharacterEngine::creator_6+0x184", g_pointers->m_Object_CharacterEngine_creator_6_0x184, reinterpret_cast<void *>(&hooks::Object_CharacterEngine_creators_2_6_0x184)),
		m_RaceSys_ModeManagerRace_calcCountDown_0x18_hook("RaceSys::ModeManagerRace::calcCountDown+0x18", g_pointers->m_RaceSys_ModeManagerRace_calcCountDown_0x18, reinterpret_cast<void *>(&hooks::RaceSys_ModeManagerRace_calcCountDown_0x18), CTRPluginFramework::USE_LR_TO_RETURN | CTRPluginFramework::EXECUTE_OI_BEFORE_CB),
		m_Sequence_BaseRacePage_subBombBlue_0x4_hook("Sequence::BaseRacePage::sub_bombBlue+0x4", g_pointers->m_Sequence_BaseRacePage_subBombBlue_0x4, reinterpret_cast<void *>(&hooks::Sequence_BaseRacePage_subBombBlue_subBombRed_0x4)),
		m_Sequence_BaseRacePage_subBombRed_0x4_hook("Sequence::BaseRacePage::sub_bombRed+0x4", g_pointers->m_Sequence_BaseRacePage_subBombRed_0x4, reinterpret_cast<void *>(&hooks::Sequence_BaseRacePage_subBombBlue_subBombRed_0x4)),
		m_Sequence_BaseRacePage_subEquipItem_0xAC_hook("Sequence::BaseRacePage::sub_equipItem+0xAC", g_pointers->m_Sequence_BaseRacePage_subEquipItem_0xAC, reinterpret_cast<void *>(&hooks::Sequence_BaseRacePage_subEquipItem_0xAC), CTRPluginFramework::USE_LR_TO_RETURN | CTRPluginFramework::EXECUTE_OI_AFTER_CB),
		m_Sequence_MenuMultiCourseVote_onPagePreStep_0x344_hook("Sequence::MenuMulti_CourseVote::onPagePreStep+0x344", g_pointers->m_Sequence_MenuMultiCourseVote_onPagePreStep_0x344, reinterpret_cast<void *>(&hooks::Sequence_MenuMultiCourseVote_onPagePreStep_0x344), CTRPluginFramework::USE_LR_TO_RETURN | CTRPluginFramework::EXECUTE_OI_AFTER_CB),
		m_Sequence_RacePage_genRaceGP_0x7C_hook("Sequence::RacePage::genRaceGP+0x7C", g_pointers->m_Sequence_RacePage_genRaceGP_0x7C, reinterpret_cast<void *>(&hooks::Sequence_RacePage_genRaceGP_0x7C), CTRPluginFramework::USE_LR_TO_RETURN | CTRPluginFramework::EXECUTE_OI_AFTER_CB),
		m_UI_BgRaceMapCharaControl_onCalc_0x14_hook("UI::BgRaceMapCharaControl::onCalc+0x14", g_pointers->m_UI_BgRaceMapCharaControl_onCalc_0x14, reinterpret_cast<void *>(&hooks::UI_BgRaceMapCharaControl_onCalc_0x14)),
		m_UI_BgRaceZoomMapControl_onCreate_0x20_hook("UI::BgRaceZoomMapControl::onCreate+0x20", g_pointers->m_UI_BgRaceZoomMapControl_onCreate_0x20, reinterpret_cast<void *>(&hooks::UI_BgRaceZoomMapControl_onCreate_0x20)),
		m_UI_RaceItemBoxControl_onCalc_0x23C_hook("UI::RaceItemBoxControl::onCalc+0x23C", g_pointers->m_UI_RaceItemBoxControl_onCalc_0x23C, reinterpret_cast<void *>(&hooks::UI_RaceItemBoxControl_onCalc_0x23C)),
		m_UI_RaceItemBoxControl_onCalc_0x254_hook("UI::RaceItemBoxControl::onCalc+0x254", g_pointers->m_UI_RaceItemBoxControl_onCalc_0x254, reinterpret_cast<void *>(&hooks::UI_RaceItemBoxControl_onCalc_0x254))
	{
		m_Item_ItemDirector_hook.hook(hooks::Director_calcBeforeStructure_index, reinterpret_cast<void *>(&hooks::Item_ItemDirector_calcBeforeStructure));
		m_Item_ItemObjGesso_hook.hook(hooks::ItemObjBase_initEntryInnerBefore_index, reinterpret_cast<void *>(&hooks::Item_ItemObjGesso_initEntryInnerBefore));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_stateInitUse_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_stateInitUse));
		m_Item_ItemObjKouraB_hook.hook(hooks::ItemObjKoura_getStripeColor_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKouraB_getStripeColor));
		m_Item_ItemObjKouraG_hook.hook(hooks::ItemObjKoura_getStripeColor_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKouraG_getStripeColor));
		m_Item_ItemObjKouraR_hook.hook(hooks::ItemObjKoura_getStripeColor_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKouraR_getStripeColor));
		m_Item_ItemObjStar_hook.hook(hooks::ItemObjBase_initEntryInnerBefore_index, reinterpret_cast<void *>(&hooks::Item_ItemObjStar_initEntryInnerBefore));
		m_Item_KartItem_hook.hook(hooks::Director_calcBeforeStructure_index, reinterpret_cast<void *>(&hooks::Item_KartItem_calcBeforeStructure));
		m_Kart_Director_hook.hook(hooks::Director_createBeforeStructure_index, reinterpret_cast<void *>(&hooks::Kart_Director_createBeforeStructure));
		m_Kart_Director_hook.hook(hooks::Director_calcBeforeStructure_index, reinterpret_cast<void *>(&hooks::Kart_Director_calcBeforeStructure));
		m_UI_TimeControl_hook.hook(hooks::UI_Control_onCreate_index, reinterpret_cast<void *>(&hooks::UI_TimeControl_onCreate));

		g_hooking = this;
	}

	hooking::~hooking()
	{
		g_hooking = nullptr;

		if (m_enabled)
			disable();

		m_UI_TimeControl_hook.unhook(hooks::UI_Control_onCreate_index);
		m_Kart_Director_hook.unhook(hooks::Director_calcBeforeStructure_index);
		m_Item_KartItem_hook.unhook(hooks::Director_calcBeforeStructure_index);
		m_Item_ItemObjStar_hook.unhook(hooks::ItemObjBase_initEntryInnerBefore_index);
		m_Item_ItemObjKouraR_hook.unhook(hooks::ItemObjKoura_getStripeColor_index);
		m_Item_ItemObjKouraG_hook.unhook(hooks::ItemObjKoura_getStripeColor_index);
		m_Item_ItemObjKouraB_hook.unhook(hooks::ItemObjKoura_getStripeColor_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_stateInitUse_index);
		m_Item_ItemObjGesso_hook.unhook(hooks::ItemObjBase_initEntryInnerBefore_index);
		m_Item_ItemDirector_hook.unhook(hooks::Director_calcBeforeStructure_index);
	}

    void hooking::enable()
	{
		m_Item_ItemDirector_hook.enable();
		m_Item_ItemObjGesso_hook.enable();
		m_Item_ItemObjKiller_hook.enable();
		m_Item_ItemObjKouraB_hook.enable();
		m_Item_ItemObjKouraG_hook.enable();
		m_Item_ItemObjKouraR_hook.enable();
		m_Item_ItemObjStar_hook.enable();
		m_Item_KartItem_hook.enable();
		m_Kart_Director_hook.enable();
		m_UI_TimeControl_hook.enable();

		m_Effect_KartEffect_calcTireEffectWheelSpin_hook.enable();
		m_Item_ItemDirector_clearItem_hook.enable();
		m_Item_ItemDirector_entryItem_hook.enable();
		m_Item_ItemDirector_itemEventRecvHandler_hook.enable();
		m_Item_ItemObjBase_calc_hook.enable();
		m_Item_ItemObjBase_setStateSelfMove_hook.enable();
		m_Item_ItemObjFlower_stateEquipHang_hook.enable();
		m_Item_ItemObjKouraB_stateEquipHang_hook.enable();
		m_Item_ItemObjKouraG_stateInitSelfMoveImpl_hook.enable();
		m_Item_ItemObjKouraR_stateInitComeBackDown_hook.enable();
		m_Item_ItemObjThunderDirector_entryOtherThunder_hook.enable();
		m_Item_ItemSlot_isStock_hook.enable();
		m_Item_KartItem_KartItem_hook.enable();
		m_Kart_NetData_read_hook.enable();
		m_Kart_NetData_send_hook.enable();
		m_Kart_Rigid_updateVel_hook.enable();
		m_Kart_Unit_calcMove_hook.enable();
		m_Kart_Unit_Unit_hook.enable();
		m_Kart_VehicleMove_startKillerImpl_hook.enable();
		m_Kart_VehicleReact_reactAccidentCommon_hook.enable();
		m_Menu3D_GarageDirector_isEndMiiIntroduction_hook.enable();
		m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived_hook.enable();
		m_Net_NetworkEngine_sendUnreliableCore_hook.enable();
		m_Net_NetworkFriendsManager_updateFriendInfo_hook.enable();
		m_Net_NetworkGameMgr_requestGoal_0x4_hook.enable();
		m_Net_NetworkItemSlotMgr_Buffer_setEquipItemType_hook.enable();
		m_RaceSys_LapRankChecker_calcLapPosition_hook.enable();
		m_sead_BufferedSafeString_format_hook.enable();
		m_sead_PtrArrayImpl_allocBuffer_hook.enable();
		m_System_KDPadInputer_calcInput_hook.enable();
		m_System_SystemSaveData_initCecComment_hook.enable();
		m_System_SystemSaveData_set_hook.enable();

		m_Item_GetExtraItemNum_hook.enable();
		m_Item_GetNumInItemType_hook.enable();
		m_Item_GetNumInItemTypeNet_hook.enable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x34_hook.enable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x58_hook.enable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x64_hook.enable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x78_hook.enable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8_hook.enable();
		m_Item_ItemDirector_createBeforeStructure_0x548_hook.enable();
		m_Item_ItemObjBase_stateEquipMulti_0x4F8_hook.enable();
		m_Item_ItemObjGesso_stateUse_0x28_hook.enable();
		m_Kart_Director_createBeforeStructure_0x284_hook.enable();
		m_Kart_Unit_startStarColor_0x4_hook.enable();
		m_Kart_Unit_updateStarColor_0x4_hook.enable();
		m_Kart_VehicleMove_calcMoveControlCommon_0x7EC_hook.enable();
		m_Kart_VehicleMove_calcMoveControlGnd_0x18_hook.enable();
		m_Kart_VehicleMove_isMiniTurboOverLv1_0x8_hook.enable();
		m_Kart_VehicleMove_startPress_0x20_hook.enable();
		m_Kart_VehicleMove_startThunder_0x14_hook.enable();
		m_Kart_VehicleReact_calcReact_0x20_hook.enable();
		m_Kart_VehicleReact_calcReact_0x4C_hook.enable();
		m_Kart_VehicleReact_reactAccidentCommon_0x98_hook.enable();
		m_Kart_VehicleReact_reactAccidentCommon_0xAC_hook.enable();
		m_Net_NetworkEventModule_calc_0xB4_hook.enable();
		m_Object_CharacterEngine_creator_2_0x184_hook.enable();
		m_Object_CharacterEngine_creator_6_0x184_hook.enable();
		m_RaceSys_ModeManagerRace_calcCountDown_0x18_hook.enable();
		m_Sequence_BaseRacePage_subBombBlue_0x4_hook.enable();
		m_Sequence_BaseRacePage_subBombRed_0x4_hook.enable();
		m_Sequence_BaseRacePage_subEquipItem_0xAC_hook.enable();
		m_Sequence_MenuMultiCourseVote_onPagePreStep_0x344_hook.enable();
		m_Sequence_RacePage_genRaceGP_0x7C_hook.enable();
		m_UI_BgRaceMapCharaControl_onCalc_0x14_hook.enable();
		m_UI_BgRaceZoomMapControl_onCreate_0x20_hook.enable();
		m_UI_RaceItemBoxControl_onCalc_0x23C_hook.enable();
		m_UI_RaceItemBoxControl_onCalc_0x254_hook.enable();

		m_enabled = true;
	}

	void hooking::disable()
	{
		m_enabled = false;

		m_UI_RaceItemBoxControl_onCalc_0x254_hook.disable();
		m_UI_RaceItemBoxControl_onCalc_0x23C_hook.disable();
		m_UI_BgRaceZoomMapControl_onCreate_0x20_hook.disable();
		m_UI_BgRaceMapCharaControl_onCalc_0x14_hook.disable();
		m_Sequence_RacePage_genRaceGP_0x7C_hook.disable();
		m_Sequence_MenuMultiCourseVote_onPagePreStep_0x344_hook.disable();
		m_Sequence_BaseRacePage_subEquipItem_0xAC_hook.disable();
		m_Sequence_BaseRacePage_subBombRed_0x4_hook.disable();
		m_Sequence_BaseRacePage_subBombBlue_0x4_hook.disable();
		m_RaceSys_ModeManagerRace_calcCountDown_0x18_hook.disable();
		m_Object_CharacterEngine_creator_6_0x184_hook.enable();
		m_Object_CharacterEngine_creator_2_0x184_hook.enable();
		m_Net_NetworkEventModule_calc_0xB4_hook.disable();
		m_Kart_VehicleReact_reactAccidentCommon_0xAC_hook.disable();
		m_Kart_VehicleReact_reactAccidentCommon_0x98_hook.disable();
		m_Kart_VehicleReact_calcReact_0x4C_hook.disable();
		m_Kart_VehicleReact_calcReact_0x20_hook.disable();
		m_Kart_VehicleMove_startThunder_0x14_hook.disable();
		m_Kart_VehicleMove_startPress_0x20_hook.disable();
		m_Kart_VehicleMove_isMiniTurboOverLv1_0x8_hook.disable();
		m_Kart_VehicleMove_calcMoveControlGnd_0x18_hook.disable();
		m_Kart_VehicleMove_calcMoveControlCommon_0x7EC_hook.disable();
		m_Kart_Unit_updateStarColor_0x4_hook.disable();
		m_Kart_Unit_startStarColor_0x4_hook.disable();
		m_Kart_Director_createBeforeStructure_0x284_hook.disable();
		m_Item_ItemObjGesso_stateUse_0x28_hook.disable();
		m_Item_ItemObjBase_stateEquipMulti_0x4F8_hook.disable();
		m_Item_ItemDirector_createBeforeStructure_0x548_hook.disable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8_hook.disable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x78_hook.disable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x64_hook.disable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x58_hook.disable();
		m_Item_ItemDirector_calcKeyInputEachPlayer_0x34_hook.disable();
		m_Item_GetNumInItemTypeNet_hook.disable();
		m_Item_GetNumInItemType_hook.disable();
		m_Item_GetExtraItemNum_hook.disable();

		m_System_SystemSaveData_set_hook.disable();
		m_System_SystemSaveData_initCecComment_hook.disable();
		m_System_KDPadInputer_calcInput_hook.disable();
		m_sead_PtrArrayImpl_allocBuffer_hook.disable();
		m_sead_BufferedSafeString_format_hook.disable();
		m_RaceSys_LapRankChecker_calcLapPosition_hook.disable();
		m_Net_NetworkItemSlotMgr_Buffer_setEquipItemType_hook.disable();
		m_Net_NetworkGameMgr_requestGoal_0x4_hook.disable();
		m_Net_NetworkFriendsManager_updateFriendInfo_hook.disable();
		m_Net_NetworkEngine_sendUnreliableCore_hook.disable();
		m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived_hook.disable();
		m_Menu3D_GarageDirector_isEndMiiIntroduction_hook.disable();
		m_Kart_VehicleReact_reactAccidentCommon_hook.disable();
		m_Kart_VehicleMove_startKillerImpl_hook.disable();
		m_Kart_Unit_Unit_hook.disable();
		m_Kart_Unit_calcMove_hook.disable();
		m_Kart_Rigid_updateVel_hook.disable();
		m_Kart_NetData_send_hook.disable();
		m_Kart_NetData_read_hook.disable();
		m_Item_KartItem_KartItem_hook.disable();
		m_Item_ItemSlot_isStock_hook.disable();
		m_Item_ItemObjThunderDirector_entryOtherThunder_hook.disable();
		m_Item_ItemObjKouraR_stateInitComeBackDown_hook.disable();
		m_Item_ItemObjKouraG_stateInitSelfMoveImpl_hook.disable();
		m_Item_ItemObjKouraB_stateEquipHang_hook.disable();
		m_Item_ItemObjFlower_stateEquipHang_hook.disable();
		m_Item_ItemObjBase_setStateSelfMove_hook.disable();
		m_Item_ItemObjBase_calc_hook.disable();
		m_Item_ItemDirector_itemEventRecvHandler_hook.disable();
		m_Item_ItemDirector_entryItem_hook.disable();
		m_Item_ItemDirector_clearItem_hook.disable();
		m_Effect_KartEffect_calcTireEffectWheelSpin_hook.disable();

		m_UI_TimeControl_hook.disable();
		m_Kart_Director_hook.disable();
		m_Item_KartItem_hook.disable();
		m_Item_ItemObjStar_hook.disable();
		m_Item_ItemObjKouraR_hook.disable();
		m_Item_ItemObjKouraG_hook.disable();
		m_Item_ItemObjKouraB_hook.disable();
		m_Item_ItemObjKiller_hook.disable();
		m_Item_ItemObjGesso_hook.disable();
		m_Item_ItemDirector_hook.disable();
	}
}