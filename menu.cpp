#include "menu.h"
#include "ImGuiUtils.h"
#include "Injector.h"

#include "Log.h"
#include <string>

#include "Definitions.h"
using namespace Definitions;

struct Circle {
	ImVec2 position;
	float radius;
	ImVec4 color;
	float glow;
	float velocity;
	float lifeTimer;
};

const int NUM_CIRCLES = 1000;
Circle circles[NUM_CIRCLES];
int ParticleSpeed = 5;

#include "dll/dlldata.h"

#ifdef DEBUG
std::string openFileDialog() {
	OPENFILENAMEA ofn;
	CHAR szFile[MAX_PATH] = { 0 };

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile) / sizeof(*szFile);
	ofn.lpstrFilter = XorStr("Dynamic Link Libraries (*.dll)\0*.dll\0All Files (*.*)\0*.*\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileNameA(&ofn) == TRUE) {
		return std::string(szFile);
	}
	else {
		return "N/A";
	}
}
#endif


void Menu::UpdateCircles(float deltaTime) {
	for (int i = 0; i < NUM_CIRCLES; ++i) {
		Circle& circle = circles[i];

		circle.position.y += circle.velocity * deltaTime;

		if (circle.position.y > 1900.0f) {
			circle.position.y = -circle.radius;
			circle.position.x = static_cast<float>(rand() % 1800);
			circle.velocity = static_cast<float>(rand() % 100 + 50) / 100.0f;
			circle.lifeTimer = 0.0f;
		}
	}
}

void Menu::RenderCircles() {
	for (int i = 0; i < NUM_CIRCLES; ++i) {
		Circle& circle = circles[i];

		circle.glow = fmaxf(0.0f, fminf(circle.glow + ((rand() % 200) - 100) / 1000.0f, 1.0f));

		ImGui::GetWindowDrawList()->AddCircleFilled(
			circle.position,
			circle.radius,
			IM_COL32(
				static_cast<int>(circle.color.x * 255 * circle.glow),
				static_cast<int>(circle.color.y * 255 * circle.glow),
				static_cast<int>(circle.color.z * 255 * circle.glow),
				static_cast<int>(circle.color.w * 255)
			)
		);
	}
}

void Menu::InitCircles()
{
	for (int i = 0; i < NUM_CIRCLES; ++i) {
		circles[i].position = ImVec2(static_cast<float>(rand() % 1900), static_cast<float>(rand() % 1800));
		circles[i].radius = static_cast<float>(rand() % 2 + 1);
		circles[i].color = ImVec4(static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, 1.0f);
		circles[i].glow = 0.0f;
		circles[i].velocity = static_cast<float>(rand() % 100 + 50) / 100.0f;  // Different downward velocity
		circles[i].lifeTimer = 0.0f;
	}
}

void Menu::UpdateLoop()
{
	while (true)
	{
		UpdateCircles(1);
		Sleep(10);
	}
}

