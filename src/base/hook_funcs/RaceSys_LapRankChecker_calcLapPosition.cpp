#include <base/hooks.hpp>

#include <base/menu.hpp>
#include <MenuEntryHelpers.hpp>

namespace base
{
	void hook_funcs::RaceSys_LapRankChecker_calcLapPosition(RaceSys::LapRankChecker *_this, RaceSys::LapRankChecker::KartInfo *kart_info)
	{
		if (g_menu->m_no_disconnect_entry->IsActivated())
		{
			_this->m_idle_timer_1 = 0;
			_this->m_idle_timer_2 = 0.f;
		}

		g_hooks->m_RaceSys_LapRankChecker_calcLapPosition.call_original<void>(_this, kart_info);
	}
}