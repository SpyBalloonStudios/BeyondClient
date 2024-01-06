#pragma once

#pragma region Offset_Help
/*
{
    OpRaiseEvent ->
    "Address": 68464544,
    "Name" : "\u00CC\u00CF\u00CE\u00CE\u00CC\u00CF\u00CD\u00CC\u00CE\u00CF\u00CD\u00CF\u00CD\u00CC\u00CC\u00CF\u00CD\u00CD\u00CE\u00CD\u00CC\u00CE\u00CD$$\u00CD\u00CF\u00CF\u00CC\u00CE\u00CE\u00CD\u00CD\u00CE\u00CF\u00CF\u00CC\u00CC\u00CE\u00CF\u00CC\u00CE\u00CD\u00CE\u00CC\u00CC\u00CD\u00CF",
    "Signature" : "bool ________________________________________________ (uint8_t _______________________, Il2CppObject* _______________________, ________________________3931_o* _______________________, ExitGames_Client_Photon_SendOptions_o _______________________, const MethodInfo* method);",
    "TypeSignature" : "iiiiii"

    PhotonAuth ->
    "Address": 68468416,
    "Name" : "\u00CC\u00CF\u00CE\u00CE\u00CC\u00CF\u00CD\u00CC\u00CE\u00CF\u00CD\u00CF\u00CD\u00CC\u00CC\u00CF\u00CD\u00CD\u00CE\u00CD\u00CC\u00CE\u00CD$$\u00CE\u00CE\u00CC\u00CC\u00CD\u00CD\u00CE\u00CF\u00CF\u00CE\u00CD\u00CF\u00CD\u00CC\u00CE\u00CE\u00CC\u00CF\u00CD\u00CD\u00CC\u00CE\u00CD",
    "Signature" : "bool ________________________________________________ (uint8_t _______________________, Il2CppObject* _______________________, ________________________3931_o* _______________________, ExitGames_Client_Photon_SendOptions_o _______________________, const MethodInfo* method);",
    "TypeSignature" : "iiiiii"
*/
#pragma endregion 

#pragma region Infinite_Variables
// Variables for Infinite Portal
uint8_t PortaleventCode;
DWORD* PortalcustomEventContent;
RaiseEventOptions* PortalraiseEventOptions;
SendOptions PortalsendOptions;
DWORD* Portalmethodinfo;

// Variables for Spam Emoji's
uint8_t EmojieventCode;
DWORD* EmojicustomEventContent;
RaiseEventOptions* EmojiraiseEventOptions;
SendOptions EmojisendOptions;
DWORD* Emojimethodinfo;
#pragma endregion 

namespace Photon_Hook {
    int TotalEvents = 0;
    DWORD WINAPI Timer()
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            if (Config::Photon::EventLimiter::Shutdown)
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            Config::Photon::EventLimiter::LastIntervalTotalEvents = TotalEvents;
            TotalEvents = 0;
        }
        return 0;
    }

    void(__fastcall* OnEventFunc)(DWORD*, EventData*, DWORD*);
    void OnEvent(DWORD* __this, EventData* eventData, DWORD* methodinfo)
    {
        TotalEvents++;

        if (eventData->Code == 70)
        {
            if (Config::Photon::Block::Portals)
            {
                Logger::AddLogEntry("Blocked Portal From Spawning", LogRaiser::Behavior);
                return;
            }
        }

        #pragma region Log_Events
        // Log event information if Log Incoming Events is Enabled
        if (Config::Photon::Log::OnEvent)
        {
            if (eventData != nullptr)
            {
                Logger::AddLogEntry("> Event Code: " + std::to_string(eventData->Code) +
                    " | SenderKey: " + std::to_string(eventData->SenderKey) +
                    " | sender: " + std::to_string(eventData->sender) +
                    " | CustomDataKey" + std::to_string(eventData->CustomDataKey),
                    LogRaiser::Safety);
            }
        }
#pragma endregion

        #pragma region Anti_Event_Crash
        // Event limiter check
        if (Config::Photon::EventLimiter::Enabled &&
            TotalEvents > Config::Photon::EventLimiter::MaxEventsPerPlayer * Players::Playerlist.size() &&
            Config::Photon::EventLimiter::Detection &&
            Players::PlayerlistSize > 1) // Probably a crash
        {
            Logger::AddLogEntry("Event Crash Detected > Blocking all Events", LogRaiser::Safety);
            Config::Photon::EventLimiter::Shutdown = true;
            return;
        }

        // Handle event limiter shutdown
        if (Config::Photon::EventLimiter::Shutdown)
        {
            Config::Photon::EventLimiter::Shutdown = false;
            Logger::AddLogEntry("Event Crash Stopped > Unblocking all Events", LogRaiser::Safety);
        }

#pragma endregion 

        OnEventFunc(__this, eventData, methodinfo);
    }

    bool(__fastcall* OpRaiseEventFunc)(uint8_t, DWORD*, RaiseEventOptions*, SendOptions, DWORD*);

    #pragma region Infinite_Threads

    // Infinite thread function for refreshing Portal events
    DWORD WINAPI InfinitePortalRefresh()
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            while (PortaleventCode != NULL && PortalcustomEventContent != NULL && PortalraiseEventOptions != NULL && Config::Photon::Repeat::Portal)
            {
                OpRaiseEventFunc(PortaleventCode, PortalcustomEventContent, PortalraiseEventOptions, PortalsendOptions, Portalmethodinfo);
                std::this_thread::sleep_for(std::chrono::seconds(29));
            }
        }
        return 0;
    }

    // Infinite thread function for refreshing Emoji events
    DWORD WINAPI InfiniteEmojiRefresh()
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            while (EmojieventCode != NULL && EmojicustomEventContent != NULL && EmojiraiseEventOptions != NULL && Config::Photon::Repeat::Emoji)
            {
                OpRaiseEventFunc(EmojieventCode, EmojicustomEventContent, EmojiraiseEventOptions, EmojisendOptions, Emojimethodinfo);
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        }
        return 0;
    }
