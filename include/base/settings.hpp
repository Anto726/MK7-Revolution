#pragma once

#include <base/services/rainbow_service.hpp>

#include <3ds/types.h>
#include <3ds/services/frd.h>

#include <Item/eItemSlot.hpp>
#include <Item/eItemType.hpp>
#include <RaceSys/ECourseID.hpp>

#include <map>
#include <set>

namespace base
{
	class settings
	{
	public:
		bool load();
		bool store();
		bool reset();

		struct options
		{
			struct item
			{
				struct disable_item_clear
				{
					bool thunder{ true };
					bool recover{ false };
				}
				disable_item_clear;

				struct item_drop
				{
					enum class mode : u8 { Drop, Pop, } mode{ mode::Pop };
				}
				item_drop;

				struct item_fixes
				{
					bool blue_shell_battle_respawn{ true };
					bool preview_minimap_explosion{ true };
					bool star_acceleration{ false };
				}
				item_fixes;

				struct item_hang
				{
					std::map<Item::eItemType, bool> items
					{
						{ Item::eItemType::Kinoko, true },
						{ Item::eItemType::Star, false },
						{ Item::eItemType::KouraB, true },
						{ Item::eItemType::Gesso, false },
						{ Item::eItemType::Flower, true },
					};
				}
				item_hang;

				struct item_limiters
				{
					struct items_value { bool enabled{ false }; u32 amount{ 0 }; };
					std::map<Item::eItemType, items_value> items
					{
						{ Item::eItemType::KouraB, { true, 8 } },
						{ Item::eItemType::Bomhei, { true, 32 } },
					};
				}
				item_limiters;

				struct item_model
				{
					enum class type : u8 { Default, Banana, Bomhei, Flower, Gesso, Kinoko, KouraB, KouraG, KouraR, Star, Tail, KouraBUnused };
					std::map<Item::eItemType, type> items
					{
						{ Item::eItemType::Banana, type::Default },
						{ Item::eItemType::Bomhei, type::Default },
						{ Item::eItemType::Flower, type::Default },
						{ Item::eItemType::Gesso, type::Default },
						{ Item::eItemType::Kinoko, type::Default },
						{ Item::eItemType::KouraB, type::KouraBUnused },
						{ Item::eItemType::KouraG, type::KouraR },
						{ Item::eItemType::KouraR, type::KouraG },
						{ Item::eItemType::Star, type::Default },
						{ Item::eItemType::Tail, type::Default },
					};
				}
				item_model;

				struct item_rain
				{
					std::set<Item::eItemType> items
					{
						Item::eItemType::KouraG,
						Item::eItemType::KouraR,
						Item::eItemType::Banana,
						Item::eItemType::Kinoko,
						Item::eItemType::Star,
					};
					bool owned{ true };
					bool multi{ false };
					bool self{ true };
					struct speed { bool enabled; float value; } speed{ true, 64.f };
					u32 delay{ 15 };
					enum class shape : u8 { Square, Circle, } shape{ shape::Square };
					float height{ 128.f };
					float width{ 256.f };
				}
				item_rain;

				struct item_rapidfire
				{
					enum class mode : u8 { X, L, } mode{ mode::L };
					u32 delay{ 3 };
				}
				item_rapidfire;

				struct item_selfstrike
				{
					enum class mode : u8 { Default, Self, Both, };
					std::map<Item::eItemType, mode> items
					{
						{ Item::eItemType::Thunder, mode::Both },
						{ Item::eItemType::Gesso, mode::Self },
					};
				}
				item_selfstrike;

				struct item_terrain
				{
					std::set<Item::eItemType> items
					{
						Item::eItemType::KouraG,
						Item::eItemType::KouraR,
						Item::eItemType::Banana,
						Item::eItemType::Kinoko,
						Item::eItemType::Star,
						Item::eItemType::Bomhei,
					};
					u32 delay{ 30 };
					enum class mode : u8 { EnemyPoint, ItemPoint, JugemPoint, StartPoint, } mode { mode::ItemPoint };
				}
				item_terrain;

