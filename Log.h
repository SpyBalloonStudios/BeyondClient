#pragma once
#include <ctime>
#include <unordered_map>
#include <sstream>
#include <filesystem>


namespace Logger
{
    std::string DumpContent;

    enum class LogRaiser {
        Error, Success, Info, Cleaner, Dumper, Important
    };

    static std::string ToString(LogRaiser category) {
        switch (category) {
        case LogRaiser::Error: return XorStr("-");
        case LogRaiser::Success:  return XorStr("+");
        case LogRaiser::Info: return XorStr("#");
        case LogRaiser::Cleaner: return XorStr("Cleaner");
        case LogRaiser::Dumper: return XorStr("Dumper");
        case LogRaiser::Important: return XorStr("Important");
        default:                     return XorStr("*");
        }
    }

    struct LogDetails {
        std::tm TimeStamp;
        LogRaiser Raiser;
        int Count;
        LogDetails() : Count(0) {}
    };

    std::unordered_map<std::string, LogDetails> LogMessages;

    std::string FormatTimeValue(int value) {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << value;
        return oss.str();
    }

    std::string FormatTime(std::tm timeInfo) {
        return FormatTimeValue(timeInfo.tm_hour) + ":" +
            FormatTimeValue(timeInfo.tm_min) + ":" +
            FormatTimeValue(timeInfo.tm_sec);
    }

    std::tm getCurrentTime() {
        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm timeInfo;
        localtime_s(&timeInfo, &currentTime);
        return timeInfo;
    }

    void AddLogEntry(const std::string& Message, LogRaiser logRaiser = LogRaiser::Info)
    {
        LogDetails& details = LogMessages[Message];
        details.Count++;
        details.TimeStamp = getCurrentTime();
        details.Raiser = logRaiser;

        DumpContent += Message + "\n";
    }

    std::vector<std::pair<std::string, LogDetails>> GetSortedLogMessages() {
        std::vector<std::pair<std::string, LogDetails>> sortedLogs(LogMessages.begin(), LogMessages.end());
        std::sort(sortedLogs.begin(), sortedLogs.end(),
            [](const auto& a, const auto& b) {
                std::tm tm_a = a.second.TimeStamp;
                std::tm tm_b = b.second.TimeStamp;
                return mktime(&tm_a) < mktime(&tm_b);
            }
        );
        return sortedLogs;
    }

    std::string GetCurrentDate() {
        time_t now = time(0);
        struct tm localTime;
        localtime_s(&localTime, &now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), XorStr("%Y-%m-%d"), &localTime);
        return std::string(buffer);
    }

    void Dump(const std::string& content) {
        CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
        OPENFILENAME ofn;
        char szFileName[MAX_PATH] = "";

        ZeroMemory(&ofn, sizeof(OPENFILENAME));
        ofn.lStructSize = sizeof(OPENFILENAME);
        ofn.hwndOwner = NULL;
        ofn.lpstrFilter = XorStr("Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0");
        ofn.lpstrFile = szFileName;
        ofn.nMaxFile = MAX_PATH;
        ofn.lpstrDefExt = XorStr("txt");
        ofn.Flags = OFN_OVERWRITEPROMPT | OFN_CREATEPROMPT;

        if (GetSaveFileName(&ofn)) {
            std::string filename = ofn.lpstrFile;
            filename += XorStr("_Error-Dump_") + GetCurrentDate() + XorStr(".txt");
            std::ofstream outputFile(filename);

            if (outputFile.is_open()) {
                outputFile << content;
                outputFile.close();
                AddLogEntry(XorStr("Successfully Dumped Errors"), LogRaiser::Dumper);
            }
            else {
                AddLogEntry(XorStr("Unable to open file for writing"), LogRaiser::Dumper);
            }
        }
        else {
            AddLogEntry(XorStr("File dialog canceled"), LogRaiser::Dumper);
        }

        CoUninitialize();
    }

}
