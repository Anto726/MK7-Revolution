#pragma once
#include <CTRPluginFramework.hpp>

#define MAJOR_VERSION       0
#define MINOR_VERSION       0
#define REVISION_VERSION    1
#define NAME                "Revolution Base"
#define ABOUT               NAME" is a CTRPluginFramework plugin with some improvements."

namespace base
{
    class menu
    {
    public:
		explicit menu();
		~menu();

        void run();

    private:
        void create();
        void finalize();

        CTRPluginFramework::PluginMenu *m_plugin_menu;
    };

    inline menu *g_menu{};
}