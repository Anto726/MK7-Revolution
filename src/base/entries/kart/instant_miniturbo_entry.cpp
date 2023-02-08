#include <base/entries.hpp>

#include <base/hooks.hpp>
#include <base/settings.hpp>

#include <array>

namespace base
{
	void entries::kart::instant_miniturbo(CTRPluginFramework::MenuEntry *entry)
	{
		std::array<std::string, 2> const types = {"Blue", "Red"};

		CTRPluginFramework::Keyboard keyboard;
		keyboard.DisplayTopScreen = true;
		keyboard.GetMessage() = entry->Name();

		int choice;
		auto type = g_settings.m_options["kart"]["instant_miniturbo"]["type"].get<u64 *>();

		do
		{
			keyboard.Populate(std::vector<std::string>
			{
				"Type: " + types[*type]
			});

			choice = keyboard.Open();

			switch (choice)
			{
				case 0: if (++*type >= types.size()) *type = 0; break;
				default: break;
			}
		}
		while (choice >= 0);
	}
}