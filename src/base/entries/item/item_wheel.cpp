#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <Item/eItemSlot.hpp>

#include <format>
#include <set>

namespace base
{
    void entries::item::item_wheel(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

		auto items = g_settings.m_options["item"]["item_wheel"]["items"].get<std::set<Item::eItemSlot>>(); // FIXME: doesn't allow getting a pointer to std::set

        int choice;

        do
		{
            auto const allowed = std::to_array({ Item::eItemSlot::Banana, Item::eItemSlot::KouraG, Item::eItemSlot::KouraR, Item::eItemSlot::Kinoko, Item::eItemSlot::Bomhei, Item::eItemSlot::Gesso, Item::eItemSlot::KouraB, Item::eItemSlot::Kinoko3, Item::eItemSlot::Star, Item::eItemSlot::Killer, Item::eItemSlot::Thunder, Item::eItemSlot::KinokoP, Item::eItemSlot::Flower, Item::eItemSlot::Tail, Item::eItemSlot::Seven, Item::eItemSlot::Test3, Item::eItemSlot::Test4, Item::eItemSlot::Banana3, Item::eItemSlot::KouraG3, Item::eItemSlot::KouraR3, Item::eItemSlot::Empty });

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

                g_settings.m_options["item"]["item_wheel"]["items"] = items;
            }
        }
        while (choice >= 0);
    }
}