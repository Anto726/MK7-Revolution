#pragma once
#include <fwddec.hpp>
#include <RaceSys/ModeManagerBase.hpp> // RaceSys::ModeManagerBase::ERaceState

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
			static void instant_respawn(Kart::Unit *);
			static void instant_miniturbo(Kart::Unit *);

			static constexpr s32 STATUS_THRESHOLD = 1 << 2;
		};

		struct mode
		{
			static RaceSys::ModeManagerBase::ERaceState drive_during_countdown_before(RaceSys::ModeManagerBase *);
			static void drive_during_countdown_after(RaceSys::ModeManagerBase *, RaceSys::ModeManagerBase::ERaceState);
		};

		struct network
		{
			static void no_disconnect(RaceSys::LapRankChecker *);
		};
	};
}