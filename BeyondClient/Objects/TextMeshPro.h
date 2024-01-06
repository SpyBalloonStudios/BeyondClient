#pragma once
/*

{
	  "Address": 69153712,
	  "Name": "TMPro.TextMeshProUGUI$$SetFaceColor",
	  "Signature": "void TMPro_TextMeshProUGUI__SetFaceColor (TMPro_TextMeshProUGUI_o* __this, UnityEngine_Color32_o color, const MethodInfo* method);",
	  "TypeSignature": "viii"
	},

*/

class TextMeshPro
{
public:
	DWORD* TextMeshProPointer;

	typedef DWORD* (__fastcall* SetFaceColorFunc)(DWORD*, Color32, DWORD*);
	void SetFaceColor(Color32 color)
	{
		((SetFaceColorFunc)(Address::UI::TextMeshPro::SetFaceColor))(TextMeshProPointer, color, nullptr);
	}

	TextMeshPro(DWORD* TextMeshPro)
	{
		TextMeshProPointer = TextMeshPro;
	}
};