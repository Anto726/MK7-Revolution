#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/services/rainbow_service.hpp>

#include <Kart/Unit.hpp>
#include <Kart/Vehicle/Vehicle.hpp>

namespace base
{
    static struct
    {
        rainbow_service::rgb rgb;
        rainbow_service::component a;
    }
    s_color_buffer;
    static_assert(sizeof(s_color_buffer) == sizeof(sead::Color4f));

    sead::Color4f *features::kart::kart_effect_color_modifier::star(Kart::Unit *_this)
    {
        if (g_menu->m_kart_effect_color_modifier_entry->IsActivated() && _this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
        {
            auto const &kart_effect_color_modifier = g_settings.m_options.kart.kart_effect_color_modifier;

            if (kart_effect_color_modifier.star.enabled)
            {
                auto const color = []()
                {
                    switch (kart_effect_color_modifier.star.mode)
                    {
                    case decltype(kart_effect_color_modifier.star.mode)::Custom:
                        return kart_effect_color_modifier.star.color;
                    case decltype(kart_effect_color_modifier.star.mode)::Rainbow:
                        return g_rainbow_service->get_color();
                    };
                    return rainbow_service::rgb{};
                }();

                s_color_buffer.rgb = color;
                s_color_buffer.a.v = 0.f;

                // FIXME: would be better to have a sead::Color4f field in settings
                return reinterpret_cast<sead::Color4f *>(&s_color_buffer);
            }
        }

        return nullptr;
    }
}