#include <base/features.hpp>

#include <base/menu.hpp>

#include <RaceSys/LapRankChecker.hpp>

namespace base
{
	void features::network::no_disconnect(RaceSys::LapRankChecker *_this)
	{
		if (g_menu->m_no_disconnect_entry->IsActivated())
		{
			_this->m_idle_timer_1 = 0;
			_this->m_idle_timer_2 = 0.f;
		}
	}
}