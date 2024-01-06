#pragma once

class Component {
private:
	typedef DWORD* (__fastcall* get_gameobject_o)(DWORD*, DWORD*);
	DWORD* get_gameobject(DWORD* component)
	{
		return ((get_gameobject_o)Address::Component::get_gameobject)(component, nullptr);
	}

	typedef DWORD* (__fastcall* get_transform_o)(DWORD*, DWORD*);
	DWORD* get_transform(DWORD* component)
	{
		return ((get_transform_o)Address::Component::get_transform)(component, nullptr);
	}

	typedef DWORD* (__fastcall* get_component_o)(DWORD*, TextStructs::System_String_o*, DWORD*);
	DWORD* get_component(DWORD* component, TextStructs::System_String_o* String)
	{
		return ((get_component_o)Address::Component::get_component)(component, String, nullptr);
	}

	/*
	
	{
      "Address": 71257872,
      "Name": "UnityEngine.Component$$GetComponentInChildren",
      "Signature": "UnityEngine_Component_o* UnityEngine_Component__GetComponentInChildren (UnityEngine_Component_o* __this, System_Type_o* t, const MethodInfo* method);",
      "TypeSignature": "iiii"


		{
	  "Address": 71258416,
	  "Name": "UnityEngine.Component$$GetComponent",
	  "Signature": "UnityEngine_Component_o* UnityEngine_Component__GetComponent (UnityEngine_Component_o* __this, System_String_o* type, const MethodInfo* method);",
	  "TypeSignature": "iiii"
	},
    },
	*/

public:
	DWORD* __this;
	DWORD* __transform;
	DWORD* __gameobject;

	bool IsValid()
	{
		if (__this == nullptr) return false;
		else return true;
	}

	DWORD* GetComponent(std::string Type)
	{
		if (__this != nullptr)
		{
			return get_component(__this, Address::StringNew(Type.c_str()));
		}

		return nullptr;
	}


	Component(DWORD* component)
	{
		__this = component;
		if (__this != nullptr)
		{
			__gameobject = get_gameobject(__this);
			__transform = get_transform(__this);
		}
	}

};
