#pragma once
#include <forward.hpp>
#include <math/seadVectorFwd.h>

namespace base::game_types
{
	using Item_ItemObjDirectorBase_emitItemImpl_t = void (*)(Item::ItemObjDirectorBase *, s32, sead::Vector3f const *, sead::Vector3f const *);
}