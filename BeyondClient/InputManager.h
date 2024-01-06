#pragma once

namespace InputManager {
	typedef void(__fastcall* EnableObjectHighlight_Gamebject_o)(DWORD*, bool, DWORD*);
	void EnableObjectHighlight_Gamebject(DWORD* Gameobject, bool enable)
	{
		((EnableObjectHighlight_Gamebject_o)(Address::InputManager::EnableObjectHighlight_Gamebject))(Gameobject, enable, nullptr);
	}

	typedef void(__fastcall* EnableObjectHighlight_Renderer_o)(DWORD*, bool, DWORD*);
	void EnableObjectHighlight_Renderer(DWORD* Renderer, bool enable)
	{
		((EnableObjectHighlight_Renderer_o)(Address::InputManager::EnableObjectHighlight_Renderer))(Renderer, enable, nullptr);
	}
}