#include <base/menu.hpp>

#include <Item/eItemSlot.hpp>
#include <Item/eItemType.hpp>

#include <base/entries.hpp>
#include <base/hooking.hpp>
#include <base/patches.hpp>
#include <base/settings.hpp>

#include <base/services/message_service.hpp>
#include <base/services/rainbow_service.hpp>

#include <format>

#define DEFAULT_ENTRY [](MenuEntry *) {}

namespace base
{
    using namespace CTRPluginFramework;
    
    menu::menu()
    :
        m_plugin_menu(new PluginMenu(NAME, ABOUT)),

        m_item_wheel_entry(new MenuEntry("Item Wheel", DEFAULT_ENTRY, entries::item::item_wheel_menu)),
        m_item_rapidfire_entry(new MenuEntry("Item Rapid-Fire", DEFAULT_ENTRY, entries::item::item_rapidfire_menu)),
        m_item_usage_entry(new MenuEntry("Item Usage", DEFAULT_ENTRY, entries::item::item_usage_menu)),
        m_item_selfstrike_entry(new MenuEntry("Item Self-Strike", DEFAULT_ENTRY, entries::item::item_selfstrike_menu)),
        m_item_drop_entry(new MenuEntry("Item Drop", DEFAULT_ENTRY, entries::item::item_drop_menu)),
        m_item_hang_entry(new MenuEntry("Item Hang", DEFAULT_ENTRY, entries::item::item_hang_menu)),
        m_item_rain_entry(new MenuEntry("Item Rain", DEFAULT_ENTRY, entries::item::item_rain_menu)),
        m_item_terrain_entry(new MenuEntry("Item Terrain", DEFAULT_ENTRY, entries::item::item_terrain_menu)),
        m_item_limiters_entry(new MenuEntry("Item Limiters", DEFAULT_ENTRY, entries::item::item_limiters_menu)),
        m_item_model_entry(new MenuEntry("Item Model", DEFAULT_ENTRY, entries::item::item_model_menu)),
        m_disable_item_clear_entry(new MenuEntry("Disable Item Clear", DEFAULT_ENTRY, entries::item::disable_item_clear_menu)),
        m_shell_gravity_modifier_entry(new MenuEntry("Shell Gravity Modifier", DEFAULT_ENTRY, entries::item::shell_gravity_modifier_menu)),
        m_shell_stripe_color_modifier_entry(new MenuEntry("Shell Stripe Color Modifier", entries::item::shell_stripe_color_modifier::game, entries::item::shell_stripe_color_modifier::menu)),
        m_item_billboard_entry(new MenuEntry("Item Billboard", DEFAULT_ENTRY)),
        m_item_fixes_entry(new MenuEntry("Item Fixes", DEFAULT_ENTRY, entries::item::item_fixes_menu)),

        m_invincibility_entry(new MenuEntry("Invincibility", DEFAULT_ENTRY)),
        m_kart_vulnerabilities_entry(new MenuEntry("Kart Vulnerabilities", DEFAULT_ENTRY, entries::kart::kart_vulnerabilities_menu)),
        m_intangibility_entry(new MenuEntry("Intangibility", DEFAULT_ENTRY, entries::kart::intangibility_menu)),
        m_kart_usage_entry(new MenuEntry("Kart Usage", DEFAULT_ENTRY, entries::kart::kart_usage_menu)),
        m_kart_statuses_entry(new MenuEntry("Kart Statuses", DEFAULT_ENTRY, entries::kart::kart_statuses_menu)),
        m_killer_control_entry(new MenuEntry("Killer Control", DEFAULT_ENTRY, entries::kart::killer_control_menu)),
        m_future_fly_entry(new MenuEntry("Future Fly", DEFAULT_ENTRY, entries::kart::future_fly_menu)),
        m_instant_acceleration_entry(new MenuEntry("Instant Acceleration", DEFAULT_ENTRY, entries::kart::instant_acceleration_menu)),
        m_instant_respawn_entry(new MenuEntry("Instant Respawn", DEFAULT_ENTRY)),
        m_instant_miniturbo_entry(new MenuEntry("Instant Mini-Turbo", DEFAULT_ENTRY, entries::kart::instant_miniturbo_menu)),
        m_kart_effect_color_modifier_entry(new MenuEntry("Kart Effect Color Modifier", DEFAULT_ENTRY, entries::kart::kart_effect_color_modifier_menu)),
        m_angry_wiggler_entry(new MenuEntry("Angry Wiggler", entries::kart::angry_wiggler::game, entries::kart::angry_wiggler::menu)),

        m_drive_during_sync_entry(new MenuEntry("Drive During Sync", DEFAULT_ENTRY)),
        m_trigger_respawn_entry(new MenuEntry("Trigger Respawn", DEFAULT_ENTRY)),
        m_stalking_entry(new MenuEntry("Stalking", DEFAULT_ENTRY)),

