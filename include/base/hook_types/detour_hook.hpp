#pragma once

#include <CTRPluginFramework.hpp>

namespace base::hook_types
{
	class detour_hook
	{
	public:
		explicit detour_hook(std::string_view name, void *target, void *detour);
		~detour_hook();

		detour_hook(detour_hook &&) = delete;
		detour_hook(detour_hook const &) = delete;
		detour_hook &operator=(detour_hook &&) = delete;
		detour_hook &operator=(detour_hook const &) = delete;

		void enable();
		void disable();

		template <typename t, typename ...args_t>
		t call_original(args_t...);
        
	private:
		std::string_view m_name;
		CTRPluginFramework::Hook m_hook;
	};

	template <typename t, typename ...args_t>
	inline t detour_hook::call_original(args_t ...args)
	{
		return CTRPluginFramework::HookContext::GetCurrent().OriginalFunction<t>(args...);
	}
}