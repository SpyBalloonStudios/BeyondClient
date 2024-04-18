#include <chrono>
#include <thread>
#include <cmath>

float a = 2.0f;
float b = 2.0f;
float alpha = 1.0f;

#pragma region Item_Stuff
float itemalpha = 1.0f;
float Alp = 1.0f;

float maxRotation = 365.0f;

void ItemOrbitHandler()
{
	while (true)
	{
		if (Players::LocalPlayer.isValid())
		{
			if (Players::ItemOrbitPlayer.isValid())
			{
				itemalpha += 0.05f;
				itemalpha = fmod(itemalpha, maxRotation);

				Transform RemotePlayerObject = Transform(Component(Players::ItemOrbitPlayer.__this).__transform);
				Vector3 PlayerPosition = RemotePlayerObject.GetPosition();

				float Steps = maxRotation / ItemUtils::Pickups.size();
				Networking n;
				int Owned = 0;
				for (VRC_Pickup Pickup : ItemUtils::Pickups)
				{
					VRCPlayerAPI PlayerApi = n.GetOwner(Gameobject(Pickup.component.__gameobject));

					if (PlayerApi.__this == Players::LocalPlayer.__VRCPlayerApi)
					{
						Owned++;
						   
						if (Alp > maxRotation || itemalpha + Alp > maxRotation)
							Alp -= maxRotation;

						Alp = fmod(Alp, maxRotation);

						float CalculatedX = PlayerPosition.x + a * cos(itemalpha + Alp);
						float CalculatedY = PlayerPosition.y + 1;
						float CalculatedZ = PlayerPosition.z + b * sin(itemalpha + Alp);

						Vector3 CalculatedPosition(CalculatedX, CalculatedY, CalculatedZ);

						Pickup.transform.SetPosition(CalculatedPosition);
						Alp += Steps;
					}
				}

				float ownershipThreshold = 0.99f;
				bool isOverThreshold = (static_cast<float>(Owned) / ItemUtils::Pickups.size()) >= ownershipThreshold;

				if (isOverThreshold)
				{
					ItemUtils::MakeMeOwner();
					//std::thread(ItemUtils::MakeMeOwner).detach();
				}
			}

			if (Players::ItemAttachPlayer.isValid())
				ItemUtils::MoveAllPickups(Players::ItemAttachPlayer.GetPosition());
		}

		Sleep(50);
	}
}

void ItemESPHandler()
{
	while (true)
	{
		if (Players::LocalPlayer.isValid())
		{
			if (Config::Render::ESP::ItemEsp)
			{
				for (VRC_Pickup pickup : ItemUtils::Pickups)
				{
					InputManager::EnableObjectHighlight_Gamebject(pickup.component.__gameobject, true);
				}
			}
		}
		Sleep(250);
	}
}

void ItemHandler()
{
	while (true)
	{
		if (Players::LocalPlayer.isValid())
		{
			if (Config::Pickups::ForceAllowPickupable)
				ItemUtils::ForceAllowPickupable(true);

			if (Config::Pickups::ForceAllowTheft)
				ItemUtils::ForceAllowSteal(true);

			if (Config::Pickups::Freeze)
			{
				ItemUtils::MakeMeOwner();
			}
		}

		Sleep(1);
	}
}

#pragma endregion

void PlayerThread()
{

	if (Players::LocalPlayer.isValid())
	{
		/*
		vrcplayer LocalPlayer(Players::LocalPlayer.__this);
		Transform LocalPTransform(LocalPlayer.GetParent());
		Transform LocalPlayerObject(LocalPTransform);

		if (Config::Photon::Block::Movement)
		{
			// Calculate the distance between the last position and the current position
			Render::DrawTextWorldSpace(Config::Photon::Block::LastPosition, "Last Position\n" + std::to_string(LocalPlayerObject.GetPosition().distance(Config::Photon::Block::LastPosition)) + "m");
		}

		if (Players::AttachedToPlayer.isValid())
		{
			Vector3 PlayerPosition = Transform(vrcplayer(Players::AttachedToPlayer.__this).GetParent()).GetPosition();

			if (!PlayerPosition.isEqual(LocalPlayerObject.GetPosition()))
				LocalPlayerObject.SetPosition(PlayerPosition);
		}
		else if (Players::BoneAttachPlayer.isValid())
		{
			HumanBodyBones Bone;
			switch (Players::BoneAttachType)
			{
			case 0:
				Bone = Head;
				break;
			case 1:
				Bone = LeftHand;
				break;
			case 2:
				Bone = LeftFoot;
				break;
			case 3:
				Bone = RightHand;
				break;
			case 4:
				Bone = RightFoot;
				break;
			default:
				Bone = Head;
				break;
			}

			Vector3 BonePosition = Players::BoneAttachPlayer.GetBonePosition(Bone);
			if (Players::BoneAttachType == 5)
			{
			}
			else
			{
				if (!BonePosition.isEqual(LocalPlayerObject.GetPosition()))
					LocalPlayerObject.SetPosition(BonePosition);
			}
		}
		else if (Players::PossessedPlayer.isValid())
		{
			Vector3 HeadPosition = Players::PossessedPlayer.GetBonePosition(Head);

			LocalPlayerObject.SetPosition(HeadPosition);
		}

		*/
		if (Config::Fly::Enabled)
			FlyHandler::Update();

		if (Config::BunnyHop::Enabled)
			BunnyHop::Update();
		
	}
}

void HandlePlayers()
{
	if (Config::Render::DirectLines::Enabled || Config::Render::NamePlate::Enabled || Config::Render::ESP::Enabled || Config::Render::Position::Enabled)
	{
		Players::PlayerlistMutex.lock();
		for (Player Player : Players::Playerlist)
		{
			if (!Player.isValid())
				continue;

			if (Config::Render::DirectLines::Enabled)
			{
				Render::RenderLineESP(Player);
			}
			if (Config::Render::NamePlate::Enabled)
			{
				Render::RenderPlayerNamePlate(Player);

				/*
				if (Player.isEqual(Players::SelectedPlayer))
				{
					Render::RenderNamePlate(Player, "Selected");
				}
				else {
					Render::RenderNamePlate(Player);
				}
				*/
			}
			if (Config::Render::ESP::Enabled)
			{
				Render::RenderPlayerESP(Player);
			}
			if (Config::Render::Position::Enabled)
			{
				Render::RemderPosition(Player);
			}
		}
		Players::PlayerlistMutex.unlock();
	}
}

