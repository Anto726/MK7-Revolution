#pragma once

#include <forward.hpp>
#include <types.hpp>

#include "game_types.hpp"

#include <random/seadRandom.h>

namespace base
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();

		// FIXME: for some reason, sead::GlobalRandom corrupts the instance when used
		sead::Random **m_random;
		System::RootSystem *m_root_system;

		void *m_Item_ItemDirector;
		void *m_Item_KartItem;
		void *m_Kart_Director;

		game_types::Item_ItemObjDirectorBase_emitItemImpl_t m_Item_ItemObjDirectorBase_emitItemImpl;
		game_types::Item_KartItem_setItemForce_t m_Item_KartItem_setItemForce;

		void *m_Item_ItemObjBase_setStateSelfMove;
		void *m_Item_ItemObjKouraR_stateInitComeBackDown;
		void *m_Effect_KartEffect_calcTireEffectWheelSpin;
		void *m_Kart_Unit_calcMove;
		void *m_Kart_Unit_calcReact;
		void *m_Kart_VehicleReact_reactAccidentCommon;
		void *m_Net_NetworkEngine_sendUnreliableCore;
		void *m_RaceSys_LapRankChecker_calcLapPosition;

		float *m_miniturbo_blue_threshold;
		float *m_miniturbo_red_threshold;
		s32 *m_invincibility_frames_invisible_amount;
		s32 *m_invincibility_frames_visible_amount;
		float *m_press_frames_kart_size;
	};

	inline pointers *g_pointers{};
}