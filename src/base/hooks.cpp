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

		if (m_enabled)
			disable();
	}

    void hooks::enable()
	{
		m_enabled = true;
	}

	void hooks::disable()
	{
		m_enabled = false;
	}
}