#pragma once

namespace PickupStruct
{
#pragma region PickupStruct
    typedef void(*Il2CppMethodPointer)();

    struct MethodInfo;

    struct VirtualInvokeData
    {
        Il2CppMethodPointer methodPtr;
        const MethodInfo* method;
    };

    struct Il2CppType
    {
        void* data;
        unsigned int bits;
    };

    struct Il2CppClass;

    struct Il2CppObject
    {
        Il2CppClass* klass;
        void* monitor;
    };

    union Il2CppRGCTXData
    {
        void* rgctxDataDummy;
        const MethodInfo* method;
        const Il2CppType* type;
        Il2CppClass* klass;
    };

    struct Il2CppRuntimeInterfaceOffsetPair
    {
        Il2CppClass* interfaceType;
        int32_t offset;
    };
    struct Il2CppClass_1
    {
        void* image;
        void* gc_desc;
        const char* name;
        const char* namespaze;
        Il2CppType byval_arg;
        Il2CppType this_arg;
        Il2CppClass* element_class;
        Il2CppClass* castClass;
        Il2CppClass* declaringType;
        Il2CppClass* parent;
        void* generic_class;
        void* typeMetadataHandle;
        void* interopData;
        Il2CppClass* klass;
        void* fields;
        void* events;
        void* properties;
        void* methods;
        Il2CppClass** nestedTypes;
        Il2CppClass** implementedInterfaces;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
    };
    struct Il2CppClass_2
    {
        Il2CppClass** typeHierarchy;
        void* unity_user_data;
        uint32_t initializationExceptionGCHandle;
        uint32_t cctor_started;
        uint32_t cctor_finished;
        size_t cctor_thread;
        void* genericContainerHandle;
        uint32_t instance_size;
        uint32_t actualSize;
        uint32_t element_size;
        int32_t native_size;
        uint32_t static_fields_size;
        uint32_t thread_static_fields_size;
        int32_t thread_static_fields_offset;
        uint32_t flags;
        uint32_t token;
        uint16_t method_count;
        uint16_t property_count;
        uint16_t field_count;
        uint16_t event_count;
        uint16_t nested_type_count;
        uint16_t vtable_count;
        uint16_t interfaces_count;
        uint16_t interface_offsets_count;
        uint8_t typeHierarchyDepth;
        uint8_t genericRecursionDepth;
        uint8_t rank;
        uint8_t minimumAlignment;
        uint8_t naturalAligment;
        uint8_t packingSize;
        uint8_t bitflags1;
        uint8_t bitflags2;
    };
    struct Il2CppClass
    {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        VirtualInvokeData vtable[255];
    };

    typedef uintptr_t il2cpp_array_size_t;
    typedef int32_t il2cpp_array_lower_bound_t;
    struct Il2CppArrayBounds
    {
        il2cpp_array_size_t length;
        il2cpp_array_lower_bound_t lower_bound;
    };

    typedef void (*InvokerMethod)(Il2CppMethodPointer, const MethodInfo*, void*, void**, void*);
    struct MethodInfo
    {
        Il2CppMethodPointer methodPointer;
        Il2CppMethodPointer virtualMethodPointer;
        InvokerMethod invoker_method;
        const char* name;
        Il2CppClass* klass;
        const Il2CppType* return_type;
        const Il2CppType** parameters;
        union
        {
            const Il2CppRGCTXData* rgctx_data;
            const void* methodMetadataHandle;
        };
        union
        {
            const void* genericMethod;
            const void* genericContainerHandle;
        };
        uint32_t token;
        uint16_t flags;
        uint16_t iflags;
        uint16_t slot;
        uint8_t parameters_count;
        uint8_t bitflags;
    };

