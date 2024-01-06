#pragma once

namespace Object {

	typedef DWORD* (__fastcall* Instantiate_o)(DWORD*, DWORD*, bool, DWORD*);
	DWORD* Instantiate(DWORD* original, DWORD* transform, bool instantiateInWorldSpace)
	{
		return ((Instantiate_o)(Address::Object::Instantiate))(original, transform, instantiateInWorldSpace, nullptr);
	}

	typedef const char* (__fastcall* get_name_o)(DWORD*, DWORD*);
	const char* get_name(DWORD* object)
	{
		return ((get_name_o)Address::Object::getname)(object, nullptr);
	}
}