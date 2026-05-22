#include <base/features.hpp>

#include <base/menu.hpp>

#include <RaceSys/ModeManager/ModeManagerBase.hpp>
#include <RaceSys/RaceDirector.hpp>
#include <System/RootSystem.hpp>
#include <System/KDPadInputer.hpp>

namespace base
{
	void features::mode::drive_during_sync::after(RaceSys::ModeManagerBase *mode_manager, RaceSys::ModeManagerBase::RaceState original)
    {
        if (g_menu->m_drive_during_sync_entry->IsActivated())
        {
            if (mode_manager == nullptr)
                mode_manager = System::g_root_system->get_race_director()->m_mode_manager;

            mode_manager->m_state_observer.m_state_current = original;
        }
    }

    RaceSys::ModeManagerBase::RaceState features::mode::drive_during_sync::before(RaceSys::ModeManagerBase *mode_manager)
    {
        RaceSys::ModeManagerBase::RaceState original{};

        if (g_menu->m_drive_during_sync_entry->IsActivated())
        {
            if (mode_manager == nullptr)
                mode_manager = System::g_root_system->get_race_director()->m_mode_manager;

            original = static_cast<RaceSys::ModeManagerBase::RaceState>(mode_manager->m_state_observer.m_state_current);
            mode_manager->m_state_observer.m_state_current = std::to_underlying(RaceSys::ModeManagerBase::RaceState_Race);
        }

        return original;
    }

    bool features::mode::drive_during_sync::bottom_screen(bool is_bottom_screen_sync)
    {
        return g_menu->m_drive_during_sync_entry->IsActivated() ? false : is_bottom_screen_sync;
    }

    bool features::mode::drive_during_sync::input(System::KDPadInputer *_this)
    {
        if (g_menu->m_drive_during_sync_entry->IsActivated())
        {
            _this->calcInput();
            return true;
        }

        return false;
    }
}