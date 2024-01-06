#pragma once

namespace VRCPlayerApiStruct
{
#pragma region VRCPlayerApiStruct
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

	struct __declspec(align(8)) VRC_SDKBase_VRCPlayerApi_Fields {
		bool isLocal;
		struct System_String_o* displayName;
		int32_t mPlayerId;
		struct UnityEngine_GameObject_o* gameObject;
		bool _isValid;
	};
	struct VRC_SDKBase_VRCPlayerApi_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_IsValid;
	};

	struct VRC_SDKBase_VRCPlayerApi_c {
		Il2CppClass_1 _1;
		struct VRC_SDKBase_VRCPlayerApi_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VRC_SDKBase_VRCPlayerApi_VTable vtable;
	};

	struct VRC_SDKBase_VRCPlayerApi_o {
		VRC_SDKBase_VRCPlayerApi_c* klass;
		void* monitor;
		VRC_SDKBase_VRCPlayerApi_Fields fields;
	};
#pragma endregion
}