#pragma once


namespace ItemUtils {
	VRC_Pickup SelectedPickup;
	std::vector<VRC_Pickup> Pickups;
	std::vector<VRC_Pickup> NotPickupable;
	std::vector<VRC_Pickup> NotStealable;

	void MakeMeOwner()
	{
		Networking n;
		for (VRC_Pickup Pickup : ItemUtils::Pickups)
		{
			VRCPlayerAPI PlayerApi = n.GetOwner(Gameobject(Pickup.component.__gameobject));

			if (PlayerApi.__this != Players::LocalPlayer.__VRCPlayerApi)
			{
				n.SetOwner(VRCPlayerAPI(Players::LocalPlayer.VRCPlayerApi_o), Gameobject(Pickup.component.__gameobject));
				//Sleep(50);
			}

			Sleep(5);
		}
	}

	
	void MoveAllPickups(Vector3 Position)
	{
		//std::thread(MakeMeOwner).detach();
		MakeMeOwner();
		for (VRC_Pickup Pickup : Pickups)
		{
			//if (Pickup.transform.GetPosition().isEqual(Position))
			//	continue;

			//Networking n;
			//n.SetOwner(VRCPlayerAPI(Players::LocalPlayer.__VRCPlayerApi, false), Gameobject(Pickup.component.__gameobject));
			Pickup.transform.SetPosition(Position);
		}
	}

	void ForceAllowSteal(bool state)
	{
		for (VRC_Pickup Pickup : Pickups)
		{
			Pickup.Pickup_o->fields.DisallowTheft = !state;
		}
	}

	void ForceAllowPickupable(bool state)
	{
		for (VRC_Pickup Pickup : Pickups)
		{
			Pickup.Pickup_o->fields.pickupable = state;
		}
	}
}