#pragma endregion 

    bool __stdcall OpRaiseEvent(uint8_t eventCode, DWORD* customEventContent, RaiseEventOptions* raiseEventOptions, SendOptions sendOptions, DWORD* methodinfo)
    {
        // Log OpRaiseEvent information if log outgoing events is enabled
        if (Config::Photon::Log::OpRaiseEvent)
        {
            Logger::AddLogEntry("OpRaiseEvent -> " + std::to_string(eventCode), LogRaiser::Photon);
        }

        #pragma region Handle_Event_Codes
        // Handle specific event codes
        switch (eventCode)
        {
        case 1:
            // Handle Voice event repetition
            if (Config::Photon::Repeat::Voice)
            {
                Logger::AddLogEntry("Sending Malformed Voice Packages When Talking!", LogRaiser::Photon);

                int index = 0;
                int amount = 5;

                while (index < amount)
                {
                    index++;
                    OpRaiseEventFunc(eventCode, customEventContent, raiseEventOptions, sendOptions, methodinfo);
                }
                return true;
            }
            break;
        case 12:
            // Handle Movement event spoofing or blocking
            if (Config::Photon::Invisible::SpoofCoords)
            {
                Logger::AddLogEntry("Spoofed Local Player", LogRaiser::Photon);
                return true;
            }
            else if (Config::Photon::Block::Movement)
            {
                Logger::AddLogEntry("Blocked Movement Event [E12]", LogRaiser::Photon);
                return true;
            }
            break;
        case 13:
            if (Config::Photon::Repeat::E13)
            {
                int index = 0;
                int amount = 50000;

                while (index < amount)
                {
                    index++;
                    OpRaiseEventFunc(eventCode, customEventContent, raiseEventOptions, sendOptions, methodinfo);
                }
            }
            break;
        case 33:
            // Block outgoing Moderations event if configured
            if (Config::Photon::Block::E33Out)
            {
                Logger::AddLogEntry("Blocked Outgoing Moderation Event [E33]", LogRaiser::Photon);
                return true;
            }
            break;
        case 70:
            // Log Portal event and set variables if configured
            Logger::AddLogEntry("[event70] Create Portal Event Sent", LogRaiser::Photon);
            if (Config::Photon::Repeat::Portal && PortalcustomEventContent == NULL)
            {
                PortaleventCode = eventCode;
                PortalcustomEventContent = customEventContent;
                PortalraiseEventOptions = raiseEventOptions;
                PortalsendOptions = sendOptions;
                Portalmethodinfo = methodinfo;
            }
            else if (!Config::Photon::Repeat::Portal)
            {
                PortalcustomEventContent = NULL;
            }
            break;
        case 71:
            // Log Emoji event and set variables if configured
            Logger::AddLogEntry("[event71] Emoji Event Sent", LogRaiser::Photon);
            if (Config::Photon::Repeat::Emoji && EmojicustomEventContent == NULL)
            {
                EmojieventCode = eventCode;
                EmojicustomEventContent = customEventContent;
                EmojiraiseEventOptions = raiseEventOptions;
                EmojisendOptions = sendOptions;
                Emojimethodinfo = methodinfo;
            }
            else if (!Config::Photon::Repeat::Emoji)
            {
                EmojicustomEventContent = NULL;
            }
        case 202:
            // Log Local Player instantiation event
            Logger::AddLogEntry("[event202] Local Player Instantiated", LogRaiser::Photon);
            break;
        }

        // Reset variables if not configured to repeat events
        if (!Config::Photon::Repeat::Portal)
        {
            PortalcustomEventContent = NULL;
        }
        if (!Config::Photon::Repeat::Emoji)
        {
            EmojicustomEventContent = NULL;
        }
#pragma endregion 

        return OpRaiseEventFunc(eventCode, customEventContent, raiseEventOptions, sendOptions, methodinfo);
    }

    bool(__fastcall* PhotonAuthenthicationFunc)(uint8_t, DWORD*, RaiseEventOptions*, SendOptions, DWORD*);
    bool __stdcall PhotonAuthenthication(uint8_t eventCode, DWORD* customEventContent, RaiseEventOptions* raiseEventOptions, SendOptions sendOptions, DWORD* methodinfo)
    {
        Logger::AddLogEntry("Photon Authenticated Server Side", LogRaiser::Photon);
        Config::Photon::EventLimiter::Detection = true;
        return PhotonAuthenthicationFunc(eventCode, customEventContent, raiseEventOptions, sendOptions, methodinfo);
    }

    void Init()
    {
        // Start the Timer thread to reset TotalEvents every 100ms
        std::thread(Timer).detach();

        // Hook OnEvent, OpRaiseEvent, PhotonAuthenthication function
        HookFunction(Address::Photon::OnEvent, OnEvent, OnEventFunc);
        HookFunction(Address::Photon::OpRaiseEvent, OpRaiseEvent, OpRaiseEventFunc);
        HookFunction(Address::Photon::PhotonAuth, PhotonAuthenthication, PhotonAuthenthicationFunc);

        // Start InfinitePortalRefresh and InfiniteEmojiRefresh threads
        std::thread(InfinitePortalRefresh).detach();
        std::thread(InfiniteEmojiRefresh).detach();
    }
}
