#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
	void hook_funcs::Kart_VehicleMove_calcMoveControlCommon(Kart::VehicleMove *_this)
	{
		features::kart::blinking_invincibility(_this);

		g_hooks->m_Kart_VehicleMove_calcMoveControlCommon.call_original<void>(_this);
	}
}