void Playerlist()
{
	#pragma region ImGui_Playerlist
	ImGui::Begin("Playerlist", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
	{
		ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), "Players In Instance");

		ImGui::SameLine();
		ImGui::Text("[");
		ImGui::SameLine(0.0f, 0.0f);
		ImGui::TextColored(ImVec4(0.5f, 0.7f, 1.0f, 1.0f), std::to_string(Players::PlayerlistSize).c_str());
		ImGui::SameLine(0.0f, 0.0f);
		ImGui::Text("]");

		Players::PlayerlistMutex.lock();
		for (Player Player : Players::Playerlist)
		{
			if (!Player.isValid())
			{
				continue;
			}

			Render::Render(Player);

			if (Player.IsPlayerGrounded())
			{
				ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), Player.DisplayName.c_str());
			} else {
				ImGui::TextColored(ImVec4(241.0f / 255.0f, (110.0f - Player.TimeSinceLastGrounded() * 10) / 255.0f, (237.0f - Player.TimeSinceLastGrounded()) / 255.0f, 1.0f), Player.DisplayName.c_str());
			}

			ImGui::SameLine();
			ImGui::Text("[");
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), std::to_string(Player.PlayerID).c_str());
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::Text("]");

			if (Player.IsPhotonBot)
			{
				ImGui::SameLine();
				ImGui::Text("[");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Bot");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::Text("]");
			}

			ImGui::SameLine();
			ImGui::Text("[");
			ImGui::SameLine(0.0f, 0.0f);
			switch (Player.IsUserInVR)
			{
				case true:
					ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "VR");
					break;
				case false:
					ImGui::TextColored(ImVec4(0.0f, 0.0f, 1.0f, 1.0f), "PC");
					break;
			}
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::Text("]");

			if (Player.GetApiUser().IsSelf)
			{
				if (Config::Menu::OwnUsername.empty())
				{
					Config::Menu::OwnUsername = Player.DisplayName.c_str();
				}

				Players::LocalPlayer = Player;

				ImGui::SameLine();
				ImGui::Text("[");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::TextColored(ImVec4(0.5f, 0.7f, 1.0f, 1.0f), "Self");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::Text("]");
			}
			else if (Player.GetApiUser().IsFriend())
			{
				ImGui::SameLine();
				ImGui::Text("[");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::TextColored(ImVec4(255.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f, 1.0f), "F");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::Text("]");
			}

			if (Player.IsPlayerMoving())
			{
				ImGui::SameLine();
				ImGui::Text("[");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::TextColored(ImVec4(255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f), "M");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::Text("]");
			} 
			if (Player.IsAFK())
			{
				ImGui::SameLine();
				ImGui::Text("[");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::TextColored(ImVec4(255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f), ("AFK for " + std::to_string(Player.minutesAFK()) + "m").c_str());
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::Text("]");
			}


			if (Players::SelectedPlayer.isEqual(Player))
			{
				ImGui::SameLine();
				ImGui::Text(" [");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::TextColored(ImVec4(0.5f, 0.7f, 1.0f, 1.0f), "Selected");
				ImGui::SameLine(0.0f, 0.0f);
				ImGui::Text("]");
			}

		}
		//PlayerThread();
		Players::PlayerlistMutex.unlock();
	};
	ImGui::End();
#pragma endregion
}

void SpoofPosition()
{
	#pragma region Position_Spoofer

	if (Players::LocalPlayer.__this != nullptr)
	{
		Vector3 Position_o = Vector3(0, 0, 0);
		vrcplayer LocalPlayer(Players::LocalPlayer.__this);
		Transform LocalPlayerObject = Transform(LocalPlayer.transformpointer).GetRoot();

		Position_o = LocalPlayerObject.GetPosition();
		LocalPlayerObject.SetPosition(Vector3(0, 1000000, 0));

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		Config::Photon::Invisible::SpoofCoords = true;
		LocalPlayerObject.SetPosition(Position_o);
	}
#pragma endregion
}

#pragma region Menu_Tab_Variables

#define TI_Home 0
#define TI_Movement 1
#define TI_Misc 2
#define TI_Instance 3
#define TI_Safety 4
#define TI_Visuals 5

#pragma endregion

void HomeTab()
{
	#pragma region Menu_Tab_Home

	ImGui::Text("Welcome to");
	ImGui::SameLine();
	ImGui::TextColored(ImVec4(150 / 255.0f, 112 / 255.0f, 154 / 255.0f, 255 / 255.0f), "Elements Base-Mod based of Beyond Client");

	ImGui::Text("Made by");
	ImGui::SameLine();
	ImGui::TextColored(ImVec4(150 / 255.0f, 112 / 255.0f, 154 / 255.0f, 255 / 255.0f), "dll.gg, NONE, Louis45");

	ImGui::Text("Developing Firm");
	ImGui::SameLine();
	ImGui::TextColored(ImVec4(150 / 255.0f, 112 / 255.0f, 154 / 255.0f, 255 / 255.0f), "Elementscheats");

#pragma endregion
}

void MovementTab()
{
	#pragma region Menu_Tab_Movement

	if (ImGui::Selectable("Fly", &Config::Fly::Enabled))
	{
		if (Config::Fly::Enabled)
		{
			Config::Unity::NoGravity = false;
			Config::Unity::MoonGravity = false;

			if (Config::Fly::Mode == FI_GFly)
			{
				Unity().SetGravity(Vector3().Nan);
			}
		}
		else
		{
			if (Config::Fly::Mode == FI_GFly)
			{
				Unity().SetGravity(Vector3().normal);
			}
		}
	}
	ImGui::SameLine();
	if (Config::Fly::Enabled)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	if (Config::Menu::ShowHotkeys)
	{
		static bool checkforkeyspressed = false;

		if (checkforkeyspressed)
		{
			ImGui::Text(Dot.c_str());
		}
		else if (Config::Menu::Hotkeys::FlyHotkey == -1) {
			ImGui::Text("[None]");
		}
		else {
			ImGui::Text(("[" + GetKeyName(Config::Menu::Hotkeys::FlyHotkey) + "]").c_str());
		}

		if (ImGui::IsItemClicked())
		{
			checkforkeyspressed = true;
		}

		if (checkforkeyspressed)
		{
			for (int i = 3; i < 256; i++) {
				if (GetAsyncKeyState(i) & 0x8001) {
					if (!(GetAsyncKeyState(i) & 0x0001)) {
						checkforkeyspressed = false;
						Config::Menu::Hotkeys::FlyHotkey = i;
						break;
					}
				}
			}
		}

		if (Config::Menu::Hotkeys::FlyHotkey != -1) {
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1, 0, 0, 1), "(x)");
			if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(0))
			{
				Config::Menu::Hotkeys::FlyHotkey = -1;
			}
		}
	}

	static const char* items[] = { "G Fly", "V Fly" };
	ImGui::Combo("Mode", &Config::Fly::Mode, items, IM_ARRAYSIZE(items));

	ImGui::SameLine();
	ImGui::TextColored(ImColor(220, 190, 0, 255), "(?)");
	if (ImGui::IsItemHovered())
		ImGui::SetTooltip("G Fly (Gravity Based) is a Gerneral Fly, V Fly (Velocity Based) is a Fly Optimised for Worlds like Black Cat, Great Pub");

	ImGui::Selectable("Bunnyhop", &Config::BunnyHop::Enabled);
	ImGui::SameLine();
	if (Config::BunnyHop::Enabled)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	if (Config::Menu::ShowHotkeys)
	{
		static bool checkforkeyspressed = false;

		if (checkforkeyspressed)
		{
			ImGui::Text(Dot.c_str());
		}
		else if (Config::Menu::Hotkeys::BunnyHopHotkey == -1) {
			ImGui::Text("[None]");
		}
		else {
			ImGui::Text(("[" + GetKeyName(Config::Menu::Hotkeys::BunnyHopHotkey) + "]").c_str());
		}

		if (ImGui::IsItemClicked())
		{
			checkforkeyspressed = true;
		}

		if (checkforkeyspressed)
		{
			for (int i = 3; i < 256; i++) {
				if (GetAsyncKeyState(i) & 0x8001) {
					if (!(GetAsyncKeyState(i) & 0x0001)) {
						checkforkeyspressed = false;
						Config::Menu::Hotkeys::BunnyHopHotkey = i;
						break;
					}
				}
			}
		}


		if (Config::Menu::Hotkeys::BunnyHopHotkey != -1) {
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1, 0, 0, 1), "(x)");
			if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(0))
			{
				Config::Menu::Hotkeys::BunnyHopHotkey = -1;
			}
		}
	}

	if (ImGui::Selectable("No Gravity", &Config::Unity::NoGravity))
	{
		if (Config::Unity::NoGravity)
		{
			Config::Unity::MoonGravity = false;
			Unity().SetGravity(Vector3().NoGravity);
		}
		else
		{
			Unity().SetGravity(Vector3().normal);
		}
	}
	ImGui::SameLine();
	if (Config::Unity::NoGravity)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");


	if (ImGui::Selectable("Moon Gravity", &Config::Unity::MoonGravity))
	{
		if (Config::Unity::MoonGravity)
		{
			Config::Unity::NoGravity = false;
			Unity().SetGravity(Vector3().MoonGravity, false);
		}
		else
		{
			Unity().SetGravity(Vector3().normal, false);
		}
	}
	ImGui::SameLine();
	if (Config::Unity::MoonGravity)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	//ImGui::BeginChild("", ImVec2(0.0f, 0.0f));
	//ImGui::EndChild();


	ImGui::CustomSliderInt("Fly Speed +/-", &Config::Fly::Speed, 1, 50, 100); ImGui::SameLine(0.0f, 20.0f);
	ImGui::PushID(321);
	if (ImGui::Button("Reset"))
	{
		Config::Fly::Speed = 10;
	}
	ImGui::PopID();
	ImGui::CustomSliderFloat("Gravity +/-", &Config::Unity::Gravity, -9.81, 9.81, 100); ImGui::SameLine(0.0f, 35.0f);
	if (ImGui::IsItemEdited())
	{
		Unity().SetGravity(Vector3(0, Config::Unity::Gravity, 0), false);
	}
	ImGui::PushID(123);
	if (ImGui::Button("Reset"))
	{
		Config::Unity::Gravity = -9.81;
		Unity().SetGravity(Vector3(0, Config::Unity::Gravity, 0), false);
	}
	ImGui::PopID();

	ImGui::CustomSliderInt("Speed +/-", &Config::Unity::Speed, 1, 20, 100); ImGui::SameLine(0.0f, 47.0f);
	if (ImGui::IsItemEdited())
	{
		Config::VRCPlayerAPI::Speed::Current::Walk = Config::Unity::Speed * 2;
		Config::VRCPlayerAPI::Speed::Current::Run = Config::Unity::Speed * 4;
		VRCPlayerAPI().SetWalkSpeed(false);
		VRCPlayerAPI().SetRunSpeed(false);
	}
	ImGui::PushID(222);
	if (ImGui::Button("Reset"))
	{
		Config::Unity::Speed = 1;
		Config::VRCPlayerAPI::Speed::Current::Walk = Config::Unity::Speed * 2;
		Config::VRCPlayerAPI::Speed::Current::Run = Config::Unity::Speed * 4;
		VRCPlayerAPI().SetWalkSpeed(false);
		VRCPlayerAPI().SetRunSpeed(false);
	}
	ImGui::PopID();

