#pragma once
#include <CTRPluginFramework.hpp>

namespace base
{
	class files
	{
	public:
		explicit files();
		~files();

		static void set_working_directory();

		CTRPluginFramework::File m_logger_file;
		std::string m_settings_path;
	};

	inline files *g_files{};
}