				struct item_usage
				{
					enum class type : u8 { Accident, Recover, Vanish, Killer, Dokan, Goal, };
					std::map<type, bool> toggles
					{
						{ type::Accident, true },
						{ type::Recover, false },
						{ type::Vanish, false },
						{ type::Killer, true },
						{ type::Dokan, false },
						{ type::Goal, false },
					};
				}
				item_usage;

				struct item_wheel
				{
					std::set<Item::eItemSlot> items
					{
						Item::eItemSlot::Banana,
						Item::eItemSlot::KouraG,
						Item::eItemSlot::KouraR,
						Item::eItemSlot::Kinoko,
						Item::eItemSlot::Bomhei,
						Item::eItemSlot::Gesso,
						Item::eItemSlot::KouraB,
						Item::eItemSlot::Star,
						Item::eItemSlot::Killer,
						Item::eItemSlot::Thunder,
						Item::eItemSlot::Flower,
						Item::eItemSlot::Tail,
						Item::eItemSlot::Seven,
					};

					struct cycler
					{
						bool enabled{ false };
						u32 delay{ 10 };
					}
					cycler;

					enum class decide_sound : u8 { Default, Enabled, Disabled, } decide_sound{ decide_sound::Disabled };
					enum class decide_anim : u8 { Default, None, Use, } decide_anim{ decide_anim::Use };
				}
				item_wheel;

				struct shell_gravity_modifier
				{
					enum class mode : u8 { Custom, Invert, } mode{ mode::Custom };
					float custom_value{ 0.f };
					struct offset
					{
						bool enabled{ false };
						float value{ 2.f };
					}
					offset;
				}
				shell_gravity_modifier;

				struct shell_stripe_color_modifier
				{
					bool keep{ true };
					
					struct type
					{
						bool enabled{ true };
						enum class mode : u8 { Custom, Rainbow, } mode{ mode::Rainbow };
						rainbow_service::rgb color{ 1.f, 1.f, 1.f };
					};
					std::map<Item::eItemType, type> shells
					{
						{ Item::eItemType::KouraB, { .color{ 0.f, 0.f, 1.f } } },
						{ Item::eItemType::KouraG, { .color{ 0.f, 1.f, 0.f } } },
						{ Item::eItemType::KouraR, { .color{ 1.f, 0.f, 0.f } } },
					};
				}
				shell_stripe_color_modifier;
			}
			item;

			struct kart
			{
				struct angry_wiggler
				{
					bool keep{ true };
				}
				angry_wiggler;

				struct future_fly
				{
					bool pitch_keep{ false };
					float yaw_strength{ 3.5f };
					float pitch_limit{ 0.5f };
					float speed_forward{ 23.f };
					float speed_backward{ 13.f };
				}
				future_fly;

				struct instant_acceleration
				{
					bool stop{ true };

					struct custom
					{
						bool enabled{ false };
						float value{ 10.f };
					}
					custom;
				}
				instant_acceleration;

				struct instant_miniturbo
				{
					enum class type : u8 { Blue, Red, } type{ type::Red };
				}
				instant_miniturbo;

				struct intangibility
				{
					bool invert{ true };
				}
				intangibility;

				struct kart_effect_color_modifier
				{
					struct type
					{
						bool enabled{ true };
						enum class mode : u8 { Custom, Rainbow, } mode{ mode::Rainbow };
						rainbow_service::rgb color{ 0.f, 1.f, 0.f };
					}
					star;
				}
				kart_effect_color_modifier;

				struct kart_statuses
				{
					enum class status : u8 { Trick, Blink, Ink, Stun, Press, Star, Thunder, Draft, };
					std::map<status, bool> toggles
					{
						{ status::Trick, false },
						{ status::Blink, true },
						{ status::Ink, true },
						{ status::Stun, false },
						{ status::Press, false },
						{ status::Star, false },
						{ status::Thunder, false },
						{ status::Draft, false },
					};
				}
				kart_statuses;

				struct kart_vulnerabilities
				{
					enum class status : u8 { Star, Blink, Killer, Hang, };
					std::map<status, bool> toggles
					{
						{ status::Star, true },
						{ status::Blink, false },
						{ status::Killer, false },
						{ status::Hang, false },
					};
				}
				kart_vulnerabilities;

