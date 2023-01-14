#include <base/logger.hpp>

#include <base/files.hpp>

#include <3ds/os.h>

namespace base
{
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

    void logger::log_impl(std::string str)
    {
        g_files->m_logger_file.WriteLine("[" + logger::get_current_date_time_string(true) + "] " + str);
    }
}