void Menu::Render()
{
	static auto G = Globals::Get();
	static float TextPos = ImGui::GetContentRegionAvail().y;

#ifdef DEBUG
	static string CustomPath = XorStr("N/A");
#endif

	if (!initialized)
	{
		InitCircles();
		std::thread(UpdateLoop).detach();

		initialized = true;
		Slogan = GetSlogan();
	}

	if (G->ShowParticles)
	{
		//UpdateCircles(1);
		RenderCircles();
	}

#ifdef DEBUG
	ImGuiUtils::RenderTop(XorStr("Beyond Launcher [Debug]"));
#endif

#ifndef DEBUG
	ImGuiUtils::RenderTop(XorStr("Beyond Launcher"));
#endif

	//ImGuiUtils::RenderCloseIcon(ImVec4((50 + (glow * 2)) / 255.f, (50 + (glow * 2)) / 255.f, (50 + (glow * 2)) / 255.f, (255 / 255.f)));

	ImGuiUtils::RenderMenuTab(XorStr("Home"), Globals::MP_Home, ButtonSize);

#ifdef DEBUG
	ImGui::SameLine();
	ImGuiUtils::RenderMenuTab(XorStr("Custom"), Globals::MP_Custom, ButtonSize);
#endif

	ImGui::SameLine();
	ImGuiUtils::RenderMenuTab(XorStr("Logs"), Globals::MP_Logs, ButtonSize);

	ImGui::SameLine();
	ImGuiUtils::RenderMenuTab(XorStr("Credits"), Globals::MP_Credits, ButtonSize);
	

	if (ImGuiUtils::ShouldRenderPadge(Globals::MP_Home))
	{
		ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (CenterSize.x / 2), (ImGui::GetContentRegionAvail().y / 2) - (CenterSize.y / 2) + 45));
		ImGui::BeginChild(XorStr("##Center"), CenterSize, TRUE);
		ImGuiUtils::CenterText(XorStr("Welcome to Beyond"), 0, 0);

		ImGui::SetWindowFontScale(0.9f);
		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(52, 52, 52, 255));
		ImGuiUtils::CenterText(Slogan.c_str(), 0, 0);
		ImGui::PopStyleColor();
		ImGui::SetWindowFontScale(1.f);


		ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ButtonSize.x / 2), 150));
		if (ImGui::Button(XorStr("Inject"), ButtonSize))
		{
			G->Menu = G->MP_Logs;
			Injection_Info __IInfo;
			__IInfo.FromVector = true;
			__IInfo.RawData = RawDllData;

			std::thread Inject(Injector::InjectDll, __IInfo);
			Inject.detach();
		}

		ImGui::EndChild();
	}
#ifdef DEBUG
	else if (ImGuiUtils::ShouldRenderPadge(Globals::MP_Custom))
	{
		ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (CenterSize.x / 2), (ImGui::GetContentRegionAvail().y / 2) - (CenterSize.y / 2) + 45));
		ImGui::BeginChild(XorStr("##Center"), CenterSize, TRUE);
		ImGuiUtils::CenterText(XorStr("Custom"), 0, 0);

		ImGui::SetWindowFontScale(0.9f);
		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(52, 52, 52, 255));
		ImGuiUtils::CenterText(CustomPath.c_str(), 0, 0);
		ImGui::PopStyleColor();
		ImGui::SetWindowFontScale(1.f);

		ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ButtonSize.x / 2), 110));
		if (ImGui::Button(XorStr("Select"), ButtonSize))
		{
			CustomPath = openFileDialog();
		}

		ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ButtonSize.x / 2), 150));
		if (ImGui::Button(XorStr("Inject"), ButtonSize))
		{
			if (CustomPath != XorStr("N/A"))
			{
				G->Menu = G->MP_Logs;
				Injection_Info __IInfo;
				__IInfo.FromPath = true;
				__IInfo.Path = CustomPath.c_str();

				std::thread Inject(Injector::InjectDll, __IInfo);
				Inject.detach();
			}
		}

		ImGui::EndChild();
	}
