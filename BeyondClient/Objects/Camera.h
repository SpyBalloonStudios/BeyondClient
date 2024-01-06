#pragma once

/*

{
      "Address": 70918272,
      "Name": "UnityEngine.Camera$$get_fieldOfView",
      "Signature": "float UnityEngine_Camera__get_fieldOfView (UnityEngine_Camera_o* __this, const MethodInfo* method);",
      "TypeSignature": "fii"
    },
    {
      "Address": 70923840,
      "Name": "UnityEngine.Camera$$set_fieldOfView",
      "Signature": "void UnityEngine_Camera__set_fieldOfView (UnityEngine_Camera_o* __this, float value, const MethodInfo* method);",
      "TypeSignature": "vifi"
    },

*/

class Camera
{
    public:
            typedef Vector3(__fastcall* GetWorldToScreenPointVector3Func)(DWORD*, Vector3, DWORD*);
            Vector3 GetWorldToScreenPointVector3(DWORD* Camera, Vector3 WPosition)
            {
                return ((GetWorldToScreenPointVector3Func)Address::Camera::GetWorldToScreenPointVector3)(Camera, WPosition, nullptr);
            }

            typedef DWORD* (__fastcall* GetMainCameraFunc)(DWORD*);
            DWORD* GetMainCamera()
            {
                return ((GetMainCameraFunc)Address::Camera::GetMainCamera)(nullptr);
            }

            Vector3 WorldToScreenPoint(Vector3 Position)
            {
                return GetWorldToScreenPointVector3(GetMainCamera(), Position);
            }

            float GetDistance(Vector3 Position)
			{
				return WorldToScreenPoint(Position).z;
			}

            typedef float (__fastcall* GetFovFunc)(DWORD*, DWORD*);
            float GetFov()
            {
                return ((GetFovFunc)Address::Camera::GetFov)(GetMainCamera(), nullptr);
            }

            typedef void(__fastcall* SetFovFunc)(DWORD*, float, DWORD*);
            void SetFov(float FOV)
            {
                return ((SetFovFunc)Address::Camera::SetFov)(GetMainCamera(), FOV, nullptr);
            }

            float Fov;
            bool Saved = false;
            void Zoom()
            {
                if (!Saved)
                {
                    Fov = GetFov();
                    Saved = true;
                }

                if (GetFov() != (Fov / 4))
                    SetFov(Fov / 4);
            }

            void DontZoom()
            {
                if (!Saved)
                {
                    Fov = GetFov();
                    Saved = true;
                }

                if (GetFov() != Fov)
                    SetFov(Fov);
            }

            Camera()
            {

            }
};