        m_kart_warp_entry(new MenuEntry("Kart Warp", DEFAULT_ENTRY)),
        m_disable_killer_lag_entry(new MenuEntry("Disable Killer Lag", DEFAULT_ENTRY)),
        m_item_delimiters_entry(new MenuEntry("Item Delimiters", DEFAULT_ENTRY, entries::network::item_delimiters_menu)),
        m_high_data_rate_entry(new MenuEntry("High Data Rate", DEFAULT_ENTRY)),
        m_invisibility_entry(new MenuEntry("Invisibility", DEFAULT_ENTRY, entries::network::invisibility_menu)),
        m_disable_idle_disconnect_entry(new MenuEntry("Disable Idle Disconnect", DEFAULT_ENTRY)),
        m_instant_disconnect_entry(new MenuEntry("Instant Disconnect", nullptr, entries::network::instant_disconnect_game)),
        m_course_vote_controller_entry(new MenuEntry("Course Vote Controller", DEFAULT_ENTRY, entries::network::course_vote_controller_menu)),
        m_event_frame_modifier_entry(new MenuEntry("Event Frame Modifier", DEFAULT_ENTRY, entries::network::event_frame_modifier_menu)),
        m_friend_info_modifier_entry(new MenuEntry("Friend Info Modifier", DEFAULT_ENTRY, entries::network::friend_info_modifier_menu)),
        m_goal_score_modifier_entry(new MenuEntry("Goal Score Modifier", DEFAULT_ENTRY, entries::network::goal_score_modifier_menu)),
        m_mii_matching_viewer_entry(new MenuEntry("Mii Matching Viewer", DEFAULT_ENTRY)),
        m_mii_dumper_entry(new MenuEntry("Mii Dumper", nullptr, entries::network::mii_dumper_menu)),
        m_force_replacement_entry(new MenuEntry("Force Replacement", DEFAULT_ENTRY, entries::network::force_replacement_menu)),
        m_protections_entry(new MenuEntry("Protections", DEFAULT_ENTRY, entries::network::protections_menu)),
        m_vr_extender_fix_entry(new MenuEntry("VR Extender Fix", entries::network::vr_extender_fix_game)),

        m_save_data_modifier_entry(new MenuEntry("Save Data Modifier", nullptr, entries::system::save_data_modifier_game)),

        m_grand_prix_timer_entry(new MenuEntry("Grand Prix Timer", DEFAULT_ENTRY, entries::ui::grand_prix_timer_menu)),
        m_enhanced_minimap_entry(new MenuEntry("Enhanced Minimap", entries::ui::enhanced_minimap::game, entries::ui::enhanced_minimap::menu)),
        m_mii_heads_entry(new MenuEntry("Mii Heads", entries::ui::mii_heads::game, entries::ui::mii_heads::menu)),
         
        m_disable_features_entry(new MenuEntry("Disable features", nullptr, entries::base::disable_features_game)),
        m_enabled_features_entry(new MenuEntry("", nullptr, entries::base::enabled_features_menu)),
        m_reset_settings_entry(new MenuEntry("Reset settings", nullptr, entries::base::reset_settings_game)),
        m_rainbow_entry(new MenuEntry("Rainbow", entries::base::rainbow::game, entries::base::rainbow::menu)),
        m_friends_entry(new MenuEntry("Friends", entries::base::friends::game, entries::base::friends::menu))
    {
        m_plugin_menu->SynchronizeWithFrame(true);
        m_plugin_menu->ShowWelcomeMessage(false);

        m_plugin_menu->Callback([]()
        {
            g_patches->m_star_acceleration_patch.set(g_menu->m_item_fixes_entry->IsActivated() && g_settings.m_options.item.item_fixes.star_acceleration);
        });
        m_plugin_menu->OnNewFrame = [](Time)
        {
            g_menu->update_colors();
            g_menu->update_counter();
        };
        m_plugin_menu->OnClosing = []()
        {
            g_settings.store();
        };

        create();
        finalize();

        g_menu = this;
    }

    menu::~menu()
    {
        g_menu = nullptr;

        //delete m_plugin_menu; // FIXME: causes a crash in _free_r+3C
    }

    void menu::run()
    {
        m_plugin_menu->Run();
    }

    menu::entries_t menu::get_all_entries()
    {
        auto out = entries_t();

        push_entry_list(out, m_plugin_menu->GetEntryList());

        for (auto const &f : m_plugin_menu->GetFolderList())
            if (f != nullptr)
                parse_folder(out, *f);

        return out;
    }

    menu::entries_t menu::get_feature_entries()
    {
        auto out = get_all_entries();

        std::erase(out, m_rainbow_entry);
        std::erase(out, m_friends_entry);

        // Removes all entries that can't be checked
        std::erase_if(out, [](auto const *e) { return e->GetGameFunc() == nullptr; });

        return out;
    }

