#pragma once
#include <CTRPluginFramework.hpp>

namespace base
{
	struct entries
	{
		struct item
		{
			static void item_rain(CTRPluginFramework::MenuEntry *);
		};

		struct kart
		{
			static void intangibility(CTRPluginFramework::MenuEntry *);
			static void instant_miniturbo(CTRPluginFramework::MenuEntry *);
		};

#ifdef _DEBUG
		struct debug
		{
			static void toggle_hooks(CTRPluginFramework::MenuEntry *);
		};
#endif
	};
}