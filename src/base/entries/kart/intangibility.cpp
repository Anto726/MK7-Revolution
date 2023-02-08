#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

namespace base
{
	void entries::kart::intangibility(CTRPluginFramework::MenuEntry *entry)
	{
		CTRPluginFramework::Keyboard keyboard;
		keyboard.DisplayTopScreen = true;
		keyboard.GetMessage() = entry->Name();

		int choice;
		auto invert = g_settings.m_options["kart"]["intangibility"]["invert"].get<bool *>();

		do
		{
			keyboard.Populate(std::vector<std::string>
			{
				"Invert: " + menu::s_toggles[*invert]
			});

			choice = keyboard.Open();

			switch (choice)
			{
				case 0: *invert ^= true; break;
				default: break;
			}
		}
		while (choice >= 0);
	}
}