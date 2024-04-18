#pragma once

namespace Address {
    const uintptr_t gameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");

    namespace TextMeshProUGUI {
        const uintptr_t OnPreRenderCanvas = gameAssembly + 0x42ACCE0; //
    }

    namespace Gameobject {
        const uintptr_t Find = gameAssembly + 0x43F95C0; //
    }

    namespace Unity { //Updated
        const uintptr_t SetTime = gameAssembly + 0x440A8C0; //
        const uintptr_t GetDeltaTime = gameAssembly + 0x440A3C0; //
        const uintptr_t SetGravity = gameAssembly + 0x44B1520; //
    }

    namespace Renderer {
        const uintptr_t ctor = gameAssembly + 0x4397240; //
    }

    namespace Component {
        const uintptr_t get_gameobject = gameAssembly + 0x43F56C0; //
        const uintptr_t get_transform = gameAssembly + 0x43F5770; //
        const uintptr_t GetComponentInChildren = gameAssembly + 0x43F4F10; //

        const uintptr_t get_component = gameAssembly + 0x43F5130; //
    }

    namespace Object {
        const uintptr_t Instantiate = gameAssembly + 0x43FD870; //
        const uintptr_t getname = gameAssembly + 0x43FE0C0; //
    }

    namespace Renderere {
        const uintptr_t ctor = gameAssembly + 0x4397240; //
    }

    namespace InputManager {
        const uintptr_t EnableObjectHighlight_Gamebject = gameAssembly + 0x5C10290; //
        const uintptr_t EnableObjectHighlight_Renderer = gameAssembly + 0x5C10220; //
    }

    namespace Networking { //Updated
        const uintptr_t LocalVRCPlayer = gameAssembly + 0x5C11DE0; //
        const uintptr_t GetServerTimeInMilliseconds = gameAssembly + 0x5C11540; //

        const uintptr_t Destroy = gameAssembly + 0x5C11330; //
        const uintptr_t SetOwner = gameAssembly + 0x5C11AE0; //
        const uintptr_t GetOwner = gameAssembly + 0x5C114E0; //
    }

    namespace VRCPlayerAPI {  //Updated
        const uintptr_t GetVRCPlayerApi = gameAssembly + 0x6DC2B0;  // from player*

        const uintptr_t GetAvatarEyeHeight = gameAssembly + 0x5BF14D0; //
        const uintptr_t GetJumpImpulse = gameAssembly + 0x5BF1920; //
        const uintptr_t SetVelocity = gameAssembly + 0x5BF3530; //
        const uintptr_t GetVelocity = gameAssembly + 0x5BF2090; //
        const uintptr_t SetWalkSpeed = gameAssembly + 0x5BF38A0; //
        const uintptr_t SetRunSpeed = gameAssembly + 0x5BF32B0; //
        const uintptr_t GetWalkSpeed = gameAssembly + 0x5BF2130; //
        const uintptr_t GetRunSpeed = gameAssembly + 0x5BF1ED0; //
        const uintptr_t IsUserInVR = gameAssembly + 0x5BF2360; //
        const uintptr_t EnablePickups = gameAssembly + 0x5BF13D0; //
        const uintptr_t IsPlayerGrounded = gameAssembly + 0x5BF22C0; //
        const uintptr_t IsValid = gameAssembly + 0x6893C0; //
        const uintptr_t SetNamePlateColor = gameAssembly + 0x5BF30F0; //
        const uintptr_t SetPickupInHand = gameAssembly + 0x65DB40; //
        const uintptr_t GetBonePosition = gameAssembly + 0x5BF1650; //
        const uintptr_t GetPlayerID = gameAssembly + 0x5BF1C10; //
        const uintptr_t isMaster = gameAssembly + 0x5BF4F10; //
        const uintptr_t GetBoneTransform = gameAssembly + 0x5BF17B0; //
        const uintptr_t Respawn = gameAssembly + 0x5BF26C0; //
    }

    namespace VRCPlayer { //Updated
        const uintptr_t GetVRCPlayer = gameAssembly + 0x7C3140; // 
        const uintptr_t GetTransform = gameAssembly + 0x87DB60; //
    }

    namespace Transform { //Updated
        const uintptr_t get_right = gameAssembly + 0x44107C0; //
        const uintptr_t get_up = gameAssembly + 0x4410930; //
        const uintptr_t get_forward = gameAssembly + 0x4410180; //

