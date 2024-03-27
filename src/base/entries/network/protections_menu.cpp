#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::network::protections_menu(CTRPluginFramework::MenuEntry *entry)
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
				std::format("Network ({})", menu::s_toggles[*network])
			});

            choice = keyboard.Open();

            switch (choice)
			{
                case 0: *network ^= true; break;
            }
        }
        while (choice >= 0);
    }
}