#pragma endregion
}

void MiscTab()
{
	#pragma region Menu_Tab_Misc
	ImVec2 ChildSize = ImVec2((ImGui::GetContentRegionAvail().x / 2) - 5, (ImGui::GetContentRegionAvail().y / 2) - 10);

	ImGui::BeginChild("##PhotonExploits", ChildSize);
	ImGui::Button("Photon Exploits");

	ImGui::Selectable("Infinite Portal", &Config::Photon::Repeat::Portal);
	ImGui::SameLine();
	if (Config::Photon::Repeat::Portal)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::Selectable("Spam Emoji", &Config::Photon::Repeat::Emoji);
	ImGui::SameLine();
	if (Config::Photon::Repeat::Emoji)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	if (ImGui::Selectable("Anti Attach (Infinite Pos)", &Config::Photon::Invisible::Enabled))
	{
		if (Config::Photon::Invisible::Enabled)
		{
			Config::Photon::Block::Movement = false;
			std::thread(SpoofPosition).detach();
		}
		else
		{
			Config::Photon::Invisible::SpoofCoords = false;
		}
	}
	ImGui::SameLine();
	if (Config::Photon::Invisible::Enabled)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	if (ImGui::Selectable("Serilized Movement", &Config::Photon::Block::Movement))
	{
		if (Config::Photon::Block::Movement)
		{
			if (Players::LocalPlayer.isValid())
			{
				vrcplayer LocalPlayer(Players::LocalPlayer.__this);
				Transform LocalPTransform(LocalPlayer.GetParent());
				Transform LocalPlayerObject(LocalPTransform);

				Config::Photon::Block::LastPosition = LocalPlayerObject.GetPosition();
			}
		}
	}
	ImGui::SameLine();
	if (Config::Photon::Block::Movement)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	if (Config::Menu::ShowHotkeys)
	{

		static bool checkforkeyspressed = false;

		if (checkforkeyspressed)
		{
			ImGui::Text(Dot.c_str());
		}
		else if (Config::Menu::Hotkeys::SerilisedMovementHotkey == -1) {
			ImGui::Text("[None]");
		}
		else {
			ImGui::Text(("[" + GetKeyName(Config::Menu::Hotkeys::SerilisedMovementHotkey) + "]").c_str());
		}

		if (ImGui::IsItemClicked())
		{
			checkforkeyspressed = true;
		}

		if (checkforkeyspressed)
		{
			for (int i = 3; i < 256; i++) {
				if (GetAsyncKeyState(i) & 0x8001) {
					if (!(GetAsyncKeyState(i) & 0x0001)) {
						checkforkeyspressed = false;
						Config::Menu::Hotkeys::SerilisedMovementHotkey = i;
						break;
					}
				}
			}
		}


		if (Config::Menu::Hotkeys::SerilisedMovementHotkey != -1) {
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1, 0, 0, 1), "(x)");
			if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(0))
			{
				Config::Menu::Hotkeys::SerilisedMovementHotkey = -1;
			}
		}
	}

	ImGui::EndChild();

	ImGui::SameLine();

	ImGui::BeginChild("##PhotonUtils", ChildSize);
	ImGui::Button("Photon Utils");

	ImGui::Selectable("Log Incomming Events", &Config::Photon::Log::OnEvent);
	ImGui::SameLine();
	if (Config::Photon::Log::OnEvent)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::Selectable("Log Outgoing Events", &Config::Photon::Log::OpRaiseEvent);
	ImGui::SameLine();
	if (Config::Photon::Log::OpRaiseEvent)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::EndChild();

	ImGui::BeginChild("##UdonExploits", ChildSize);
	ImGui::Button("Udon Exploits");

	if (ImGui::Selectable("Force Allow Pickup Theft", &Config::Pickups::ForceAllowTheft))
	{
		if (!Config::Pickups::ForceAllowTheft)
		{
			ItemUtils::ForceAllowSteal(false);
		}
	}
	ImGui::SameLine();
	if (Config::Pickups::ForceAllowTheft)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	if (ImGui::Selectable("Force Allow Pickupable", &Config::Pickups::ForceAllowPickupable))
	{
		if (!Config::Pickups::ForceAllowPickupable)
		{
			ItemUtils::ForceAllowPickupable(false);
		}
	}
	ImGui::SameLine();
	if (Config::Pickups::ForceAllowPickupable)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");


	if (ImGui::Selectable("Infinite Pickup Reach", &Config::Pickups::InfiniteReach))
	{
		if (Config::Pickups::InfiniteReach)
		{
			for (VRC_Pickup pickup : ItemUtils::Pickups)
			{
				pickup.Pickup_o->fields.proximity = 9999999.f;
			}
		}
		else
		{
			for (VRC_Pickup pickup : ItemUtils::Pickups)
			{
				pickup.Pickup_o->fields.proximity = 5.f;
			}
		}
	}
	ImGui::SameLine();
	if (Config::Pickups::InfiniteReach)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::Selectable("Freeze Pickups", &Config::Pickups::Freeze);
	ImGui::SameLine();
	if (Config::Pickups::Freeze)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::EndChild();

	ImGui::SameLine();


	ImGui::BeginChild("##UdonUtils", ChildSize);
	ImGui::Button("Udon Utils");

	ImGui::Selectable("Log RPC's", &Config::RPC::LogRpcs);
	ImGui::SameLine();
	if (Config::RPC::LogRpcs)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");


	ImGui::EndChild();

	/*
	ImGui::Selectable("Spam Reload", &Config::RPCSpam::SpamReload);
	ImGui::SameLine();
	if (Config::RPCSpam::SpamReload)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::Selectable("Spam Emote", &Config::RPCSpam::SpamEmote);
	ImGui::SameLine();
	if (Config::RPCSpam::SpamEmote)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	*/

	

	
	//float EventsPerPlayer = static_cast<float>(Config::Photon::EventLimiter::LastIntervalTotalEvents / Players::PlayerlistSize);
	//ImGui::CustomSliderFloat("LastIntervalTotalEvent", &EventsPerPlayer, 2, 20, 100); ImGui::SameLine(0.0f, 20.0f);
