#pragma once

namespace base
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();

	public:
		void *m_Item_KartItem;
	};

	inline pointers *g_pointers{};
}