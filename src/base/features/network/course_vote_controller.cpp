#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <base/services/message_service.hpp>

#include <Net/NetworkEngine.hpp>
#include <Net/NetworkSelectMenuProcess.hpp>
#include <RaceSys/ECourseID.hpp>
#include <Sequence/MenuData.hpp>

#include <format>

namespace base
{
    void features::network::course_vote_controller(Sequence::MenuData *data, Net::NetworkSelectMenuProcess *process, Net::NetworkEngine *engine)
    {
        if (g_menu->m_course_vote_controller_entry->IsActivated() && engine->m_local_player_id == engine->m_master_player_id)
        {
            auto const &course_vote_controller = g_settings.m_options.network.course_vote_controller;

            auto const &votes = data->m_course_votes;
            auto &vote = process->m_selected_course_vote_index;

            switch (course_vote_controller.mode)
            {
                case decltype(course_vote_controller.mode)::Choose:
                {
                    auto keyboard = CTRPluginFramework::Keyboard(g_menu->m_course_vote_controller_entry->Name());
                    keyboard.DisplayTopScreen = true;

                    keyboard.GetMessage() += "\nChoose" + (votes.at(vote)->course_id == RaceSys::ECourseID::MAX ? std::format("\n\nRandom: {}", utils::course_name(static_cast<RaceSys::ECourseID>(process->m_selected_random_course_id))) : "");

                    auto options = std::vector<std::string>();
                    for (auto i = s32{}; i < votes.size(); ++i)
                        options.push_back((i == vote ? CTRPluginFramework::Color::LimeGreen << "" : "") + utils::course_name(votes.at(i)->course_id));
                    keyboard.Populate(options);

                    // Falls back to the original index if the user aborts the Keyboard
                    if (auto const choice = keyboard.Open(); choice >= 0)
                        vote = choice;

                    break;
                }
                case decltype(course_vote_controller.mode)::Self:
                {
                    for (auto i = s32{}; i < votes.size(); ++i)
                        if (votes.at(i)->station_id == engine->m_local_station_id)
                        {
                            vote = i;
                            break;
                        }

                    break;
                }
                case decltype(course_vote_controller.mode)::Direct:
                {
                    switch (course_vote_controller.direct_mode)
                    {
                        case decltype(course_vote_controller.direct_mode)::First: vote = {}; break;
                        case decltype(course_vote_controller.direct_mode)::Last: vote = votes.size() - 1; break;
                    }

                    break;
                }
                case decltype(course_vote_controller.mode)::Filter:
                {
                    auto const select_vote = [&](auto const &set, auto const &predicate) -> std::optional<size_t>
                    {
                        auto vector = std::vector<size_t>();

                        for (auto i = s32{}; i < votes.size(); ++i)
                            if (predicate(set, votes.at(i)->course_id))
                                vector.push_back(i);

                        if (!vector.empty())
                            return vector.at(utils::random_u32(vector.size()));

                        return {};
                    };

                    switch (course_vote_controller.filter_mode)
                    {
                        case decltype(course_vote_controller.filter_mode)::Whitelist:
                        {
                            if (auto const opt = select_vote(course_vote_controller.whitelist_set, [](auto const &set, auto const &course_id) { return set.contains(course_id); }); opt.has_value())
                                vote = opt.value();
                            
                            break;
                        }
                        case decltype(course_vote_controller.filter_mode)::Blacklist:
                        {
                            if (auto const opt = select_vote(course_vote_controller.blacklist_set, [](auto const &set, auto const &course_id) { return !set.contains(course_id); }); opt.has_value())
                                vote = opt.value();

                            break;
                        }
                    }

                    break;
                }
            }
        }
    }
}