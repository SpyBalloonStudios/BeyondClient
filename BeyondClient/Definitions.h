#pragma once
#include <sstream>
#include <map>

enum class HTTPMethods : uint8_t {
    Get,
    Head,
    Post,
    Put,
    Delete,
    Patch,
    Merge,
    Options
};

std::map<HTTPMethods, std::string> methodToString = {
    {HTTPMethods::Get, "GET"},
    {HTTPMethods::Head, "HEAD"},
    {HTTPMethods::Post, "POST"},
    {HTTPMethods::Put, "PUT"},
    {HTTPMethods::Delete, "DELETE"},
    {HTTPMethods::Patch, "PATCH"},
    {HTTPMethods::Merge, "MERGE"},
    {HTTPMethods::Options, "OPTIONS"}
};

std::string GetMethodName(HTTPMethods method) {
    auto it = methodToString.find(method);
    if (it != methodToString.end()) {
        return it->second;
    }
    return "UNKNOWN";
}



enum HumanBodyBones
{
    Hips = 0,
    LeftUpperLeg = 1,
    RightUpperLeg = 2,
    LeftLowerLeg = 3,
    RightLowerLeg = 4,
    LeftFoot = 5,
    RightFoot = 6,
    Spine = 7,
    Chest = 8,
    UpperChest = 54,
    Neck = 9,
    Head = 10,
    LeftShoulder = 11,
    RightShoulder = 12,
    LeftUpperArm = 13,
    RightUpperArm = 14,
    LeftLowerArm = 15,
    RightLowerArm = 16,
    LeftHand = 17,
    RightHand = 18,
    LeftToes = 19,
    RightToes = 20,
    LeftEye = 21,
    RightEye = 22,
    Jaw = 23,
    LeftThumbProximal = 24,
    LeftThumbIntermediate = 25,
    LeftThumbDistal = 26,
    LeftIndexProximal = 27,
    LeftIndexIntermediate = 28,
    LeftIndexDistal = 29,
    LeftMiddleProximal = 30,
    LeftMiddleIntermediate = 31,
    LeftMiddleDistal = 32,
    LeftRingProximal = 33,
    LeftRingIntermediate = 34,
    LeftRingDistal = 35,
    LeftLittleProximal = 36,
    LeftLittleIntermediate = 37,
    LeftLittleDistal = 38,
    RightThumbProximal = 39,
    RightThumbIntermediate = 40,
    RightThumbDistal = 41,
    RightIndexProximal = 42,
    RightIndexIntermediate = 43,
    RightIndexDistal = 44,
    RightMiddleProximal = 45,
    RightMiddleIntermediate = 46,
    RightMiddleDistal = 47,
    RightRingProximal = 48,
    RightRingIntermediate = 49,
    RightRingDistal = 50,
    RightLittleProximal = 51,
    RightLittleIntermediate = 52,
    RightLittleDistal = 53,
    LastBone = 55
};
#pragma once
class Vector2 {
public:
    float x;
    float y;

    static const Vector2 zero;

    std::string ToString() const {
        std::stringstream ss;
        ss << "(" << x << ", " << y << ")";
        return ss.str();
    }
};

const Vector2 Vector2::zero = { 0.0f, 0.0f };

class Quaternion {
public:
    float x;
    float y;
    float z;
    float w;

    static const Quaternion zero;

    std::string ToString() const {
        std::stringstream ss;
        ss << "(" << x << ", " << y << ", " << z << ", " << w << ")";
        return ss.str();
    }

    float distance(Quaternion Compare)
    {
        float distance = sqrt(pow(x - Compare.x, 2) + pow(y - Compare.y, 2) + pow(z - Compare.z, 2) + pow(w - Compare.w, 2));
        return distance;
    }
};

const Quaternion Quaternion::zero = { 0.0f, 0.0f, 0.0f, 0.0f };

class Color {
public:
    float r;
    float g;
    float b;
    float a;