#endif

	else if (ImGuiUtils::ShouldRenderPadge(Globals::MP_Logs))
	{
		ImGui::SetWindowFontScale(0.9f);
		ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - ((CenterSize.x * 1.7) / 2), (ImGui::GetContentRegionAvail().y / 2) - (CenterSize.y / 2) + 45));
		ImGui::BeginChild(XorStr("##Logs"), ImVec2(CenterSize.x * 1.7, CenterSize.y), true);
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.4f, 0.4f, 0.4f, 1.0f));
		for (auto& pair : Logger::GetSortedLogMessages())
		{

			const std::string& Message = pair.first;
			const Logger::LogDetails& details = pair.second;

			std::string TimeStamp = Logger::FormatTime(details.TimeStamp);
			Logger::LogRaiser logRaiser = details.Raiser;

			ImVec4 color = ImVec4(70.0f / 255.0f, 67.0f / 255.0f, 70.0f / 255.0f, 1.0f); // Default color
			if (logRaiser == Logger::LogRaiser::Error)
				color = ImVec4(1.f, 0.f, 0.f, 1.f);
			else if (logRaiser == Logger::LogRaiser::Success)
				color = ImVec4(0.f, 1.f, 0.f, 1.f);
			else if (logRaiser == Logger::LogRaiser::Cleaner)
				color = ImVec4(0.f, 0.f, 1.f, 1.f);
			else if (logRaiser == Logger::LogRaiser::Dumper)
				color = ImVec4(0.5f, 0.0f, 0.0f, 1.0f);
			else if (logRaiser == Logger::LogRaiser::Important)
				color = ImVec4(0.5f, 0.0f, 0.0f, 1.0f);
			else if (logRaiser == Logger::LogRaiser::Info)
				color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);

			ImGui::Text(XorStr("["));
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("%s"), TimeStamp.c_str());
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::Text(XorStr("]"));

			ImGui::SameLine();
			ImGui::Text(XorStr("["));
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::TextColored(color, Logger::ToString(logRaiser).c_str());
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::Text(XorStr("]"));

			ImGui::SameLine();
			ImGui::TextColored(ImVec4(0.4f, 0.4f, 0.4f, 1.0f), XorStr("%s"), Message.c_str());

			if (details.Count > 1)
			{
				ImGui::SameLine();
				ImGui::Text(XorStr("(%dx)"), details.Count);
			}

			ImGui::SetScrollHereY(1.0f);
		}
		ImGui::PopStyleColor();
		ImGui::EndChild();

		ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - ((CenterSize.x * 1.7) / 2), (ImGui::GetContentRegionAvail().y / 2) - (((CenterSize.y / 6.f) - 6) / 2) + 280));
		ImGui::BeginChild(XorStr("##ConsoleInput"), ImVec2(CenterSize.x * 1.7, (CenterSize.y / 6.f) - 6), false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
		static char buffer[10] = ".help";
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0);

		ImGui::SetNextItemWidth(CenterSize.x * 1.8);
		ImGui::SetCursorPosY(0);
		ImGui::SetCursorPosX(0);
		if (ImGui::InputText(XorStr("##CInput"), buffer, sizeof(buffer), ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_NoHorizontalScroll))
		{
			const string msg = buffer;
			if (msg == XorStr(".help"))
			{
				Logger::AddLogEntry(msg, Logger::LogRaiser::Success);
				Sleep(200);
				Logger::AddLogEntry(XorStr(".help  -- to show this menu"), Logger::LogRaiser::Info);
				Sleep(20);
				Logger::AddLogEntry(XorStr(".dump  -- to dump all errors into a .txt file"), Logger::LogRaiser::Info);
				Sleep(20);
				Logger::AddLogEntry(XorStr(".cls   -- to clear this window"), Logger::LogRaiser::Info);

			}
			else if (msg == XorStr(".dump"))
			{
				Logger::AddLogEntry(msg, Logger::LogRaiser::Success);
				Sleep(20);
				Logger::Dump(Logger::DumpContent);
			}
			else if (msg == XorStr(".cls"))
			{
				Logger::LogMessages.clear();
				Logger::AddLogEntry(msg, Logger::LogRaiser::Success);
				Sleep(20);
			}
			else if (msg != "")
			{
				Logger::AddLogEntry((msg + XorStr(" << Is A Invalid Command")), Logger::LogRaiser::Error);
				Sleep(20);
			}

			buffer[0] = '\0';
			ImGui::SetKeyboardFocusHere(-1);
		}

		ImGui::PopStyleVar();

		ImGui::EndChild();
		ImGui::SetWindowFontScale(1.f);
	}

	else if (ImGuiUtils::ShouldRenderPadge(Globals::MP_Credits))
	{
		if (-1120.f > TextPos)
		{
			TextPos = ImGui::GetContentRegionAvail().y;
		}
		else {
			TextPos -= 0.6f;
		}

		if (TextPos > 80.f)
		{
			ImGui::SetWindowFontScale(1.2f);
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Beyond Credits")).x / 2), TextPos));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Beyond Credits"));
			ImGui::SetWindowFontScale(1.f);
		}

		if (TextPos + 300 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Made By dll.gg")).x / 2), TextPos + 300));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Made By dll.gg"));
		}

		if (TextPos + 340 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Special Thanks to")).x / 2), TextPos + 380));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Special Thanks to"));
		}

		if (TextPos + 360 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Louis45 - For Helping Me Develop This SHit")).x / 2), TextPos + 400));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Louis45 -"));
			ImGui::SameLine(0.f, 0.f);
			ImGui::Text(XorStr(" For Helping Me Develop This SHit"));
		}

		if (TextPos + 380 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("JustCosmic - For Leaking The Beta")).x / 2), TextPos + 420));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("JustCosmic -"));
			ImGui::SameLine(0.f, 0.f);
			ImGui::Text(XorStr(" For Leaking The Beta"));
		}

		if (TextPos + 400 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("None - For Being Nice")).x / 2), TextPos + 440));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("None -"));
			ImGui::SameLine(0.f, 0.f);
			ImGui::Text(XorStr(" For Being Nice"));
		}

		if (TextPos + 420 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Asuka - Forgot :>")).x / 2), TextPos + 460));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Asuka -"));
			ImGui::SameLine(0.f, 0.f);
			ImGui::Text(XorStr(" Forgot :>"));
		}

		if (TextPos + 600 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Random Shoutouts")).x / 2), TextPos + 600));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Random Shoutouts"));
		}

		if (TextPos + 620 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Notixe - For Giving Me Discord Nitro for 4 Months")).x / 2), TextPos + 620));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Notixe -"));
			ImGui::SameLine(0.f, 0.f);
			ImGui::Text(XorStr(" For Giving Me Discord Nitro for 4 Months"));
		}

		if (TextPos + 640 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("GREEEN - For Feedback")).x / 2), TextPos + 640));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("GREEEN -"));
			ImGui::SameLine(0.f, 0.f);
			ImGui::Text(XorStr(" For Feedback"));
		}

		if (TextPos + 660 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Nightking - For Helping Me Debug Errors")).x / 2), TextPos + 660));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Nightking -"));
			ImGui::SameLine(0.f, 0.f);
			ImGui::Text(XorStr(" For Helping Me Debug Errors"));
		}

		if (TextPos + 740 > 80.f)
		{
			ImGui::SetWindowFontScale(1.1f);
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Beta Testers")).x / 2), TextPos + 760));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Beta Testers"));
			ImGui::SetWindowFontScale(1.0f);
		}

		if (TextPos + 780 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Barcode")).x / 2), TextPos + 780));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr(("Barcode")));
		}

		if (TextPos + 800 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("JustCosmic")).x / 2), TextPos + 800));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("JustCosmic"));
		}

		if (TextPos + 820 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Louis45")).x / 2), TextPos + 820));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Louis45"));
		}

		if (TextPos + 840 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("GREEEN")).x / 2), TextPos + 840));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("GREEEN"));
		}

		if (TextPos + 860 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("FakeRiley")).x / 2), TextPos + 860));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("FakeRiley"));
		}

		if (TextPos + 880 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Aogmax")).x / 2), TextPos + 880));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Aogmax"));
		}

		if (TextPos + 900 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("None")).x / 2), TextPos + 900));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("None"));
		}

		if (TextPos + 920 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("timefireyt")).x / 2), TextPos + 920));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("timefireyt"));
		}

		if (TextPos + 940 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("MrHappy")).x / 2), TextPos + 940));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("MrHappy"));
		}

		if (TextPos + 960 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Mxgazine")).x / 2), TextPos + 960));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Mxgazine"));
		}

		if (TextPos + 980 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Foonix")).x / 2), TextPos + 980));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Foonix"));
		}

		if (TextPos + 1000 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Notixe")).x / 2), TextPos + 1000));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Notixe"));
		}

		if (TextPos + 1020 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Yui")).x / 2), TextPos + 1020));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Yui"));
		}

		if (TextPos + 1040 > 80.f)
		{
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("Lucy")).x / 2), TextPos + 1040));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("Lucy"));
		}

		if (TextPos + 1120 > 80.f)
		{
			ImGui::SetWindowFontScale(1.1f);
			ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(XorStr("And Many Many More Because the Beta got leaked...")).x / 2), TextPos + 1080));
			ImGui::TextColored(ImVec4(169.0f / 255.0f, 110.0f / 255.0f, 241.0f / 255.0f, 1.0f), XorStr("And Many Many More Because the Beta got leaked..."));
			ImGui::SetWindowFontScale(1.f);
		}
	}

	if(G->InsideConfig)
	{
		ImGui::SetCursorPos(ImVec2((ImGui::GetContentRegionAvail().x / 2) - (CenterSize.x / 2), (ImGui::GetContentRegionAvail().y / 2) - (CenterSize.y / 2) + 45));
		ImGui::BeginChild(XorStr("##Center"), CenterSize, TRUE);
		ImGuiUtils::CenterText(XorStr("Config"), 0, 0);

		ImGui::SetWindowFontScale(0.85f);
		ImGui::Selectable(XorStr("Particles"), &G->ShowParticles);
		ImGui::SameLine();
		if (G->ShowParticles)
			ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), XorStr("ON"));
		else
			ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), XorStr("OFF"));

		if (G->ShowTooltips)
		{
			HELPMARKER(XorStr("Shows/Hides The Particles")); 
		}

		ImGui::Selectable(XorStr("Advanced Info"), &G->ShowAdvancedInfo);
		ImGui::SameLine();
		if (G->ShowAdvancedInfo)
			ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), XorStr("ON"));
		else
			ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), XorStr("OFF"));

		if (G->ShowTooltips)
		{
			HELPMARKER(XorStr("Great for Debugging"));
		}

		ImGui::Selectable(XorStr("Helpfull Tooltips"), &G->ShowTooltips);
		ImGui::SameLine();
		if (G->ShowTooltips)
			ImGui::TextColored(ImVec4(0.f, 1.f, 0.24f, 1.f), XorStr("ON"));
		else
			ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), XorStr("OFF"));

		if (G->ShowTooltips)
		{
			HELPMARKER(XorStr("This"));
		}

		ImGui::SetWindowFontScale(1.0f);
		ImGui::EndChild();
	}
	ImGui::SetCursorPos(ImVec2(5, 377));
	ImGui::PushStyleColor(ImGuiCol_Text, G->InsideConfig  ? ImVec4(0.24f, 0.23f, 0.29f, 1.00f) : ImVec4(52 / 255.f, 52 / 255.f, 52 / 255.f, 1.00f));
	ImGui::Text(ICON_FA_COG);
	if(ImGui::IsItemClicked())
	{
		G->InsideConfig = !G->InsideConfig;
	}
	ImGui::PopStyleColor();
}

