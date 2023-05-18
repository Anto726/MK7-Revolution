#include <base/pointers.hpp>

#include <base/memory/all.hpp>
#include <CTRPluginFramework.hpp>

#include <base/hook_funcs.hpp>

#define TEXT_BASE 0x100000

namespace base
{
	pointers::pointers()
	{
		memory::batch batch;

		batch.add("System::RootSystem", "00 20 95 E5 70 40 BD E8", [this](memory::handle handle)
		{
			m_root_system = *handle.add(0x20).as<decltype(m_root_system) *>();
		});
		
		batch.add("Item::ItemDirector", "20 41 80 E5 24 41 80 E5 28 41 80 E5 10 80 BD E8", [this](memory::handle handle)
		{
			m_Item_ItemDirector = handle.add(0x10).as<decltype(m_Item_ItemDirector)>();
		});

		batch.add("Item::KartItem", "02 01 8C E7 34 00 84 E5 04 00 A0 E1 B0 80 BD E8", [this](memory::handle handle)
		{
			m_Item_KartItem = handle.add(0x10).as<decltype(m_Item_KartItem)>();
		});

		batch.add("Kart::Director", "04 00 A0 E1 24 50 84 E5 70 80 BD E8", [this](memory::handle handle)
		{
			m_Kart_Director = handle.add(0xC).as<decltype(m_Kart_Director)>();

			auto Kart_Director_calcBeforeStructure = (*static_cast<decltype(m_Kart_Director) **>(m_Kart_Director))[hook_funcs::Kart_Director_calcBeforeStructure_index];
			auto hnd = memory::handle(Kart_Director_calcBeforeStructure);
			m_Kart_Unit_calcMove = hnd.add(0x224).jmp().as<decltype(m_Kart_Unit_calcMove)>();
			m_Kart_Unit_calcReact = hnd.add(0x1E8).jmp().as<decltype(m_Kart_Unit_calcReact)>();
		});

		batch.add("Effect::KartEffect::_calcTireEffect_WheelSpin", "70 40 2D E9 00 40 A0 E1 02 8B 2D ED 60 D0 4D E2", [this](memory::handle handle)
		{
			m_Effect_KartEffect_calcTireEffectWheelSpin = handle.as<decltype(m_Effect_KartEffect_calcTireEffectWheelSpin)>();
		});

		batch.add("Kart::VehicleReact::reactAccidentCommon", "FF 4F 2D E9 0C D0 4D E2 00 40 A0 E1 01 5A 84 E2", [this](memory::handle handle)
		{
			m_Kart_VehicleReact_reactAccidentCommon = handle.as<decltype(m_Kart_VehicleReact_reactAccidentCommon)>();
		});

		batch.add("RaceSys::LapRankChecker::calcLapPosition_", "F0 4F 2D E9 01 40 A0 E1 00 50 A0 E1 02 8B 2D ED", [this](memory::handle handle)
		{
			m_RaceSys_LapRankChecker_calcLapPosition = handle.as<decltype(m_RaceSys_LapRankChecker_calcLapPosition)>();
		});

		batch.add("Data", "F0 4F 2D E9 01 6A 80 E2 00 40 A0 E1 04 8B 2D ED", [this](memory::handle handle)
		{
			auto hnd = memory::handle(*handle.add(0x410).as<void **>());
			m_miniturbo_blue_threshold = hnd.add(0x12C).as<decltype(m_miniturbo_blue_threshold)>();
			m_miniturbo_red_threshold = hnd.add(0x130).as<decltype(m_miniturbo_red_threshold)>();
			m_invincibility_frames_invisible_amount = hnd.add(0x230).as<decltype(m_invincibility_frames_invisible_amount)>();
			m_invincibility_frames_visible_amount = hnd.add(0x234).as<decltype(m_invincibility_frames_visible_amount)>();
			m_press_frames_kart_size = hnd.add(0x2CC).as<decltype(m_press_frames_kart_size)>();
		});
		
		batch.run(memory::range(memory::handle(TEXT_BASE), CTRPluginFramework::Process::GetTextSize()));

		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}
