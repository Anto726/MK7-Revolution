#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Field/Accessor/JugemPoint.hpp>
#include <Item/ItemDirector.hpp>
#include <Item/KartItem.hpp>
#include <Kart/NetData.hpp>
#include <Net/eNetworkBufferType.hpp>
#include <Net/NetworkReceivedInfo.hpp>

namespace base
{
    bool features::network::protections::item(Item::ItemDirector *_this, Net::NetworkItemEventDataMgr::SlotData *data)
    {
        if (g_menu->m_protections_entry->IsActivated())
        {
            auto const &protections = g_settings.m_options.network.protections;

            auto const &kart_item = _this->m_kart_items.at(reinterpret_cast<Net::NetworkItemEventDataMgr::SSelfMove *>(data->data)->player_id);
            auto const &status_flags = kart_item->m_info_proxy->m_vehicle->m_status_flags;

            auto const killer_protection = [&]() { return protections.item.killer_items && status_flags.killer; };
            auto const tail_protection = [&]() { return protections.item.tail_items && status_flags.tail; };

            switch (data->event_type)
            {
                case Net::NetworkItemEventDataMgr::EEventType::SelfMove:
                case Net::NetworkItemEventDataMgr::EEventType::InitUse:
                {
                    if (killer_protection()) return true;

                    // TODO: it false flags this way, as it is possible to send InitUse while in Tail (e.g. dropped Stars).
                    // Dropped items might also send SelfMove on deflect.
                    if (tail_protection()) return true;

                    break;
                }
                default:
                    break;
            }
        }

        return false;
    }

    bool features::network::protections::kart(Kart::NetData *_this)
    {
        if (g_menu->m_protections_entry->IsActivated())
        {
            auto const &protections = g_settings.m_options.network.protections;

            if (protections.kart.accident_type && _this->m_accident_type >= Kart::VehicleReact::EAcdType::MAX)
                return true;

            if (protections.kart.respawn_point && _this->m_respawn_point_id >= Field::GetJugemPointAccessor()->m_entries.size())
                return true;
        }

        return false;
    }

    bool features::network::protections::system_info(Net::NetworkReceivedInfo *info)
    {
        return g_menu->m_protections_entry->IsActivated() && g_settings.m_options.network.protections.network.system_info && info->m_size != g_pointers->m_network_buffer_sizes[std::to_underlying(Net::eNetworkBufferType::SystemInfo)];
    }
}