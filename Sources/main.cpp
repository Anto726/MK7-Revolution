#include <3ds.h>

#include <base/logger.hpp>
#include <base/menu.hpp>

namespace CTRPluginFramework
{
    using namespace base;

    int main()
    {
        OSD::Notify(NAME"!");

        auto logger_instance = std::make_unique<logger>();
        g_logger->log_now(Utils::Format("Hello from %s!", NAME));

        auto menu_instance = std::make_unique<menu>();
        g_logger->log_now("CTRPluginFramework menu created.");

        OSD::Notify("Enjoy. :)");
        g_menu->run();

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
