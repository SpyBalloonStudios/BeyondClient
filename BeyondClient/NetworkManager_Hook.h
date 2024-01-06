#pragma once


namespace NetworkManager_Hook {

    void(__fastcall* OnPlayerLeftFunc)(DWORD*, DWORD*, DWORD*);
    void __stdcall OnPlayerLeft(DWORD* __this, DWORD* PlayerP, DWORD* methodinfo)
    {
        Player p(PlayerP);

        #pragma region Log_Player_Leave
        // Log player leaving information
        std::string DisplayName = p.DisplayName;
        Logger::AddLogEntry("Player " + DisplayName + " Left", LogRaiser::PlayerLeave);
        ImGui::InsertNotification({ ImGuiToastType_Error, 5000, ("[-] Player " + DisplayName + " Left").c_str(), "" });
        #pragma endregion 
        #pragma region Handle_Local_Player

        // Check if the leaving player is the local player
        if (p.Self)
        {
            // Reset various player-related data for the local player
            Players::LocalPlayer = Player(nullptr);
            Config::CustomWorldJoinBehaivior::insideloadeingScreen = true;
            ItemUtils::Pickups.clear();
            ItemUtils::NotStealable.clear();
            ItemUtils::NotPickupable.clear();

            Players::SelectedPlayer = Player(nullptr);
            Players::AttachedToPlayer = Player(nullptr);
            Players::OrbitingPlayer = Player(nullptr);
            Players::ItemAttachPlayer = Player(nullptr);
            Players::ItemOrbitPlayer = Player(nullptr);
        }

     #pragma endregion 
        #pragma region Clear_Player_Data

        // Clear selected player data if leaving player is the selected player
        if (p.isEqual(Players::SelectedPlayer))
        {
            Players::SelectedPlayer = Player(nullptr);
        }
        else if (p.isEqual(Players::AttachedToPlayer))
        {
            Players::AttachedToPlayer = Player(nullptr);
        }
        else if (p.isEqual(Players::OrbitingPlayer))
        {
            Players::OrbitingPlayer = Player(nullptr);
        }
        else if (p.isEqual(Players::ItemAttachPlayer))
        {
            Players::ItemAttachPlayer = Player(nullptr);
        }
        else if (p.isEqual(Players::ItemOrbitPlayer))
        {
            Players::ItemOrbitPlayer = Player(nullptr);
        }

    #pragma endregion 
        #pragma region Remove_Player_From_Player_List

        // Lock player list, find the leaving player, and erase from the vector
        Players::PlayerlistMutex.lock();
        auto playerIt = std::find_if(
            Players::Playerlist.begin(), Players::Playerlist.end(),
            [&p](const Player& player) {
                return player.__this == p.__this;
            });

        if (playerIt != Players::Playerlist.end()) {
            Players::Playerlist.erase(playerIt);
        }
        Players::updatePlayerListSize();
        Players::PlayerlistMutex.unlock();

    #pragma endregion

        OnPlayerLeftFunc(__this, PlayerP, methodinfo);
    }

    void OnPlayerJoinedThread(Player p)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        #pragma region Push_Player_Into_PlayerList

        Players::PlayerlistMutex.lock();
        Players::Playerlist.push_back(p);
        Players::updatePlayerListSize();
        Players::PlayerlistMutex.unlock();
    #pragma endregion 
    }

    void(__fastcall* OnPlayerJoinedFunc)(DWORD*, DWORD*, DWORD*);
    void __stdcall OnPlayerJoined(DWORD* __this, DWORD* PlayerP, DWORD* methodinfo)
    {
        Player p = Player(PlayerP);

        #pragma region Log_Player_Join
        // Log player join information
        std::string DisplayName = p.DisplayName;
        Logger::AddLogEntry("Player " + DisplayName + " Joined", LogRaiser::PlayerJoin);
        ImGui::InsertNotification({ ImGuiToastType_Success, 3000, ("[+] Player " + DisplayName + " Joined").c_str() });
#pragma endregion 
        #pragma region Handle_Local_Player

        // If the player is the local player, perform additional setup
        if (p.Self)
        {
            Players::LocalPlayer = p;
            Config::CustomWorldJoinBehaivior::insideloadeingScreen = false;
            VRCPlayerAPI().InitializeOriginalSpeed();
        }
        else
        {
            // Additional actions for non-local players (commented out)
            // ...
        }

#pragma endregion 

        // Start a thread to handle player join
        std::thread(OnPlayerJoinedThread, p).detach();

        OnPlayerJoinedFunc(__this, PlayerP, methodinfo);
    }

    void Init() {
        // Hook OnPlayerLeft for handling leaving players
        HookFunction(Address::NetworkManager::OnPlayerLeft, OnPlayerLeft, OnPlayerLeftFunc);

        // Hook OnPlayerJoined for handling joined players
        HookFunction(Address::NetworkManager::OnPlayerJoined, OnPlayerJoined, OnPlayerJoinedFunc);
    }
}
