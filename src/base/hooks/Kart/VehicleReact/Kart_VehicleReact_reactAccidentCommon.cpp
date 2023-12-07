#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
	void hooks::Kart_VehicleReact_reactAccidentCommon(Kart::VehicleReact *_this, Kart::VehicleReact::ECallType call_type, int unk1, int unk2, Kart::VehicleReact::EAcdType acd_type, sead::Vector3f *unk3, sead::Vector3f *unk4)
	{
		if (features::kart::invincibility(_this))
			return;

		g_hooking->m_Kart_VehicleReact_reactAccidentCommon_hook.call_original<void>(_this, call_type, unk1, unk2, acd_type, unk3, unk4);
	}
}