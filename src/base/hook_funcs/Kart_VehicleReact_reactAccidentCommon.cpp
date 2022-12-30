#include <base/hooks.hpp>

#include <base/menu.hpp>

namespace base
{
	void hook_funcs::Kart_VehicleReact_reactAccidentCommon(Kart::VehicleReact *_this, Kart::VehicleReact::ECallType call_type, int unk1, int unk2, Kart::VehicleReact::EAcdType acd_type, sead::Vector3f *unk3, sead::Vector3f *unk4)
	{
		if (g_menu->m_invincibility_entry->IsActivated())
			if (_this->m_is_master && !_this->m_is_net_recv)
				return;

		g_hooks->m_Kart_VehicleReact_reactAccidentCommon.call_original<void>(_this, call_type, unk1, unk2, acd_type, unk3, unk4);
	}
}