#pragma once


class Unity
{
	public:
		typedef void(__fastcall* SetTimeScaleFunc)(float, uintptr_t);
		void SetTimescale(bool Log = true)
		{
			if (Log)
			{
				Logger::AddLogEntry("Timescale Set to " + std::to_string(Config::Unity::Timescale), LogRaiser::Local);
				ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[/] Timescale set to " + std::to_string(Config::Unity::Timescale)).c_str(), "" });

			}
			((SetTimeScaleFunc)Address::Unity::SetTime)(Config::Unity::Timescale, 0);
		}

		typedef void(__fastcall* SetGravityFunc)(uintptr_t, uintptr_t);
		void SetGravity(Vector3 Gravity, bool Log = true)
		{
			if (Log)
			{
				printf("Gravity Set to %f\n", Config::Unity::Gravity);
				Logger::AddLogEntry("Gravity set to " + Gravity.ToString(), LogRaiser::Local);
				ImGui::InsertNotification({ ImGuiToastType_Info, 3000, ("[/] Gravity set to " + Gravity.ToString()).c_str(), "" });
			}
			((SetGravityFunc)Address::Unity::SetGravity)(reinterpret_cast<uintptr_t>(&Gravity), 0);
		}
		void SetGravity(bool Log = true)
		{
			SetGravity(Vector3(0, Config::Unity::Gravity, 0), Log);
		}

		typedef bool(__fastcall* isFocusedFunc)(DWORD*);
		bool isFocused()
		{
			return ((isFocusedFunc)Address::Unity::SetTime)(nullptr);
		}

		typedef float(__fastcall* GetDeltaTimeFunc)(DWORD*);
		float GetDeltaTime()
		{
			return ((GetDeltaTimeFunc)Address::Unity::GetDeltaTime)(nullptr);
		}

		int CalculateFps(float DeltaTime)
		{
			return (1.0f / DeltaTime);
		}
};