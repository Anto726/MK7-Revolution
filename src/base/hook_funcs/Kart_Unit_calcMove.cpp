#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
	void hook_funcs::Kart_Unit_calcMove(Kart::Unit *_this, bool a2, bool a3)
	{
		features::kart::blinking_invincibility(_this);
		features::kart::infinite_star(_this);
		features::kart::infinite_ink(_this);
		features::kart::infinite_thunder(_this);
		features::kart::infinite_press(_this);
		auto intangibility = features::kart::intangibility_before(_this);

		g_hooks->m_Kart_Unit_calcMove.call_original<void>(_this, a2, a3);

		features::kart::intangibility_after(_this, intangibility);
	}
}