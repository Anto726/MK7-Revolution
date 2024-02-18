#include <base/menu.hpp>
#include <MenuEntryHelpers.hpp>

#include <base/menu_types.hpp>

#include <Item/eItemSlot.hpp>
#include <Item/eItemType.hpp>

#include <base/entries.hpp>
#include <base/hooking.hpp>
#include <base/settings.hpp>

namespace base
{
    using namespace CTRPluginFramework;
    
    menu::menu()
    :
        m_plugin_menu(new PluginMenu(NAME, MAJOR_VERSION, MINOR_VERSION, REVISION_VERSION, ABOUT)),

        m_item_wheel_entry(new MenuEntry("Item Wheel", [](MenuEntry *) {})),
        m_drop_items_entry(new MenuEntry("Drop Items", [](MenuEntry *) {})),
        m_item_rain_entry(new MenuEntry("Item Rain", [](MenuEntry *) {}, entries::item::item_rain)),
        m_blue_shell_battle_crash_fix_entry(new MenuEntry("Blue Shell Battle Crash Fix", [](MenuEntry *) {})),

        m_invincibility_entry(new MenuEntry("Invincibility", [](MenuEntry *) {})),
        m_blinking_invincibility_entry(new MenuEntry("Blinking Invincibility", [](MenuEntry *) {})),
        m_intangibility_entry(new MenuEntry("Intangibility", [](MenuEntry *) {}, entries::kart::intangibility)),
        m_infinite_star_entry(new MenuEntry("Infinite Star", [](MenuEntry *) {})),
        m_infinite_ink_entry(new MenuEntry("Infinite Ink", [](MenuEntry *) {})),
        m_infinite_thunder_entry(new MenuEntry("Infinite Thunder", [](MenuEntry *) {})),
        m_infinite_press_entry(new MenuEntry("Infinite Press", [](MenuEntry *) {})),
        m_instant_respawn_entry(new MenuEntry("Instant Respawn", [](MenuEntry *) {})),
        m_instant_miniturbo_entry(new MenuEntry("Instant Mini-Turbo", [](MenuEntry *) {}, entries::kart::instant_miniturbo)),

        m_drive_during_countdown_entry(new MenuEntry("Drive During Countdown", [](MenuEntry *) {})),

        m_no_disconnect_entry(new MenuEntry("No Disconnect", [](MenuEntry *) {})),
        m_high_data_rate_entry(new MenuEntry("High Data Rate", [](MenuEntry *) {}))
    {
        m_plugin_menu->SynchronizeWithFrame(true);
        m_plugin_menu->ShowWelcomeMessage(false);
        m_plugin_menu->OnClosing = []() { g_settings.store(); };

        create();
        finalize();

        g_menu = this;
    }

    menu::~menu()
    {
        g_menu = nullptr;

        delete m_plugin_menu;
    }

    void menu::run()
    {
        m_plugin_menu->Run();
    }

    void menu::create()
    {
        if (auto item = new MenuFolder("Item"))
        {
            *item += m_item_wheel_entry;
            *item += m_drop_items_entry;
            *item += m_item_rain_entry;
            *item += m_blue_shell_battle_crash_fix_entry;

            *m_plugin_menu += item;
        }

        if (auto kart = new MenuFolder("Kart"))
        {
            *kart += m_invincibility_entry;
            *kart += m_blinking_invincibility_entry;
            *kart += m_intangibility_entry;
            *kart += m_infinite_star_entry;
            *kart += m_infinite_ink_entry;
            *kart += m_infinite_thunder_entry;
            *kart += m_infinite_press_entry;
            *kart += m_instant_respawn_entry;
            *kart += m_instant_miniturbo_entry;

            *m_plugin_menu += kart;
        }

        if (auto mode = new MenuFolder("Mode"))
        {
            *mode += m_drive_during_countdown_entry;

            *m_plugin_menu += mode;
        }

        if (auto network = new MenuFolder("Network"))
        {
            *network += m_no_disconnect_entry;
            *network += m_high_data_rate_entry;

            *m_plugin_menu += network;
        }
        
#ifdef _DEBUG
        *m_plugin_menu += new MenuFolder
        (
            "Debug", 
            {
                new MenuEntry(g_hooking->is_enabled() ? "Disable hooks" : "Enable hooks", nullptr, entries::debug::toggle_hooks)
            }
        );
#endif
    }

    void menu::finalize()
    {
        // Item
        *GetArg<menu_types::item_rain_data_t>(m_item_rain_entry) =
        {
            { Item::eItemType::KouraG, Item::eItemType::KouraR, Item::eItemType::Banana, Item::eItemType::Kinoko, Item::eItemType::Star, Item::eItemType::KouraB, Item::eItemType::Bomhei, Item::eItemType::Gesso, Item::eItemType::Flower }
        };

        *GetArg<menu_types::item_wheel_data_t>(m_item_wheel_entry) =
        {
            SIZE_MAX,
            { Item::eItemSlot::Banana, Item::eItemSlot::KouraG, Item::eItemSlot::KouraR, Item::eItemSlot::Kinoko, Item::eItemSlot::Bomhei, Item::eItemSlot::Gesso, Item::eItemSlot::KouraB, Item::eItemSlot::Kinoko3, Item::eItemSlot::Star, Item::eItemSlot::Killer, Item::eItemSlot::Thunder, Item::eItemSlot::KinokoP, Item::eItemSlot::Flower, Item::eItemSlot::Tail, Item::eItemSlot::Seven, Item::eItemSlot::Banana3, Item::eItemSlot::KouraG3, Item::eItemSlot::KouraR3, Item::eItemSlot::Empty }
        };
    }
}