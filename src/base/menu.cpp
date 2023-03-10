#include <base/menu.hpp>
#include <MenuEntryHelpers.hpp>

#include <base/menu_types.hpp>

#include <Item/eItemSlot.hpp>

#include <base/hooks.hpp>
#include <base/settings.hpp>

namespace base
{
    using namespace CTRPluginFramework;
    
    menu::menu()
    :
        m_plugin_menu(new PluginMenu(NAME, MAJOR_VERSION, MINOR_VERSION, REVISION_VERSION, ABOUT)),

        m_item_wheel_entry(new MenuEntry("Item Wheel", [](MenuEntry *) {})),

        m_invincibility_entry(new MenuEntry("Invincibility", [](MenuEntry *) {})),
        m_blinking_invincibility_entry(new MenuEntry("Blinking Invincibility", [](MenuEntry *) {})),
        m_intangibility_entry(new MenuEntry("Intangibility", [](MenuEntry *) {}, entries::kart::intangibility)),
        m_infinite_star_entry(new MenuEntry("Infinite Star", [](MenuEntry *) {})),
        m_infinite_ink_entry(new MenuEntry("Infinite Ink", [](MenuEntry *) {})),
        m_infinite_thunder_entry(new MenuEntry("Infinite Thunder", [](MenuEntry *) {})),
        m_infinite_press_entry(new MenuEntry("Infinite Press", [](MenuEntry *) {})),
        m_instant_respawn_entry(new MenuEntry("Instant Respawn", [](MenuEntry *) {})),
        m_instant_miniturbo_entry(new MenuEntry("Instant Mini-Turbo", [](MenuEntry *) {}, entries::kart::instant_miniturbo)),

        m_no_disconnect_entry(new MenuEntry("No Disconnect", [](MenuEntry *) {}))
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

        if (auto network = new MenuFolder("Network"))
        {
            *network += m_no_disconnect_entry;

            *m_plugin_menu += network;
        }
        
#ifdef _DEBUG
        if (auto debug = new MenuFolder("Debug"))
        {
            *debug += new MenuEntry(g_hooks->is_enabled() ? "Disable hooks" : "Enable hooks", nullptr, entries::debug::toggle_hooks);

            *m_plugin_menu += debug;
        }
#endif
    }

    void menu::finalize()
    {
        // Item
        *GetArg<menu_types::item_wheel_data_t>(m_item_wheel_entry) =
        {
            SIZE_MAX,
            { Item::eItemSlot::Banana, Item::eItemSlot::KouraG, Item::eItemSlot::KouraR, Item::eItemSlot::Kinoko, Item::eItemSlot::Bomhei, Item::eItemSlot::Gesso, Item::eItemSlot::KouraB, Item::eItemSlot::Kinoko3, Item::eItemSlot::Star, Item::eItemSlot::Killer, Item::eItemSlot::Thunder, Item::eItemSlot::KinokoP, Item::eItemSlot::Flower, Item::eItemSlot::Konoha, Item::eItemSlot::Seven, Item::eItemSlot::Banana3, Item::eItemSlot::KouraG3, Item::eItemSlot::KouraR3, Item::eItemSlot::Empty }
        };
    }
}