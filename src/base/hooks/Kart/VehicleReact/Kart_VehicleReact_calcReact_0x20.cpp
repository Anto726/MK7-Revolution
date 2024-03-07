#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
	void hooks::Kart_VehicleReact_calcReact_0x20()
	{
		asm volatile
		(
			"push {r1-r3, lr}\n"
			"bl __intangibility\n"
			"pop {r1-r3, pc}\n"
		);
	}

	extern "C" auto __intangibility(Kart::VehicleReact *_this)
	{				
		return base::features::kart::intangibility(_this);
	}
}