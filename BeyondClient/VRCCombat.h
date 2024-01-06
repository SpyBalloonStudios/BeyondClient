
namespace VRC_Combat {
    typedef DWORD*(__fastcall* GetInstance_o)(DWORD*);
    DWORD* GetInstance()
    {
        return ((GetInstance_o)Address::VRC_Combat::GetInstance)(nullptr);
    }

    typedef void(__fastcall* RespawnPlayerRPC_o)(DWORD*, DWORD*, DWORD*);
    void RespawnPlayerRPC(DWORD* VRC_Combat_System, DWORD* VRCPlayerApi)
    {
        ((RespawnPlayerRPC_o)Address::VRC_Combat::RespawnPlayerRPC)(VRC_Combat_System, VRCPlayerApi, nullptr);
    }
}