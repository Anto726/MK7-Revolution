#pragma once
#include <fmt/format.h>

namespace base
{
	class logger
	{
	public:
		explicit logger() = default;
		~logger() = default;
		
		template <typename ...args_t>
		void log(fmt::format_string<args_t ...>, args_t &&...);

		template <typename ...args_t>
		void log_debug(fmt::format_string<args_t ...>, args_t &&...);

		static std::string get_current_date_time_string(bool human_readable);

	private:
		void log_impl(std::string);
	};

	template <typename ...args_t>
    inline void logger::log(fmt::format_string<args_t ...> fmt, args_t &&...args)
    {
        auto str = fmt::format(fmt,  std::forward<args_t>(args)...);
        log_impl(str);
    }

    template <typename ...args_t>
    inline void logger::log_debug(fmt::format_string<args_t ...> fmt, args_t &&...args)
    {
#ifdef _DEBUG
		log(fmt, std::forward<args_t>(args)...);
#endif
    }

	inline logger g_logger;
}