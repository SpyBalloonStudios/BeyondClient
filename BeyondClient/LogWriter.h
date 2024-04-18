namespace fs = std::filesystem;

std::string LogFile;
std::mutex LogFileMutex;

void CreateLogFile()
{
    if (!Config::Log::File::Enabled) return;
    fs::create_directory("ecbase");

    std::time_t currentTime = std::time(0);
    std::tm* now = std::localtime(&currentTime);

    char timestamp[20];
    std::string fileName;
    if (Config::Log::File::UseSingle)
    {
        fileName = "output_log";
    } else {
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", now);
        fileName = "output_log_" + std::string(timestamp);
    }
    LogFile = "ecbase/" + fileName + ".txt";

    std::ofstream outputFile(LogFile);

    if (outputFile.is_open())
    {
        outputFile.close();
    }
}

void WriteToLogFile(const std::string& inputString)
{
    if (!Config::Log::File::Enabled) return;
    LogFileMutex.lock();
    std::ofstream outputFile(LogFile, std::ios::app);

    if (outputFile.is_open())
    {
        outputFile << inputString << std::endl;
        outputFile.close();
    }
    LogFileMutex.unlock();
}