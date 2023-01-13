#pragma once
#include <CTRPluginFramework.hpp>

namespace base
{
	class files
	{
	public:
		explicit files();
		~files();

		inline CTRPluginFramework::File get_main_out() const { return m_main_out; }

		static void set_working_directory();

	private:
		CTRPluginFramework::File m_main_out;
	};

	inline files *g_files{};
}