#pragma endregion
}

void InstanceTab()
{
	#pragma region Menu_Tab_Instance

	static const char* items[] = { "Players", "Pickups"};
	ImGui::Combo("##", &Config::Menu::InstanceTab, items, IM_ARRAYSIZE(items));

	ImGui::SameLine();

	if (ImGui::Button("Give Pickups"))
	{
		if (Players::LocalPlayer.isValid())
			ItemUtils::MoveAllPickups(Players::LocalPlayer.GetPosition());
	}

	if (Config::Menu::ShowHotkeys)
	{
		static bool checkforkeyspressed = false;

		if (checkforkeyspressed)
		{
			ImGui::Text(Dot.c_str());
		}
		else if (Config::Menu::Hotkeys::GivePickupsHotkey == -1) {
			ImGui::Text("[None]");
		}
		else {
			ImGui::Text(("[" + GetKeyName(Config::Menu::Hotkeys::GivePickupsHotkey) + "]").c_str());
		}

		if (ImGui::IsItemClicked())
		{
			checkforkeyspressed = true;
		}

		if (checkforkeyspressed)
		{
			for (int i = 3; i < 256; i++) {
				if (GetAsyncKeyState(i) & 0x8001) {
					if (!(GetAsyncKeyState(i) & 0x0001)) {
						checkforkeyspressed = false;
						Config::Menu::Hotkeys::GivePickupsHotkey = i;
						break;
					}
				}
			}
		}


		if (Config::Menu::Hotkeys::GivePickupsHotkey != -1) {
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1, 0, 0, 1), "(x)");
			if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(0))
			{
				Config::Menu::Hotkeys::GivePickupsHotkey = -1;
			}
		}
	}

	if (Config::Menu::InstanceTab == 0)
	{
		ImGui::BeginChild("players", ImVec2(250, ImGui::GetContentRegionAvail().y), false);
		{
			if (Players::PlayerlistSize == 0)
			{
				ImGui::Text("Rejoin for the player list to work");
			}
			else
			{
				ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), (std::to_string(Players::PlayerlistSize) + " players").c_str());
			}
			Players::PlayerlistMutex.lock();
			for (Player Player : Players::Playerlist)
			{
				ImGui::PushID(Player.DisplayName.c_str());

				if (Players::SelectedPlayer.isEqual(Player))
				{
					ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(100.0f / 255.0f, 110.0f / 255.0f, 160.0f / 255.0f, 1.0f));
				}
				else if (Player.GetApiUser().IsSelf)
				{
					ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(158.0f / 255.0f, 130 / 255.0f, 100.0f / 255.0f, 1.0f));
				}
				if (ImGui::Selectable(Player.DisplayName.c_str()))
				{
					Players::SelectedPlayer = Player;
				}
				ImGui::PopStyleColor();
				ImGui::PopID();
			}
			Players::PlayerlistMutex.unlock();
		}
		ImGui::EndChild();

		ImGui::SameLine();

		ImGui::BeginChild("functions", ImVec2(250, ImGui::GetContentRegionAvail().y), false);
		{
			if (Players::SelectedPlayer.isValid())
			{
				ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), "functions");

				if (Players::SelectedPlayer.GetApiUser().IsSelf)
				{
					if (ImGui::Selectable("Copy AvatarID"))
					{
						SetClipboard(Players::SelectedPlayer.GetApiUser().AvatarID);
						Logger::AddLogEntry(("Copied AvatarID From " + Players::SelectedPlayer.GetApiUser().DisplayName + " (" + Players::SelectedPlayer.GetApiUser().AvatarID) + ")");
					}
					if (ImGui::Selectable("Copy Avatar Asset Url"))
					{
						SetClipboard(Players::SelectedPlayer.GetApiUser().AvatarAssetUrl);
						Logger::AddLogEntry(("Copied AvatarAssetUrl From " + Players::SelectedPlayer.GetApiUser().DisplayName + " (" + Players::SelectedPlayer.GetApiUser().AvatarAssetUrl) + ")");
					}
				}
				else
				{
					if (ImGui::Selectable("Teleport"))
					{
						// Players::SelectedPlayer.TeleportMe();
						vrcplayer LocalPlayer(Players::LocalPlayer.__this);
						Transform LocalPTransform(LocalPlayer.GetParent());

						vrcplayer vrc(Players::SelectedPlayer.__this);

						Transform PTransform(vrc.GetParent());
						Vector3 PlayerPosition = PTransform.GetPosition();

						Transform MLTransform(LocalPTransform);
						MLTransform.SetLocalPosition(PlayerPosition);

						Logger::AddLogEntry("Teleported to " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
						ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[/] Teleported to " + Players::SelectedPlayer.DisplayName).c_str(), "" });
					}
					if (Players::AttachedToPlayer.isValid())
					{
						if (ImGui::Selectable("Deattach"))
						{
							//if (!Config::Fly::Enabled)
							//	unity.SetGravity(Vector3().normal, false);

							Players::AttachedToPlayer = NULL;
							Logger::AddLogEntry("Deattached from " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
							ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[-] Deattached from " + Players::SelectedPlayer.DisplayName).c_str(), "" });

						}
						ImGui::PopStyleColor();
					}
					else
					{
						if (ImGui::Selectable("Attach"))
						{
							//if (!Config::Fly::Enabled)
							//	unity.SetGravity(Vector3().NoGravity, false);

							Players::AttachedToPlayer = Players::SelectedPlayer;
							Players::OrbitingPlayer = NULL;
							Players::BoneAttachPlayer = NULL;

							Logger::AddLogEntry("Attached to " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
							ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[+] Attached to " + Players::SelectedPlayer.DisplayName).c_str(), "" });
						}
					}




					if (Players::OrbitingPlayer.isValid())
					{
						if (ImGui::Selectable("Stop Orbit"))
						{
							//unity.SetGravity(Vector3().normal);
							Players::OrbitingPlayer = NULL;
							Logger::AddLogEntry("Stopped Orbiting " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
						}
					}
					else
					{
						if (ImGui::Selectable("Orbit"))
						{
							//unity.SetGravity(Vector3().NoGravity);
							Players::OrbitingPlayer = Players::SelectedPlayer;
							Players::BoneAttachPlayer = NULL;
							Players::AttachedToPlayer = NULL;

							Logger::AddLogEntry("Orbiting " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
						}
					}

					/*
					ImGui::Combo("Bone", &Players::BoneAttachType, "Head\0Left Hand\0Left Foot\0Right Hand\0Right Foot\0Troll Bone");
					if (Players::BoneAttachPlayer.isValid())
					{
						if (ImGui::Selectable("Stop Bone Attach"))
						{

							if (!Config::Fly::Enabled)
								unity.SetGravity(Vector3().normal, false);

							Players::BoneAttachPlayer = NULL;

							ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[-] Stopped Bone Attach  " + Players::SelectedPlayer.DisplayName).c_str(), "" });
							Logger::AddLogEntry("Stopped Bone Attach " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
						}
						ImGui::PopStyleColor();
					}
					else
					{
						if (ImGui::Selectable("Bone Attach"))
						{
							if (!Config::Fly::Enabled)
								unity.SetGravity(Vector3().NoGravity, false);

							Players::BoneAttachPlayer = Players::SelectedPlayer;
							Players::OrbitingPlayer = NULL;
							Players::AttachedToPlayer = NULL;

							ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[+] Bone Attached to  " + Players::SelectedPlayer.DisplayName).c_str(), "" });
							Logger::AddLogEntry("Bone Attached to " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
						}
					}
					*/

				}

				if (ImGui::Selectable("Teleport Pickups"))
				{
					ItemUtils::MoveAllPickups(Players::SelectedPlayer.GetPosition());
				}

				if (Players::ItemAttachPlayer.isValid())
				{
					if (ImGui::Selectable("Stop Item Attach"))
					{
						Players::ItemAttachPlayer = NULL;

						ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[-] Stopped Item Attach  " + Players::SelectedPlayer.DisplayName).c_str(), "" });
						Logger::AddLogEntry("Stopped Item Attach " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
					}
					ImGui::PopStyleColor();
				}
				else
				{
					if (ImGui::Selectable("Item Attach"))
					{
						Players::ItemAttachPlayer = Players::SelectedPlayer;
						Players::ItemOrbitPlayer = NULL;


						std::thread(ItemUtils::MakeMeOwner).detach();


						//for (VRC_Pickup Pickup : ItemOrbit::Pickups)
						//{
						//	Pickup.isOwner = false;
						//}

						ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[+] Item Attach to " + Players::SelectedPlayer.DisplayName).c_str(), "" });
						Logger::AddLogEntry("Item Attach to " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
					}
				}

				if (Players::ItemOrbitPlayer.isValid())
				{
					if (ImGui::Selectable("Stop Item Orbit"))
					{
						Players::ItemOrbitPlayer = NULL;

						ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[-] Stopped Item Orbit  " + Players::SelectedPlayer.DisplayName).c_str(), "" });
						Logger::AddLogEntry("Stopped Item Orbit " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
					}
					ImGui::PopStyleColor();
				}
				else
				{
					if (ImGui::Selectable("Item Orbit"))
					{
						Players::ItemOrbitPlayer = Players::SelectedPlayer;
						Players::ItemAttachPlayer = NULL;

						//for (VRC_Pickup Pickup : ItemOrbit::Pickups)
						//{
						//	Pickup.isOwner = false;
						//}

						std::thread(ItemUtils::MakeMeOwner).detach();


						ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[+] Item Orbit to " + Players::SelectedPlayer.DisplayName).c_str(), "" });
						Logger::AddLogEntry("Item Orbit to " + Players::SelectedPlayer.DisplayName, LogRaiser::Local);
					}
				}

				if (ImGui::Selectable("Reload Avatar"))
				{
					RPC_Hook::ReloadAvatarNetworkedRPC_o(Players::SelectedPlayer.__vrcplayer, Players::SelectedPlayer.__this, 0);
				}

				if (ImGui::Selectable("Copy Displayname"))
				{
					SetClipboard(Players::SelectedPlayer.GetApiUser().DisplayName);
					Logger::AddLogEntry(("Copied DisplayName (" + Players::SelectedPlayer.GetApiUser().DisplayName + ")"));
				}
			}
		}
		ImGui::EndChild();
	}
	else if (Config::Menu::InstanceTab == 1)
	{
		ImGui::BeginChild("pickups", ImVec2(250, ImGui::GetContentRegionAvail().y), false);
		{
			if (Players::PlayerlistSize == 0)
			{
				ImGui::Text("Rejoin for the pickup list to work");
			}
			else
			{
				ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), (std::to_string(ItemUtils::Pickups.size()) + " pickups").c_str());
			}

			for (VRC_Pickup pickup : ItemUtils::Pickups)
			{
				ImGui::PushID(pickup.name.c_str());
				if (ItemUtils::SelectedPickup._this == pickup._this)
				{
					ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(100.0f / 255.0f, 110.0f / 255.0f, 160.0f / 255.0f, 1.0f));
				}

				if (ImGui::Selectable(pickup.name.c_str()))
				{
					ItemUtils::SelectedPickup = pickup;
				}

				if (ItemUtils::SelectedPickup._this == pickup._this)
				{
					ImGui::PopStyleColor();
				}

				ImGui::PopID();
			}
		}
		ImGui::EndChild();

		ImGui::SameLine();

		ImGui::BeginChild("functions", ImVec2(250, ImGui::GetContentRegionAvail().y), false);
		{
			if (ItemUtils::SelectedPickup._this != nullptr)
			{
				ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), "functions");

				if (ImGui::Selectable("Give Me"))
				{
					if (ItemUtils::SelectedPickup._this != nullptr && Players::LocalPlayer.__this != nullptr)
					{
						if (Players::LocalPlayer.isValid())
						{
							Networking n;
							VRCPlayerAPI PlayerApi = n.GetOwner(Gameobject(ItemUtils::SelectedPickup.component.__gameobject));

							if (PlayerApi.__this != Players::LocalPlayer.__VRCPlayerApi)
							{
								n.SetOwner(VRCPlayerAPI(Players::LocalPlayer.VRCPlayerApi_o), Gameobject(ItemUtils::SelectedPickup.component.__gameobject));
							}
						}

						ItemUtils::SelectedPickup.transform.SetPosition(Players::LocalPlayer.GetPosition());

						Logger::AddLogEntry(("Teleported (" + ItemUtils::SelectedPickup.name + ") to you :)"));
					}
				}
			}
		}
		ImGui::EndChild();
	}
