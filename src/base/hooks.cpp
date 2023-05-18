#include <base/hooks.hpp>

#include <base/pointers.hpp>

namespace base
{
    hooks::hooks()
	:
		m_Item_ItemDirector("Item::ItemDirector", g_pointers->m_Item_ItemDirector, hook_funcs::Item_ItemDirector_count),

		m_Item_KartItem("Item::KartItem", g_pointers->m_Item_KartItem, hook_funcs::Item_KartItem_count),

		m_Kart_Director("Kart::Director", g_pointers->m_Kart_Director, hook_funcs::Kart_Director_count),

		m_Effect_KartEffect_calcTireEffectWheelSpin("Effect::KartEffect::_calcTireEffect_WheelSpin", g_pointers->m_Effect_KartEffect_calcTireEffectWheelSpin, reinterpret_cast<void *>(&hook_funcs::Effect_KartEffect_calcTireEffectWheelSpin)),

		m_Kart_Unit_calcMove("Kart::Unit::calcMove", g_pointers->m_Kart_Unit_calcMove, reinterpret_cast<void *>(hook_funcs::Kart_Unit_calcMove)),
		m_Kart_Unit_calcReact("Kart::Unit::calcReact", g_pointers->m_Kart_Unit_calcReact, reinterpret_cast<void *>(hook_funcs::Kart_Unit_calcReact)),

		m_Kart_VehicleReact_reactAccidentCommon("Kart::VehicleReact::reactAccidentCommon", g_pointers->m_Kart_VehicleReact_reactAccidentCommon, reinterpret_cast<void *>(&hook_funcs::Kart_VehicleReact_reactAccidentCommon)),

		m_RaceSys_LapRankChecker_calcLapPosition("RaceSys::LapRankChecker::calcLapPosition_", g_pointers->m_RaceSys_LapRankChecker_calcLapPosition, reinterpret_cast<void *>(&hook_funcs::RaceSys_LapRankChecker_calcLapPosition))
	{
		m_Item_ItemDirector.hook(hook_funcs::Item_ItemDirector_calcBeforeStructure_index, reinterpret_cast<void *>(&hook_funcs::Item_ItemDirector_calcBeforeStructure));

		m_Item_KartItem.hook(hook_funcs::Item_KartItem_initBeforeStructure_index, reinterpret_cast<void *>(&hook_funcs::Item_KartItem_initBeforeStructure));
		m_Item_KartItem.hook(hook_funcs::Item_KartItem_calcBeforeStructure_index, reinterpret_cast<void *>(&hook_funcs::Item_KartItem_calcBeforeStructure));

		m_Kart_Director.hook(hook_funcs::Kart_Director_calcBeforeStructure_index, reinterpret_cast<void *>(&hook_funcs::Kart_Director_calcBeforeStructure));

		g_hooks = this;
	}

	hooks::~hooks()
	{
		g_hooks = nullptr;

		if (m_enabled)
			disable();
	}

    void hooks::enable()
	{
		m_Item_ItemDirector.enable();

		m_Item_KartItem.enable();

		m_Kart_Director.enable();

		m_Effect_KartEffect_calcTireEffectWheelSpin.enable();

		m_Kart_Unit_calcMove.enable();
		m_Kart_Unit_calcReact.enable();

		m_Kart_VehicleReact_reactAccidentCommon.enable();

		m_RaceSys_LapRankChecker_calcLapPosition.enable();
		
		m_enabled = true;
	}

	void hooks::disable()
	{
		m_enabled = false;
		
		m_RaceSys_LapRankChecker_calcLapPosition.disable();

		m_Kart_VehicleReact_reactAccidentCommon.disable();

		m_Kart_Unit_calcReact.disable();
		m_Kart_Unit_calcMove.disable();

		m_Effect_KartEffect_calcTireEffectWheelSpin.disable();

		m_Kart_Director.disable();

		m_Item_KartItem.disable();

		m_Item_ItemDirector.disable();
	}
}