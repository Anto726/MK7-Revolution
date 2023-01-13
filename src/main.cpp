#include <3ds.h>

#include <base/files.hpp>
#include <base/logger.hpp>
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
        g_logger.log("Greetings from " NAME "!");

        auto menu_instance = std::make_unique<menu>();
        g_logger.log("CTRPluginFramework menu created.");

        auto pointers_instance = std::make_unique<pointers>();
        g_logger.log("Pointers initialized.");

        auto hooks_instance = std::make_unique<hooks>();
        g_logger.log("Hooks initialized.");

        g_hooks->enable();
        g_logger.log("Hooks enabled.");

        OSD::Notify("Enjoy. :)");
        g_menu->run();

        g_hooks->disable();
        g_logger.log("Hooks disabled.");

        hooks_instance.reset();
        g_logger.log("Hooks uninitialized.");

        pointers_instance.reset();
        g_logger.log("Pointers uninitialized.");

        menu_instance.reset();
        g_logger.log("CTRPluginFramework menu deleted.");

        g_logger.log("Farewell!");
        files_instance.reset();

        return EXIT_SUCCESS;
    }

    void PatchProcess(FwkSettings &settings)
    {
        settings.WaitTimeToBoot = Time::Zero;

        files::set_working_directory();
    }
}