#pragma endregion
}

void SafetyTab()
{
	#pragma region Menu_Tab_Safety

	ImGui::Selectable("Block Avatar Image Download", &Config::API::BlockDownload::Image);
	ImGui::SameLine();
	if (Config::API::BlockDownload::Image)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::Selectable("Block Avatar Download", &Config::API::BlockDownload::Avatar);
	ImGui::SameLine();
	if (Config::API::BlockDownload::Avatar)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::Selectable("Network Sanity", &Config::Photon::EventLimiter::Enabled);
	ImGui::SameLine();
	if (Config::Photon::EventLimiter::Enabled)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::Selectable("Anti-Hexed Exploids", &Config::Photon::EventLimiter::Enabled);
	ImGui::SameLine();
	if (Config::Photon::EventLimiter::Enabled)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");


	if (Config::Photon::EventLimiter::Shutdown) {
		ImGui::SameLine(0.0);
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), " | SHUTDOWN");
	}

	ImGui::CustomSliderFloat("Max Events +/-", &Config::Photon::EventLimiter::MaxEventsPerPlayer, 2, 20, 100); ImGui::SameLine(0.0f, 20.0f);
	ImGui::PushID(111);
	if (ImGui::Button("Reset"))
	{
		Config::Photon::EventLimiter::MaxEventsPerPlayer = 2;
	}
	ImGui::PopID();
