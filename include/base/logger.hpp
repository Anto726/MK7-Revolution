#pragma once
#include <CTRPluginFramework.hpp>

#include <fmt/format.h>

namespace base
{
	class logger
	{
	public:
		explicit logger();
		~logger();
		
		template <typename ...args_t>
		void log(fmt::format_string<args_t ...>, args_t &&...);

		template <typename ...args_t>
		void log_debug(fmt::format_string<args_t ...>, args_t &&...);

		static void set_working_directory();

	private:
		std::string get_current_date_time_string(bool = false);

		CTRPluginFramework::File m_main_out;
	};

	template <typename ...args_t>
    inline void logger::log(fmt::format_string<args_t ...> fmt, args_t &&...args)
    {
        auto res = fmt::format(fmt,  std::forward<args_t>(args)...);
        m_main_out.WriteLine("[" + get_current_date_time_string(true) + "] " + res);
    }

    template <typename ...args_t>
    inline void logger::log_debug(fmt::format_string<args_t ...> fmt, args_t &&...args)
    {
#ifdef _DEBUG
		log(fmt, std::forward<args_t>(args)...);
#endif
    }

	inline logger *g_logger{};
}