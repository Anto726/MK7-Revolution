#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

#include <Kart/Unit.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
	void features::kart::infinite_press(Kart::Unit *_this)
	{
		if (g_menu->m_infinite_press_entry->IsActivated())
			if (_this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
				if (_this->m_vehicle->m_press_frames <= c_status_threshold)
				{
					_this->m_vehicle->m_press_frames = c_status_threshold + 1;
					_this->m_vehicle->m_press_size = *g_pointers->m_press_frames_kart_size;
				}
	}
}