#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/Unit.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
	bool features::kart::intangibility_before(Kart::Unit *_this)
	{
		bool original{};

        if (g_menu->m_intangibility_entry->IsActivated())
        {
            original = _this->m_vehicle->m_is_intangible;
            _this->m_vehicle->m_is_intangible ^= true;
        }

		return original;
	}
}