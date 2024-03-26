#pragma once

#include <CTRPluginFramework.hpp>

namespace base
{
	class logger
	{
	public:
		explicit logger() = default;
		~logger() = default;
		
		template <typename ...args_t>
		void info(fmt::format_string<args_t ...>, args_t &&...);

		template <typename ...args_t>
		void debug(fmt::format_string<args_t ...>, args_t &&...);

		static std::string get_current_date_time_string(bool human_readable);

	private:
		void log(std::string);
		
		CTRPluginFramework::Mutex m_mutex;
	};

	template <typename ...args_t>
    inline void logger::info(fmt::format_string<args_t ...> fmt, args_t &&...args)
    {
        auto str = fmt::format(fmt, std::forward<args_t>(args)...);
        log(str);
    }

    template <typename ...args_t>
    inline void logger::debug(fmt::format_string<args_t ...> fmt, args_t &&...args)
    {
#ifdef _DEBUG
		info(fmt, std::forward<args_t>(args)...);
#endif
    }

	inline logger g_logger;
}