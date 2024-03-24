#pragma once

#include <CTRPluginFramework.hpp>

namespace base
{
	struct entries
	{
#ifdef _DEBUG
		struct debug
		{
			static void toggle_hooks(CTRPluginFramework::MenuEntry *);
		};
#endif
	};
}