#pragma endregion
}

void VisualsTab()
{
	#pragma region Menu_Tab_Visuals

	if (ImGui::Selectable("Item ESP", &Config::Render::ESP::ItemEsp))
	{
		if (!Config::Render::ESP::ItemEsp)
		{
			for (VRC_Pickup pickup : ItemUtils::Pickups)
			{
				InputManager::EnableObjectHighlight_Gamebject(pickup.component.__gameobject, false);
			}
		}
	}
	ImGui::SameLine();
	if (Config::Render::ESP::ItemEsp)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::Selectable("Lines ESP", &Config::Render::DirectLines::Enabled);
	ImGui::SameLine();
	if (Config::Render::DirectLines::Enabled)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	/*
	ImGui::Selectable("Show Name", &Config::Render::NamePlate::Enabled);
	ImGui::SameLine();
	if (Config::Render::NamePlate::Enabled)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");
	*/

	ImGui::Selectable("Show Hotkeys", &Config::Menu::ShowHotkeys);
	ImGui::SameLine();
	if (Config::Menu::ShowHotkeys)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");


	ImGui::Selectable("Custom Cursor", &Config::Render::Cursor::Enabled);
	ImGui::SameLine();
	if (Config::Render::Cursor::Enabled)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::Selectable("Show Corner Info", &Config::Render::FpsCounter::Enabled);
	ImGui::SameLine();
	if (Config::Render::FpsCounter::Enabled)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	ImGui::Selectable("Show Key Presses", &Config::Render::Keyboard::Enabled);
	ImGui::SameLine();
	if (Config::Render::Keyboard::Enabled)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");


	if (ImGui::Selectable("Log Api Calls", &Config::API::LogApiCalls));
	ImGui::SameLine();
	if (Config::API::LogApiCalls)
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), "ON");
	else
		ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "OFF");

	//ImGui::BeginChild("", ImVec2(0.0f, 0.0f));
	//ImGui::EndChild();
	ImGui::CustomSliderFloat("Thickness +/-", &Config::Render::Thickness, 0, 255, 100); ImGui::SameLine(0.0f, 20.0f);
	if (ImGui::IsItemEdited())
	{
		Config::Render::ESP::Thickness = Config::Render::Thickness;
		Config::Render::DirectLines::Thickness = Config::Render::Thickness;
	}

	ImGui::PushID(1337);
	if (ImGui::Button("Reset"))
	{
		Config::Render::Thickness = 2.0f;
		Config::Render::ESP::Thickness = Config::Render::Thickness;
		Config::Render::DirectLines::Thickness = Config::Render::Thickness;
	}
	ImGui::PopID();

	ImGui::CustomSliderFloat("Roundness +/-", &Config::Render::Roundness, 0, 255, 100); ImGui::SameLine(0.0f, 20.0f);
	if (ImGui::IsItemEdited())
	{
		Config::Render::ESP::Roundness = Config::Render::Roundness;
	}
	ImGui::PushID(2345);
	if (ImGui::Button("Reset"))
	{
		Config::Render::Roundness = 10.0f;
		Config::Render::ESP::Roundness = Config::Render::Roundness;
	}
	ImGui::PopID();

#pragma endregion
}

void RenderMenuItems()
{
	#pragma region Handle_Menu_Tabs

	switch (Config::Menu::TabIndex)
	{
		case TI_Home:
			HomeTab();
			break;
		case TI_Movement:
			MovementTab();
			break;
		case TI_Misc:
			MiscTab();
			break;
		case TI_Instance:
			InstanceTab();
			break;
		case TI_Safety:
			SafetyTab();
			break;
		case TI_Visuals:
			VisualsTab();
			break;

		default:
			break;
	}
#pragma endregion
}

void LoadStyle()
{
	#pragma region Style_Vars

	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowRounding = 8.000f;
	style->WindowTitleAlign = ImVec2(0.490f, 0.520f);
	style->WindowPadding = ImVec2(15, 15);
	style->FramePadding = ImVec2(5, 5);
	style->FrameRounding = 4.0f;
	style->ItemSpacing = ImVec2(12, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;
	style->GrabRounding = 3.0f;
	style->WindowBorderSize = 0.0f;
	style->ButtonTextAlign = ImVec2(0.510f, 0.490f);
	style->AntiAliasedLines = true;

	style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);

	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);

	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);

#pragma endregion
}

void RenderKeyBoardPresses()
{
	#pragma region Keyboard_Renderer


	static int screenWidth = 0;
	if (screenWidth == 0)
		screenWidth = GetSystemMetrics(SM_CXSCREEN);

	static float WGlow = 0.1f;
	static float AGlow = 0.1f;
	static float SGlow = 0.1f;
	static float DGlow = 0.1f;

	ImGui::SetNextWindowSize(ImVec2(250, 190));
	ImGui::SetNextWindowPos(ImVec2(screenWidth - 250, 0));
	ImGui::Begin("Keyboard", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove);
	{
		ImGui::SetWindowFontScale(1.5f);

		if (GetAsyncKeyState(0x57))
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(Config::Render::Saturation::Value, Config::Render::Saturation::Value, Config::Render::Saturation::Value, WGlow));
			ImGui::SetCursorPos(ImVec2(85, 25));
			ImGui::Button("W", ImVec2(70, 70));
			ImGui::PopStyleColor();
			if (WGlow < 0.7f)
				WGlow += 0.08f;
		}
		else
			WGlow = 0.1f;



		if (GetAsyncKeyState(0x41))
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(Config::Render::Saturation::Value, Config::Render::Saturation::Value, Config::Render::Saturation::Value, AGlow));

			ImGui::SetCursorPos(ImVec2(10, 100));
			ImGui::Button("A", ImVec2(70, 70));
			ImGui::PopStyleColor();
			if (AGlow < 0.7f)
				AGlow += 0.08f;
		}
		else
			AGlow = 0.1f;


		if (GetAsyncKeyState(0x53))
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(Config::Render::Saturation::Value, Config::Render::Saturation::Value, Config::Render::Saturation::Value, SGlow));
			ImGui::SetCursorPos(ImVec2(85, 100));
			ImGui::Button("S", ImVec2(70, 70));
			ImGui::PopStyleColor();

			if (SGlow < 0.7f)
				SGlow += 0.08f;
		}
		else
			SGlow = 0.1f;



		if (GetAsyncKeyState(0x44))
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(Config::Render::Saturation::Value, Config::Render::Saturation::Value, Config::Render::Saturation::Value, 0.7));
			ImGui::SetCursorPos(ImVec2(160, 100));
			ImGui::Button("D", ImVec2(70, 70));
			ImGui::PopStyleColor();

			if (DGlow < 0.7f)
				DGlow += 0.08f;
		}
		else
			DGlow = 0.1f;

		ImGui::SetWindowFontScale(1.0f);
	}
	ImGui::End();

