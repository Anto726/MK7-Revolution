#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <base/game/kart/unit.hpp>

#include <Kart/Vehicle/Vehicle.hpp>

namespace base
{
	void features::kart::kart_statuses(game::kart::unit *_this)
	{
		using status = settings::options::kart::kart_statuses::status;

		if (g_menu->m_kart_statuses_entry->IsActivated() && _this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
		{
			auto const &kart_statuses = g_settings.m_options.kart.kart_statuses;

			if (kart_statuses.toggles.at(status::Trick) && _this->m_vehicle->m_trick_frames <= c_status_threshold)
				_this->m_vehicle->m_trick_frames = c_status_threshold + 1;

			if (kart_statuses.toggles.at(status::Blink) && _this->m_vehicle->m_invincibility_frames <= 1)
				_this->m_vehicle->m_invincibility_frames = *g_pointers->m_invincibility_frames_invisible_amount + *g_pointers->m_invincibility_frames_visible_amount;
			
			if (kart_statuses.toggles.at(status::Ink) && _this->m_vehicle->m_ink_frames <= c_status_threshold)
				_this->m_vehicle->m_ink_frames = c_status_threshold + 1;

			if (kart_statuses.toggles.at(status::Stun) && _this->m_vehicle->m_stun_frames <= c_status_threshold)
				_this->m_vehicle->m_stun_frames = c_status_threshold + 1;

			if (kart_statuses.toggles.at(status::Press) && _this->m_vehicle->m_press_frames <= c_status_threshold)
			{
				_this->m_vehicle->m_press_frames = c_status_threshold + 1;
				_this->m_vehicle->m_press_size = *g_pointers->m_press_frames_kart_size;
			}

			if (kart_statuses.toggles.at(status::Star) && _this->m_vehicle->m_star_frames <= c_status_threshold)
				_this->m_vehicle->m_star_frames = c_status_threshold + 1;

			if (kart_statuses.toggles.at(status::Thunder) && _this->m_vehicle->m_thunder_frames <= c_status_threshold)
				_this->m_vehicle->m_thunder_frames = c_status_threshold + 1;

			if (kart_statuses.toggles.at(status::Draft))
				_this->m_vehicle->m_draft_frames = c_status_threshold;
		}
	}
}