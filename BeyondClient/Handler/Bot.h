#pragma once

namespace AppBot
{
    std::string GetLaunchParameter(const std::string& name) {
        int argc;
        LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

        if (argv) {
            for (int i = 1; i < argc; ++i) {  // Start from 1 to skip the executable name
                std::wstring argWStr(argv[i]);
                std::string argStr(argWStr.begin(), argWStr.end());

                if (argStr.find(name) == 0) {
                    size_t pos = argStr.find('=');
                    if (pos != std::string::npos) {
                        return argStr.substr(pos + 1);
                    }
                    return argStr;
                }
            }

            LocalFree(argv);
        }

        return std::string();
    }

    void ClientThread() {
        WSADATA wsaData;
        SOCKET clientSocket;
        SOCKADDR_IN serverAddr;
        char message[1024] = { 0 };

        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            std::cerr << "Failed to initialize Winsock." << std::endl;
            return;
        }

        // Create socket
        clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Failed to create socket." << std::endl;
            WSACleanup();
            return;
        }

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(667799); // <-- Port

        if (bind(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
            std::cerr << "Bind failed." << std::endl;
            closesocket(clientSocket);
            WSACleanup();
            return;
        }

        std::cout << "Client started. Waiting for messages..." << std::endl;

        while (true) {
            memset(message, 0, sizeof(message));
            int serverAddrSize = sizeof(serverAddr);
            int bytesRead = recvfrom(clientSocket, message, sizeof(message), 0, (SOCKADDR*)&serverAddr, &serverAddrSize);
            if (bytesRead <= 0) {
                std::cerr << "Error in receiving message." << std::endl;
                break;
            }


            Logger::AddLogEntry("Received: " + std::string(message), LogRaiser::Behavior);

            std::string ReceivedMessage(message);
            if (ReceivedMessage.starts_with("attach"))
            {
                std::istringstream iss(ReceivedMessage);
                std::string DisplayName;

                std::getline(iss, DisplayName, ':');
                std::getline(iss, DisplayName, ':');

                Players::PlayerlistMutex.lock();
                for (Player Player : Players::Playerlist)
                {
                    if (!Player.isValid()) {
                        continue;
                    }

                    if (Player.DisplayName == DisplayName)
                    {
                        Players::AttachedToPlayer = Player;
                        break;
                    }
                }
                Players::PlayerlistMutex.unlock();

            }
            else if (ReceivedMessage.starts_with("deattach"))
            {
                Players::AttachedToPlayer = NULL;
            }
            else if(ReceivedMessage.starts_with("ping"))
            {
                Logger::AddLogEntry("Ping Received", LogRaiser::Local);
                std::string responseMessage = "Pong by " + Config::Menu::OwnUsername;
                if (sendto(clientSocket, responseMessage.c_str(), responseMessage.size(), 0, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
                    Logger::AddLogEntry("Error Sending Pong", LogRaiser::Local);
                }
            }
        }

        closesocket(clientSocket);
        WSACleanup();
    }
    void InitAppBot()
    {
        std::thread(ClientThread).detach();
    }
}

namespace BotSender
{
    struct ClientInfo {
        SOCKET socket;
        SOCKADDR_IN address;
    };

    std::vector<ClientInfo> clients;
    SOCKET serverSocket;
    char buffer[1024];

    void ServerThread()
    {
        WSADATA wsaData;
        SOCKADDR_IN serverAddr, clientAddr;

        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            Logger::AddLogEntry("Failed to initialize Winsock.", LogRaiser::Behavior);
            return;
        }

        serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
        if (serverSocket == INVALID_SOCKET) {
            Logger::AddLogEntry("Failed to create socket.", LogRaiser::Behavior);
            WSACleanup();
            return;
        }

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(667799); //... <-- Port

        // Bind the socket
        if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
            Logger::AddLogEntry("Bind failed.", LogRaiser::Behavior);
            closesocket(serverSocket);
            WSACleanup();
            return;
        }

        Logger::AddLogEntry("Server listening on port 667799...", LogRaiser::Behavior);


        // Receive and forward messages
        while (true) {
            memset(buffer, 0, sizeof(buffer));
            int clientAddrSize = sizeof(clientAddr);
            int bytesRead = recvfrom(serverSocket, buffer, sizeof(buffer), 0, (SOCKADDR*)&clientAddr, &clientAddrSize);
            if (bytesRead <= 0) {
                std::cerr << "Error in receiving message." << std::endl;
                break;
            }

            Logger::AddLogEntry("Received: " + std::string(buffer), LogRaiser::Behavior);

            
            ClientInfo newClient;
            newClient.socket = serverSocket;
            newClient.address = clientAddr;
            clients.push_back(newClient);
        }

        // Cleanup
        closesocket(serverSocket);
        WSACleanup();
        return;
    }

    void InitClientHandler()
    {
        std::thread(ServerThread).detach();
    }

    void SendMessageToBots(std::string Message)
    {
        for (const auto& client : clients) {
            if (sendto(serverSocket, buffer, 100, 0, (SOCKADDR*)&client.address, sizeof(client.address)) == SOCKET_ERROR) {
                Logger::AddLogEntry("Error in sending message.", LogRaiser::Behavior);
            }
        }
    }
}