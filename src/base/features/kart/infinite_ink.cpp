#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/Unit.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
	void features::kart::infinite_ink(Kart::Unit *_this)
	{
		if (g_menu->m_infinite_ink_entry->IsActivated())
			if (_this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
				if (_this->m_vehicle->m_ink_frames <= c_status_threshold)
					_this->m_vehicle->m_ink_frames = c_status_threshold + 1;
	}
}