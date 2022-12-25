#include <base/hooks.hpp>

#include <base/menu.hpp>

#include <Kart/VehicleReact.hpp>

namespace base
{
	void hook_funcs::Kart_VehicleReact_calcReact(Kart::VehicleReact *_this)
	{
		bool is_intangible_original;

        if (g_menu->m_intangibility_entry->IsActivated())
        {
            is_intangible_original = _this->m_is_intangible;
            _this->m_is_intangible ^= true;

            g_hooks->m_Kart_VehicleReact_calcReact.call_original<void>(_this);

			// It could be XORed again, but just to be sure (in case there's other patches in the original function), restore the original value
			_this->m_is_intangible = is_intangible_original;
			return;
        }

		g_hooks->m_Kart_VehicleReact_calcReact.call_original<void>(_this);
	}
}