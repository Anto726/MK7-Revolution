#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
	void hooks::Kart_Unit_calcReact(Kart::Unit *_this)
	{
		auto intangibility = features::kart::intangibility_before(_this);

		g_hooking->m_Kart_Unit_calcMove_hook.call_original<void>(_this);

		features::kart::intangibility_after(_this, intangibility);
	}
}