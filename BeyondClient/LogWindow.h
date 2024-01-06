#pragma once

class LogWindow {
    private:
        std::deque<std::pair<std::string, ImVec4>> messages;
        int maxMessages;
    public:
        LogWindow() : maxMessages(10) {}

        void AddLog(const std::string& logSource, const std::string& logMessage, ImVec4 textColor) {
            std::string logEntry = "[" + logSource + "] " + logMessage;
            messages.push_back(std::make_pair(logEntry, textColor));

            // Keep the number of messages within the specified limit
            while (messages.size() > maxMessages) {
                messages.pop_front();
            }
        }

        void Render() {
            ImVec2 screenSize = ImGui::GetIO().DisplaySize;
            ImVec2 windowSize(screenSize.x * 0.8f, 0); // Use 80% of the screen width
            ImVec2 windowPos((screenSize.x - windowSize.x) / 2, screenSize.y - 30); // 30 pixels above the bottom edge

            ImGui::SetNextWindowPos(windowPos);
            ImGui::SetNextWindowSize(windowSize);
            ImGui::Begin("Notification", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground);

            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

            ImVec4 Color = ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f);

            for (const auto& message : messages) {
                ImGui::TextColored(Color, "%s", message.first.c_str());
            }

            ImGui::PopStyleVar();

            ImGui::End();
        }
};