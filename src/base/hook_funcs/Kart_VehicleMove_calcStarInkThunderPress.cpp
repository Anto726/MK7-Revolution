#include <base/hooks.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

// Could be read from the game
#define THRESHOLD 1

namespace base
{
	void hook_funcs::Kart_VehicleMove_calcStarInkThunderPress(Kart::VehicleMove *_this)
	{
		if (_this->m_is_master && !_this->m_is_net_recv)
		{
			if (g_menu->m_infinite_star->IsActivated())
				if (_this->m_star_frames <= THRESHOLD)
					_this->m_star_frames = THRESHOLD + 1;

			if (g_menu->m_infinite_ink->IsActivated())
				if (_this->m_ink_frames <= THRESHOLD)
					_this->m_ink_frames = THRESHOLD + 1;

			if (g_menu->m_infinite_thunder->IsActivated())
				if (_this->m_thunder_frames <= THRESHOLD)
					_this->m_thunder_frames = THRESHOLD + 1;

			if (g_menu->m_infinite_press->IsActivated())
				if (_this->m_press_frames <= THRESHOLD)
				{
					_this->m_press_frames = THRESHOLD + 1;
					_this->m_press_size = *g_pointers->m_press_frames_kart_size;
				}
		}

		g_hooks->m_Kart_VehicleMove_calcStarInkThunderPress.call_original<void>(_this);
	}
}