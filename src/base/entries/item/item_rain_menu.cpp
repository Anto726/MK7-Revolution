#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <Item/eItemType.hpp>

#include <format>
#include <set>

namespace base
{
	void entries::item::item_rain_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
		keyboard.IsHexadecimal(false);

		auto &settings = g_settings.m_options["item"]["item_rain"];
		auto &speed = settings["speed"];
		auto items = settings["items"].get<std::set<Item::eItemType>>(); // FIXME: doesn't allow getting a pointer to std::set
		auto owned = settings["owned"].get<bool *>();
		auto multi = settings["multi"].get<bool *>();
		auto speed_status = speed["status"].get<bool *>();
		auto speed_value = speed["value"].get<double *>();
        auto delay = settings["delay"].get<u64 *>();
        auto height = settings["height"].get<double *>();
		auto width = settings["width"].get<double *>();

		int choice;

		do
		{
			keyboard.Populate(std::vector<std::string>
			{
				std::format("Items ({})", items.size()),
				std::format("Owned ({})", menu::s_toggles[*owned]),
				std::format("Multi ({})", menu::s_toggles[*multi]),
				std::format("Speed ({}, {})", menu::s_toggles[*speed_status], *speed_value),
                std::format("Delay ({})", *delay),
				std::format("Height ({})", *height),
				std::format("Width ({})", *width)
			});

			choice = keyboard.Open();

			switch (choice)
			{
				case 0:
				{
					auto const allowed = std::to_array({ Item::eItemType::KouraG, Item::eItemType::KouraR, Item::eItemType::Banana, Item::eItemType::Kinoko, Item::eItemType::Star, Item::eItemType::KouraB, Item::eItemType::Bomhei, Item::eItemType::Gesso, Item::eItemType::Flower });

					while (true)
					{
						auto options = std::vector<std::string>();

						for (auto const i : allowed)
							options.push_back(std::format("{} ({})", magic_enum::enum_name(i), menu::s_toggles[items.contains(i)]));

						keyboard.Populate(options);

						choice = keyboard.Open();

						if (choice < 0)
							break;

						auto const item = allowed[choice];

						if (items.contains(item))
							items.erase(item);
						else
							items.emplace(item);

						settings["items"] = items;
					}

					choice = 0;
					break;
				}
				case 1: *owned ^= true; break;
				case 2: *multi ^= true; break;
				case 3:
				{
					while (true)
					{
						keyboard.Populate(std::vector<std::string>
						{
							std::format("Status ({})", menu::s_toggles[*speed_status]),
							std::format("Value ({})", *speed_value)
						});

						choice = keyboard.Open();

						if (choice < 0)
							break;

						switch (choice)
						{
							case 0: *speed_status ^= true; break;
							case 1: keyboard.Open(*speed_value, *speed_value); break;
						}
					}

					choice = 0;
					break;
				}
                case 4: keyboard.Open(*delay, *delay); break;
			    case 5: keyboard.Open(*height, *height); break;
				case 6: keyboard.Open(*width, *width); break;
			}
		}
		while (choice >= 0);
	}
}