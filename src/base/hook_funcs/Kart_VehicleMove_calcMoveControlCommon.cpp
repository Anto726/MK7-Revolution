#include <base/hooks.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

namespace base
{
	void hook_funcs::Kart_VehicleMove_calcMoveControlCommon(Kart::VehicleMove *_this)
	{
		if (g_menu->m_blinking_invincibility_entry->IsActivated())
			if (_this->m_is_master && !_this->m_is_net_recv)
				if (_this->m_invincibility_frames <= 1)
					_this->m_invincibility_frames = *g_pointers->m_invincibility_frames_invisible_amount + *g_pointers->m_invincibility_frames_visible_amount;

		g_hooks->m_Kart_VehicleMove_calcMoveControlCommon.call_original<void>(_this);
	}
}