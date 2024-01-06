#pragma once

namespace VRCPlayerApi_Hook {
    void(__fastcall* RespawnFunc)(DWORD*, DWORD*);
    void __stdcall Respawn(DWORD* VRC_SDKBase_VRCPlayerApi_o, DWORD* methodinfo)
    {
        // Check if respawn is blocked based on configuration
        if (Config::VRCPlayerAPI::Block::Respawn)
            return;

        return RespawnFunc(VRC_SDKBase_VRCPlayerApi_o, methodinfo);
    }

    void Init() {
        HookFunction(Address::VRCPlayerAPI::Respawn, Respawn, RespawnFunc);
    }
}
