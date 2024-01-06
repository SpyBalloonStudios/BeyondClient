#pragma once


/*
[Token(Token = "0x6000027")]
		[Address(RVA = "0x105EF10", Offset = "0x105DB10", VA = "0x18105EF10")]
		public Vector3 GetBonePosition(HumanBodyBones tt)
		{
			return default(Vector3);
		}

		{
	  "Address": 17166096,
	  "Name": "VRC.SDKBase.VRCPlayerApi$$GetBonePosition",
	  "Signature": "UnityEngine_Vector3_o VRC_SDKBase_VRCPlayerApi__GetBonePosition (VRC_SDKBase_VRCPlayerApi_o* __this, int32_t tt, const MethodInfo* method);",
	  "TypeSignature": "iiii"
	},
	{
	  "Address": 95498384,
	  "Name": "VRC.SDKBase.VRCPlayerApi$$get_playerId",
	  "Signature": "int32_t VRC_SDKBase_VRCPlayerApi__get_playerId (VRC_SDKBase_VRCPlayerApi_o* __this, const MethodInfo* method);",
	  "TypeSignature": "iii"
	},


	{
	  "Address": 95436080,
	  "Name": "VRC.SDKBase.VRCPlayerApi$$GetJumpImpulse",
	  "Signature": "float VRC_SDKBase_VRCPlayerApi__GetJumpImpulse (VRC_SDKBase_VRCPlayerApi_o* __this, const MethodInfo* method);",
	  "TypeSignature": "fii"
	},

	 {
	  "Address": 95443264,
	  "Name": "VRC.SDKBase.VRCPlayerApi$$SetVelocity",
	  "Signature": "void VRC_SDKBase_VRCPlayerApi__SetVelocity (VRC_SDKBase_VRCPlayerApi_o* __this, UnityEngine_Vector3_o velocity, const MethodInfo* method);",
	  "TypeSignature": "viii"
	},

	{
	  "Address": 95437984,
	  "Name": "VRC.SDKBase.VRCPlayerApi$$GetVelocity",
	  "Signature": "UnityEngine_Vector3_o VRC_SDKBase_VRCPlayerApi__GetVelocity (VRC_SDKBase_VRCPlayerApi_o* __this, const MethodInfo* method);",
	  "TypeSignature": "iii"
	},
*/



namespace Networking_ {
	typedef VRCPlayerApiStruct::VRC_SDKBase_VRCPlayerApi_o* (__fastcall* GetLocalPlayerFunc)(DWORD*);
	VRCPlayerApiStruct::VRC_SDKBase_VRCPlayerApi_o* GetLocalPlayer()
	{
		return ((GetLocalPlayerFunc)(Address::Networking::LocalVRCPlayer))(nullptr);
	}

}
class VRCPlayerAPI
{
	private:
		typedef DWORD* (__fastcall* GetVRCPlayerApiFunc)(DWORD*, DWORD*);
		DWORD* GetVRCPlayerApi(DWORD* Player)
		{
			return ((GetVRCPlayerApiFunc)Address::VRCPlayerAPI::GetVRCPlayerApi)(Player, nullptr);
		}

	public:
		DWORD* __this; // Former VRCPlayerApiPointer
		VRCPlayerApiStruct::VRC_SDKBase_VRCPlayerApi_o* VRCPlayerApi_o;

		typedef void(__fastcall* SetVelocity_o)(DWORD*, Vector3,  DWORD*);
		void SetVelocity(Vector3 Velocity)
		{
			return ((SetVelocity_o)Address::VRCPlayerAPI::SetVelocity)(__this, Velocity, nullptr);
		}

		typedef Vector3(__fastcall* GetVelocity_o)(DWORD*, DWORD*);
		Vector3 GetVelocity()
		{
			return ((GetVelocity_o)Address::VRCPlayerAPI::GetVelocity)(__this, nullptr);
		}

		typedef float(__fastcall* GetJumpImpulse_o)(DWORD*, DWORD*);
		float GetJumpImpulse()
		{
			return ((GetJumpImpulse_o)Address::VRCPlayerAPI::GetJumpImpulse)(__this, nullptr);
		}

		typedef float(__fastcall* GetAvatarEyeHeight_o)(DWORD*, DWORD*);
		float GetAvatarEyeHeight()
		{
			return ((GetAvatarEyeHeight_o)Address::VRCPlayerAPI::GetAvatarEyeHeight)(__this, nullptr);
		}

		typedef Vector3(__fastcall* GetBonePositionFunc)(DWORD*, HumanBodyBones, DWORD*);
		Vector3 GetBonePosition(HumanBodyBones Bone)
		{
			return ((GetBonePositionFunc)Address::VRCPlayerAPI::GetBonePosition)(__this, Bone, nullptr);
		}

		typedef int32_t(__fastcall* GetSenderID)(DWORD*, DWORD*); //Aka PlayerID
		int32_t PhotonSenderID()
		{
			return ((GetSenderID)Address::VRCPlayerAPI::GetPlayerID)(__this, nullptr);
		}

		typedef void(__fastcall* SetNamePlateColorFunc)(DWORD*, Color, DWORD*);
		void SetNamePlateColor(Color col)
		{
			((SetNamePlateColorFunc)Address::VRCPlayerAPI::SetNamePlateColor)(__this, col, nullptr);
		}

