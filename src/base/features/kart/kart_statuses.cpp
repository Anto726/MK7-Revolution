#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Kart/Unit.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
	void features::kart::kart_statuses(Kart::Unit *_this)
	{
		if (g_menu->m_kart_statuses_entry->IsActivated() && _this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
		{
			auto const &settings = g_settings.m_options["kart"]["kart_statuses"];
			
			if (settings["ink"] && _this->m_vehicle->m_ink_frames <= c_status_threshold)
				_this->m_vehicle->m_ink_frames = c_status_threshold + 1;

			if (settings["press"] && _this->m_vehicle->m_press_frames <= c_status_threshold)
			{
				_this->m_vehicle->m_press_frames = c_status_threshold + 1;
				_this->m_vehicle->m_press_size = *g_pointers->m_press_frames_kart_size;
			}

			if (settings["star"] && _this->m_vehicle->m_star_frames <= c_status_threshold)
				_this->m_vehicle->m_star_frames = c_status_threshold + 1;

			if (settings["thunder"] && _this->m_vehicle->m_thunder_frames <= c_status_threshold)
				_this->m_vehicle->m_thunder_frames = c_status_threshold + 1;
		}
	}
}