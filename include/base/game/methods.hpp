#pragma once

#include <forward.hpp>

#include <LMS_MessageID.hpp>
#include <Item/eItemSlot.hpp>
#include <Kart/EJugemRecoverType.hpp>

#include <math/seadMatrix.h>
#include <math/seadVectorFwd.h>

#include <base/sead/safe_string.hpp>

namespace base::game::methods
{
	using operator_new_t = void *(*)(size_t count);
	using Item_ItemDirector_dropEquip_t = void (*)(Item::ItemDirector *_this, s32 player_id);
	using Item_ItemObjBase_stateEquipHang_t = void (*)(Item::ItemObjBase *_this);
	using Item_ItemObjDirectorBase_emitItemImpl_t = void (*)(Item::ItemObjDirectorBase *_this, s32 player_id, sead::Vector3f const *position, sead::Vector3f const *velocity);
	using Item_ItemObjDirectorBase_entryUse_t = Item::ItemObjBase *(*)(Item::ItemObjDirectorBase *_this, Kart::InfoProxy *info_proxy, bool on_self);
	using Item_KartItem_setItemForce_t = void (*)(Item::KartItem *_this, Item::eItemSlot item);
	using Kart_Unit_startJugemRecover_t = void (*)(Kart::Unit *_this, Kart::EJugemRecoverType type);
	using Kart_VehicleMove_endKiller_t = void (*)(Kart::VehicleMove *_this);
	using Sequence_BaseRacePage_initTime_t = void (*)(Sequence::BaseRacePage *_this);
	using UI_MessageData_getMessage_t = void (*)(char16_t **out, UI::MessageData *message_data, LMS_MessageID message_id);
	using UI_MessageIDConverter_getMessageData_t = UI::MessageData *(*)(UI::MessageIDConverter *_this, _sead::safe_string const *);
	using Util_Math_CopyRotate = void (*)(sead::Matrix34f *_this, sead::Matrix33f *src);
}