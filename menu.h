#pragma once
#include "Imports.h"
#include "globals.h"
#include "Xorstr.h"

namespace Menu
{
	static ImVec4 active = ImVec4(219 / 255.f, 190 / 255.f, 0, 255);
	static ImVec4 inactive = ImVec4(255 / 255.f, 255 / 255.f, 255 / 255.f, 255);
	static ImVec2 CenterSize = ImVec2(300, 200);
	static ImVec2 ButtonSize = ImVec2(90, 25);


	static bool initialized = false;
	static string Slogan;

	static float glow = 0.078;
	static float glowstep = 0.0003;
	static bool increasingglow = true;

	static const ImVec4 RED_COLOR = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	static const ImVec4 BLUE_COLOR = ImVec4(0.0f, 0.0f, 1.0f, 1.0f);
	static const ImVec4 GREEN_COLOR = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);

	void Theme();
	void Render();
	void UpdateCircles(float deltaTime);
	void RenderCircles();
	void InitCircles();
	void UpdateLoop();
}