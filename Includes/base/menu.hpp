#pragma once

#include <CTRPluginFramework.hpp>

#include "hook_funcs.hpp"

#include <fwddec.hpp>

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

    public:
        // Item
        struct item_wheel_data_t
        {
            size_t index;
            std::vector<::Item::eItemSlot> items;
        };

        CTRPluginFramework::MenuEntry *m_item_wheel_entry{};

        // Kart
        CTRPluginFramework::MenuEntry *m_intangibility_entry{};

    private:
        CTRPluginFramework::PluginMenu *m_plugin_menu;
    };

    inline menu *g_menu{};
}