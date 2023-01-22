#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/VehicleReact.hpp>

namespace base
{
	bool features::kart::invincibility(Kart::VehicleReact *_this)
	{
		return g_menu->m_invincibility_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv;
	}
}