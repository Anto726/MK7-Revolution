#include <base/features.hpp>

#include <base/pointers.hpp>

#include <base/game/kart/director.hpp>

#include <Kart/Unit.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
    void features::kart_director_create(game::kart::director *_this)
    {
        auto is_opponent = [](auto u)
        {
            auto const &v = u->m_vehicle;
            return !v->m_is_master || v->m_is_net_recv;
        };
        
        auto buffer = static_cast<Kart::Unit **>(nullptr);
        auto i = s32{};

        // count opponents
        auto size = s32{};
        for (auto const &u : _this->m_units)
            if (is_opponent(u))
                size++;

        // no opponents found
        if (size == 0) goto fail;

        // allocate enough space
        buffer = static_cast<decltype(buffer)>(g_pointers->m_operator_new(size * sizeof(decltype(*buffer))));
        if (buffer == nullptr) goto fail;

        // build opponents array
        for (auto const &u : _this->m_units)
            if (is_opponent(u))
                buffer[i++] = u;

        // store opponents array
        _this->m_opponent_units.setBuffer(size, buffer);
        return;

    fail:
        _this->m_opponent_units.setBuffer(0, nullptr);
    }

    size_t features::kart_director_size()
    {
        return sizeof(game::kart::director);
    }
}