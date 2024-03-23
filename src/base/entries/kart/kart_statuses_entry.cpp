#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <fmt/format.h>

namespace base
{
    void entries::kart::kart_statuses_entry(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
		keyboard.IsHexadecimal(false);

        auto &settings = g_settings.m_options["kart"]["kart_statuses"];
        auto ink = settings["ink"].get<bool *>();
        auto press = settings["press"].get<bool *>();
        auto star = settings["star"].get<bool *>();
        auto thunder = settings["thunder"].get<bool *>();

        int choice;

        do
		{
			keyboard.Populate(std::vector<std::string>
			{
				fmt::format("Ink ({})", menu::s_toggles[*ink]),
				fmt::format("Press ({})", menu::s_toggles[*press]),
				fmt::format("Star ({})", menu::s_toggles[*star]),
				fmt::format("Thunder ({})", menu::s_toggles[*thunder])
			});

			choice = keyboard.Open();

			switch (choice)
			{
				case 0: *ink ^= true; break;
                case 1: *press ^= true; break;
                case 2: *star ^= true; break;
                case 3: *thunder ^= true; break;
            }
        }
        while (choice >= 0);
    }
}