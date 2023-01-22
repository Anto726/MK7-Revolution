#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/menu_types.hpp>
#include <MenuEntryHelpers.hpp>

#include <Item/KartItem.hpp>

namespace base
{
	void features::item::item_wheel_init(Item::KartItem *_this)
	{
		using namespace CTRPluginFramework;

		if (g_menu->m_item_wheel_entry->IsActivated())
			if (_this->isMaster() && !_this->isNetRecv())
				GetArg<menu_types::item_wheel_data_t>(g_menu->m_item_wheel_entry)->index = SIZE_MAX;
	}
}