#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/Vehicle/VehicleReact.hpp>

namespace base
{
    bool features::kart::intangibility(Kart::VehicleReact *_this)
    {
        if (g_menu->m_intangibility_entry->IsActivated())
        {
			if (g_settings.m_options.kart.intangibility.invert)
            	return _this->m_is_intangible ^ true;

			return true;
        }

		return _this->m_is_intangible;
    }
}