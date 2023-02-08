#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Kart/Unit.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
	void features::kart::instant_miniturbo(Kart::Unit *_this)
	{
		if (g_menu->m_instant_miniturbo_entry->IsActivated())
			if (_this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
				if (_this->m_vehicle->m_miniturbo_charge > 0)
					switch (g_settings.m_options["kart"]["instant_miniturbo"]["type"].get<u64>())
					{
						case 0: _this->m_vehicle->m_miniturbo_charge = *g_pointers->m_miniturbo_blue_threshold; break;
						case 1: _this->m_vehicle->m_miniturbo_charge = *g_pointers->m_miniturbo_red_threshold; break;
					}
	}
}