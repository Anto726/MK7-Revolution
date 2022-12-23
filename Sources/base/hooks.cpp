#include <base/hooks.hpp>

#include <base/pointers.hpp>

namespace base
{
    hooks::hooks()
	:
		m_Item_KartItem("Item::KartItem", g_pointers->m_Item_KartItem, hook_funcs::Item_KartItem_count)
	{
		m_Item_KartItem.hook(hook_funcs::Item_KartItem_initBeforeStructure_index, reinterpret_cast<void *>(&hook_funcs::Item_KartItem_initBeforeStructure));
		m_Item_KartItem.hook(hook_funcs::Item_KartItem_calcBeforeStructure_index, reinterpret_cast<void *>(&hook_funcs::Item_KartItem_calcBeforeStructure));

		g_hooks = this;
	}

	hooks::~hooks()
	{
		g_hooks = nullptr;
	}

    void hooks::enable()
	{
		m_Item_KartItem.enable();
	}

	void hooks::disable()
	{
		m_Item_KartItem.disable();
	}
}