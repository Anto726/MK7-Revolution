#pragma once

#include <CTRPluginFramework.hpp>

namespace base::hook_types
{
	class naked_hook
	{
	public:
		explicit naked_hook(std::string_view name, void *target, void *callback, u32 flags = CTRPluginFramework::USE_LR_TO_RETURN);
		~naked_hook();

		naked_hook(naked_hook &&) = delete;
		naked_hook(naked_hook const &) = delete;
		naked_hook &operator=(naked_hook &&) = delete;
		naked_hook &operator=(naked_hook const &) = delete;

		void enable();
		void disable();
        
	private:
		std::string_view m_name;
		CTRPluginFramework::Hook m_hook;
	};
}