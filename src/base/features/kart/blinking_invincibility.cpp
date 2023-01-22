#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

#include <Kart/VehicleMove.hpp>

namespace base
{
	void features::kart::blinking_invincibility(Kart::VehicleMove *_this)
	{
		if (g_menu->m_blinking_invincibility_entry->IsActivated())
			if (_this->m_is_master && !_this->m_is_net_recv)
				if (_this->m_invincibility_frames <= 1)
					_this->m_invincibility_frames = *g_pointers->m_invincibility_frames_invisible_amount + *g_pointers->m_invincibility_frames_visible_amount;
	}
}