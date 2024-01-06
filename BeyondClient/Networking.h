#pragma once

/*

  {
	  "Address": 96540304,
	  "Name": "VRC.SDKBase.Networking$$GoToRoom",
	  "Signature": "bool VRC_SDKBase_Networking__GoToRoom (System_String_o* roomID, const MethodInfo* method);",
	  "TypeSignature":
	  
	  
	  {
      "Address": 96541152,
      "Name": "VRC.SDKBase.Networking$$RPC",
      "Signature": "void VRC_SDKBase_Networking__RPC (int32_t targetClients, UnityEngine_GameObject_o* targetObject, System_String_o* methodName, System_Object_array* parameters, const MethodInfo* method);",
      "TypeSignature": "viiiii"
    },"iii"
	},

	 {
	  "Address": 96540416,
	  "Name": "VRC.SDKBase.Networking$$Instantiate",
	  "Signature": "UnityEngine_GameObject_o* VRC_SDKBase_Networking__Instantiate (int32_t broadcast, System_String_o* prefabPathOrDynamicPrefabName, UnityEngine_Vector3_o position, UnityEngine_Quaternion_o rotation, const MethodInfo* method);",
	  "TypeSignature": "iiiiii"
	},

	{
	  "Address": 96541008,
	  "Name": "VRC.SDKBase.Networking$$RPC",
	  "Signature": "void VRC_SDKBase_Networking__RPC (VRC_SDKBase_VRCPlayerApi_o* targetPlayer, UnityEngine_GameObject_o* targetObject, System_String_o* methodName, System_Object_array* parameters, const MethodInfo* method);",
	  "TypeSignature": "viiiii"
	},

*/

class Networking
{
	private: 
		typedef int32_t(__fastcall* GetServerTimeInMillisecondsFunc)(DWORD*);
		typedef void (__fastcall* Destroy_o)(DWORD*, DWORD*);
		typedef void (__fastcall* SetOwner_o)(DWORD*, DWORD*, DWORD*);
		typedef VRCPlayerApiStruct::VRC_SDKBase_VRCPlayerApi_o* (__fastcall* GetOwner_o)(DWORD*, DWORD*);
		typedef DWORD* (__fastcall* Instantinate_o)(int32_t, DWORD*, Vector3, Quaternion, DWORD*);
		typedef void (__fastcall* RPC_o)(int32_t, DWORD*, DWORD*, DWORD*, DWORD*);

	public:
	
		int32_t GetServerTimeInMilliseconds()
		{
			return ((GetServerTimeInMillisecondsFunc)(Address::Networking::LocalVRCPlayer))(nullptr);
		}

		void Destroy(DWORD* Gameobject)
		{
			((Destroy_o)(Address::Networking::Destroy))(Gameobject, nullptr);
		}

		void SetOwner(VRCPlayerAPI player, Gameobject gameobject)
		{
			((SetOwner_o)(Address::Networking::SetOwner))(player.__this, gameobject.GameobjectPointer, nullptr);
		}

		VRCPlayerAPI GetOwner(Gameobject gameobject)
		{
			VRCPlayerApiStruct::VRC_SDKBase_VRCPlayerApi_o* ApiPlayer = ((GetOwner_o)(Address::Networking::GetOwner))(gameobject.GameobjectPointer, nullptr);
			VRCPlayerAPI vrcplayerapi = VRCPlayerAPI(ApiPlayer);

			return vrcplayerapi;
		}
};
