#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/VehicleReact.hpp>

namespace base
{
	bool features::kart::intangibility_before(Kart::VehicleReact *_this)
	{
		bool original{};

        if (g_menu->m_intangibility_entry->IsActivated())
        {
            original = _this->m_is_intangible;
            _this->m_is_intangible ^= true;
        }

		return original;
	}
}