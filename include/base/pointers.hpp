#pragma once
#include <fwddec.hpp>
#include <types.hpp>

namespace base
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();

	public:
		System::RootSystem *m_root_system;

		void *m_Item_ItemDirector;

		void *m_Item_KartItem;

		void *m_Kart_Director;

		void *m_Kart_Unit_calcMove;
		void *m_Kart_Unit_calcReact;

		void *m_Kart_VehicleReact_reactAccidentCommon;

		void *m_RaceSys_LapRankChecker_calcLapPosition;

		float *m_miniturbo_blue_threshold;
		float *m_miniturbo_red_threshold;
		s32 *m_invincibility_frames_invisible_amount;
		s32 *m_invincibility_frames_visible_amount;
		float *m_press_frames_kart_size;
	};

	inline pointers *g_pointers{};
}