#ifdef _DEBUG
#include <base/entries.hpp>
#include <base/hooks.hpp>

namespace base
{
	void entries::debug::toggle_hooks(CTRPluginFramework::MenuEntry *entry)
	{
		if (g_hooks->is_enabled())
		{
			g_hooks->disable();
			entry->Name() = "Enable hooks";
		}
		else
		{
			g_hooks->enable();
			entry->Name() = "Disable hooks";
		}
	}
}

#endif