#include <base/hooking.hpp>

namespace base
{
    hooking::hooking()
	{
		g_hooking = this;
	}

	hooking::~hooking()
	{
		g_hooking = nullptr;

		if (m_enabled)
			disable();
	}

    void hooking::enable()
	{
		m_enabled = true;
	}

	void hooking::disable()
	{
		m_enabled = false;
	}
}