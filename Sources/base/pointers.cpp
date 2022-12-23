#include <base/pointers.hpp>

#include <base/memory/all.hpp>
#include <CTRPluginFramework.hpp>

namespace base
{
	pointers::pointers()
	{
		memory::batch batch;

		batch.add("Item::KartItem", "02 01 8C E7 34 00 84 E5 04 00 A0 E1 B0 80 BD E8", [this](memory::handle handle)
		{
			m_Item_KartItem = handle.add(0x10).as<decltype(m_Item_KartItem)>();
		});

		batch.run(memory::range(memory::handle(0x100000), CTRPluginFramework::Process::GetTextSize()));

		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}
