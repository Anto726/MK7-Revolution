#include <base/features.hpp>

#include <base/menu.hpp>

#include <System/KDPadInputer.hpp>

namespace base
{
    bool features::mode::drive_during_sync_input(System::KDPadInputer *_this)
    {
        if (g_menu->m_drive_during_sync_entry->IsActivated())
        {
            _this->calcInput();
            return true;
        }

        return false;
    }
}