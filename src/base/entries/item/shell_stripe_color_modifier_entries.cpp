#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/patches.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <magic_enum/magic_enum_all.hpp>

#include <format>

namespace base
{
    using namespace CTRPluginFramework;

    void entries::item::shell_stripe_color_modifier::game(MenuEntry *entry)
    {
        if (entry->WasJustActivated())
        {
            if (g_settings.m_options.item.shell_stripe_color_modifier.keep)
            {
                g_patches->m_Item_ItemObjKouraG_calcStripe_0x34_patch.enable();
                g_patches->m_Item_ItemObjKouraG_calcStripe_0xC4_patch.enable();
            }
        }
        else if (!entry->IsActivated())
        {
            g_patches->m_Item_ItemObjKouraG_calcStripe_0xC4_patch.disable();
            g_patches->m_Item_ItemObjKouraG_calcStripe_0x34_patch.disable();
        }
    }

    void entries::item::shell_stripe_color_modifier::menu(MenuEntry *entry)
    {
        auto keyboard = Keyboard();
		keyboard.DisplayTopScreen = true;

        auto &shell_stripe_color_modifier = g_settings.m_options.item.shell_stripe_color_modifier;

        while (true)
        {
            keyboard.GetMessage() = entry->Name();

            auto options = std::vector<std::string>{ std::format("Keep ({})", menu::toggle_name(shell_stripe_color_modifier.keep)) };
            std::for_each(shell_stripe_color_modifier.shells.begin(), shell_stripe_color_modifier.shells.end(), [&](auto const &e) { options.push_back(std::format("{} ({}, {})", utils::item_name(e.first), menu::toggle_name(e.second.enabled), magic_enum::enum_name(e.second.mode))); });
            keyboard.Populate(options);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0:
                {
                    shell_stripe_color_modifier.keep ^= true;
                    g_patches->m_Item_ItemObjKouraG_calcStripe_0x34_patch.set(shell_stripe_color_modifier.keep);
                    g_patches->m_Item_ItemObjKouraG_calcStripe_0xC4_patch.set(shell_stripe_color_modifier.keep);
                    break;
                }
                default:
                {
                    auto const &shell = std::next(shell_stripe_color_modifier.shells.begin(), choice - 1);

                    while (true)
                    {
                        keyboard.GetMessage() = std::format("{}\n{}", entry->Name(), utils::item_name(shell->first));

                        auto options = std::vector<std::string>
                        {
                            std::format("Enabled ({})", menu::toggle_name(shell->second.enabled)),
                            std::format("Mode ({})", magic_enum::enum_name(shell->second.mode)),
                        };
                        if (shell->second.mode == decltype(shell->second.mode)::Custom)
                            options.push_back(Color(shell->second.color.as_u32()) << "Color");
                        keyboard.Populate(options);

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: shell->second.enabled ^= true; break;
                            case 1: shell->second.mode = magic_enum::enum_next_value_circular(shell->second.mode); break;
                            case 2:
                            {
                                keyboard.GetMessage() = std::format("{}\n{}\nColor", entry->Name(), utils::item_name(shell->first));

                                while (true)
                                {
                                    keyboard.Populate(std::vector<std::string>
                                    {
                                        Color(shell->second.color.r.as_u8(), 0, 0) << "Red",
                                        Color(0, shell->second.color.g.as_u8(), 0) << "Green",
                                        Color(0, 0, shell->second.color.b.as_u8()) << "Blue",
                                    });

                                    auto const choice = keyboard.Open();
                                    if (choice < 0)
                                        break;

                                    switch (choice)
                                    {
                                        case 0: keyboard.Open(shell->second.color.r.v, shell->second.color.r.v); break;
                                        case 1: keyboard.Open(shell->second.color.g.v, shell->second.color.g.v); break;
                                        case 2: keyboard.Open(shell->second.color.b.v, shell->second.color.b.v); break;
                                    }
                                }

                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
}