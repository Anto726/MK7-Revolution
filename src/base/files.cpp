#include <base/files.hpp>

#include <base/logger.hpp>

#define LOGS_PATH "Logs"
#define BASE_PATH "RevolutionBase"

namespace base
{
	using namespace CTRPluginFramework;

	files::files()
	{
        auto main_log_path = logger::get_current_date_time_string(false) + ".log";
        
        // Create the logs folder
        if (!Directory::IsExists(LOGS_PATH))
            Directory::Create(LOGS_PATH);

        // Create the log file
        main_log_path = LOGS_PATH + std::string("/") + main_log_path;
        if (File::Open(m_main_out, main_log_path, File::Mode::WRITE | File::Mode::CREATE | File::Mode::SYNC) != File::OPResult::SUCCESS)
            abort();

        g_files = this;
	}

	files::~files()
	{
        g_files = nullptr;

		m_main_out.Close();
	}

	void files::set_working_directory()
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
}