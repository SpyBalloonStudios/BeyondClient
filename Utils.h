#include "Imports.h"
#include "XorStr.h"

using namespace std;
std::string GetSlogan() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	std::vector<std::string> slogans = {
		XorStr("Always on Top"),
		XorStr("Embrace the chaos"),
		XorStr("To Infinity"),
		XorStr("Life's a game; play it your way"),
		XorStr("Stands Supreme"),
		XorStr("Unleash the possibilities"),
		XorStr("Dare to dream big"),
		XorStr("Redefine your limits"),
		XorStr("Ignite the passion within"),
		XorStr("Create your destiny"),
		XorStr("Innovate, Inspire, Ignite"),
		XorStr("Elevate your existence"),
		XorStr("Chase your dreams with determination"),
		XorStr("Forge your own path"),
		XorStr("Discover the extraordinary"),
		XorStr("Strive for greatness"),
		XorStr("Leave a legacy"),
		XorStr("Master your fate"),
		XorStr("Transform challenges into opportunities"),
		XorStr("Beyond Meat Lmao xD"),
		XorStr("No Bitches?"),
	};

	int randomIndex = std::rand() % slogans.size();
	return slogans[randomIndex];
}

PVOID GetDllByFile(const char* FilePath)
{
	HANDLE h_dll = CreateFileA(FilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h_dll == INVALID_HANDLE_VALUE)
		return NULL;

	DWORD dll_file_sz = GetFileSize(h_dll, NULL);
	PVOID dll_buffer = VirtualAlloc(NULL, dll_file_sz, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	if (!ReadFile(h_dll, dll_buffer, dll_file_sz, NULL, FALSE) || *(PDWORD)dll_buffer != 9460301)
	{
		VirtualFree(dll_buffer, 0, MEM_RELEASE);
		goto exit;
	}

exit:
	CloseHandle(h_dll);
	return dll_buffer;
}

PVOID GetDllByVector(const std::vector<uint32_t>& dllData)
{
	if (dllData.empty())
		return NULL;

	PVOID dll_buffer = VirtualAlloc(NULL, dllData.size() * sizeof(uint32_t), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	if (!dll_buffer)
		return NULL;

	memcpy(dll_buffer, dllData.data(), dllData.size() * sizeof(uint32_t));
	if (*(PDWORD)dll_buffer != 9460301)
	{
		VirtualFree(dll_buffer, 0, MEM_RELEASE);
		return NULL;
	}

	return dll_buffer;
}

DWORD GetVRChat(PDWORD p_thread_id)
{
	DWORD PID = 0;
	*p_thread_id = GetWindowThreadProcessId(FindWindowA(nullptr, XorStr("VRChat")), &PID);
	return PID;
}