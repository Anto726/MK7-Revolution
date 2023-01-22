#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
	void hook_funcs::RaceSys_LapRankChecker_calcLapPosition(RaceSys::LapRankChecker *_this, RaceSys::LapRankChecker::KartInfo *kart_info)
	{
		features::network::no_disconnect(_this);

		g_hooks->m_RaceSys_LapRankChecker_calcLapPosition.call_original<void>(_this, kart_info);
	}
}