#pragma endregion
}

void RenderCornerInfo()
{
	float Delta = unity.GetDeltaTime();
	int32_t ServerTime = -1;
	Vector3 Position = Vector3(0, 0, 0);
	if (Players::LocalPlayer.__this != nullptr)
	{
		ServerTime = Networking().GetServerTimeInMilliseconds();
		Position = Players::LocalPlayer.GetPosition();
	}

	Gui.Text((std::to_string(unity.CalculateFps(Delta)) + " FPS (Deltatime: " + std::to_string(Delta) + ", ServerTime: " + std::to_string(ServerTime) + "ms, Position: " + Position.ToString() + ", Fov: " + std::to_string(Render::GetFov()) + ")"), ImVec2(10, 10), ImColor(255, 255, 255, 255));
}

void DrawCallBack()
{
	auto &Style = ImGui::GetStyle();
	static bool IsMenuInit = false;
	if (!IsMenuInit)
	{
		ImGui::InsertNotification({ ImGuiToastType_Info, 20000, "Press ---> - <--- to Open Menu!", ""});
		Logger::AddLogEntry("Press ---> - <--- to Open Menu!");

		ImGui::InsertNotification({ ImGuiToastType_Info, 20000, "Press ---> x <--- to Zoom!", "" });
		Logger::AddLogEntry("Press ---> x <--- to Zoom!");

		std::thread(ItemHandler).detach();
		std::thread(DotThread).detach();
		std::thread(ItemESPHandler).detach();
		std::thread(ItemOrbitHandler).detach();
	}

	if (Players::LocalPlayer.__this != nullptr)
	{
		if (Config::Fly::Enabled)
			FlyHandler::Update();

		if (Config::BunnyHop::Enabled)
			BunnyHop::Update();

		if (Players::OrbitingPlayer.isValid())
		{
			alpha += 0.1f;

			alpha = fmod(alpha, 365.0f);

			vrcplayer LocalPlayer(Players::LocalPlayer.__this);
			Transform LocalPlayerObject = Transform(LocalPlayer.transformpointer).GetRoot();

			vrcplayer RemotePlayer(Players::OrbitingPlayer.__this);
			Transform RemotePlayerObject = Transform(RemotePlayer.transformpointer).GetRoot();

			Vector3 PlayerPosition = RemotePlayerObject.GetPosition();

			float CalculatedX = PlayerPosition.x + a * cos(alpha);
			float CalculatedY = PlayerPosition.y;
			float CalculatedZ = PlayerPosition.z + b * sin(alpha);

			Vector3 CalculatedPosition(CalculatedX, CalculatedY, CalculatedZ);

			VRCPlayerAPI().SetVelocity(Vector3(0, 0, 0));

			LocalPlayerObject.SetPosition(CalculatedPosition);

		}

		HandlePlayers();

		if (Config::RPCSpam::SpamReload)
		{
			RPC_Hook::ReloadAvatarNetworkedRPC_o(Players::LocalPlayer.__vrcplayer, Players::LocalPlayer.__this, 0);
		}
		if (Config::RPCSpam::SpamEmote)
		{
			RPC_Hook::PlayEmoteRPC_o(Players::LocalPlayer.__vrcplayer, 3, Players::LocalPlayer.__this, 0);
		}
	}

	if (Players::AttachedToPlayer.__this != nullptr)
	{
		vrcplayer LocalPlayer(Players::LocalPlayer.__this);
		Transform LocalPlayerObject = Transform(LocalPlayer.transformpointer).GetRoot();

		vrcplayer RemotePlayer(Players::AttachedToPlayer.__this);
		Transform RemotePlayerObject = Transform(RemotePlayer.transformpointer).GetRoot();


		Vector3 PlayerPosition = RemotePlayerObject.GetPosition();

		VRCPlayerAPI().SetVelocity(Vector3(0, 0, 0));

		if (!PlayerPosition.isEqual(LocalPlayerObject.GetPosition()))
			LocalPlayerObject.SetPosition(PlayerPosition);
	}
	else if (Players::BoneAttachPlayer.__this != nullptr)
	{
		HumanBodyBones Bone;
		switch (Players::BoneAttachType)
		{
			case 0:
				Bone = Head;
				break;
			case 1:
				Bone = LeftHand;
				break;
			case 2:
				Bone = LeftFoot;
				break;
			case 3:
				Bone = RightHand;
				break;
			case 4:
				Bone = RightFoot;
				break;
			default:
				Bone = Head;
				break;
		}

		Vector3 BonePosition = Players::BoneAttachPlayer.GetBonePosition(Bone);
		if (Players::BoneAttachType == 5)
		{
		}
		else
		{
			vrcplayer LocalPlayer(Players::LocalPlayer.__this);
			Transform LocalPlayerObject = Transform(LocalPlayer.transformpointer).GetRoot();

			if (!BonePosition.isEqual(LocalPlayerObject.GetPosition()))
			{
				LocalPlayerObject.SetPosition(BonePosition);
			}
		}
	}

	if (Config::Menu::Visible)
	{
		if (Config::Menu::ShowMenu)
		{
			ImGui::SetNextWindowSize(ImVec2(580, 290));
			ImGui::Begin("Elements Base", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
			{
				//if (Players::LocalPlayer.isValid())
				if (true)
				{
					if (ImGui::Button("home", ImVec2(75, 23)))
						Config::Menu::TabIndex = TI_Home;

					ImGui::SameLine();
					if (ImGui::Button("movement", ImVec2(75, 23)))
						Config::Menu::TabIndex = TI_Movement;

					ImGui::SameLine();

					if (ImGui::Button("misc", ImVec2(75, 23)))
						Config::Menu::TabIndex = TI_Misc;

					ImGui::SameLine();

					if (ImGui::Button("instance", ImVec2(75, 23)))
						Config::Menu::TabIndex = TI_Instance;

					ImGui::SameLine();

					if (ImGui::Button("safety", ImVec2(75, 23)))
						Config::Menu::TabIndex = TI_Safety;

					ImGui::SameLine();

					if (ImGui::Button("visuals", ImVec2(75, 23)))
						Config::Menu::TabIndex = TI_Visuals;
				}
				else
				{
					ImGui::Button("Please Rejoin / Join a World", ImVec2(300, 23));
				}
				RenderMenuItems();
			}
			ImGui::End();
		}

		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.f);
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(43.f / 255.f, 43.f / 255.f, 43.f / 255.f, 100.f / 255.f)); // Background color
		ImGui::RenderNotifications();
		ImGui::PopStyleVar(1);
		ImGui::PopStyleColor(1);
	}

	ImGui::Begin("Logs", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
	{
		/*
		int x, y;
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);
		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		x = screenHeight / 18;
		y = screenWidth / 18;

		ImGui::SetNextWindowPos(ImVec2(x, y));

		*/

		auto &Style = ImGui::GetStyle();

		Style.Colors[ImGuiCol_ScrollbarBg] = Config::Menu::AccentColor;
		Style.Colors[ImGuiCol_ScrollbarGrab] = Config::Menu::AccentColor;
		Style.Colors[ImGuiCol_ScrollbarGrabHovered] = Config::Menu::AccentColor;
		Style.Colors[ImGuiCol_ScrollbarGrabActive] = Config::Menu::AccentColor;

		Style.Colors[ImGuiCol_ResizeGrip] = Config::Menu::Resize::InactiveColor;
		Style.Colors[ImGuiCol_ResizeGripHovered] = Config::Menu::Resize::HoveredColor;
		Style.Colors[ImGuiCol_ResizeGripActive] = Config::Menu::Resize::ActiveColor;

		Style.ScrollbarRounding = Config::Menu::ScrollRoundness;

		for (auto &pair : Logger::GetSortedLogMessages())
		{
			const std::string &Message = pair.first;
			const Logger::LogDetails &details = pair.second;

			std::string TimeStamp = Logger::FormatTime(details.TimeStamp);
			LogRaiser logRaiser = details.Raiser;

			ImVec4 color = ImVec4(70.0f / 255.0f, 67.0f / 255.0f, 70.0f / 255.0f, 1.0f); // Default color
			if (logRaiser == LogRaiser::Patch)
				color = ImVec4(0.5f, 0.7f, 1.0f, 1.0f);
			else if (logRaiser == LogRaiser::Patch)
				color = ImVec4(0.0f, 0.0f, 0.5f, 1.0f);
			else if (logRaiser == LogRaiser::Behavior)
				color = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
			else if (logRaiser == LogRaiser::Local)
				color = ImVec4(1.0f, 0.0f, 1.0f, 1.0f);
			else if (logRaiser == LogRaiser::Api)
				color = ImVec4(0.7f, 0.9f, 0.7f, 1.0f);
			else if (logRaiser == LogRaiser::PlayerLeave)
				color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
			else if (logRaiser == LogRaiser::PlayerJoin)
				color = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
			else if (logRaiser == LogRaiser::Safety)
				color = ImVec4(0.5f, 0.7f, 1.0f, 1.0f);
			else if (logRaiser == LogRaiser::Risk)
				color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
			else if (logRaiser == LogRaiser::Photon)
				color = ImVec4(0.0f, 0.0f, 1.0f, 1.0f);
			else if (logRaiser == LogRaiser::RPC)
				color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

			ImGui::Text("[");
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), "%s", TimeStamp.c_str());
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::Text("]");

			ImGui::SameLine();
			ImGui::Text("[");
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::TextColored(color, ToString(logRaiser).c_str());
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::Text("]");

			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), "%s", Message.c_str());

			if (details.Count > 1)
			{
				ImGui::SameLine();
				ImGui::Text("(%dx)", details.Count);
			}
		}
		ImGui::SetScrollHereY(1.0f);
		ImGui::End();

		if (Config::CustomWorldJoinBehaivior::insideloadeingScreen)
		{
			ImGui::SetNextWindowPos(ImVec2(0, 0));

			int screenHeight = GetSystemMetrics(SM_CYSCREEN);
			int screenWidth = GetSystemMetrics(SM_CXSCREEN);

			ImGui::SetNextWindowSize(ImVec2(screenWidth, screenHeight));
			ImGui::Begin("Particles", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoBringToFrontOnFocus);
			{
				Gui.Draw_Particles(IM_COL32(150, 112, 154, 255));
			}
			ImGui::End();
		}

		if (!IsMenuInit)
		{
			Gui.Setup_Particles(150);
			IsMenuInit = true;
		}
	}
}

