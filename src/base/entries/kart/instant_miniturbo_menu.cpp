#include <base/entries.hpp>

#include <base/hooks.hpp>
#include <base/settings.hpp>

#include <array>
#include <format>

namespace base
{
	void entries::kart::instant_miniturbo_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

		auto const types = std::to_array({ "Blue", "Red" });
		auto type = g_settings.m_options["kart"]["instant_miniturbo"]["type"].get<u64 *>();

		int choice;

		do
		{
			keyboard.Populate(std::vector<std::string>
			{
				std::format("Type: {}", types[*type])
			});

			choice = keyboard.Open();

			switch (choice)
			{
				case 0: if (++*type >= types.size()) *type = 0; break;
			}
		}
		while (choice >= 0);
	}
}