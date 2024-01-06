#pragma once
#include "imgui.h"
#include "imgui_internal.h"

#include <string>
#include <vector>
#include <functional>

#define MAX_RGB 255.0
#define HELPMARKER(str) ImGui::SameLine(); ImGui::TextColored(ImColor(220, 190, 0, 255), "(?)"); if (ImGui::IsItemHovered()) ImGui::SetTooltip(str)
#pragma warning(disable: 26812 26815)

namespace ImGuiUtils
{
	void Line(int newId)
	{
		std::string id = (XorStr("imguipp_line_") + std::to_string(newId));
		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		{
			ImGui::BeginChild(id.c_str(), ImVec2(ImGui::GetContentRegionAvail().x, 1), false);
			ImGui::Separator();
			ImGui::EndChild();
		}
		ImGui::PopStyleColor();
	}

	void Linevertical()
	{
		ImGui::SameLine();
		ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
		ImGui::SameLine();
	}

	void CenterText(const char* text, int lineId, bool separator)
	{
		if (text == nullptr)
			return;

		ImGui::Spacing();
		ImGui::SameLine((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(text).x / 2));
		ImGui::Text(text);

		if (true == separator)
			Line(lineId);
	}

	void CenterTextEx(const char* text, float width, int lineId, bool separator)
	{
		if (text == nullptr)
			return;

		ImGui::Spacing();
		ImGui::SameLine((width / 2) - (ImGui::CalcTextSize(text).x / 2));
		ImGui::Text(text);
		ImGui::Spacing();

		if (true == separator)
			Line(lineId);
	}



	void DrawTextImGui(ImVec2 position, ImColor color, const char* format, ...)
	{
		if (format == nullptr)
			return;

		char buffer[512];

		va_list  args;
		va_start(args, format);
		vsnprintf_s(buffer, sizeof(buffer), format, args);
		va_end(args);

		ImGui::GetBackgroundDrawList()->AddText(position, color, format, buffer);
	}

	void DrawCircle(ImVec2 windowSize, ImColor color, float radius, float thickness = 1)
	{
		ImGui::GetBackgroundDrawList()->AddCircle(windowSize, radius, color, 100, thickness);
	}

	float GetX()
	{
		return ImGui::GetContentRegionAvail().x;
	}

	float GetY()
	{
		return ImGui::GetContentRegionAvail().y;
	}

	ImVec4 ToVec4(float r, float g, float b, float a)
	{
		return ImVec4(r / MAX_RGB, g / MAX_RGB, b / MAX_RGB, a / MAX_RGB);
	}

	void RenderTop(std::string Text)
	{
		/*
		ImGui::BeginChild(XorStr("##TopBar"), ImVec2(ImGui::GetContentRegionAvail().x, 40), TRUE);
		ImGuiUtils::CenterText(Text.c_str(), 0, 0);
		ImGui::SameLine(0.f, 0.f);
		ImGui::EndChild();
		*/

		ImGui::BeginChild(XorStr("##TopBar"), ImVec2(ImGui::GetContentRegionAvail().x, 40), TRUE);
		//ImGuiPP::CenterText("Beyond Launcher", 0, 0);
		ImGui::SetCursorPos(ImVec2(5, (40 / 2) - (ImGui::CalcTextSize(Text.c_str()).y / 2)));
		ImGui::Text(Text.c_str());


		ImGui::SetWindowFontScale(0.4f);
		ImGui::SetCursorPos(ImVec2(ImGui::GetContentRegionAvail().x - 35, 19));
		ImGui::Text(XorStr(ICON_FA_MINUS));

		ImGui::SetCursorPos(ImVec2(ImGui::GetContentRegionAvail().x - 10, 17));
		ImGui::Text(XorStr(ICON_FA_TIMES));
		if (ImGui::IsItemClicked())
		{
			exit(0);
		}

		ImGui::SetWindowFontScale(1.f);

		ImGui::EndChild();

	}

	void RenderCloseIcon(ImVec4 Color)
	{
		ImGui::SetCursorPos(ImVec2(ImGui::GetContentRegionAvail().x - 45, 23));
		ImGui::PushStyleColor(ImGuiCol_Text, Color);
		ImGui::Text(ICON_FA_TIMES_CIRCLE);
		if (ImGui::IsItemClicked())
		{
			exit(0);
		}
		ImGui::PopStyleColor();
	}

	void RenderMenuTab(std::string Label, Globals::MenuPadge MenuPadge, ImVec2 Size)
	{
		ImGui::SetWindowFontScale(0.9f);
		ImGui::PushStyleColor(ImGuiCol_Button, Globals::Get()->Menu == MenuPadge ? ImVec4(0.14f, 0.13f, 0.16f, 1.00f) : ImVec4(0.10f, 0.09f, 0.12f, 1.00f));
		if (ImGui::Button(Label.c_str(), Size))
		{
			Globals::Get()->Menu = MenuPadge;
			Globals::Get()->InsideConfig = false;
		}
		ImGui::PopStyleColor();
		ImGui::SetWindowFontScale(1.f);
	}

	bool ShouldRenderPadge(Globals::MenuPadge MenuPadge)
	{
		if (Globals::Get()->Menu == MenuPadge && !Globals::Get()->InsideConfig)
		{
			return true;
		}
		return false;
	}
}