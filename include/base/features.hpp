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
			static void blinking_invincibility(Kart::Unit *);
			static void infinite_ink(Kart::Unit *);
			static void infinite_press(Kart::Unit *);
			static void infinite_star(Kart::Unit *);
			static void infinite_thunder(Kart::Unit *);
			static void intangibility_after(Kart::Unit *, bool);
			static bool intangibility_before(Kart::Unit *);
			static bool invincibility(Kart::VehicleReact *);

			static constexpr s32 STATUS_THRESHOLD = 1 << 2;
		};

		struct network
		{
			static void no_disconnect(RaceSys::LapRankChecker *);
		};
	};
}