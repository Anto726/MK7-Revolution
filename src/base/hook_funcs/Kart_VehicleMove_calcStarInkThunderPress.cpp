#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
	void hook_funcs::Kart_VehicleMove_calcStarInkThunderPress(Kart::VehicleMove *_this)
	{
		features::kart::infinite_star(_this);
		features::kart::infinite_ink(_this);
		features::kart::infinite_thunder(_this);
		features::kart::infinite_press(_this);

		g_hooks->m_Kart_VehicleMove_calcStarInkThunderPress.call_original<void>(_this);
	}
}