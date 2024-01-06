#pragma once

// Fly Key Codes Typedef's ->
#pragma region Fly_Key_Codes
#define KEY_SHIFT 0x10

#define KEY_W 0x57
#define KEY_A 0x41
#define KEY_S 0x53
#define KEY_D 0x44

#define KEY_E 0x45
#define KEY_Q 0x51
#pragma endregion 

namespace FlyHandler
{
	void Update()
	{
		Transform LocalPlayerObject = Players::LocalPlayer.GetTransform();
		float Speed = Config::Fly::Speed / 60.0f;

		if (Config::Fly::Mode == FI_VFly)
		{
			VRCPlayerAPI().SetVelocity(Vector3(0, 0.1f, 0));
		}

		if (GetAsyncKeyState(KEY_SHIFT)) Speed *= 2; /// if Keycode = Shift Increase Speed Temporarly

		if(Config::Fly::Directional)
		{ 
			///Do Something with Transform HeadTransform = GetBoneTransform(Head); and than HeadTransform.GetForward(); instead of LocalPlayerObject.GetForward();
		}

		Vector3 NextPosition = LocalPlayerObject.GetPosition();
		if (GetAsyncKeyState(KEY_W)) /// W
		{
			Vector3 Forward = LocalPlayerObject.GetForward();

			NextPosition.x += Forward.x * Speed;
			NextPosition.y += Forward.y * Speed;
			NextPosition.z += Forward.z * Speed;

			LocalPlayerObject.SetPosition(NextPosition);
		}

		if (GetAsyncKeyState(KEY_S)) /// S
		{
			Vector3 Backward = LocalPlayerObject.GetBackward();

			NextPosition.x += Backward.x * Speed;
			NextPosition.y += Backward.y * Speed;
			NextPosition.z += Backward.z * Speed;

			LocalPlayerObject.SetPosition(NextPosition);
		}

		if (GetAsyncKeyState(KEY_A)) /// A
		{
			Vector3 Left = LocalPlayerObject.GetLeft();

			NextPosition.x += Left.x * Speed;
			NextPosition.y += Left.y * Speed;
			NextPosition.z += Left.z * Speed;

			LocalPlayerObject.SetPosition(NextPosition);
		}

		if (GetAsyncKeyState(KEY_D)) /// D
		{
			Vector3 Right = LocalPlayerObject.GetRight();

			NextPosition.x += Right.x * Speed;
			NextPosition.y += Right.y * Speed;
			NextPosition.z += Right.z * Speed;

			LocalPlayerObject.SetPosition(NextPosition);
		}

		if (GetAsyncKeyState(KEY_E)) /// E
		{
			Vector3 Up = LocalPlayerObject.GetUp();

			NextPosition.x += Up.x * Speed / 2.0f;
			NextPosition.y += Up.y * Speed / 2.0f;
			NextPosition.z += Up.z * Speed / 2.0f;

			LocalPlayerObject.SetPosition(NextPosition);
		}

		if (GetAsyncKeyState(KEY_Q)) /// Q
		{
			Vector3 Down = LocalPlayerObject.GetDown();

			NextPosition.x += Down.x * Speed / 2.0f;
			NextPosition.y += Down.y * Speed / 2.0f;
			NextPosition.z += Down.z * Speed / 2.0f;

			LocalPlayerObject.SetPosition(NextPosition);
		}
	}
}