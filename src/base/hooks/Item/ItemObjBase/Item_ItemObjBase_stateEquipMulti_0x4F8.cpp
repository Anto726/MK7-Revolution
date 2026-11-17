#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjBase_stateEquipMulti_0x4F8()
    {
        asm volatile
        (
            "push {r0, r3, lr}\n"
            "bl __item_billboard_multi\n"
            "pop {r0, r3, pc}\n"
        );
    }

    extern "C" auto __item_billboard_multi(f32 original)
    {
        return features::item::item_billboard::multi(original);
    }
}