#pragma once

/*

 {
	  "Address": 8250416,
	  "Name": "UnityEngine.UI.Text$$get_text",
	  "Signature": "System_String_o* UnityEngine_UI_Text__get_text (UnityEngine_UI_Text_o* __this, const MethodInfo* method);",
	  "TypeSignature": "iii"
	},
	{
	  "Address": 61529760,
	  "Name": "UnityEngine.UI.Text$$set_text",
	  "Signature": "void UnityEngine_UI_Text__set_text (UnityEngine_UI_Text_o* __this, System_String_o* value, const MethodInfo* method);",
	  "TypeSignature": "viii"
	},

*/

class Text
{
	public:
		DWORD* TextPointer;

		typedef void(__fastcall* SetTextFunc)(DWORD*, const char*, DWORD*);
		void SetText(std::string value)
		{
			const char* Text = ConvertToIL2Cpp(value);
			((SetTextFunc)Address::Text::SetText)(TextPointer, Text, 0);
		}

		typedef char*(__fastcall* GetTextFunc)(DWORD*, DWORD*);
		std::string GetText()
		{
			char* Text = ((GetTextFunc)Address::Text::GetText)(TextPointer, 0);
			return ToString(Text);
		}

		Text(DWORD* Text)
		{
			TextPointer = Text;
		}
};