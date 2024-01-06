#pragma once

namespace VRC_Pickup_Hook {

    void(__fastcall* AwakeFunc)(PickupStruct::VRC_SDKBase_VRC_Pickup_o*, DWORD*);
    void __stdcall Awake(PickupStruct::VRC_SDKBase_VRC_Pickup_o* Pickup, DWORD* methodinfo)
    {
        // Cast Pickup pointer to DWORD*
        DWORD* Pickup__ = reinterpret_cast<DWORD*>(Pickup);

        #pragma region  Initialize_VRC_Pickup

        // Create a VRC_Pickup instance and initialize its properties
        VRC_Pickup vrc_pickup;
        vrc_pickup.isOwner = false;
        vrc_pickup._this = Pickup__;
        vrc_pickup.component = Component(Pickup__);
        vrc_pickup.transform = Transform(vrc_pickup.component.__transform);
        vrc_pickup.name = Gameobject(vrc_pickup.component.__gameobject).name;
        vrc_pickup.Pickup_o = Pickup;

#pragma endregion 

        // Adjust proximity for infinite reach if infinite pickup reach is enabled
        if (Config::Pickups::InfiniteReach)
        {
            vrc_pickup.Pickup_o->fields.proximity = 9999999.f;
        }

        // Add the VRC_Pickup instance to the ItemUtils::Pickups vector
        ItemUtils::Pickups.push_back(vrc_pickup);

        return AwakeFunc(Pickup, methodinfo);
    }

    void Init() {
        HookFunction(Address::VRC_Pickup::Awake, Awake, AwakeFunc);
    }
}
