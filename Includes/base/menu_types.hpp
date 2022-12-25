#pragma once
#include <fwddec.hpp>

namespace base::menu_types
{
	struct item_wheel_data_t
	{
		size_t index;
		std::vector<Item::eItemSlot> items;
	};
}