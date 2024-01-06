#pragma once
#include "Imports.h"
#include "Xorstr.h"

#define WindowSizeX 650
#define WindowSizeY 400

struct Globals
{
	static Globals* Get()
	{
		static auto* instance = new Globals();
		return instance;
	}

	enum MenuPadge {
		MP_Home,
		MP_Custom,
		MP_Logs,
		MP_Credits
	};
	int Menu = 0;

	bool InsideConfig = false;

	bool ShowParticles = true;
	bool ShowAdvancedInfo = false;
	bool ShowTooltips = true;

	const char* RoutingName = "NtDxgkGetTrackedWorkloadStatistics";
};