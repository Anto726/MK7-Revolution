#pragma once

#include "hooking/detour_hook.hpp"
#include "hooking/vmt_hook.hpp"

#include "hook_funcs.hpp"

namespace base
{
    class hooks
    {
        friend hook_funcs;

	public:
		explicit hooks();
		~hooks();

        inline bool is_enabled() const { return m_enabled; }

        void enable();
		void disable();

    private:
        bool m_enabled{};
    };

    inline hooks *g_hooks{};
}