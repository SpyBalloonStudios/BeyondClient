#pragma once
#include <vector>

std::string consoletitle = "Midnight";

#define UpperScreen 0
#define MiddleScreen 1
#define LowerScreen 2
#define FromCursor 3

#define FilledCursor 0
#define HollowCursor 1


#define AvatarAssetDownloadUrl "analysis/file"
#define AvatarImageDownloadUrl "vrchat.com/files"

namespace Config {
	namespace Log {
		bool Debug = false;

		namespace AutoClean {
			bool Enabled = false;
			int Interval = 5;
		}

		namespace File {
			bool Enabled = true;
			bool UseSingle = true; // Former SingleFile
		}
	}

	namespace Spoof {
		namespace Ping {
			bool Enabled = false;
			int Value = 420;
		}

		namespace Fps {
			bool Enabled = false;
			int Value = 69;
		}
	}

	namespace Photon {
		namespace Log {
			bool OpRaiseEvent = false; // Former LogOutgoingEvents
			bool OnEvent = false; // Former LogIncomingEvents
		}
		
		namespace Invisible {
			bool Enabled = false;
			bool SpoofCoords = false;
		}

		namespace Repeat { // Repeats certain Actions
			bool Emoji = false;
			bool E13 = false;
			bool Portal = false;
			bool Voice = false;
		}

		namespace Block { // Blocks certain Actions
			bool E33Out = false;
			bool Movement = false;
			Vector3 LastPosition;
			bool OnEvent = false; // Former LogIncomingEvents
			bool Portals = false;
			bool Teleport = false;
		}

		namespace EventLimiter {
			bool Enabled = false;
			float MaxEventsPerPlayer = 2;
			bool Detection = false; // INTERNAL: Former DetectEventSpam
			bool Shutdown = false; // INTERNAL: Initializes a event shutdown
			int LastIntervalTotalEvents = 0; // INTERNAL: Stores the total events of the last interval
		}
	}

	namespace Render {

		float Thickness = 2.0f;
		float Roundness = 10.0f;

		namespace Saturation {
			bool Up = false; // INTERNAL: Former SaturationUp
			float Value = 0.2f; // INTERNAL: Stores the current saturation value
			float Min = 0.4f;
			float Max = 0.8f;
			float Step = 0.003f; // Stores the step size of the saturation change
		}

		namespace ESP {
			bool Enabled = false;
			float Thickness = 2.0f;
			float Size = 250.0f;
			float Roundness = 0.0f;
			float GlowIntensity = 1.0f;
			ImColor Color(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f);

			bool ItemEsp = false;
		}

		namespace DirectLines {
			bool Enabled = false;
			float Thickness = 2.0f;
			int Type = 0;
			ImColor Color(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f);
		}

		namespace Position {
			bool Enabled = false;
		}

		namespace Cursor {
			bool Enabled = true;
			float Thickness = 2.0f;
			float Radius = 10.0f;
			int Type = 1;
			ImColor Color(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f);
		}

		namespace FpsCounter {
			bool Enabled = true;
		}

		namespace Keyboard {
			bool Enabled = true;
		}

		namespace NamePlate {
			bool Enabled = false;
			int Type = 2;
			float Size = 30.0f;
			ImColor Color(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f);
		}
	}

	namespace Menu {
		bool Visible = true;
		bool PickupsInteractable = false; // Former HidePickups

		int InstanceTab = 0;

		bool ShowMenu;

		bool BotMenu = false;

		int TabIndex = 0;

		bool ShowHotkeys = false;
		namespace Hotkeys {
			int FlyHotkey = -1;
			int BunnyHopHotkey = -1;
			int GivePickupsHotkey = -1;
			int SerilisedMovementHotkey = -1;
		}

		inline ImVec4 AccentColor = ImColor(0, 255, 19, 255);
		inline float ScrollRoundness = 30.f;
		namespace Resize {
			inline ImVec4 ActiveColor = ImColor(26, 27, 29, 255);
			inline ImVec4 InactiveColor = ImColor(16, 17, 19, 255);
			inline ImVec4 HoveredColor = ImColor(22, 24, 26, 255);
		}

		std::string OwnUsername; // INTERNAL: Stores the own username

		int gamePriority = 2; // Initialize with "Normal" as the default
	}

	namespace API {
		bool LogApiCalls = false;
		namespace BlockDownload {
			bool Avatar = false;
			bool Image = false;
		}
	}

	namespace Portal {
		bool AutoDestroy = false;
	}

	namespace VRCPlayerAPI {
		namespace Speed { // Speeds of the own Player
			namespace Current {
				float Walk = 2.0f;
				float Run = 4.0f;
			}
			namespace Original {
				float Walk = 2.0f;
				float Run = 4.0f;
			}
		}

		namespace Block {
			bool Respawn = false;
		}
		
	}

	namespace Pickups {
		bool ForceAllowPickupable = false;
		bool ForceAllowTheft = false;
		bool InfiniteReach = false;
		bool Freeze = false;
	}

	namespace VideoPlayer {
		namespace Block {
			bool BlockUntrusted = true;
			std::vector<std::string> whitelisted = { "https:://youtube.com", "https:://vrchat.com" };
		}
	}

	namespace CustomWorldJoinBehaivior {
		bool insideloadeingScreen = false;
	}

	namespace Unity {
		float Timescale = 1.0f;
		float Gravity = -9.81f;

		int Speed = 1.0f;

		bool NoGravity = false;
		bool MoonGravity = false;
	}

	namespace Jetpack {
		bool Enabled = false;
	}

	namespace BunnyHop {
		bool Enabled = false;
	}

	namespace Fly {
#define FI_GFly 0
#define FI_VFly 1

		bool Enabled = false;
		bool Directional = false;
		int Mode = FI_VFly;
		int Speed = 10;
	}

	namespace RPCSpam {
		bool SpamReload = false;
		bool SpamEmote = false;
	}

	namespace RPC {
		bool LogRpcs = false;
	}
}