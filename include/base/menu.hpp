#pragma once

#include <CTRPluginFramework.hpp>

#include "hook_funcs.hpp"

#define MAJOR_VERSION       0
#define MINOR_VERSION       0
#define REVISION_VERSION    1
#define NAME                "Revolution"
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
        CTRPluginFramework::MenuEntry *m_intangibility_entry;

        // Network
        CTRPluginFramework::MenuEntry *m_no_disconnect_entry;
    };

    inline menu *g_menu{};
}