        const uintptr_t set_position = gameAssembly + 0x4410FE0; //
        const uintptr_t get_position = gameAssembly + 0x4410770; //
         
        const uintptr_t get_rotation = gameAssembly + 0x44108E0; //
        const uintptr_t set_rotation = gameAssembly + 0x4411130; //


        const uintptr_t set_localposition = gameAssembly + 0x4410D40; //
        const uintptr_t get_localposition = gameAssembly + 0x4410440; //

        const uintptr_t get_parent = gameAssembly + 0x440C670; //
        const uintptr_t GetRoot = gameAssembly + 0x440C710; //
        const uintptr_t Find = gameAssembly + 0x440C370; //
    }

    namespace ApiAvatar { //Updated
        const uintptr_t GetAPIAvatar = gameAssembly + 0x1125DD0; //
        const uintptr_t GetAssetUrl = gameAssembly + 0x6EF5A0; //
    }

    namespace ApiUser { //Updated
        const uintptr_t GetApiUser = gameAssembly + 0x673560; // From Player* Updated //
        const uintptr_t GetApiUserDisplayName = gameAssembly + 0x6AE840; //
        const uintptr_t GetApiUserAvatarID = gameAssembly + 0x6AFC40; //
        const uintptr_t GetApiUserIsSelf = gameAssembly + 0x5AD4960; //
        const uintptr_t GetApiUserAvatarAssetURL = gameAssembly + 0x893380; //
        const uintptr_t isFriend = gameAssembly + 0xA57380;
    }


    namespace Camera { //Updated
        const uintptr_t GetMainCamera = gameAssembly + 0x43A22E0; //
        const uintptr_t GetWorldToScreenPointVector3 = gameAssembly + 0x43A15A0; //
        const uintptr_t Render = gameAssembly + 0x43A0240; //

        const uintptr_t GetFov = gameAssembly + 0x43A2080; //
        const uintptr_t SetFov = gameAssembly + 0x43A3640; //
    }

    namespace Gizmos {
        const uintptr_t DrawLine = gameAssembly + 0x43AB030; //
        const uintptr_t SetColor = gameAssembly + 0x43ABEA0; //
    }

    namespace API { //Updated
        const uintptr_t SendRequest = gameAssembly + 0x5AA6F30; //
    }

    namespace NetworkManager { //Updated
        const uintptr_t OnPlayerLeft = gameAssembly + 0x827610; //
        const uintptr_t OnPlayerJoined = gameAssembly + 0x7B7610; //
    }

    namespace Photon {
        const uintptr_t OpRaiseEvent = gameAssembly + 0x1094360; //
        const uintptr_t PhotonAuth = gameAssembly + 0x1095A00; //
        const uintptr_t OnEvent = gameAssembly + 0x81BC60; //
    }

    namespace System_Type {
        const uintptr_t GetType = gameAssembly + 0x372BF20; //
    }

    namespace VRC_Pickup { //Updated
        const uintptr_t Awake = gameAssembly + 0x5BFEB70; //
    }

    namespace RPC {
        const uintptr_t ReloadAvatarNetworkedRPC = gameAssembly + 0xD083E0;
        const uintptr_t PlayEmoteRPC = gameAssembly + 0xD082F0;
        const uintptr_t AddUrl = gameAssembly + 0x5BB93A0; // <- VRC_SyncVideoPlayer
        const uintptr_t AddUrl2 = gameAssembly + 0x5BBA440; // <- VRC_SyncVideoStream
    }

    namespace VRC_Combat {
        const uintptr_t GetInstance = gameAssembly + 0x5BB6120;
        const uintptr_t RespawnPlayerRPC = gameAssembly + 0x5BB61B0;
    }

    namespace Text {
        const uintptr_t SetText = gameAssembly + 0x46B8FB0;
        const uintptr_t GetText = gameAssembly + 0x6C2980;
    }

    namespace Button {
        const uintptr_t Press = gameAssembly + 0x450D5F0;
    }

    namespace UI {
        const uintptr_t UpdateGeometry = gameAssembly + 0x45EE1E0;

        namespace AdvancedUserInterface {
            const uintptr_t ViewOnWebsideButton = 0x180;
        }


        namespace TextMeshPro {
            const uintptr_t SetFaceColor = gameAssembly + 0x41F3430;
            const uintptr_t OnPreRenderObject = gameAssembly + 0x41EFF40;
        }
    }
}
