#include <3ds.h>

#include <base/files.hpp>
#include <base/logger.hpp>
#include <base/settings.hpp>
#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/hooks.hpp>

namespace CTRPluginFramework
{
    using namespace base;

    int main()
    {
        OSD::Notify(NAME "!");

        auto files_instance = std::make_unique<files>();
        g_logger.info("Greetings from " NAME "!");

        g_settings.load();
        g_logger.info("Settings loaded.");

        auto menu_instance = std::make_unique<menu>();
        g_logger.info("Menu created.");

        auto pointers_instance = std::make_unique<pointers>();
        g_logger.info("Pointers initialized.");

        auto hooks_instance = std::make_unique<hooks>();
        g_logger.info("Hooks initialized.");

        g_hooks->enable();
        g_logger.info("Hooks enabled.");

        OSD::Notify("Enjoy. :)");
        g_menu->run();

        g_hooks->disable();
        g_logger.info("Hooks disabled.");

        hooks_instance.reset();
        g_logger.info("Hooks uninitialized.");

        pointers_instance.reset();
        g_logger.info("Pointers uninitialized.");

        menu_instance.reset();
        g_logger.info("Menu deleted.");

        g_settings.store();
        g_logger.info("Settings stored.");

        g_logger.info("Farewell!");
        files_instance.reset();

        return EXIT_SUCCESS;
    }

    void PatchProcess(FwkSettings &settings)
    {
        settings.ThreadPriority = 0x3E;
        settings.WaitTimeToBoot = Time::Zero;
#ifdef _DEBUG
        settings.CachedDrawMode = true;
#endif

        files::set_working_directory();
    }
}
