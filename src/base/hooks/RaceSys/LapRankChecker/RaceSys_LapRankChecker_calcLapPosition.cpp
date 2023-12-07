#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
	void hooks::RaceSys_LapRankChecker_calcLapPosition(RaceSys::LapRankChecker *_this, RaceSys::LapRankChecker::KartInfo *kart_info)
	{
		features::network::no_disconnect(_this);

		g_hooking->m_RaceSys_LapRankChecker_calcLapPosition_hook.call_original<void>(_this, kart_info);
	}
}