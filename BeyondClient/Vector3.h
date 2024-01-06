#pragma once
#include <sstream>

/*


{
      "Address": 70476992,
      "Name": "UnityEngine.Vector3$$get_zero",
      "Signature": "UnityEngine_Vector3_o UnityEngine_Vector3__get_zero (const MethodInfo* method);",
      "TypeSignature": "ii"
    },
*/

class Vector3 {
public:
    float x;
    float y;
    float z;

    static const Vector3 NoGravity;
    static const Vector3 MoonGravity;
    static const Vector3 normal;
    static const Vector3 Nan;

    std::string ToString() const {
        std::stringstream ss;
        ss << "(" << x << ", " << y << ", " << z << ")";
        return ss.str();
    }

    bool isEqual(Vector3 Compare)
    {
        if (x == Compare.x && y == Compare.y && z == Compare.z)
            return true;
        else
            return false;
    }

    float distance(Vector3 Compare)
	{
		float distance = sqrt(pow(x - Compare.x, 2) + pow(y - Compare.y, 2) + pow(z - Compare.z, 2));
		return distance;
	}
};

const Vector3 Vector3::NoGravity = { 0.0f, 0.0f, 0.0f };
const Vector3 Vector3::MoonGravity = { 0.0f, -1.62f, 0.0f };
const Vector3 Vector3::normal = { 0.0f, -9.81f, 0.0f };
const Vector3 Vector3::Nan = { (-(float)(INFINITY * 0.0F)), (-(float)(INFINITY * 0.0F)), (-(float)(INFINITY * 0.0F)) };