    std::string ToString() const {
        std::stringstream ss;
        ss << "(" << r << ", " << g << ", " << b << ", " << a << ")";
        return ss.str();
    }
};


class Color32 {
public:
    uint8_t r; 
    uint8_t g; 
    uint8_t b; 
    uint8_t a; 

    Color32(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : r(red), g(green), b(blue), a(alpha) {}

    std::string ToString() const {
        std::stringstream ss;
        ss << "(" << static_cast<int>(r) << ", " << static_cast<int>(g) << ", " << static_cast<int>(b) << ", " << static_cast<int>(a) << ")";
        return ss.str();
    }
};


class EventData
{
public:
    uint8_t Code;
    static DWORD* Parameters;
    uint8_t SenderKey;
    int32_t sender;
    uint8_t CustomDataKey;
    DWORD* customData;
};

typedef enum DeliveryMode {
    Unreliable,
    Reliable,
    UnreliableUnsequenced,
    ReliableUnsequenced
} DeliveryMode;
const char* deliveryModeStrings[] = {
        "Unreliable",
        "Reliable",
        "UnreliableUnsequenced",
        "ReliableUnsequenced"
};

struct SendOptions
{
    DeliveryMode DeliveryMode;   // Assuming the size of DeliveryMode is 4 bytes, adjust accordingly if not
    bool Encrypt;
    uint8_t Channel;
};

// public enum мнннонллмнлноннмлммонло : byte
// Search in dnSpy 2000B20
typedef enum EventCaching : uint8_t {
    DoNotCache,
    MergeCache,            // Obsolete
    ReplaceCache,          // Obsolete
    RemoveCache,           // Obsolete
    AddToRoomCache,
    AddToRoomCacheGlobal,
    RemoveFromRoomCache,
    RemoveFromRoomCacheForActorsLeft,
    SliceIncreaseIndex = 10,
    SliceSetIndex,
    SlicePurgeIndex,
    SlicePurgeUpToIndex
} EventCaching;
const char* EventCachingStrings[] = {
    "DoNotCache",
    "MergeCache",
    "ReplaceCache",
    "RemoveCache",
    "AddToRoomCache",
    "AddToRoomCacheGlobal",
    "RemoveFromRoomCache",
    "RemoveFromRoomCacheForActorsLeft",
    "SliceIncreaseIndex = 10",
    "SliceSetIndex",
    "SlicePurgeIndex",
    "SlicePurgeUpToIndex"
};

// public enum оомннлмллоннлнлоолмолоо : byte
// Search in dnSpy 2000B1F
typedef enum ReceiverGroup : uint8_t {
    Others,
    All,
    MasterClient
} ReceiverGroup;
const char* ReceiverGroupStrings[] = {
    "Others",
    "All",
    "MasterClient"
};

// public class ммлонлонммноллмолломмнл
// Search in dnSpy 2000B38
class WebFlags
{
public:
    static WebFlags* staticInstance;
    uint8_t member1;
    const uint8_t member2 = 1;
    const uint8_t member3 = 2;
    const uint8_t member4 = 4;
    const uint8_t member5 = 8;
};

// Search in dnSpy 2000B23
class RaiseEventOptions
{
public:
    static RaiseEventOptions* staticInstance;
    EventCaching CachingOption;
    uint8_t InterestGroup;
    int32_t* TargetActors;
    ReceiverGroup Receivers;
    uint8_t SequenceChannel;
    WebFlags* WebFlags;
};

enum class LogRaiser {
    Default, Patch, Photon, PlayerLeave, PlayerJoin,
    Api, Behavior, Local, Safety, Risk, Debug, RPC
};

int gamePriorities[] = { IDLE_PRIORITY_CLASS, BELOW_NORMAL_PRIORITY_CLASS, NORMAL_PRIORITY_CLASS, ABOVE_NORMAL_PRIORITY_CLASS, HIGH_PRIORITY_CLASS, REALTIME_PRIORITY_CLASS };
const char* gamePriorityStrings[] = { "Low", "Below Normal", "Normal", "Above Normal", "High", "Realtime" };