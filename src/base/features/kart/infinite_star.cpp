#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/Unit.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
	void features::kart::infinite_star(Kart::Unit *_this)
	{
		if (g_menu->m_infinite_star_entry->IsActivated())
			if (_this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
				if (_this->m_vehicle->m_star_frames <= STATUS_THRESHOLD)
					_this->m_vehicle->m_star_frames = STATUS_THRESHOLD + 1;
	}
}