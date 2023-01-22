#pragma once

#include <CTRPluginFramework.hpp>

#include "features.hpp"

#define MAJOR_VERSION       0
#define MINOR_VERSION       0
#define REVISION_VERSION    1
#ifdef _DEBUG
#define NAME                "Revolution Base (Debug)"
#else
#define NAME                "Revolution Base"
#endif
#define ABOUT               NAME " is a CTRPluginFramework plugin with some improvements."

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

        CTRPluginFramework::PluginMenu *m_plugin_menu;
    };

    inline menu *g_menu{};
}