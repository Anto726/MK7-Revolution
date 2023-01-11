#include <base/pointers.hpp>

#include <base/memory/all.hpp>
#include <CTRPluginFramework.hpp>

#define TEXT_BASE 0x100000

namespace base
{
	pointers::pointers()
	{
		memory::batch batch;
		
		batch.run(memory::range(memory::handle(TEXT_BASE), CTRPluginFramework::Process::GetTextSize()));

		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}
