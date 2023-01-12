#include <base/logger.hpp>

#define LOGS_PATH "Logs"
#define BASE_PATH "Revolution"

namespace base
{
    using namespace CTRPluginFramework;

    logger::logger()
    {
        // Have some names
        std::string main_log_path = get_current_date_time_string() + ".log";
        
        // Create the logs folder
        if (!Directory::IsExists(LOGS_PATH))
            Directory::Create(LOGS_PATH);

        // Create the log file
        main_log_path = LOGS_PATH + std::string("/") + main_log_path;
        if (File::Open(m_main_out, main_log_path, File::Mode::WRITE | File::Mode::CREATE | File::Mode::SYNC) != File::OPResult::SUCCESS)
            abort();

        g_logger = this;
    }

    logger::~logger()
    {
        g_logger = nullptr;

        m_main_out.Close();
    }

    void logger::set_working_directory()
    {
        std::string path = "/luma/plugins";

        // Start from the root
        Directory::ChangeWorkingDirectory("");

        // https://gitlab.com/thepixellizeross/ctrpluginframework/-/blob/develop/Library/source/pluginInit.cpp#L157
        if (FwkSettings::Header->isDefaultPlugin)
        {
            path += "/ActionReplay";
            if (!Directory::IsExists(path))
                Directory::Create(path);

            path += Utils::Format("/%016llX", Process::GetTitleID());
            if (!Directory::IsExists(path))
                Directory::Create(path);
        }
        else
        {
            // Exists already to run the plugin
            path += Utils::Format("/%016llX", Process::GetTitleID());
        }

        path += std::string("/") + BASE_PATH;
        if (!Directory::IsExists(path))
            Directory::Create(path);

        Directory::ChangeWorkingDirectory(path + "/");
    }

    std::string logger::get_current_date_time_string(bool human_readable)
    {
        timeval t;
        time_t nowtime;
        tm *nowtm;
        char buf[64];

        // https://gitlab.com/thepixellizeross/ctrpluginframework/-/blob/develop/Library/source/ctrulibExtension/system/syscalls.c#L49
        s64 now = osGetTime() - 2208988800000ULL;
        t.tv_sec = now / 1000;
        t.tv_usec = (now - 1000 * t.tv_sec) * 1000;

        // https://stackoverflow.com/a/2409054
        nowtime = t.tv_sec;
        nowtm = localtime(&nowtime);
        strftime(buf, sizeof(buf), (human_readable ? "%Y-%m-%d %H:%M:%S" : "%Y-%m-%d_%H-%M-%S"), nowtm);

        return std::string(buf);
    }
}