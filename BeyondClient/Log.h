#pragma once


namespace Logger
{
    struct LogDetails {
        std::tm TimeStamp;
        LogRaiser Raiser;
        int Count;
        LogDetails() : Count(0) {}  // default constructor initializes count to 0
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

    void AddLogEntry(const std::string& Message, LogRaiser logRaiser = LogRaiser::Default)
    {
        if (!Config::Log::Debug && logRaiser == LogRaiser::Debug)
		{
			return;
		}

        LogDetails& details = LogMessages[Message];
        details.Count++;
        details.TimeStamp = getCurrentTime();
        details.Raiser = logRaiser;

        if (details.Count % 1000 == 1 || Config::Log::Debug)
        {
            WriteToLogFile("[" + FormatTime(details.TimeStamp) + "] [" + ToString(logRaiser) + "] [" + Message + "]");
        }


        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        printf("[");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf((FormatTime(details.TimeStamp).c_str()));
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("] [");
        printf(ToString(logRaiser).c_str());
        printf("] ");

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf(Message.c_str());
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        printf("\n");
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
}