void MainRenderer(const std::chrono::time_point<std::chrono::steady_clock> &LastTimePoint, const std::chrono::time_point<std::chrono::steady_clock> &CurTimePoint)
{
	//Playerlist();
	LoadStyle();

	if (Config::Render::Keyboard::Enabled)
		RenderKeyBoardPresses();

	if (Config::Render::FpsCounter::Enabled)
		RenderCornerInfo();

	notificationManager.Update();
	notificationManager.Render();

	if (GetAsyncKeyState(0xBD))
	{
		Config::Menu::ShowMenu = !Config::Menu::ShowMenu;
		Sleep(200);
	}

	if (GetAsyncKeyState(0x58)) Render::Zoom();
	else Render::DontZoom();

	if (Config::Render::Saturation::Up)
	{
		if (Config::Render::Saturation::Value < Config::Render::Saturation::Max)
		{
			Config::Render::Saturation::Value += Config::Render::Saturation::Step;
		}
		else
		{
			Config::Render::Saturation::Up = false;
		}
	}
	else
	{
		if (Config::Render::Saturation::Value > Config::Render::Saturation::Min)
		{
			Config::Render::Saturation::Value -= Config::Render::Saturation::Step;
		}
		else
		{
			Config::Render::Saturation::Up = true;
		}
	}

	DrawCallBack();
}

void MainRendererHandler()
{
	static std::chrono::time_point LastTimePoint = std::chrono::steady_clock::now();
	auto CurTimePoint = std::chrono::steady_clock::now();
	//Players::UpdateTimes();
	if (!Config::Menu::BotMenu)
	{
		MainRenderer(LastTimePoint, CurTimePoint);
	}
	LastTimePoint = CurTimePoint;

	if (Players::LocalPlayer.isValid())
	{
		if (Config::Menu::Hotkeys::FlyHotkey != -1 && GetAsyncKeyState(Config::Menu::Hotkeys::FlyHotkey))
		{
			Sleep(250);
			Config::Fly::Enabled = !Config::Fly::Enabled;
			if (Config::Fly::Enabled)
			{
				Config::Unity::NoGravity = false;
				Config::Unity::MoonGravity = false;

				if (Config::Fly::Mode == FI_GFly)
				{
					Unity().SetGravity(Vector3().Nan);
				}
			}
			else
			{
				if (Config::Fly::Mode == FI_GFly)
				{
					Unity().SetGravity(Vector3().normal);
				}
			}
		}

		if (Config::Menu::Hotkeys::BunnyHopHotkey != -1 && GetAsyncKeyState(Config::Menu::Hotkeys::BunnyHopHotkey))
		{
			Sleep(250);
			Config::BunnyHop::Enabled = !Config::BunnyHop::Enabled;
		}

		if (Config::Menu::Hotkeys::GivePickupsHotkey != -1 && GetAsyncKeyState(Config::Menu::Hotkeys::GivePickupsHotkey))
		{
			Sleep(250);
			if (Players::LocalPlayer.isValid())
				ItemUtils::MoveAllPickups(Players::LocalPlayer.GetPosition());
		}

		if (Config::Menu::Hotkeys::SerilisedMovementHotkey != -1 && GetAsyncKeyState(Config::Menu::Hotkeys::SerilisedMovementHotkey))
		{
			Sleep(250);
			if (Config::Photon::Block::Movement)
			{
				if (Players::LocalPlayer.isValid())
				{
					vrcplayer LocalPlayer(Players::LocalPlayer.__this);
					Transform LocalPTransform(LocalPlayer.GetParent());
					Transform LocalPlayerObject(LocalPTransform);

					Config::Photon::Block::LastPosition = LocalPlayerObject.GetPosition();
				}
			}
		}
	}

	Render::DrawClientCursor();
}