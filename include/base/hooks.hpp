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

        void enable();
		void disable();
    };

    inline hooks *g_hooks{};
}