#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

#include <Kart/VehicleMove.hpp>

namespace base
{
	void features::kart::infinite_press(Kart::VehicleMove *_this)
	{
		if (g_menu->m_infinite_press->IsActivated())
			if (_this->m_is_master && !_this->m_is_net_recv)
				if (_this->m_press_frames <= STATUS_THRESHOLD)
				{
					_this->m_press_frames = STATUS_THRESHOLD + 1;
					_this->m_press_size = *g_pointers->m_press_frames_kart_size;
				}
	}
}