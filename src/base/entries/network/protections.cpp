#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <fmt/format.h>

namespace base
{
    void entries::network::protections(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
        
        auto &settings = g_settings.m_options["network"]["protections"];
        auto network = settings["network"].get<bool *>();

        int choice;

        do
		{
            keyboard.Populate(std::vector<std::string>
			{
				fmt::format("Network ({})", menu::s_toggles[*network])
			});

            choice = keyboard.Open();

            switch (choice)
			{
                case 0: *network ^= true;
            }
        }
        while (choice >= 0);
    }
}