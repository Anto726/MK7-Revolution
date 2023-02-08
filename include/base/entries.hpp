#pragma once
#include <CTRPluginFramework.hpp>

namespace base
{
	struct entries
	{
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