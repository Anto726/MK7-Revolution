#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/VehicleMove.hpp>

namespace base
{
	void features::kart::infinite_thunder(Kart::VehicleMove *_this)
	{
		if (g_menu->m_infinite_thunder->IsActivated())
			if (_this->m_is_master && !_this->m_is_net_recv)
				if (_this->m_thunder_frames <= STATUS_THRESHOLD)
					_this->m_thunder_frames = STATUS_THRESHOLD + 1;
	}
}