#pragma once

#include <forward.hpp>
#include <math/seadVectorFwd.h>

namespace base::utils
{
    void emit_item(s32 const player_id, Item::eItemType const item, sead::Vector3f const &position, sead::Vector3f const &velocity);
}