				struct kart_usage
				{
					enum class type : u8 { Accident, };
					std::map<type, bool> toggles
					{
						{ type::Accident, true },
					};
				}
				kart_usage;

				struct killer_control
				{
					bool toggle{ true };
				}
				killer_control;
			}
			kart;

			struct network
			{
				struct course_vote_controller
				{
					enum class mode : u8 { Choose, Self, Direct, Filter, } mode{ mode::Self };
					enum class direct_mode : u8 { First, Last, } direct_mode{ direct_mode::First };
					enum class filter_mode : u8 { Whitelist, Blacklist, } filter_mode{ filter_mode::Whitelist };
					std::set<RaceSys::ECourseID> whitelist_set
					{
						{ RaceSys::ECourseID::Gctr_ToadCircuit },
						{ RaceSys::ECourseID::Bctr_WuhuIsland3 },
					};
					std::set<RaceSys::ECourseID> blacklist_set
					{
						{ RaceSys::ECourseID::Gctr_IceSlider },
						{ RaceSys::ECourseID::Bctr_IceRink },
					};
				}
				course_vote_controller;

				struct event_frame_modifier
				{
					u32 value{ 2 };
				}
				event_frame_modifier;

				struct force_replacement
				{
					std::set<Item::eItemType> items
					{
						{ Item::eItemType::KouraB },
						{ Item::eItemType::Thunder },
						{ Item::eItemType::Gesso },
					};
				}
				force_replacement;

				struct friend_info_modifier
				{
					struct principal_id
					{
						bool enabled{ false };
						bool notify{ true };
						enum class mode : u8 { Value, Random, } mode{ mode::Value };
						u32 value{ 1 };
					}
					principal_id;
				}
				friend_info_modifier;

				struct goal_score_modifier
				{
					struct type
					{
						bool enabled{ true };
						enum class mode : u8 { Win, Lose, } mode{ mode::Lose };
					}
					race, battle;
				}
				goal_score_modifier;

				struct invisibility
				{
					enum class mode : u8 { Position, Velocity, } mode{ mode::Position };
				}
				invisibility;

				struct item_delimiters
				{
					std::map<Item::eItemSlot, bool> items
					{
						{ Item::eItemSlot::Gesso, true },
						{ Item::eItemSlot::Thunder, true },
					};
				}
				item_delimiters;

				struct protections
				{
					struct item
					{
						bool killer_items{ false };
						bool tail_items{ false };
					}
					item;

					struct kart
					{
						bool accident_type{ true };
						bool respawn_point{ true };
					}
					kart;

					struct network
					{
						bool system_info{ true };
					}
					network;
				}
				protections;
			}
			network;

			struct ui
			{
				struct enhanced_minimap
				{
					bool extended_minimap_items{ true };
					bool directed_heads{ true };
					enum class battle_zoom : u8 { Default, Enabled, Disabled, } battle_zoom{ battle_zoom::Enabled };
				}
				enhanced_minimap;

				struct grand_prix_timer
				{
					float x{ -275.f };
					float y{ -205.f };
				}
				grand_prix_timer;

				struct mii_heads
				{
					bool map{ true };
					bool mii_bar{ true };
					bool rank_board{ true };
					bool results{ true };
				}
				mii_heads;
			}
			ui;
			
			struct base
			{
				struct enabled_features
				{
					bool show_all{ false };
				}
				enabled_features;

				struct friends
				{
					u32 delay{ 60 };
					std::set<FriendNotificationTypes> events
					{
						FRIEND_WENT_ONLINE,
						FRIEND_UPDATED_MII,
						FRIEND_UPDATED_PROFILE,
						FRIEND_WENT_OFFLINE,
					};
				}
				friends;
				
				struct rainbow
				{
					float hue_amount{ 1.f / 300.f };
					float saturation{ 1.f };
					float value{ 1.f };
				}
				rainbow;
			}
			base;
		}
		m_options{};

	private:
		bool load_impl();
	};

	inline settings g_settings;
}
