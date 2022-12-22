#include <base/menu.hpp>

namespace base
{
    menu::menu()
    :
        m_plugin_menu(new CTRPluginFramework::PluginMenu(NAME, MAJOR_VERSION, MINOR_VERSION, REVISION_VERSION, ABOUT))
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
    }

    void menu::finalize()
    {
    }
}