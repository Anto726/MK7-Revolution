#include <base/utils.hpp>

#include <base/pointers.hpp>

#include <Item/eItemType.hpp>
#include <Item/ItemDirector.hpp>
#include <Kart/Unit.hpp>
#include <Kart/Vehicle.hpp>
#include <Object/CharacterEngine.hpp>
#include <System/RootScene.hpp>
#include <System/RootSystem.hpp>
#include <System/SceneManager.hpp>

#include <math/seadVector.h>

namespace base::utils
{
    void emit_item(Kart::Unit const *unit, Item::eItemType const item, sead::Vector3f const &position, sead::Vector3f const &velocity)
    {
        auto const item_director = reinterpret_cast<Object::CharacterEngine *>(g_pointers->m_root_system->m_scene_manager->m_root_scene->get_engine(Object::EEngineType::Character))->m_collection->m_item_director;
        auto const item_obj_director = item_director->getDirector_FromItemType(item);
        if (item_obj_director != nullptr)
            g_pointers->m_Item_ItemObjDirectorBase_emitItemImpl(item_obj_director, unit->m_vehicle->m_player_id, &position, &velocity);
    }
}