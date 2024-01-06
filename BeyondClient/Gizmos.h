#pragma once

/*


{
    "Address": 70958752,
    "Name": "UnityEngine.Gizmos$$set_color",
    "Signature": "void UnityEngine_Gizmos__set_color (UnityEngine_Color_o value, const MethodInfo* method);",
    "TypeSignature": "vii"
},



*/


class Gizmos {
public:
	typedef void(__fastcall* SetColor_o)(ImVec4, DWORD*);
	void SetColor(ImVec4 Color)
	{
		((SetColor_o)Address::Gizmos::SetColor)(Color, 0);
	}

	typedef void(__fastcall* DrawLine_o)(Vector3, Vector3, DWORD*);
	void DrawLine(Vector3 from, Vector3 to)
	{
		((DrawLine_o)Address::Gizmos::DrawLine)(from, to, 0);
	}
};