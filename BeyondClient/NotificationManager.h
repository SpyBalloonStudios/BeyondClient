#pragma once

class NotificationManager {
    public:
        struct Notification {
            std::string message;
            float duration; // Duration in seconds
            float startTime;
        };

        void ShowNotification(const std::string& message, float duration) {
            Notification notification{ message, duration, ImGui::GetTime() };
            notifications.push_back(notification);
        }

        void Update() {
            // Iterate through notifications and remove expired ones
            auto currentTime = ImGui::GetTime();
            notifications.erase(std::remove_if(notifications.begin(), notifications.end(), [currentTime](const Notification& notification) {
                return (currentTime - notification.startTime >= notification.duration);
                }), notifications.end());
        }

        void Render() {
            for (const auto& notification : notifications) {
                // Calculate position, e.g., lower center
                ImVec2 screenSize = ImGui::GetIO().DisplaySize;
                ImVec2 notificationSize(300, 70); // Fixed width and height for the notification window
                ImVec2 notificationPos((screenSize.x - notificationSize.x) / 2, screenSize.y - notificationSize.y - 20);

                ImGui::SetNextWindowPos(notificationPos);
                ImGui::SetNextWindowSize(notificationSize);
                ImGui::Begin("Notification", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar);

                // Show the message
                ImGui::TextWrapped("%s", notification.message.c_str());

                // Calculate progress (from 0.0 to 1.0) based on remaining time
                float progress = 1.0f - ((ImGui::GetTime() - notification.startTime) / notification.duration);
                ImGui::ProgressBar(progress, ImVec2(-1, 0), "");

                ImGui::End();
            }
        }
    private:
        std::vector<Notification> notifications;
};

NotificationManager notificationManager;