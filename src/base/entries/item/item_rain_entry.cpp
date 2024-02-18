#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <fmt/format.h>

namespace base
{
	void entries::item::item_rain(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
		keyboard.IsHexadecimal(false);

		auto &settings = g_settings.m_options["item"]["item_rain"];
		auto multi = settings["multi"].get<bool *>();
        auto delay = settings["delay"].get<u64 *>();
        auto height = settings["height"].get<double *>();
		auto width = settings["width"].get<double *>();

		int choice;

		do
		{
			keyboard.Populate(std::vector<std::string>
			{
				fmt::format("Multi ({})", menu::s_toggles[*multi]),
                fmt::format("Delay ({})", *delay),
				fmt::format("Height ({})", *height),
				fmt::format("Width ({})", *width)
			});

			choice = keyboard.Open();

			switch (choice)
			{
				case 0: *multi ^= true; break;
                case 1: keyboard.Open(*delay, *delay); break;
			    case 2: keyboard.Open(*height, *height); break;
				case 3: keyboard.Open(*width, *width); break;
			}
		}
		while (choice >= 0);
	}
}