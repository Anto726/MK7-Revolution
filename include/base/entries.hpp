#pragma once

#include <CTRPluginFramework.hpp>

namespace base
{
	struct entries
	{
		struct item
		{
			static void item_rain_menu(CTRPluginFramework::MenuEntry *);
			static void item_wheel_menu(CTRPluginFramework::MenuEntry *);
		};

		struct kart
		{
			static void intangibility_menu(CTRPluginFramework::MenuEntry *);
			static void instant_miniturbo_menu(CTRPluginFramework::MenuEntry *);
			static void kart_statuses_menu(CTRPluginFramework::MenuEntry *);
		};

		struct network
		{
			static void protections_menu(CTRPluginFramework::MenuEntry *);
		};

#ifdef _DEBUG
		struct debug
		{
			static void toggle_hooks(CTRPluginFramework::MenuEntry *);
		};
#endif
	};
}