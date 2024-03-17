#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Net/NetworkReceivedInfo.hpp>

#define SYSTEMINFO_SIZE 0xA0

namespace base
{
    bool features::network::protections_system_info(Net::NetworkReceivedInfo *info)
    {        
        return g_menu->m_protections_entry->IsActivated() && g_settings.m_options["network"]["protections"]["network"] && info->size != SYSTEMINFO_SIZE;
    }
}