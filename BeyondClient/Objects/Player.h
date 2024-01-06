#pragma once
/*

{  Get vrcplayer  ->
	  "Address": 8253008,
	  "Name": "\u00CC\u00CC\u00CF\u00CD\u00CD\u00CD\u00CC\u00CE\u00CD\u00CD\u00CF\u00CE\u00CC\u00CF\u00CC\u00CE\u00CD\u00CF\u00CC\u00CC\u00CF\u00CC\u00CF$$\u00CC\u00CF\u00CD\u00CC\u00CE\u00CE\u00CD\u00CD\u00CD\u00CC\u00CC\u00CC\u00CF\u00CF\u00CC\u00CD\u00CE\u00CE\u00CE\u00CE\u00CE\u00CF\u00CC",
	  "Signature": "________________________70_o* ________________________________________________ (________________________75_o* __this, const MethodInfo* method);",
	  "TypeSignature": "iii"
	},
	{
*/

class Player
{
	private:
	typedef VRCPlayerApiStruct::VRC_SDKBase_VRCPlayerApi_o* (__fastcall* GetVRCPlayerApiFunc)(DWORD*, DWORD*);
	VRCPlayerApiStruct::VRC_SDKBase_VRCPlayerApi_o* GetVRCPlayerApi(DWORD* Player)
	{
		return ((GetVRCPlayerApiFunc)Address::VRCPlayerAPI::GetVRCPlayerApi)(Player, nullptr);
	}

	public:
		DWORD* __this; // Former PlayerPointer
		DWORD* __vrcplayer;
		VRCPlayerApiStruct::VRC_SDKBase_VRCPlayerApi_o* VRCPlayerApi_o;
		DWORD* __VRCPlayerApi;

		std::string DisplayName;
		bool IsPhotonBot;
		bool IsUserInVR;
		bool Self = false;
		int32_t PlayerID;
		std::chrono::time_point<std::chrono::high_resolution_clock> LastGroundedTime;
		std::chrono::time_point<std::chrono::high_resolution_clock> LastPositionChangeTime;
		Vector3 LastPosition;
		Quaternion LastRotation;

		DWORD* GetVRCPlayer()
		{
			return vrcplayer(__this).__this;
		}

		Transform GetTransform()
		{
			Transform PlayerTransform = Transform(Component(__this).__transform);
			return PlayerTransform;
		}

		std::string GetAvatarAssetUrl()
		{
			return APIAvatar(__this).UnityPackageUrl;
		}

		DWORD* GetVRCPlayerAPI()
		{
			return VRCPlayerAPI(VRCPlayerApi_o).__this;
		}

		int32_t GetPlayerID()
		{
			//PlayerID = VRCPlayerAPI(GetVRCPlayerAPI()).PhotonSenderID();
			PlayerID = 69;
			return PlayerID;
		}

		Vector3 GetPosition()
		{
			return vrcplayer(__this).GetPosition();
		}

		Quaternion GetRotation()
		{
			return vrcplayer(__this).GetRotation();
		}

		float GetEyeHeight()
		{
			return VRCPlayerAPI(VRCPlayerApi_o).GetAvatarEyeHeight();
		}

		void SetNamePlateColor(Color col)
		{
			VRCPlayerAPI(VRCPlayerApi_o).SetNamePlateColor(col);
		}

		Vector3 GetBonePosition(HumanBodyBones Bone)
		{
			return VRCPlayerAPI(VRCPlayerApi_o).GetBonePosition(Bone);
		}

		Transform GetBoneTransform(HumanBodyBones Bone)
		{
			return VRCPlayerAPI(VRCPlayerApi_o).GetBoneTransform(Bone);
		}

		APIUser GetApiUser()
		{
			return APIUser(__this);
		}
		APIAvatar GetApiAvatar()
		{
			return APIAvatar(__this);
		}

		bool IsPlayerGrounded()
		{
			return VRCPlayerAPI(VRCPlayerApi_o).IsPlayerGrounded();
		}

		void UpdateGroundedTime() {
			if (IsPlayerGrounded()) {
				LastGroundedTime = std::chrono::high_resolution_clock::now();
			}
		}

