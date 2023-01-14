#include <base/files.hpp>

#include <base/logger.hpp>

#define LOGS_PATH "Logs"
#define BASE_PATH "RevolutionBase"

namespace base
{
	using namespace CTRPluginFramework;

	files::files()
    :
        m_settings_path("settings.json")
	{
        auto logger_path = logger::get_current_date_time_string(false) + ".log";
        
        // Create the logs folder
        if (!Directory::IsExists(LOGS_PATH))
            Directory::Create(LOGS_PATH);

        // Create the logger file
        logger_path = LOGS_PATH + std::string("/") + logger_path;
        if (File::Open(m_logger_file, logger_path, File::Mode::WRITE | File::Mode::CREATE | File::Mode::SYNC) != File::OPResult::SUCCESS)
            abort();

        g_files = this;
	}

	files::~files()
	{
        g_files = nullptr;

		m_logger_file.Close();
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