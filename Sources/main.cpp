#include <3ds.h>

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

        auto logger_instance = std::make_unique<logger>();
        g_logger->log_now("Greetings from " NAME "!");

        auto menu_instance = std::make_unique<menu>();
        g_logger->log_now("CTRPluginFramework menu created.");

        auto pointers_instance = std::make_unique<pointers>();
        g_logger->log_now("Pointers initialized.");

        auto hooks_instance = std::make_unique<hooks>();
        g_logger->log_now("Hooks initialized.");

        g_hooks->enable();
        g_logger->log_now("Hooks enabled.");

        OSD::Notify("Enjoy. :)");
        g_menu->run();

        g_hooks->disable();
        g_logger->log_now("Hooks disabled.");

        hooks_instance.reset();
        g_logger->log_now("Hooks uninitialized.");

        pointers_instance.reset();
        g_logger->log_now("Pointers uninitialized.");

        menu_instance.reset();
        g_logger->log_now("CTRPluginFramework menu deleted.");

        g_logger->log_now("Farewell!");
        logger_instance.reset();

        return EXIT_SUCCESS;
    }

    void PatchProcess(FwkSettings &settings)
    {
        settings.WaitTimeToBoot = Time::Zero;

        logger::set_working_directory();
    }
}
