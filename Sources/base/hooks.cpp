#include <base/hooks.hpp>

#include <base/pointers.hpp>

namespace base
{
    hooks::hooks()
	:
		m_Item_KartItem("Item::KartItem", g_pointers->m_Item_KartItem, hook_funcs::Item_KartItem_count),

		m_Kart_VehicleReact_calcReact("Kart::VehicleReact::calcReact", g_pointers->m_Kart_VehicleReact_calcReact, reinterpret_cast<void *>(&hook_funcs::Kart_VehicleReact_calcReact)),

		m_RaceSys_LapRankChecker_calcLapPosition("RaceSys::LapRankChecker::calcLapPosition_", g_pointers->m_RaceSys_LapRankChecker_calcLapPosition, reinterpret_cast<void *>(&hook_funcs::RaceSys_LapRankChecker_calcLapPosition))
	{
		m_Item_KartItem.hook(hook_funcs::Item_KartItem_initBeforeStructure_index, reinterpret_cast<void *>(&hook_funcs::Item_KartItem_initBeforeStructure));
		m_Item_KartItem.hook(hook_funcs::Item_KartItem_calcBeforeStructure_index, reinterpret_cast<void *>(&hook_funcs::Item_KartItem_calcBeforeStructure));

		g_hooks = this;
	}

	hooks::~hooks()
	{
		g_hooks = nullptr;
	}

    void hooks::enable()
	{
		m_Item_KartItem.enable();

		m_Kart_VehicleReact_calcReact.enable();

		m_RaceSys_LapRankChecker_calcLapPosition.enable();
	}

	void hooks::disable()
	{
		m_RaceSys_LapRankChecker_calcLapPosition.disable();

		m_Kart_VehicleReact_calcReact.disable();

		m_Item_KartItem.disable();
	}
}