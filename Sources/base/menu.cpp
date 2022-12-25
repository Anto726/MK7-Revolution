#include <base/menu.hpp>

#include <MenuEntryHelpers.hpp>

#include <Item/eItemSlot.hpp>

namespace base
{
    using namespace CTRPluginFramework;
    
    menu::menu()
    :
        m_plugin_menu(new PluginMenu(NAME, MAJOR_VERSION, MINOR_VERSION, REVISION_VERSION, ABOUT))
    {
        m_plugin_menu->SynchronizeWithFrame(true);
        m_plugin_menu->ShowWelcomeMessage(false);

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
            *item += (m_item_wheel_entry = new MenuEntry("Item Wheel", [](MenuEntry *) {}));

            *m_plugin_menu += item;
        }

        if (auto kart = new MenuFolder("Kart"))
        {
            *kart += (m_intangibility_entry = new MenuEntry("Intangibility", [](MenuEntry *) {}));

            *m_plugin_menu += kart;
        }
    }

    void menu::finalize()
    {
        // Item
        *GetArg<item_wheel_data_t>(m_item_wheel_entry) =
        {
            SIZE_MAX,
            { Item::eItemSlot::Banana, Item::eItemSlot::KouraG, Item::eItemSlot::KouraR, Item::eItemSlot::Kinoko, Item::eItemSlot::Bomhei, Item::eItemSlot::Gesso, Item::eItemSlot::KouraB, Item::eItemSlot::Kinoko3, Item::eItemSlot::Star, Item::eItemSlot::Killer, Item::eItemSlot::Thunder, Item::eItemSlot::KinokoP, Item::eItemSlot::Flower, Item::eItemSlot::Konoha, Item::eItemSlot::Seven, Item::eItemSlot::Banana3, Item::eItemSlot::KouraG3, Item::eItemSlot::KouraR3, Item::eItemSlot::Empty }
        };
    }
}