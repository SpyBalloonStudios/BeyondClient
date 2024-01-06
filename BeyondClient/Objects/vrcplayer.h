#pragma once

/*


{ getvrcplayer ->
    {
      "Address": 8253008,
      "Name": "\u00CE\u00CC\u00CE\u00CE\u00CC\u00CD\u00CD\u00CE\u00CF\u00CE\u00CE\u00CC\u00CC\u00CD\u00CC\u00CE\u00CC\u00CF\u00CE\u00CE\u00CD\u00CC\u00CC$$\u00CC\u00CD\u00CD\u00CF\u00CE\u00CC\u00CC\u00CF\u00CD\u00CF\u00CC\u00CF\u00CC\u00CC\u00CE\u00CC\u00CC\u00CC\u00CC\u00CC\u00CE\u00CD\u00CC",
      "Signature": "________________________3084_o* ________________________________________________ (________________________4015_o* __this, const MethodInfo* method);",
      "TypeSignature": "iii"
    },





	get transform ->

	  "Address": 8950448,
	  "Name": "\u00CF\u00CD\u00CE\u00CC\u00CF\u00CD\u00CD\u00CC\u00CF\u00CF\u00CC\u00CE\u00CE\u00CF\u00CD\u00CD\u00CD\u00CC\u00CD\u00CF\u00CF\u00CE\u00CF$$\u00CE\u00CF\u00CC\u00CC\u00CF\u00CD\u00CF\u00CF\u00CF\u00CC\u00CC\u00CD\u00CE\u00CF\u00CC\u00CE\u00CD\u00CE\u00CD\u00CD\u00CE\u00CF\u00CD",
	  "Signature": "UnityEngine_Transform_o* ________________________________________________ (________________________3084_o* __this, const MethodInfo* method);",
	  "TypeSignature": "iii"
	},

    some offiscated vrcplayer code that takes in position and rotation? ->

     {
      "Address": 13266784,
      "Name": "\u00CC\u00CE\u00CE\u00CC\u00CF\u00CE\u00CF\u00CD\u00CC\u00CF\u00CE\u00CD\u00CE\u00CE\u00CC\u00CC\u00CF\u00CE\u00CE\u00CF\u00CC\u00CF\u00CE$$\u00CE\u00CE\u00CF\u00CF\u00CD\u00CC\u00CE\u00CC\u00CD\u00CC\u00CF\u00CC\u00CF\u00CE\u00CD\u00CC\u00CF\u00CC\u00CC\u00CD\u00CE\u00CE\u00CF",
      "Signature": "void ________________________________________________ (________________________511_o* __this, UnityEngine_Vector3_o _______________________, UnityEngine_Quaternion_o _______________________, const MethodInfo* method);",
      "TypeSignature": "viiii"
    },
*/

class vrcplayer {
    public:
	    DWORD* __this; // vrcplayerpointer
	    DWORD* transformpointer;

        Vector3 GetPosition()
        {
            return Transform(transformpointer).GetPosition();
        }

        void SetPosition(Vector3 Value)
        {
            Transform(transformpointer).SetPosition(Value);
        }

        Vector3 GetLocalPosition()
        {
            return Transform(transformpointer).GetLocalPosition();
        }

        void SetLocalPosition(Vector3 Value)
        {
            Transform(transformpointer).SetLocalPosition(Value);
        }

        Quaternion GetRotation()
        {
            return Transform(transformpointer).GetRotation();
        }

        void SetRotation(Quaternion Value)
        {
            Transform(transformpointer).SetRotation(Value);
        }

        DWORD* GetParent()
        {
            return Transform(transformpointer).GetParent();
        }

        Vector3 GetForward()
        {
            return Transform(transformpointer).GetForward();
        }

        Vector3 GetBackward()
        {
            return Transform(transformpointer).GetBackward();
        }

        Vector3 GetRight()
        {
            return Transform(transformpointer).GetRight();
        }

        Vector3 GetLeft()
        {
            return Transform(transformpointer).GetLeft();
        }

        Vector3 GetUp()
        {
            return Transform(transformpointer).GetUp();
        }

        Vector3 GetDown()
        {
            return Transform(transformpointer).GetDown();
        }

        typedef void(__fastcall* SetOffiscatedPosition)(DWORD*, Vector3, Quaternion, DWORD*);
        void SetUhhhPosition(Vector3 Position, Quaternion Rotation)
        {
            ((SetOffiscatedPosition)Address::VRCPlayer::GetVRCPlayer)(__this, Position, Rotation, nullptr);
        }

        DWORD* GetGameObject()
        {
            DWORD* gameObjectAddress = reinterpret_cast<DWORD*>(reinterpret_cast<uintptr_t>(__this) + 0x70);
            return gameObjectAddress;
        }

	    typedef DWORD*(__fastcall* getpointer)(DWORD*, DWORD*);


        vrcplayer(DWORD* PlayerPointer)
        {
            if (PlayerPointer != nullptr)
            {
                __this = ((getpointer)Address::VRCPlayer::GetVRCPlayer)(PlayerPointer, nullptr);
                transformpointer = ((getpointer)Address::VRCPlayer::GetTransform)(__this, nullptr);
            }
        }
};