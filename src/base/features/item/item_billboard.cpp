#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

#include <Camera/CameraEngine.hpp>
#include <Item/ItemObj/ItemObjBase.hpp>
#include <System/RootSystem.hpp>
#include <System/SceneManager.hpp>
#include <Util/TStateObserver.hpp>

namespace base
{
    void features::item::item_billboard::calc(Item::ItemObjBase *_this)
    {
        if (g_menu->m_item_billboard_entry->IsActivated() && _this->m_current_life >= 0 && _this->m_is_draw)
        {
            // Rotate items towards the camera
            g_pointers->m_Util_Math_CopyRotate(&_this->m_draw_mtx, &System::g_root_system->m_scene_manager->m_game_scene->get_camera_engine()->unk_0x7C);

            // Squish items horizontally
            _this->m_update_scale = true;
            _this->m_scale.z = 0.2f;
        }
    }

    f32 features::item::item_billboard::multi(f32 original)
    {
        // Prevent multi items from rotating on themselves
        if (g_menu->m_item_billboard_entry->IsActivated())
            return 0.f;

        return original;
    }
}