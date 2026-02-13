#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/Vehicle/VehicleReact.hpp>

namespace base
{
	bool features::kart::invincibility::calc(Kart::VehicleReact *_this)
	{
		return g_menu->m_invincibility_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv;
	}

	s32 features::kart::invincibility::press_thunder(Kart::VehicleMove *_this)
    {
        if (g_menu->m_invincibility_entry->IsActivated() && _this->m_is_master)
            return 1;

        return _this->m_star_frames;
    }
}