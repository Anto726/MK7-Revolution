#pragma once

#include <CTRPluginFramework.hpp>

#include "hook_funcs.hpp"

#define MAJOR_VERSION       0
#define MINOR_VERSION       0
#define REVISION_VERSION    1
#ifdef _DEBUG
#define NAME                "Revolution (Debug)"
#else
#define NAME                "Revolution"
#endif
#define ABOUT               NAME " is a plugin for Mario Kart 7. Strictly for educational purposes."

namespace base
{
    class menu
    {
        friend hook_funcs;

    public:
		explicit menu();
		~menu();

        void run();

    private:
        void create();
        void finalize();

        CTRPluginFramework::PluginMenu *m_plugin_menu;

        // Item
        CTRPluginFramework::MenuEntry *m_item_wheel_entry;

        // Kart
        CTRPluginFramework::MenuEntry *m_invincibility_entry;
        CTRPluginFramework::MenuEntry *m_blinking_invincibility_entry;
        CTRPluginFramework::MenuEntry *m_intangibility_entry;
        CTRPluginFramework::MenuEntry *m_infinite_star;
        CTRPluginFramework::MenuEntry *m_infinite_ink;
        CTRPluginFramework::MenuEntry *m_infinite_thunder;
        CTRPluginFramework::MenuEntry *m_infinite_press;

        // Network
        CTRPluginFramework::MenuEntry *m_no_disconnect_entry;
    };

    inline menu *g_menu{};
}