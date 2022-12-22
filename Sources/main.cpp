#include <3ds.h>

#include <base/menu.hpp>

namespace CTRPluginFramework
{
    int main()
    {
        using namespace base;

        auto menu_instance = std::make_unique<menu>();
        g_menu->run();
        menu_instance.reset();

        return EXIT_SUCCESS;
    }

    void PatchProcess(FwkSettings &settings)
    {
    }
}
