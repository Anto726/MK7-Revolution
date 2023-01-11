#pragma once
#include <CTRPluginFramework.hpp>

namespace base
{
	class logger
	{
	public:
		explicit logger();
		~logger();
		
		void log(std::string line);
		void log_debug(std::string line);

		static void set_working_directory();

	private:
		CTRPluginFramework::File m_main_out;
	};

	inline logger *g_logger{};
}