#include <base/menu.hpp>

#include <base/entries.hpp>
#include <base/hooks.hpp>
#include <base/settings.hpp>

namespace base
{
    using namespace CTRPluginFramework;
    
    menu::menu()
    :
        m_plugin_menu(new PluginMenu(NAME, MAJOR_VERSION, MINOR_VERSION, REVISION_VERSION, ABOUT))
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
    }
}