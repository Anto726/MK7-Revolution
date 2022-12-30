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
		void *m_Kart_VehicleReact_reactAccidentCommon;

		void *m_RaceSys_LapRankChecker_calcLapPosition;
	};

	inline pointers *g_pointers{};
}