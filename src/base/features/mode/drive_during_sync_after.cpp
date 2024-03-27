#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

#include <Object/CharacterEngine.hpp>
#include <RaceSys/ModeManagerBase.hpp>
#include <RaceSys/RaceDirector.hpp>
#include <System/RootScene.hpp>
#include <System/RootSystem.hpp>
#include <System/SceneManager.hpp>

namespace base
{
	void features::mode::drive_during_sync_after(RaceSys::ModeManagerBase *mode_manager_base, RaceSys::ModeManagerBase::ERaceState original)
    {
        if (g_menu->m_drive_during_sync_entry->IsActivated())
        {
            if (mode_manager_base == nullptr)
                mode_manager_base = reinterpret_cast<Object::CharacterEngine *>(g_pointers->m_root_system->m_scene_manager->m_root_scene->get_engine(Object::EEngineType::Character))->m_collection->m_race_director->m_mode_manager_base;

            mode_manager_base->m_race_state = original;
        }
    }
}