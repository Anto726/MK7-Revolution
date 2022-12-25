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

		void *m_Kart_VehicleReact_calcReact;
	};

	inline pointers *g_pointers{};
}