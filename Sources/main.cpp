#include <3ds.h>
#include <CTRPluginFramework.hpp>

namespace CTRPluginFramework
{
    int main()
    {
        auto menu = new PluginMenu("CTRPluginFramework", 0, 7, 4);
        menu->SynchronizeWithFrame(true);
        menu->Run();
        delete menu;
        return EXIT_SUCCESS;
    }

    void PatchProcess(FwkSettings &settings)
    {
    }
}
