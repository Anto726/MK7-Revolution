#pragma once
#include <forward.hpp>

#include <vector>

namespace base::menu_types
{
	struct item_rain_data_t
	{
		u32 count;
	};

	struct item_wheel_data_t
	{
		size_t index;
		std::vector<Item::eItemSlot> items;
	};
}