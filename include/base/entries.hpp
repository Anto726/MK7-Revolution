#pragma once

#include <CTRPluginFramework.hpp>

namespace base
{
	struct entries
	{
		struct item
		{
			static void item_rain(CTRPluginFramework::MenuEntry *);
			static void item_wheel(CTRPluginFramework::MenuEntry *);
		};

		struct kart
		{
			static void intangibility_entry(CTRPluginFramework::MenuEntry *);
			static void instant_miniturbo(CTRPluginFramework::MenuEntry *);
			static void kart_statuses_entry(CTRPluginFramework::MenuEntry *);
		};

		struct network
		{
			static void protections(CTRPluginFramework::MenuEntry *);
		};

#ifdef _DEBUG
		struct debug
		{
			static void toggle_hooks(CTRPluginFramework::MenuEntry *);
		};
#endif
	};
}