#ifdef _DEBUG
#include <base/entries.hpp>
#include <base/hooks.hpp>

namespace base
{
	void entries::debug::toggle_hooks(CTRPluginFramework::MenuEntry *entry)
	{
		if (g_hooking->is_enabled())
		{
			g_hooking->disable();
			entry->Name() = "Enable hooks";
		}
		else
		{
			g_hooking->enable();
			entry->Name() = "Disable hooks";
		}
	}
}

#endif