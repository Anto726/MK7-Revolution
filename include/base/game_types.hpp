#pragma once

#include <forward.hpp>
#include <math/seadVectorFwd.h>

namespace base::game_types
{
	using Item_ItemObjDirectorBase_emitItemImpl_t = void (*)(Item::ItemObjDirectorBase *_this, s32 player_id, sead::Vector3f const *position, sead::Vector3f const *velocity);
	using Item_KartItem_setItemForce_t = void (*)(Item::KartItem *_this, Item::eItemSlot item);
}