void Menu::Theme()
{
	if (increasingglow) {
		glow += glowstep;
		if (glow >= 0.110) {
			increasingglow = false;
		}
	}
	else {
		glow -= glowstep;
		if (glow <= 0.078) {
			increasingglow = true;
		}
	}

	ImGuiStyle& Style = ImGui::GetStyle();
	auto Color = Style.Colors;
	
	Style.WindowMinSize     = ImVec2(WindowSizeX, WindowSizeY);
	Style.WindowBorderSize  = 0;

	Style.ChildRounding     = 5;
	Style.FrameRounding     = 5;
	Style.ScrollbarRounding = 0;
	Style.GrabRounding		= 0;
	Style.PopupRounding		= 0;
	Style.WindowRounding	= 3;


	Color[ImGuiCol_WindowBg]            = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	
	Color[ImGuiCol_FrameBg]		        = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	Color[ImGuiCol_FrameBgActive]       = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	Color[ImGuiCol_FrameBgHovered]      = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);

	Color[ImGuiCol_Button]	            = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	Color[ImGuiCol_ButtonActive]        = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	Color[ImGuiCol_ButtonHovered]       = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);

	Color[ImGuiCol_Border] = ImVec4(glow, glow, glow, 255);
	Color[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);


	Color[ImGuiCol_Separator]           = ImColor(36, 36, 36, 255);

	Color[ImGuiCol_ResizeGrip]		    = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	Color[ImGuiCol_ResizeGripActive]    = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	Color[ImGuiCol_ResizeGripHovered]   = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);

	Color[ImGuiCol_ChildBg]			    = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

	Color[ImGuiCol_ScrollbarBg]         = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrab]       = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);
	Color[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);

	Color[ImGuiCol_Header]			    = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	Color[ImGuiCol_HeaderActive]	    = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	Color[ImGuiCol_HeaderHovered]       = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	Color[ImGuiCol_CheckMark]		    = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);

	Color[ImGuiCol_Text]				= ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	Color[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);


	Color[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	Color[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	Color[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);

	Color[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	Color[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	Color[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);

	Color[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	Color[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	Color[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	Color[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

	Color[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	Color[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

	Color[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	Color[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	Color[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	Color[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);

	Color[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
}

