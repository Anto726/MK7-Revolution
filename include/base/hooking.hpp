#pragma once

#include "hook_types/detour_hook.hpp"
#include "hook_types/naked_hook.hpp"
#include "hook_types/vmt_hook.hpp"

#include "hooks.hpp"

namespace base
{
    class hooking
    {
        friend hooks;

	public:
		explicit hooking();
		~hooking();

        inline bool is_enabled() const { return m_enabled; }

        void enable();
		void disable();

    private:
        bool m_enabled{};
    };

    inline hooking *g_hooking{};
}