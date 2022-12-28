#include <base/hooks.hpp>

namespace base
{
    hooks::hooks()
	{
		g_hooks = this;
	}

	hooks::~hooks()
	{
		g_hooks = nullptr;
	}

    void hooks::enable()
	{
	}

	void hooks::disable()
	{
	}
}