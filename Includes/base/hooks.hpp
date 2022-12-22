#pragma once

#include <base/hooking/detour_hook.hpp>
#include <base/hooking/vmt_hook.hpp>

namespace base
{
    struct hook_funcs
    {
    };

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