#include <Windows.h>
#include "RenderHooks/renderui.h"
#include "OffsetDumper.h"

void InitConsole()
{
	AllocConsole();
	FILE* fDummy;
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONOUT$", "w", stdout);

	//SetConsoleOutputCP(CP_UTF8);
	//SetConsoleTitle(consoletitle.c_str());
	//printf("  _____ _   _     _     _   _   \n");
	//printf(" |     |_|_| |___|_|___| |_| |_ \n");
	//printf(" | | | | | . |   | | . |   |  _|\n");
	//printf(" |_|_|_|_|___|_|_|_|_  |_|_|_|  \n");
	//printf("                  |___|         \n");
	//printf("      By dll.gg & Louis_45      \n\n");

}

DWORD WINAPI main()
{
	//InitConsole();

	MH_Initialize();

	//CreateLogFile();

	//FindMethodOffsets();


	rdr::init();
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	static HANDLE hThread = nullptr;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		main();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		//if (hThread != nullptr)
		//{
		//	WaitForSingleObject(hThread, INFINITE);
		//	CloseHandle(hThread);
		//}
		break;
	}
	return TRUE;
}
