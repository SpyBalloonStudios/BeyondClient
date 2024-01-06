#pragma once

namespace RPC_Hook {
    void(__fastcall* ReloadAvatarNetworkedRPC_o)(DWORD*, DWORD*, DWORD*);
    void __stdcall ReloadAvatarNetworkedRPC(DWORD* vrcplayer, DWORD* player, DWORD* methodinfo)
    {
        // Log the ReloadAvatarNetworkedRPC event if The Log RPC's is Enabled
        if (Config::RPC::LogRpcs)
        {
            Player p = Player(player);
            std::string PlayerName = p.DisplayName;

            Logger::AddLogEntry(PlayerName + " Reloaded his Avatar", LogRaiser::RPC);
        }

        ReloadAvatarNetworkedRPC_o(vrcplayer, player, methodinfo);
    }

    void(__fastcall* PlayEmoteRPC_o)(DWORD*, int32_t, DWORD*, DWORD*);
    void __stdcall PlayEmoteRPC(DWORD* vrcplayer, int32_t EmoteID, DWORD* player, DWORD* methodinfo)
    {
        // Log the PlayEmoteRPC event if The Log RPC's is Enabled
        if (Config::RPC::LogRpcs)
        {
            Player p = Player(player);
            std::string PlayerName = p.DisplayName;

            Logger::AddLogEntry((PlayerName + " Played Emote EmoteID: " + std::to_string(EmoteID)), LogRaiser::RPC);
        }

        PlayEmoteRPC_o(vrcplayer, EmoteID, player, methodinfo);
    }

    void Init()
    {
        HookFunction(Address::RPC::ReloadAvatarNetworkedRPC, ReloadAvatarNetworkedRPC, ReloadAvatarNetworkedRPC_o);
        HookFunction(Address::RPC::PlayEmoteRPC, PlayEmoteRPC, PlayEmoteRPC_o);
    }
}
