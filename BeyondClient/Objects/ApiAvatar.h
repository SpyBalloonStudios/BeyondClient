#pragma once

/*
{
    "Address": 7198128,
    "Name": "VRC.Core.ApiAvatar$$get_assetUrl",
    "Signature": "System_String_o* VRC_Core_ApiAvatar__get_assetUrl (VRC_Core_ApiAvatar_o* __this, const MethodInfo* method);",
    "TypeSignature": "iii"
},
*/

class APIAvatar
{
    private:
        typedef DWORD* (__fastcall* GetApiAvatarFunc)(DWORD*, DWORD*);
        DWORD* GetApiAvatar(DWORD* Player)
        {
            return ((GetApiAvatarFunc)(Address::ApiAvatar::GetAPIAvatar))(Player, nullptr);
        }

        typedef const char* (__fastcall* GetAssetUrlFunc)(DWORD*, DWORD*);
        const char* GetAssetUrl(DWORD* ApiAvatar)
        {
            return ((GetAssetUrlFunc)(Address::ApiAvatar::GetAssetUrl))(ApiAvatar, nullptr);
        }
    public:
        DWORD* __this; // Former ApiAvatarPointer
        std::string UnityPackageUrl;



        APIAvatar(DWORD* PlayerPointer)
        {
            if (PlayerPointer != NULL)
            {
                //... Get The Pointer to the ApiAvatar
                __this = GetApiAvatar(PlayerPointer);
                UnityPackageUrl = ToString(GetAssetUrl(__this));
            }
        }
};