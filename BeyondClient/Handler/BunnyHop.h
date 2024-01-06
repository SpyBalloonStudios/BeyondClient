#pragma once

// BunnyHop Key Codes Typedef's ->
#pragma region BunnyHop_Key_Codes
#define KEY_Space 0x20

#pragma endregion 

namespace BunnyHop
{
	void Jump()
	{
		Vector3 CurrentVelocity = Players::LocalPlayer.GetVelocity();
		Vector3 Velocity(CurrentVelocity.x, CurrentVelocity.y += Players::LocalPlayer.GetJumpImpulse(), CurrentVelocity.z);
		Players::LocalPlayer.SetVelocity(Velocity);
	}

	void Update()
	{
		if (GetAsyncKeyState(KEY_Space) && Players::LocalPlayer.IsPlayerGrounded()) /// if the Space Key and The LocalPlayer is Grouded Jump
		{
			Jump();
		}
	}
}