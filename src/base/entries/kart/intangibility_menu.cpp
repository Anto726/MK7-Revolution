#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
	void entries::kart::intangibility_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

		auto invert = g_settings.m_options["kart"]["intangibility"]["invert"].get<bool *>();

		int choice;

		do
		{
			keyboard.Populate(std::vector<std::string>
			{
				std::format("Invert: {}", menu::s_toggles[*invert])
			});

			choice = keyboard.Open();

			switch (choice)
			{
				case 0: *invert ^= true; break;
			}
		}
		while (choice >= 0);
	}
}