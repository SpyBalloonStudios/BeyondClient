#pragma once

#include "VRC_Pickup_Hook.h"
#include "RPC_Hook.h"
#include "Photon_Hook.h"
#include "NetworkManager_Hook.h"
#include "VRCPlayerApi_Hook.h"

namespace HookManager {
	void InitializeHooks()
	{
		VRC_Pickup_Hook::Init();
		RPC_Hook::Init();
		Photon_Hook::Init();
		NetworkManager_Hook::Init();
		VRCPlayerApi_Hook::Init();
	}
}