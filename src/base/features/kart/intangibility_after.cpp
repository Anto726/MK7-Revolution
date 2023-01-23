#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/Unit.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
	void features::kart::intangibility_after(Kart::Unit *_this, bool original)
	{
        if (g_menu->m_intangibility_entry->IsActivated())
			_this->m_vehicle->m_is_intangible = original;
	}
}