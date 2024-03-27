#include <base/pointers.hpp>

#include <base/memory/all.hpp>
#include <CTRPluginFramework.hpp>

#include <base/hooks.hpp>

#define TEXT_BASE 0x100000

namespace base
{
	pointers::pointers()
	{
		memory::batch batch;

		batch.add("sead::Random", "00 00 54 E3 04 00 85 E5 04 00 A0 11 00 40 A0 03", [this](memory::handle handle)
		{
			m_random = *handle.add(0x20).as<decltype(m_random) *>();
		});

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

			auto vtbl = *static_cast<decltype(m_Kart_Director) **>(m_Kart_Director);
			auto Kart_Director_calcBeforeStructure = vtbl[hooks::Director_calcBeforeStructure_index];
			auto hnd = memory::handle(Kart_Director_calcBeforeStructure);

			m_Kart_Unit_calcMove = hnd.add(0x224).jmp().as<decltype(m_Kart_Unit_calcMove)>();
			m_Kart_VehicleReact_calcReact_0x20 = hnd.add(0x1E8).jmp().add(0x18).jmp().add(0x20).as<decltype(m_Kart_VehicleReact_calcReact_0x20)>();
		});

		batch.add("Item::ItemObjDirectorBase::_emitItemImpl", "F0 43 2D E9 1C D0 4D E2 01 40 A0 E1 02 60 A0 E1", [this](memory::handle handle)
		{
			m_Item_ItemObjDirectorBase_emitItemImpl = reinterpret_cast<decltype(m_Item_ItemObjDirectorBase_emitItemImpl)>(handle.as<void *>());
		});

		batch.add("Item::KartItem::setItemForce", "70 40 2D E9 00 40 A0 E1 34 00 90 E5 01 50 A0 E1", [this](memory::handle handle)
		{
			m_Item_KartItem_setItemForce = reinterpret_cast<decltype(m_Item_KartItem_setItemForce)>(handle.as<void *>());
		});

		batch.add("Item::ItemObjBase::setState_SelfMove", "70 40 2D E9 00 50 A0 E1 9C 00 9F E5 01 40 A0 E1", [this](memory::handle handle)
		{
			m_Item_ItemObjBase_setStateSelfMove = handle.as<decltype(m_Item_ItemObjBase_setStateSelfMove)>();
		});

		batch.add("Item::ItemObjKouraR::stateInitComeBackDown", "F0 41 2D E9 00 40 A0 E1 28 D0 4D E2 10 01 90 E5", [this](memory::handle handle)
		{
			m_Item_ItemObjKouraR_stateInitComeBackDown = handle.as<decltype(m_Item_ItemObjKouraR_stateInitComeBackDown)>();
		});

		batch.add("Effect::KartEffect::_calcTireEffect_WheelSpin", "70 40 2D E9 00 40 A0 E1 02 8B 2D ED 60 D0 4D E2", [this](memory::handle handle)
		{
			m_Effect_KartEffect_calcTireEffectWheelSpin = handle.as<decltype(m_Effect_KartEffect_calcTireEffectWheelSpin)>();
		});

		batch.add("Kart::VehicleReact::reactAccidentCommon", "FF 4F 2D E9 0C D0 4D E2 00 40 A0 E1 01 5A 84 E2", [this](memory::handle handle)
		{
			m_Kart_VehicleReact_reactAccidentCommon = handle.as<decltype(m_Kart_VehicleReact_reactAccidentCommon)>();
		});

		batch.add("Net::NetworkEngine::sendUnreliableCore", "F0 4F 2D E9 00 40 A0 E1 01 0B 80 E2 01 50 A0 E1", [this](memory::handle handle)
		{
			m_Net_NetworkEngine_sendUnreliableCore = handle.as<decltype(m_Net_NetworkEngine_sendUnreliableCore)>();
		});

		batch.add("Net::NetworkSystemInfo::onReceivedCore", "F0 5F 2D E9 00 40 A0 E1 CC 20 90 E5 08 00 91 E5", [this](memory::handle handle)
		{
			m_Net_NetworkSystemInfo_onReceivedCore = handle.as<decltype(m_Net_NetworkSystemInfo_onReceivedCore)>();
		});

		batch.add("RaceSys::LapRankChecker::calcLapPosition_", "F0 4F 2D E9 01 40 A0 E1 00 50 A0 E1 02 8B 2D ED", [this](memory::handle handle)
		{
			m_RaceSys_LapRankChecker_calcLapPosition = handle.as<decltype(m_RaceSys_LapRankChecker_calcLapPosition)>();
		});

		batch.add("System::KDPadInputer::calcInput", "04 10 90 E5 01 00 51 E3 02 00 00 1A 00 10 90 E5", [this](memory::handle handle)
		{
			m_System_KDPadInputer_calcInput = handle.as<decltype(m_System_KDPadInputer_calcInput)>();
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
