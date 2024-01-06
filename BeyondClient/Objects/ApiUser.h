#pragma once
/*


{
      "Address": 10389888,
      "Name": "VRC.Core.APIUser$$get_isFriend",
      "Signature": "bool VRC_Core_APIUser__get_isFriend (VRC_Core_APIUser_o* __this, const MethodInfo* method);",
      "TypeSignature": "iii"
    },
 */

class APIUser
{
    private:
        typedef const char* (__fastcall* GetApiUserString)(DWORD*, DWORD*);
        std::string GetApiUserAvatarAssetURL()
        {
            return ToString(((GetApiUserString)Address::ApiUser::GetApiUserAvatarAssetURL)(__this, nullptr));
        }
        std::string GetApiUserAvatarID()
        {
            return ToString(((GetApiUserString)Address::ApiUser::GetApiUserAvatarID)(__this, nullptr));
        }
        std::string GetApiUserDisplayName()
        {
            return ToString(((GetApiUserString)Address::ApiUser::GetApiUserDisplayName)(__this, nullptr));
        }

        typedef bool(__fastcall* GetApiUserIsSelfFunc)(DWORD*, DWORD*);
        bool GetApiUserIsSelf()
	    {
            return ((GetApiUserIsSelfFunc)Address::ApiUser::GetApiUserIsSelf)(__this, nullptr);
	    }

        typedef bool(__fastcall* IsFriendsWithFunc)(std::string*, DWORD*);
        bool IsFriendsWith(std::string* userid)
        {
            return ((IsFriendsWithFunc)Address::ApiUser::GetApiUserDisplayName)(userid, nullptr);
        }

        typedef DWORD* (__fastcall* GetApiUserFunc)(DWORD*, DWORD*);
        DWORD* GetApiUser(DWORD* Player)
        {
            return ((GetApiUserFunc)Address::ApiUser::GetApiUser)(Player, nullptr);
        }
    public:
        DWORD* __this; // Former ApiUserPointer

        std::string DisplayName = "N/A";
        std::string AvatarID;
        std::string AvatarAssetUrl;
        bool IsSelf;

        typedef bool(__fastcall* GetApiUserIsSelfFunc)(DWORD*, DWORD*);
        bool IsFriend()
        {
            return ((GetApiUserIsSelfFunc)Address::ApiUser::isFriend)(__this, nullptr);
        }

        APIUser(DWORD* PlayerPointer)
        {
            if (PlayerPointer != nullptr)
            {
                //... Get The Pointer to the ApiUser 
                __this = GetApiUser(PlayerPointer);
                DisplayName = GetApiUserDisplayName(); // <- try to comment this
                IsSelf = GetApiUserIsSelf();
                
                if (IsSelf)
			    {
                    AvatarID = GetApiUserAvatarID();
                    AvatarAssetUrl = GetApiUserAvatarAssetURL();
			    }
			    else
			    {
                    AvatarID = "0";
                    AvatarAssetUrl = "Invalid";
			    }
                
            }
            else
            {
                DisplayName = "AfricaWater";
                AvatarID = "0";
                AvatarAssetUrl = "Invalid";
                IsSelf = false;
            }
        }
};