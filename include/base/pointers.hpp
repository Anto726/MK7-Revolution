#pragma once
#include <types.hpp>

namespace base
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();

	public:
		void *m_Item_KartItem;

		void *m_Kart_VehicleMove_calcMoveControlCommon;
		void *m_Kart_VehicleReact_calcReact;
		void *m_Kart_VehicleReact_reactAccidentCommon;

		void *m_RaceSys_LapRankChecker_calcLapPosition;

		s32 *m_invincibility_frames_invisible_amount;
		s32 *m_invincibility_frames_visible_amount;
	};

	inline pointers *g_pointers{};
}