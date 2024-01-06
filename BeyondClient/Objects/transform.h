#pragma once

/*
{
    "Address": 33448448,
        "Name" : "UnityEngine.Transform$$get_position",
        "Signature" : "UnityEngine_Vector3_o UnityEngine_Transform__get_position (UnityEngine_Transform_o* __this, const MethodInfo* method);",
        "TypeSignature" : "iii"
    },
    {
      "Address": 33450816,
      "Name" : "UnityEngine.Transform$$set_position",
      "Signature" : "void UnityEngine_Transform__set_position (UnityEngine_Transform_o* __this, UnityEngine_Vector3_o value, const MethodInfo* method);",
      "TypeSignature" : "viii"
    },


        {
      "Address": 33448528,
      "Name": "UnityEngine.Transform$$get_right",
      "Signature": "UnityEngine_Vector3_o UnityEngine_Transform__get_right (UnityEngine_Transform_o* __this, const MethodInfo* method);",
      "TypeSignature": "iii"
    },
{
      "Address": 33448960,
      "Name": "UnityEngine.Transform$$get_up",
      "Signature": "UnityEngine_Vector3_o UnityEngine_Transform__get_up (UnityEngine_Transform_o* __this, const MethodInfo* method);",
      "TypeSignature": "iii"
    },
    {
      "Address": 33446944,
      "Name": "UnityEngine.Transform$$get_forward",
      "Signature": "UnityEngine_Vector3_o UnityEngine_Transform__get_forward (UnityEngine_Transform_o* __this, const MethodInfo* method);",
      "TypeSignature": "iii"
    },

      typedef Vector3(__fastcall* GetPositionFunc)(DWORD*, DWORD*);
        Vector3 GetPosition()
        {
            return ((GetPositionFunc)Address::VRCPlayerAPI::GetPosition)(VRCPlayerApiPointer, nullptr);
        }




        {
      "Address": 33376560,
      "Name": "UnityEngine.Transform$$get_parent",
      "Signature": "UnityEngine_Transform_o* UnityEngine_Transform__get_parent (UnityEngine_Transform_o* __this, const MethodInfo* method);",
      "TypeSignature": "iii"
    },
     {
      "Address": 33386016,
      "Name": "UnityEngine.Transform$$get_localPosition",
      "Signature": "UnityEngine_Vector3_o UnityEngine_Transform__get_localPosition (UnityEngine_Transform_o* __this, const MethodInfo* method);",
      "TypeSignature": "iii"
    },
    {
      "Address": 33388544,
      "Name": "UnityEngine.Transform$$set_localPosition",
      "Signature": "void UnityEngine_Transform__set_localPosition (UnityEngine_Transform_o* __this, UnityEngine_Vector3_o value, const MethodInfo* method);",
      "TypeSignature": "viii"
    },

    */

class Transform
{
    public:
        DWORD* __this; // TransformPointer

        typedef DWORD* (__fastcall* FindFunc)(DWORD*, const char*, DWORD*);
        DWORD* Find(std::string Name)
        {
            return ((FindFunc)Address::Transform::Find)(__this, ConvertToIL2Cpp(Name), nullptr);
        }

        typedef DWORD*(__fastcall* GetParentFunc)(DWORD*, DWORD*);
        DWORD* GetParent()
        {
            return ((GetParentFunc)Address::Transform::get_parent)(__this, nullptr);
        }

        typedef DWORD* (__fastcall* GetRootFunc)(DWORD*, DWORD*);
        Transform GetRoot()
        {
            return Transform(((GetRootFunc)Address::Transform::GetRoot)(__this, nullptr));
        }

        typedef Vector3(__fastcall* GetPositionFunc)(DWORD*, DWORD*);
        Vector3 GetPosition()
        {
            return ((GetPositionFunc)Address::Transform::get_position)(__this, nullptr);
        }

        typedef void(__fastcall* SetPositionFunc)(DWORD*, Vector3, DWORD*);
        void SetPosition(Vector3 Value)
        {
            ((SetPositionFunc)Address::Transform::set_position)(__this, Value, nullptr);
        }

        typedef Vector3(__fastcall* GetLocalPositionFunc)(DWORD*, DWORD*);
        Vector3 GetLocalPosition()
        {
            return ((GetLocalPositionFunc)Address::Transform::get_localposition)(__this, nullptr);
        }

        typedef void(__fastcall* SetLocalPositionFunc)(DWORD*, Vector3, DWORD*);
        void SetLocalPosition(Vector3 Value)
        {
            ((SetLocalPositionFunc)Address::Transform::set_localposition)(__this, Value, nullptr);
        }

        typedef Quaternion(__fastcall* GetRotationFunc)(DWORD*, DWORD*);
        Quaternion GetRotation()
        {
            return ((GetRotationFunc)Address::Transform::get_rotation)(__this, nullptr);
        }

        typedef void(__fastcall* SetRotationFunc)(DWORD*, Quaternion, DWORD*);
        void SetRotation(Quaternion Value)
        {
            ((SetRotationFunc)Address::Transform::set_rotation)(__this, Value, nullptr);
        }


        typedef Vector3(__fastcall* GetForwardFunc)(DWORD*, DWORD*);
        Vector3 GetForward()
        {
            return ((GetForwardFunc)Address::Transform::get_forward)(__this, nullptr);
        }

        Vector3 GetBackward()
        {
            Vector3 forward = GetForward();
            Vector3 backward(forward.x * -1, forward.y * -1, forward.z * -1);
            return backward;
        }

        typedef Vector3(__fastcall* GetRightFunc)(DWORD*, DWORD*);
        Vector3 GetRight()
        {
            return ((GetRightFunc)Address::Transform::get_right)(__this, nullptr);
        }

        Vector3 GetLeft()
        {
            Vector3 Right = GetRight();
            Vector3 Left(Right.x * -1, Right.y * -1, Right.z * -1);
            return Left;
        }

        typedef Vector3(__fastcall* GetUpFunc)(DWORD*, DWORD*);
        Vector3 GetUp()
        {
            return ((GetUpFunc)Address::Transform::get_up)(__this, nullptr);
        }

        Vector3 GetDown()
        {
            Vector3 Up = GetUp();
            Vector3 Down(Up.x * -1, Up.y * -1, Up.z * -1);
            return Down;
        }

        Transform(DWORD* Transform)
        {
            __this = Transform;
        }
};