		float TimeSinceLastGrounded() {
			auto currentTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> elapsed = currentTime - LastGroundedTime;
			return elapsed.count();
		}

		void UpdateLastMovement() {
			if (GetPosition().distance(LastPosition) > 0.01 || GetRotation().distance(LastRotation) > 0.01) {
				LastPositionChangeTime = std::chrono::high_resolution_clock::now();
				LastPosition = GetPosition();
				LastRotation = GetRotation();
			}
		}

		float TimeSinceLastMovement() {
			auto currentTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> elapsed = currentTime - LastPositionChangeTime;
			return elapsed.count();
		}

		bool IsPlayerMoving()
		{
			if (TimeSinceLastMovement() < 1.0f)
				return true;
			else
				return false;
		}

		bool IsAFK()
		{
			if (TimeSinceLastMovement() > 60.0f)
				return true;
			else
				return false;
		}

		int minutesAFK()
		{
			return static_cast<int>(std::floor(TimeSinceLastMovement() / 60.0f));
		}

		void SetVelocity(Vector3 Velocity)
		{
			VRCPlayerAPI(VRCPlayerApi_o).SetVelocity(Velocity);
		}

		Vector3 GetVelocity()
		{
			return VRCPlayerAPI(VRCPlayerApi_o).GetVelocity();
		}

		float GetJumpImpulse()
		{
			return VRCPlayerAPI(VRCPlayerApi_o).GetJumpImpulse();
		}

		bool isValid()
		{
			if (__this != nullptr)
				return true;
			else
				return false;
		}

		bool isMaster()
		{
			return VRCPlayerAPI(VRCPlayerApi_o).isMaster();
		}

		bool isEqual(Player refplayer)
		{
			if (refplayer.__this == __this)
				return true;
			else
				return false;
		}

		Player(DWORD* p, bool safemode = false)
		{
			__this = p;

			if (p != nullptr)
			{
				APIUser ApiUser = GetApiUser();
				DisplayName = ApiUser.DisplayName;
				Self = ApiUser.IsSelf;
				__vrcplayer = GetVRCPlayer();
				VRCPlayerApi_o = GetVRCPlayerApi(__this);
				__VRCPlayerApi = reinterpret_cast<DWORD*>(VRCPlayerApi_o);

				//GetPlayerID();
				if (!safemode)
				{
					//LastGroundedTime = std::chrono::high_resolution_clock::now();
					//LastPositionChangeTime = std::chrono::high_resolution_clock::now();
					//LastPosition = GetPosition();
					//LastRotation = GetRotation();
					//IsUserInVR = VRCPlayerAPI(__this).IsUserInVR();

					/*
					if (!IsPlayerGrounded() && IsUserInVR)
					{
						IsPhotonBot = false;
					}
					else
					{
						IsPhotonBot = false;
					}
					*/
				}
				else
				{
					IsUserInVR = false;
					IsPhotonBot = false;
				}
			}
			else
			{
				DisplayName = "AfricasWater";
				IsUserInVR = false;
				IsPhotonBot = false;
			}
		}
};

namespace Players
{
	std::list<Player> Playerlist;
	std::mutex PlayerlistMutex;
	size_t PlayerlistSize = 0;

	void updatePlayerListSize()
	{
		// The Playerlist must get locked before calling this function
		PlayerlistSize = Playerlist.size();
	}

	void UpdateTimes()
	{
		PlayerlistMutex.lock();
		for (auto& player : Playerlist)
		{
			player.UpdateGroundedTime();
			player.UpdateLastMovement();
		}
		PlayerlistMutex.unlock();
	}

	Player SelectedPlayer = Player(nullptr);
	Player AttachedToPlayer = Player(nullptr);
	Player PossessedPlayer = Player(nullptr);
	Player OrbitingPlayer = Player(nullptr);
	Player BoneAttachPlayer = Player(nullptr);

	Player ItemAttachPlayer = Player(nullptr);
	Player ItemOrbitPlayer = Player(nullptr);

	int BoneAttachType = 1;
	Player LocalPlayer = Player(nullptr);
}