    void menu::create()
    {
        if (auto item = new MenuFolder("Item"))
        {
            *item += m_item_wheel_entry;
            *item += m_item_rapidfire_entry;
            *item += m_item_usage_entry;
            *item += m_item_selfstrike_entry;
            *item += m_item_drop_entry;
            *item += m_item_hang_entry;
            *item += m_item_rain_entry;
            *item += m_item_terrain_entry;
            *item += m_item_limiters_entry;
            *item += m_item_model_entry;
            *item += m_disable_item_clear_entry;
            *item += m_shell_gravity_modifier_entry;
            *item += m_shell_stripe_color_modifier_entry;
            *item += m_item_billboard_entry;
            *item += m_item_fixes_entry;

            *m_plugin_menu += item;
        }

        if (auto kart = new MenuFolder("Kart"))
        {
            *kart += m_invincibility_entry;
            *kart += m_kart_vulnerabilities_entry;
            *kart += m_intangibility_entry;
            *kart += m_kart_usage_entry;
            *kart += m_kart_statuses_entry;
            *kart += m_killer_control_entry;
            *kart += m_future_fly_entry;
            *kart += m_instant_acceleration_entry;
            *kart += m_instant_respawn_entry;
            *kart += m_instant_miniturbo_entry;
            *kart += m_kart_effect_color_modifier_entry;
            *kart += m_angry_wiggler_entry;

            *m_plugin_menu += kart;
        }

        if (auto mode = new MenuFolder("Mode"))
        {
            *mode += m_drive_during_sync_entry;
            *mode += m_trigger_respawn_entry;
            *mode += m_stalking_entry;

            *m_plugin_menu += mode;
        }

        if (auto network = new MenuFolder("Network"))
        {
            *network += m_kart_warp_entry;
            *network += m_disable_killer_lag_entry;
            *network += m_item_delimiters_entry;
            *network += m_high_data_rate_entry;
            *network += m_invisibility_entry;
            *network += m_disable_idle_disconnect_entry;
            *network += m_instant_disconnect_entry;
            *network += m_course_vote_controller_entry;
            *network += m_event_frame_modifier_entry;
            *network += m_friend_info_modifier_entry;
            *network += m_goal_score_modifier_entry;
            *network += m_mii_matching_viewer_entry;
            *network += m_mii_dumper_entry;
            *network += m_force_replacement_entry;
            *network += m_protections_entry;
            *network += m_vr_extender_fix_entry;

            *m_plugin_menu += network;
        }

        if (auto system = new MenuFolder("System"))
        {
            *system += m_save_data_modifier_entry;

            *m_plugin_menu += system;
        }

        if (auto ui = new MenuFolder("UI"))
        {
            *ui += m_grand_prix_timer_entry;
            *ui += m_enhanced_minimap_entry;
            *ui += m_mii_heads_entry;

            *m_plugin_menu += ui;
        }
        
#ifdef _DEBUG
        if (auto debug = new MenuFolder("Debug"))
        {
            *debug += new MenuEntry("Disable hooks", nullptr, entries::debug::toggle_hooks_menu);

            *m_plugin_menu += debug;
        }
#endif

        if (auto base = new MenuFolder("Base"))
        {
            *base += m_disable_features_entry;
            *base += m_reset_settings_entry;
            *base += m_rainbow_entry;
            *base += m_friends_entry;

            *m_plugin_menu += base;
        }

        *m_plugin_menu += m_enabled_features_entry;
    }

    void menu::finalize()
    {        
        // Base
        m_rainbow_entry->Enable();
        m_friends_entry->Enable();
    }

    void menu::update_colors()
    {
        auto &settings = FwkSettings::Get();

        if (m_rainbow_entry->IsActivated())
        {
            g_rainbow_service->run();
            auto const color = g_rainbow_service->get_ctrpf_color();

            m_plugin_menu->Title() = color << NAME;
            settings.MenuSelectedItemColor = color;
        }
        else if (m_plugin_menu->Title() != NAME)
        {
            m_plugin_menu->Title() = NAME;
            settings.SetThemeDefault();
        }
    }

    void menu::update_counter()
    {
        auto const entries = get_feature_entries();
        auto const counter = std::count_if(entries.begin(), entries.end(), [](auto const *e) { return e->IsActivated(); });

        m_enabled_features_entry->Name() = std::format("Enabled features: {}/{}", counter, entries.size());
    }

    void menu::push_entry_list(entries_t &out, entries_t const &list)
    {
        for (auto const &e : list)
            if (e != nullptr)
                out.push_back(e);
    }

    void menu::parse_folder(entries_t &out, MenuFolder const &folder)
    {
        for (auto const &f : folder.GetFolderList())
            if (f != nullptr)
                parse_folder(out, *f);

        push_entry_list(out, folder.GetEntryList());
    }

    std::string menu::toggle_name(bool status)
    {
        switch (status)
        {
            case false: return (Color::Red << g_message_service->get(LMS_MessageID::Off)) + ResetColor();
            case true: return (Color::Lime << g_message_service->get(LMS_MessageID::On)) + ResetColor();
        }
    }
}