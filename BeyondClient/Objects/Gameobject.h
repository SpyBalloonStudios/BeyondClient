#pragma once

/*
{
      "Address": 70506208,
      "Name": "UnityEngine.GameObject$$get_transform",
      "Signature": "UnityEngine_Transform_o* UnityEngine_GameObject__get_transform (UnityEngine_GameObject_o* __this, const MethodInfo* method);",
      "TypeSignature": "iii"
    },
    {
      "Address": 70505856,
      "Name": "UnityEngine.GameObject$$get_layer",
      "Signature": "int32_t UnityEngine_GameObject__get_layer (UnityEngine_GameObject_o* __this, const MethodInfo* method);",
      "TypeSignature": "iii"
    },
    {
      "Address": 70506432,
      "Name": "UnityEngine.GameObject$$set_layer",
      "Signature": "void UnityEngine_GameObject__set_layer (UnityEngine_GameObject_o* __this, int32_t value, const MethodInfo* method);",
      "TypeSignature": "viii"
    },

     {
      "Address": 71275968,
      "Name": "UnityEngine.GameObject$$Find",
      "Signature": "UnityEngine_GameObject_o* UnityEngine_GameObject__Find (System_String_o* name, const MethodInfo* method);",
      "TypeSignature": "iii"
    },
    {
*/

class Gameobject
{
    private:
        
        typedef DWORD* (__fastcall* find_o)(TextStructs::System_String_o*, DWORD*);
        DWORD* find(TextStructs::System_String_o* strval)
        {
            return ((find_o)Address::Gameobject::Find)(strval, nullptr);
        }
        

    public:
        DWORD* GameobjectPointer;
        std::string name;

        
        Gameobject Find(std::string Path)
        {
            DWORD* __ginstance = find(Address::StringNew(Path));

            return Gameobject(__ginstance);
        }
        
        Gameobject()
        {
            name = "N/A";
            GameobjectPointer = nullptr;
        }

        Gameobject(DWORD* gameobject)
        {
            GameobjectPointer = gameobject;
            if (GameobjectPointer != nullptr)
            {
                name = ToString(Object::get_name(GameobjectPointer));
            }
        }
};