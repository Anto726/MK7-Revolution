#include <base/hooks.hpp>
#include <base/features.hpp>

namespace base
{
	void hook_funcs::Kart_Unit_calcReact(Kart::Unit *_this)
	{
		auto intangibility = features::kart::intangibility_before(_this);

		g_hooks->m_Kart_Unit_calcMove.call_original<void>(_this);

		features::kart::intangibility_after(_this, intangibility);
	}
}