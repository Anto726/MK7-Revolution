#pragma once

#include <CTRPluginFramework.hpp>

#include "features.hpp"

#include <map>

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
        friend features;

    public:
		explicit menu();
		~menu();

        void run();

    private:
        void create();
        void finalize();
        
        inline static std::map<bool, std::string> m_toggles =
        {
            { false, (CTRPluginFramework::Color(255, 0, 0) << "OFF") + (CTRPluginFramework::Color::White << "") },
            { true, (CTRPluginFramework::Color(0, 255, 0) << "ON") + (CTRPluginFramework::Color::White << "") }
        };

        CTRPluginFramework::PluginMenu *m_plugin_menu;

        // Item
        CTRPluginFramework::MenuEntry *m_item_wheel_entry;

        // Kart
        CTRPluginFramework::MenuEntry *m_invincibility_entry;
        CTRPluginFramework::MenuEntry *m_blinking_invincibility_entry;
        CTRPluginFramework::MenuEntry *m_intangibility_entry;
        CTRPluginFramework::MenuEntry *m_infinite_star_entry;
        CTRPluginFramework::MenuEntry *m_infinite_ink_entry;
        CTRPluginFramework::MenuEntry *m_infinite_thunder_entry;
        CTRPluginFramework::MenuEntry *m_infinite_press_entry;
        CTRPluginFramework::MenuEntry *m_instant_respawn_entry;

        // Network
        CTRPluginFramework::MenuEntry *m_no_disconnect_entry;
    };

    inline menu *g_menu{};
}