    struct __declspec(align(8)) _Module__Fields {
    };
    struct _Module__c {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        VirtualInvokeData vtable[32];
    };
    struct _Module__o {
        _Module__c* klass;
        void* monitor;
        _Module__Fields fields;
    };
    struct __declspec(align(8)) System_Attribute_Fields {
    };
    struct System_Attribute_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
        VirtualInvokeData _4_get_TypeId;
        VirtualInvokeData _5_Match;
        VirtualInvokeData _6_IsDefaultAttribute;
    };
    struct System_Attribute_c {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        System_Attribute_VTable vtable;
    };
    struct System_Attribute_o {
        System_Attribute_c* klass;
        void* monitor;
        System_Attribute_Fields fields;
    };
    struct ________________________Fields : System_Attribute_Fields {
    };
    struct ________________________VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
        VirtualInvokeData _4_get_TypeId;
        VirtualInvokeData _5_Match;
        VirtualInvokeData _6_IsDefaultAttribute;
    };
    struct ________________________c {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        ________________________VTable vtable;
    };
    struct ________________________o {
        ________________________c* klass;
        void* monitor;
        ________________________Fields fields;
    };
    struct ________________________1_Fields : System_Attribute_Fields {
    };
    struct ________________________1_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
        VirtualInvokeData _4_get_TypeId;
        VirtualInvokeData _5_Match;
        VirtualInvokeData _6_IsDefaultAttribute;
    };
    struct ________________________1_c {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        ________________________1_VTable vtable;
    };
    struct ________________________1_o {
        ________________________1_c* klass;
        void* monitor;
        ________________________1_Fields fields;
    };
    struct __declspec(align(8)) UnityEngine_Object_Fields {
        intptr_t m_CachedPtr;
    };
    struct UnityEngine_Object_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
    };
    struct UnityEngine_Object_c {
        Il2CppClass_1 _1;
        struct UnityEngine_Object_StaticFields* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        UnityEngine_Object_VTable vtable;
    };
    struct UnityEngine_Object_o {
        UnityEngine_Object_c* klass;
        void* monitor;
        UnityEngine_Object_Fields fields;
    };
    struct UnityEngine_Object_StaticFields {
        int32_t OffsetOfInstanceIDInCPlusPlusObject;
    };
    struct UnityEngine_Component_Fields : UnityEngine_Object_Fields {
    };
    struct UnityEngine_Component_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
    };
    struct UnityEngine_Component_c {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        UnityEngine_Component_VTable vtable;
    };
    struct UnityEngine_Component_o {
        UnityEngine_Component_c* klass;
        void* monitor;
        UnityEngine_Component_Fields fields;
    };
    struct UnityEngine_Behaviour_Fields : UnityEngine_Component_Fields {
    };
    struct UnityEngine_Behaviour_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
    };
    struct UnityEngine_Behaviour_c {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        UnityEngine_Behaviour_VTable vtable;
    };
    struct UnityEngine_Behaviour_o {
        UnityEngine_Behaviour_c* klass;
        void* monitor;
        UnityEngine_Behaviour_Fields fields;
    };
    struct UnityEngine_MonoBehaviour_Fields : UnityEngine_Behaviour_Fields {
        struct System_Threading_CancellationTokenSource_o* m_CancellationTokenSource;
    };
    struct VRC_SDKBase_Network_VRCNetworkBehaviour_Fields : UnityEngine_MonoBehaviour_Fields {
    };
    struct VRC_SDKBase_VRC_Pickup_Fields : VRC_SDKBase_Network_VRCNetworkBehaviour_Fields {
        int32_t MomentumTransferMethod;
        bool DisallowTheft;
        struct UnityEngine_Transform_o* ExactGun;
        struct UnityEngine_Transform_o* ExactGrip;
        bool allowManipulationWhenEquipped;
        int32_t orientation;
        int32_t AutoHold;
        struct System_String_o* InteractionText;
        struct System_String_o* UseText;
        int32_t useEventBroadcastType;
        struct System_String_o* UseDownEventName;
        struct System_String_o* UseUpEventName;
        int32_t pickupDropEventBroadcastType;
        struct System_String_o* PickupEventName;
        struct System_String_o* DropEventName;
        float ThrowVelocityBoostMinSpeed;
        float ThrowVelocityBoostScale;
        struct UnityEngine_Component_o* currentlyHeldBy;
        struct VRC_SDKBase_VRCPlayerApi_o* currentLocalPlayer;
        bool pickupable;
        float proximity;
    };
    struct VRC_SDKBase_VRC_Pickup_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
        VirtualInvokeData _4_ProvideEvents;
    };
    struct VRC_SDKBase_VRC_Pickup_c {
        Il2CppClass_1 _1;
        struct VRC_SDKBase_VRC_Pickup_StaticFields* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        VRC_SDKBase_VRC_Pickup_VTable vtable;
    };
    struct VRC_SDKBase_VRC_Pickup_o {
        VRC_SDKBase_VRC_Pickup_c* klass;
        void* monitor;
        VRC_SDKBase_VRC_Pickup_Fields fields;
    };
#pragma endregion
}

struct VRC_Pickup {
    PickupStruct::VRC_SDKBase_VRC_Pickup_o* Pickup_o;
    Component component = Component(nullptr);
    Transform transform = Transform(nullptr);
    bool isOwner = false;
    std::string name;
    DWORD* _this;
};