#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <fmt/format.h>
#include <magic_enum/magic_enum.hpp>

#include <Item/eItemType.hpp>

#include <set>

namespace base
{
	void entries::item::item_rain(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
		keyboard.IsHexadecimal(false);

		auto &settings = g_settings.m_options["item"]["item_rain"];
		auto items = settings["items"].get<std::set<Item::eItemType>>(); // FIXME: doesn't allow getting a pointer to std::set
		auto multi = settings["multi"].get<bool *>();
        auto delay = settings["delay"].get<u64 *>();
        auto height = settings["height"].get<double *>();
		auto width = settings["width"].get<double *>();

		int choice;

		do
		{
			keyboard.Populate(std::vector<std::string>
			{
				fmt::format("Items ({})", items.size()),
				fmt::format("Multi ({})", menu::s_toggles[*multi]),
                fmt::format("Delay ({})", *delay),
				fmt::format("Height ({})", *height),
				fmt::format("Width ({})", *width)
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
							options.push_back(fmt::format("{} ({})", magic_enum::enum_name(i), menu::s_toggles[items.contains(i)]));

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
				case 1: *multi ^= true; break;
                case 2: keyboard.Open(*delay, *delay); break;
			    case 3: keyboard.Open(*height, *height); break;
				case 4: keyboard.Open(*width, *width); break;
			}
		}
		while (choice >= 0);
	}
}