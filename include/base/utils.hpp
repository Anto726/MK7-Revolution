#pragma once

#include <forward.hpp>
#include <math/seadVectorFwd.h>

namespace base::utils
{
    void emit_item(Kart::Unit *unit, Item::eItemType item, sead::Vector3f const &position, sead::Vector3f const &velocity);
}