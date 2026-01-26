#pragma once

#include <Kart/Director.hpp>

namespace base::game::kart
{
    class director : public Kart::Director
    {
    public:
        sead::Buffer<Kart::Unit *> m_opponent_units;
    };
    static_assert(sizeof(director) == 0x1A8);
}