#include <base/hooking.hpp>

#include <base/pointers.hpp>

namespace base
{
    hooking::hooking()
	:
		m_Item_ItemDirector_hook("Item::ItemDirector", g_pointers->m_Item_ItemDirector, hooks::Director_count),
		m_Item_KartItem_hook("Item::KartItem", g_pointers->m_Item_KartItem, hooks::Director_count),
		m_Kart_Director_hook("Kart::Director", g_pointers->m_Kart_Director, hooks::Director_count),

		m_Item_ItemObjBase_setStateSelfMove_hook("Item::ItemObjBase::setState_SelfMove", g_pointers->m_Item_ItemObjBase_setStateSelfMove, reinterpret_cast<void *>(&hooks::Item_ItemObjBase_setStateSelfMove)),
		m_Item_ItemObjKouraR_stateInitComeBackDown_hook("Item::ItemObjKouraR::stateInitComeBackDown", g_pointers->m_Item_ItemObjKouraR_stateInitComeBackDown, reinterpret_cast<void *>(&hooks::Item_ItemObjKouraR_stateInitComeBackDown)),
		m_Effect_KartEffect_calcTireEffectWheelSpin_hook("Effect::KartEffect::_calcTireEffect_WheelSpin", g_pointers->m_Effect_KartEffect_calcTireEffectWheelSpin, reinterpret_cast<void *>(&hooks::Effect_KartEffect_calcTireEffectWheelSpin)),
		m_Kart_Unit_calcMove_hook("Kart::Unit::calcMove", g_pointers->m_Kart_Unit_calcMove, reinterpret_cast<void *>(&hooks::Kart_Unit_calcMove)),
		m_Kart_VehicleReact_calcReact_0x20_hook("Kart::VehicleReact::calcReact+0x20", g_pointers->m_Kart_VehicleReact_calcReact_0x20, reinterpret_cast<void *>(&hooks::Kart_VehicleReact_calcReact_0x20)),
		m_Kart_VehicleReact_reactAccidentCommon_hook("Kart::VehicleReact::reactAccidentCommon", g_pointers->m_Kart_VehicleReact_reactAccidentCommon, reinterpret_cast<void *>(&hooks::Kart_VehicleReact_reactAccidentCommon)),
		m_Net_NetworkEngine_sendUnreliableCore_hook("Net::NetworkEngine::sendUnreliableCore", g_pointers->m_Net_NetworkEngine_sendUnreliableCore, reinterpret_cast<void *>(&hooks::Net_NetworkEngine_sendUnreliableCore)),
		m_Net_NetworkSystemInfo_onReceivedCore_hook("Net::NetworkSystemInfo::onReceivedCore", g_pointers->m_Net_NetworkSystemInfo_onReceivedCore, reinterpret_cast<void *>(&hooks::Net_NetworkSystemInfo_onReceivedCore)),
		m_RaceSys_LapRankChecker_calcLapPosition_hook("RaceSys::LapRankChecker::calcLapPosition_", g_pointers->m_RaceSys_LapRankChecker_calcLapPosition, reinterpret_cast<void *>(&hooks::RaceSys_LapRankChecker_calcLapPosition))
	{
		m_Item_ItemDirector_hook.hook(hooks::Director_calcBeforeStructure_index, reinterpret_cast<void *>(&hooks::Item_ItemDirector_calcBeforeStructure));
		m_Item_KartItem_hook.hook(hooks::Director_initBeforeStructure_index, reinterpret_cast<void *>(&hooks::Item_KartItem_initBeforeStructure));
		m_Item_KartItem_hook.hook(hooks::Director_calcBeforeStructure_index, reinterpret_cast<void *>(&hooks::Item_KartItem_calcBeforeStructure));
		m_Kart_Director_hook.hook(hooks::Director_calcBeforeStructure_index, reinterpret_cast<void *>(&hooks::Kart_Director_calcBeforeStructure));

		g_hooking = this;
	}

	hooking::~hooking()
	{
		g_hooking = nullptr;

		if (m_enabled)
			disable();
	}

    void hooking::enable()
	{
		m_Item_ItemDirector_hook.enable();
		m_Item_KartItem_hook.enable();
		m_Kart_Director_hook.enable();

		m_Item_ItemObjBase_setStateSelfMove_hook.enable();
		m_Item_ItemObjKouraR_stateInitComeBackDown_hook.enable();
		m_Effect_KartEffect_calcTireEffectWheelSpin_hook.enable();
		m_Kart_Unit_calcMove_hook.enable();
		m_Kart_VehicleReact_calcReact_0x20_hook.enable();
		m_Kart_VehicleReact_reactAccidentCommon_hook.enable();
		m_Net_NetworkEngine_sendUnreliableCore_hook.enable();
		m_Net_NetworkSystemInfo_onReceivedCore_hook.enable();
		m_RaceSys_LapRankChecker_calcLapPosition_hook.enable();

		m_enabled = true;
	}

	void hooking::disable()
	{
		m_enabled = false;

		m_RaceSys_LapRankChecker_calcLapPosition_hook.disable();
		m_Net_NetworkSystemInfo_onReceivedCore_hook.disable();
		m_Net_NetworkEngine_sendUnreliableCore_hook.disable();
		m_Kart_VehicleReact_reactAccidentCommon_hook.disable();
		m_Kart_VehicleReact_calcReact_0x20_hook.disable();
		m_Kart_Unit_calcMove_hook.disable();
		m_Effect_KartEffect_calcTireEffectWheelSpin_hook.disable();
		m_Item_ItemObjKouraR_stateInitComeBackDown_hook.disable();
		m_Item_ItemObjBase_setStateSelfMove_hook.disable();

		m_Kart_Director_hook.disable();
		m_Item_KartItem_hook.disable();
		m_Item_ItemDirector_hook.disable();
	}
}