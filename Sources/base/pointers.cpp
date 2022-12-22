#include <base/pointers.hpp>

#include <base/memory/all.hpp>
#include <CTRPluginFramework.hpp>

namespace base
{
	pointers::pointers()
	{
		memory::batch batch;
		batch.run(memory::range(memory::handle(0x100000), CTRPluginFramework::Process::GetTextSize()));

		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}
