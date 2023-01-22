#pragma once
#include <fwddec.hpp>

namespace base
{
	struct features
	{
		struct item
		{
			static void item_wheel_calc(Item::KartItem *);
			static void item_wheel_init(Item::KartItem *);
		};

		struct kart
		{
			static void blinking_invincibility(Kart::VehicleMove *);
			static void infinite_ink(Kart::VehicleMove *);
			static void infinite_press(Kart::VehicleMove *);
			static void infinite_star(Kart::VehicleMove *);
			static void infinite_thunder(Kart::VehicleMove *);
			static void intangibility_after(Kart::VehicleReact *, bool);
			static bool intangibility_before(Kart::VehicleReact *);
			static bool invincibility(Kart::VehicleReact *);

			static const s32 STATUS_THRESHOLD = 1 << 2;
		};

		struct network
		{
			static void no_disconnect(RaceSys::LapRankChecker *);
		};
	};
}