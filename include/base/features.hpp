#pragma once

#include <forward.hpp>
#include <RaceSys/ModeManagerBase.hpp> // RaceSys::ModeManagerBase::ERaceState

namespace base
{
	struct features
	{
		struct item
		{
			static bool blue_shell_battle_crash_fix(Item::ItemObjKouraR *);
			static void drop_items(Item::ItemObjBase *);
			static void item_rain(Item::KartItem *);
			static void item_wheel_calc(Item::KartItem *);
			static void item_wheel_init(Item::KartItem *);
		};

		struct kart
		{
			static bool intangibility(Kart::VehicleReact *);
			static bool invincibility(Kart::VehicleReact *);
			static void instant_respawn(Kart::Unit *);
			static void instant_miniturbo(Kart::Unit *);
			static void kart_statuses(Kart::Unit *);

			static constexpr s32 c_status_threshold = 1 << 2;
			static constexpr s32 c_respawn_threshold = 1;
		};

		struct mode
		{
			static RaceSys::ModeManagerBase::ERaceState drive_during_countdown_before(RaceSys::ModeManagerBase *);
			static void drive_during_countdown_after(RaceSys::ModeManagerBase *, RaceSys::ModeManagerBase::ERaceState);
		};

		struct network
		{
			static void high_data_rate(u32 *);
			static void no_disconnect(RaceSys::LapRankChecker *);
			static bool protections_system_info(Net::NetworkReceivedInfo *);
		};
	};
}