		typedef void(__fastcall* SetSpeedFunc)(DWORD*, float, DWORD*);
		void SetWalkSpeed(bool log = true)
		{
			((SetSpeedFunc)Address::VRCPlayerAPI::SetWalkSpeed)(__this, (Config::VRCPlayerAPI::Speed::Current::Walk), nullptr);
			if (log)
			{
				Logger::AddLogEntry("Walk Speed Set to " + std::to_string(Config::VRCPlayerAPI::Speed::Current::Walk), LogRaiser::Local);
				ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("Walk Speed Set to " + std::to_string(Config::VRCPlayerAPI::Speed::Current::Walk)).c_str(), ""});
				printf("Walk Speed Set to %f\n", Config::VRCPlayerAPI::Speed::Current::Walk);
			}
		}
		void SetRunSpeed(bool log = true)
		{
			((SetSpeedFunc)Address::VRCPlayerAPI::SetRunSpeed)(__this, (Config::VRCPlayerAPI::Speed::Current::Run), nullptr);
			if (log)
			{
				printf("Run Speed Set to %f\n", Config::VRCPlayerAPI::Speed::Current::Run);
				ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("Run Speed Set to " + std::to_string(Config::VRCPlayerAPI::Speed::Current::Run)).c_str(), ""});
				Logger::AddLogEntry("Run Speed Set to " + std::to_string(Config::VRCPlayerAPI::Speed::Current::Run), LogRaiser::Local);
			}
		}

		typedef float(__fastcall* GetSpeedFunc)(DWORD*, DWORD*);
		float GetWalkSpeed()
		{
			return ((GetSpeedFunc)Address::VRCPlayerAPI::GetWalkSpeed)(__this, nullptr);
		}
		float GetRunSpeed()
		{
			return ((GetSpeedFunc)Address::VRCPlayerAPI::GetRunSpeed)(__this, nullptr);
		}
		void InitializeOriginalSpeed()
		{
			Logger::AddLogEntry("Original Speed Initialized", LogRaiser::Behavior);
			Config::VRCPlayerAPI::Speed::Original::Walk = GetWalkSpeed();
			Config::VRCPlayerAPI::Speed::Original::Run = GetRunSpeed();
			Config::VRCPlayerAPI::Speed::Current::Walk = Config::VRCPlayerAPI::Speed::Original::Walk;
			Config::VRCPlayerAPI::Speed::Current::Run = Config::VRCPlayerAPI::Speed::Original::Run;

			Config::Unity::Gravity = Vector3().Nan.y;
			if (Config::Fly::Enabled)
				unity.SetGravity(false);
		}

		typedef void(__fastcall* EnablePickupsFunc)(DWORD*, bool, DWORD*);
		void EnablePickups(bool state, bool log = true)
		{
			(((EnablePickupsFunc)Address::VRCPlayerAPI::EnablePickups), state, nullptr);

			if (log)
			{
				if (!state)
				{
					Logger::AddLogEntry("Hiding Pickups", LogRaiser::Local);
					printf("Hiding Pickups\n");
					notificationManager.ShowNotification("Hiding Pickups", 2.f);
				}
				else
				{
					Logger::AddLogEntry("Showing Pickups", LogRaiser::Local);
					printf("Showing Pickups\n");
					notificationManager.ShowNotification("Showing Pickups", 2.f);
				}
			}
		}

		typedef bool(__fastcall* ReturnBool)(DWORD*, DWORD*);
		bool IsUserInVR()
		{
			return ((ReturnBool)Address::VRCPlayerAPI::IsUserInVR)(__this, nullptr);
		}
		bool IsPlayerGrounded()
		{
			return ((ReturnBool)Address::VRCPlayerAPI::IsPlayerGrounded)(__this, nullptr);
		}
		bool IsValid()
		{
			return ((ReturnBool)Address::VRCPlayerAPI::IsValid)(__this, nullptr);
		}
		bool isMaster()
		{
			return ((ReturnBool)Address::VRCPlayerAPI::isMaster)(__this, nullptr);
		}

		typedef DWORD*(__fastcall* GetBoneTransformFunc)(DWORD*, HumanBodyBones, DWORD*);
		Transform GetBoneTransform(HumanBodyBones Bone)
		{
			DWORD* TransformP = ((GetBoneTransformFunc)Address::VRCPlayerAPI::GetBoneTransform)(__this, Bone, nullptr);
			Transform BoneTransform(TransformP);
			return BoneTransform;
		}

		VRCPlayerAPI()
		{
			VRCPlayerApiStruct::VRC_SDKBase_VRCPlayerApi_o* VRCPlayerApi;
			VRCPlayerApi = Networking_::GetLocalPlayer();

			DWORD* VRCPlayerApi__ = reinterpret_cast<DWORD*>(VRCPlayerApi);
			__this = VRCPlayerApi__;

			VRCPlayerApi_o = VRCPlayerApi;
		}

		VRCPlayerAPI(VRCPlayerApiStruct::VRC_SDKBase_VRCPlayerApi_o* VRCPlayerApi)
		{
			if (VRCPlayerApi != nullptr)
			{
				DWORD* VRCPlayerApi__ = reinterpret_cast<DWORD*>(VRCPlayerApi);
				__this = VRCPlayerApi__;

				VRCPlayerApi_o = VRCPlayerApi;
			}
		}
};