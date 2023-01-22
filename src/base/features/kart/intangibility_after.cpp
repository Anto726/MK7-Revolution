#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/VehicleReact.hpp>

namespace base
{
	void features::kart::intangibility_after(Kart::VehicleReact *_this, bool original)
	{
        if (g_menu->m_intangibility_entry->IsActivated())
			_this->m_is_intangible = original;
	}
}