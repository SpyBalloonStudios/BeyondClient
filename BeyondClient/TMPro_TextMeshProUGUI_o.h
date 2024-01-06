#pragma once

namespace TextStructs {
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
	struct UnityEngine_MonoBehaviour_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct UnityEngine_MonoBehaviour_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_MonoBehaviour_VTable vtable;
	};
	struct UnityEngine_MonoBehaviour_o {
		UnityEngine_MonoBehaviour_c* klass;
		void* monitor;
		UnityEngine_MonoBehaviour_Fields fields;
	};
	struct ________________________3_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Shader_o* _______________________;
		struct UnityEngine_Material_o* _1________________________;
	};
	struct ________________________3_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
	};
	struct ________________________3_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________3_VTable vtable;
	};
	struct ________________________3_o {
		________________________3_c* klass;
		void* monitor;
		________________________3_Fields fields;
	};
	struct ________________________2_Fields : ________________________3_Fields {
		bool _______________________;
		float _1________________________;
		bool _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
		float _8________________________;
		float _9________________________;
	};
	struct ________________________2_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11_Update;
		VirtualInvokeData _12_OnRenderImage;
		VirtualInvokeData _13________________________;
	};
	struct ________________________2_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________2_VTable vtable;
	};
	struct ________________________2_o {
		________________________2_c* klass;
		void* monitor;
		________________________2_Fields fields;
	};
	struct ________________________4_Fields : ________________________3_Fields {
		float _______________________;
	};
	struct ________________________4_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8_OnRenderImage;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________4_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________4_VTable vtable;
	};
	struct ________________________4_o {
		________________________4_c* klass;
		void* monitor;
		________________________4_Fields fields;
	};
	struct ________________________5_Fields : ________________________3_Fields {
		struct UnityEngine_Texture_o* _______________________;
		float _1________________________;
		int32_t _2________________________;
	};
	struct ________________________5_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12_OnRenderImage;
	};
	struct ________________________5_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________5_VTable vtable;
	};
	struct ________________________5_o {
		________________________5_c* klass;
		void* monitor;
		________________________5_Fields fields;
	};
	struct ________________________6_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
	};
	struct ________________________6_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13_OnRenderImage;
	};
	struct ________________________6_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________6_VTable vtable;
	};
	struct ________________________6_o {
		________________________6_c* klass;
		void* monitor;
		________________________6_Fields fields;
	};
	struct UnityEngine_Vector2_Fields {
		float x;
		float y;
	};
	struct UnityEngine_Vector2_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Equals;
		VirtualInvokeData _5_ToString;
	};
	struct UnityEngine_Vector2_c {
		Il2CppClass_1 _1;
		struct UnityEngine_Vector2_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_Vector2_VTable vtable;
	};
	struct UnityEngine_Vector2_o {
		UnityEngine_Vector2_Fields fields;
	};
	struct UnityEngine_Vector2_StaticFields {
		struct UnityEngine_Vector2_o zeroVector;
		struct UnityEngine_Vector2_o oneVector;
		struct UnityEngine_Vector2_o upVector;
		struct UnityEngine_Vector2_o downVector;
		struct UnityEngine_Vector2_o leftVector;
		struct UnityEngine_Vector2_o rightVector;
		struct UnityEngine_Vector2_o positiveInfinityVector;
		struct UnityEngine_Vector2_o negativeInfinityVector;
	};
	struct ________________________7_Fields : ________________________3_Fields {
		struct UnityEngine_Vector2_o _______________________;
		struct UnityEngine_Vector2_o _1________________________;
		struct UnityEngine_Vector2_o _2________________________;
	};
	struct ________________________7_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9_OnRenderImage;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________7_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________7_VTable vtable;
	};
	struct ________________________7_o {
		________________________7_c* klass;
		void* monitor;
		________________________7_Fields fields;
	};
	struct ________________________8_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
		float _8________________________;
		float _9________________________;
		float _10________________________;
		float _11________________________;
		int32_t _12________________________;
	};
	struct ________________________8_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12_OnRenderImage;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________8_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________8_VTable vtable;
	};
	struct ________________________8_o {
		________________________8_c* klass;
		void* monitor;
		________________________8_Fields fields;
	};
	struct ________________________9_Fields : ________________________3_Fields {
		int32_t _______________________;
		int32_t _1________________________;
		int32_t _2________________________;
	};
	struct ________________________9_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10_OnRenderImage;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________9_c {
		Il2CppClass_1 _1;
		struct ________________________9_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________9_VTable vtable;
	};
	struct ________________________9_o {
		________________________9_c* klass;
		void* monitor;
		________________________9_Fields fields;
	};
	struct ________________________9_StaticFields {
		struct UnityEngine_Vector4_array* _3________________________;
	};
	struct ________________________10_Fields : ________________________3_Fields {
		struct UnityEngine_Vector2_o _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
	};
	struct ________________________10_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8_OnRenderImage;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________10_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________10_VTable vtable;
	};
	struct ________________________10_o {
		________________________10_c* klass;
		void* monitor;
		________________________10_Fields fields;
	};
	struct UnityEngine_Vector3_Fields {
		float x;
		float y;
		float z;
	};
	struct UnityEngine_Vector3_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Equals;
		VirtualInvokeData _5_ToString;
	};
	struct UnityEngine_Vector3_c {
		Il2CppClass_1 _1;
		struct UnityEngine_Vector3_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_Vector3_VTable vtable;
	};
	struct UnityEngine_Vector3_o {
		UnityEngine_Vector3_Fields fields;
	};
	struct UnityEngine_Vector3_StaticFields {
		struct UnityEngine_Vector3_o zeroVector;
		struct UnityEngine_Vector3_o oneVector;
		struct UnityEngine_Vector3_o upVector;
		struct UnityEngine_Vector3_o downVector;
		struct UnityEngine_Vector3_o leftVector;
		struct UnityEngine_Vector3_o rightVector;
		struct UnityEngine_Vector3_o forwardVector;
		struct UnityEngine_Vector3_o backVector;
		struct UnityEngine_Vector3_o positiveInfinityVector;
		struct UnityEngine_Vector3_o negativeInfinityVector;
	};
	struct ________________________11_Fields : ________________________3_Fields {
		struct UnityEngine_Vector3_o _______________________;
		struct UnityEngine_Vector3_o _1________________________;
		struct UnityEngine_Vector3_o _2________________________;
		float _3________________________;
		float _4________________________;
	};
	struct ________________________11_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9_OnRenderImage;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________11_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________11_VTable vtable;
	};
	struct ________________________11_o {
		________________________11_c* klass;
		void* monitor;
		________________________11_Fields fields;
	};
	struct ________________________12_Fields : ________________________3_Fields {
		int32_t _______________________;
		float _1________________________;
		bool _2________________________;
		bool _3________________________;
		struct UnityEngine_Camera_o* _4________________________;
	};
	struct ________________________12_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8_OnRenderImage;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________12_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________12_VTable vtable;
	};
	struct ________________________12_o {
		________________________12_c* klass;
		void* monitor;
		________________________12_Fields fields;
	};
	struct ________________________13_Fields : ________________________3_Fields {
		struct UnityEngine_Vector2_o _______________________;
		float _1________________________;
	};
	struct ________________________13_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11_OnRenderImage;
	};
	struct ________________________13_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________13_VTable vtable;
	};
	struct ________________________13_o {
		________________________13_c* klass;
		void* monitor;
		________________________13_Fields fields;
	};
	struct ________________________14_Fields : ________________________3_Fields {
		struct UnityEngine_Vector2_o _______________________;
		float _1________________________;
		float _2________________________;
		bool _3________________________;
	};
	struct ________________________14_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13_OnRenderImage;
		VirtualInvokeData _14________________________;
	};
	struct ________________________14_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________14_VTable vtable;
	};
	struct ________________________14_o {
		________________________14_c* klass;
		void* monitor;
		________________________14_Fields fields;
	};
	struct ________________________15_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		bool _3________________________;
	};
	struct ________________________15_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8_OnRenderImage;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________15_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________15_VTable vtable;
	};
	struct ________________________15_o {
		________________________15_c* klass;
		void* monitor;
		________________________15_Fields fields;
	};
	struct ________________________________________________Fields {
		int32_t value__;
	};
	struct ________________________________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________VTable vtable;
	};
	struct ________________________________________________o {
		________________________________________________Fields fields;
	};
	struct __declspec(align(8)) ________________________InterferenceSettings_Fields {
		float speed;
		float density;
		float maxDisplacement;
	};
	struct ________________________InterferenceSettings_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________InterferenceSettings_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________InterferenceSettings_VTable vtable;
	};
	struct ________________________InterferenceSettings_o {
		________________________InterferenceSettings_c* klass;
		void* monitor;
		________________________InterferenceSettings_Fields fields;
	};
	struct __declspec(align(8)) ________________________TearingSettings_Fields {
		float speed;
		float intensity;
		float maxDisplacement;
		bool allowFlipping;
		bool yuvColorBleeding;
		float yuvOffset;
	};
	struct ________________________TearingSettings_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________TearingSettings_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________TearingSettings_VTable vtable;
	};
	struct ________________________TearingSettings_o {
		________________________TearingSettings_c* klass;
		void* monitor;
		________________________TearingSettings_Fields fields;
	};
	struct ________________________16_Fields : ________________________3_Fields {
		bool _______________________;
		struct UnityEngine_Vector2_o _1________________________;
		struct UnityEngine_Vector2_o _2________________________;
		int32_t _3________________________;
		struct ________________________InterferenceSettings_o* _4________________________;
		struct ________________________TearingSettings_o* _5________________________;
		struct UnityEngine_Camera_o* _6________________________;
		bool _7________________________;
		float _8________________________;
		float _9________________________;
		float _10________________________;
		float _11________________________;
	};
	struct ________________________16_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnEnable;
		VirtualInvokeData _8_OnRenderImage;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
		VirtualInvokeData _15_Update;
	};
	struct ________________________16_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________16_VTable vtable;
	};
	struct ________________________16_o {
		________________________16_c* klass;
		void* monitor;
		________________________16_Fields fields;
	};
	struct ________________________17_Fields : ________________________3_Fields {
		struct UnityEngine_Texture_o* _______________________;
		float _1________________________;
	};
	struct ________________________17_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10_OnRenderImage;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________17_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________17_VTable vtable;
	};
	struct ________________________17_o {
		________________________17_c* klass;
		void* monitor;
		________________________17_Fields fields;
	};
	struct ________________________18_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
	};
	struct ________________________18_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10_OnRenderImage;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________18_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________18_VTable vtable;
	};
	struct ________________________18_o {
		________________________18_c* klass;
		void* monitor;
		________________________18_Fields fields;
	};
	struct ________________________19_Fields : ________________________3_Fields {
		float _______________________;
		int32_t _1________________________;
		bool _2________________________;
		bool _3________________________;
		struct UnityEngine_Camera_o* _4________________________;
	};
	struct ________________________19_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnRenderImage;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________19_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________19_VTable vtable;
	};
	struct ________________________19_o {
		________________________19_c* klass;
		void* monitor;
		________________________19_Fields fields;
	};
	struct ________________________20_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
	};
	struct ________________________20_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnRenderImage;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________20_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________20_VTable vtable;
	};
	struct ________________________20_o {
		________________________20_c* klass;
		void* monitor;
		________________________20_Fields fields;
	};
	struct ________________________21_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
		float _8________________________;
		float _9________________________;
		float _10________________________;
		float _11________________________;
		float _12________________________;
		float _13________________________;
		float _14________________________;
		float _15________________________;
		float _16________________________;
		float _17________________________;
		float _18________________________;
		float _19________________________;
		float _20________________________;
		bool _21________________________;
		int32_t _22________________________;
	};
	struct ________________________21_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnRenderImage;
	};
	struct ________________________21_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________21_VTable vtable;
	};
	struct ________________________21_o {
		________________________21_c* klass;
		void* monitor;
		________________________21_Fields fields;
	};
	struct ________________________22_Fields : ________________________3_Fields {
		int32_t _______________________;
		struct UnityEngine_Camera_o* _1________________________;
	};
	struct ________________________22_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnRenderImage;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________22_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________22_VTable vtable;
	};
	struct ________________________22_o {
		________________________22_c* klass;
		void* monitor;
		________________________22_Fields fields;
	};
	struct ________________________23_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
		bool _2________________________;
		float _3________________________;
		int32_t _4________________________;
		struct UnityEngine_Camera_o* _5________________________;
	};
	struct ________________________23_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9_OnRenderImage;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________23_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________23_VTable vtable;
	};
	struct ________________________23_o {
		________________________23_c* klass;
		void* monitor;
		________________________23_Fields fields;
	};
	struct ________________________24_Fields : ________________________3_Fields {
		bool _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
		float _8________________________;
		float _9________________________;
		float _10________________________;
		float _11________________________;
		float _12________________________;
		float _13________________________;
		float _14________________________;
		float _15________________________;
		float _16________________________;
		float _17________________________;
		float _18________________________;
		float _19________________________;
		float _20________________________;
		int32_t _21________________________;
		bool _22________________________;
	};
	struct ________________________24_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnRenderImage;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
	};
	struct ________________________24_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________24_VTable vtable;
	};
	struct ________________________24_o {
		________________________24_c* klass;
		void* monitor;
		________________________24_Fields fields;
	};
	struct ________________________25_Fields : ________________________3_Fields {
		struct UnityEngine_Texture_o* _______________________;
		float _1________________________;
	};
	struct ________________________25_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnRenderImage;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________25_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________25_VTable vtable;
	};
	struct ________________________25_o {
		________________________25_c* klass;
		void* monitor;
		________________________25_Fields fields;
	};
	struct ________________________26_Fields : ________________________3_Fields {
		float _______________________;
	};
	struct ________________________26_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9_OnRenderImage;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________26_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________26_VTable vtable;
	};
	struct ________________________26_o {
		________________________26_c* klass;
		void* monitor;
		________________________26_Fields fields;
	};
	struct UnityEngine_Color_Fields {
		float r;
		float g;
		float b;
		float a;
	};
	struct UnityEngine_Color_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Equals;
		VirtualInvokeData _5_ToString;
	};
	struct UnityEngine_Color_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_Color_VTable vtable;
	};
	struct UnityEngine_Color_o {
		UnityEngine_Color_Fields fields;
	};
	struct ________________________27_Fields : ________________________3_Fields {
		struct UnityEngine_Color_o _______________________;
		float _1________________________;
	};
	struct ________________________27_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8_OnRenderImage;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________27_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________27_VTable vtable;
	};
	struct ________________________27_o {
		________________________27_c* klass;
		void* monitor;
		________________________27_Fields fields;
	};
	struct ________________________28_Fields : ________________________3_Fields {
		float _______________________;
		bool _1________________________;
		float _2________________________;
		int32_t _3________________________;
		struct UnityEngine_Camera_o* _4________________________;
	};
	struct ________________________28_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12_OnRenderImage;
	};
	struct ________________________28_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________28_VTable vtable;
	};
	struct ________________________28_o {
		________________________28_c* klass;
		void* monitor;
		________________________28_Fields fields;
	};
	struct ________________________29_Fields : ________________________3_Fields {
		int32_t _______________________;
	};
	struct ________________________29_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10_OnRenderImage;
		VirtualInvokeData _11________________________;
	};
	struct ________________________29_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________29_VTable vtable;
	};
	struct ________________________29_o {
		________________________29_c* klass;
		void* monitor;
		________________________29_Fields fields;
	};
	struct ________________________30_Fields : ________________________3_Fields {
		float _______________________;
		int32_t _1________________________;
		struct UnityEngine_Vector2_o _2________________________;
		int32_t _3________________________;
	};
	struct ________________________30_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10_OnRenderImage;
		VirtualInvokeData _11________________________;
	};
	struct ________________________30_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________30_VTable vtable;
	};
	struct ________________________30_o {
		________________________30_c* klass;
		void* monitor;
		________________________30_Fields fields;
	};
	struct ________________________31_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
	};
	struct ________________________31_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnRenderImage;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________31_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________31_VTable vtable;
	};
	struct ________________________31_o {
		________________________31_c* klass;
		void* monitor;
		________________________31_Fields fields;
	};
	struct ________________________32_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
	};
	struct ________________________32_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12_OnRenderImage;
	};
	struct ________________________32_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________32_VTable vtable;
	};
	struct ________________________32_o {
		________________________32_c* klass;
		void* monitor;
		________________________32_Fields fields;
	};
	struct ________________________33_Fields : ________________________3_Fields {
		float _______________________;
		struct UnityEngine_Vector3_o _1________________________;
		float _2________________________;
	};
	struct ________________________33_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12_OnRenderImage;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________33_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________33_VTable vtable;
	};
	struct ________________________33_o {
		________________________33_c* klass;
		void* monitor;
		________________________33_Fields fields;
	};
	struct ________________________34_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
		bool _2________________________;
	};
	struct ________________________34_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8_OnRenderImage;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________34_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________34_VTable vtable;
	};
	struct ________________________34_o {
		________________________34_c* klass;
		void* monitor;
		________________________34_Fields fields;
	};
	struct ________________________35_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		bool _4________________________;
	};
	struct ________________________35_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12_OnRenderImage;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________35_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________35_VTable vtable;
	};
	struct ________________________35_o {
		________________________35_c* klass;
		void* monitor;
		________________________35_Fields fields;
	};
	struct ________________________________________________1_Fields {
		int32_t value__;
	};
	struct ________________________________________________1_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________1_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________1_VTable vtable;
	};
	struct ________________________________________________1_o {
		________________________________________________1_Fields fields;
	};
	struct ________________________36_Fields : ________________________25_Fields {
		int32_t _______________________;
		int32_t _1________________________;
	};
	struct ________________________36_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnRenderImage;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________36_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________36_VTable vtable;
	};
	struct ________________________36_o {
		________________________36_c* klass;
		void* monitor;
		________________________36_Fields fields;
	};
	struct ________________________37_Fields : ________________________3_Fields {
		struct UnityEngine_Color_o _______________________;
		int32_t _1________________________;
	};
	struct ________________________37_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9_OnRenderImage;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11_Reset;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________37_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________37_VTable vtable;
	};
	struct ________________________37_o {
		________________________37_c* klass;
		void* monitor;
		________________________37_Fields fields;
	};
	struct ________________________38_Fields : ________________________3_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		bool _3________________________;
	};
	struct ________________________38_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5_OnDisable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8_Update;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11_OnRenderImage;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________38_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________38_VTable vtable;
	};
	struct ________________________38_o {
		________________________38_c* klass;
		void* monitor;
		________________________38_Fields fields;
	};
	struct DynamicBone_________________________Fields {
		int32_t value__;
	};
	struct DynamicBone_________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct DynamicBone_________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		DynamicBone_________________________VTable vtable;
	};
	struct DynamicBone_________________________o {
		DynamicBone_________________________Fields fields;
	};
	struct UnityEngine_Quaternion_Fields {
		float x;
		float y;
		float z;
		float w;
	};
	struct UnityEngine_Quaternion_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Equals;
		VirtualInvokeData _5_ToString;
	};
	struct UnityEngine_Quaternion_c {
		Il2CppClass_1 _1;
		struct UnityEngine_Quaternion_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_Quaternion_VTable vtable;
	};
	struct UnityEngine_Quaternion_o {
		UnityEngine_Quaternion_Fields fields;
	};
	struct UnityEngine_Quaternion_StaticFields {
		struct UnityEngine_Quaternion_o identityQuaternion;
	};
	struct __declspec(align(8)) DynamicBone_________________________1_Fields {
		struct UnityEngine_Transform_o* _______________________;
		int32_t _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
		struct UnityEngine_Vector3_o _8________________________;
		struct UnityEngine_Vector3_o _9________________________;
		struct UnityEngine_Vector3_o _10________________________;
		struct UnityEngine_Vector3_o _11________________________;
		struct UnityEngine_Quaternion_o _12________________________;
	};
	struct DynamicBone_________________________1_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct DynamicBone_________________________1_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		DynamicBone_________________________1_VTable vtable;
	};
	struct DynamicBone_________________________1_o {
		DynamicBone_________________________1_c* klass;
		void* monitor;
		DynamicBone_________________________1_Fields fields;
	};
	struct __declspec(align(8)) DynamicBone___c_Fields {
	};
	struct DynamicBone___c_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct DynamicBone___c_c {
		Il2CppClass_1 _1;
		struct DynamicBone___c_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		DynamicBone___c_VTable vtable;
	};
	struct DynamicBone___c_o {
		DynamicBone___c_c* klass;
		void* monitor;
		DynamicBone___c_Fields fields;
	};
	struct DynamicBone___c_StaticFields {
		struct DynamicBone___c_o* __9;
		struct System_Predicate_DynamicBoneCollider__o* __9__42_0;
		struct System_Predicate_Transform__o* __9__42_1;
	};
	struct DynamicBone_Fields : UnityEngine_MonoBehaviour_Fields {
		struct System_Action_o* _______________________;
		struct System_Action_o* _1________________________;
		struct UnityEngine_Transform_o* m_Root;
		float m_UpdateRate;
		float m_Damping;
		struct UnityEngine_AnimationCurve_o* m_DampingDistrib;
		float m_Elasticity;
		struct UnityEngine_AnimationCurve_o* m_ElasticityDistrib;
		float m_Stiffness;
		struct UnityEngine_AnimationCurve_o* m_StiffnessDistrib;
		float m_Inert;
		struct UnityEngine_AnimationCurve_o* m_InertDistrib;
		float m_Radius;
		struct UnityEngine_AnimationCurve_o* m_RadiusDistrib;
		float m_EndLength;
		struct UnityEngine_Vector3_o m_EndOffset;
		struct UnityEngine_Vector3_o m_Gravity;
		struct UnityEngine_Vector3_o m_Force;
		struct System_Collections_Generic_List_DynamicBoneCollider__o* m_Colliders;
		struct System_Collections_Generic_List_Transform__o* m_Exclusions;
		int32_t m_FreezeAxis;
		bool m_DistantDisable;
		struct UnityEngine_Transform_o* m_ReferenceObject;
		float m_DistanceToObject;
		struct UnityEngine_Vector3_o _24________________________;
		struct UnityEngine_Vector3_o _25________________________;
		struct UnityEngine_Vector3_o _26________________________;
		float _27________________________;
		float _28________________________;
		float _29________________________;
		float _30________________________;
		bool _31________________________;
		struct System_Collections_Generic_List_DynamicBone__________________________o* _32________________________;
		float _33________________________;
		bool _34________________________;
		bool _35________________________;
	};
	struct DynamicBone_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
	};
	struct DynamicBone_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		DynamicBone_VTable vtable;
	};
	struct DynamicBone_o {
		DynamicBone_c* klass;
		void* monitor;
		DynamicBone_Fields fields;
	};
	struct DynamicBoneCollider_________________________Fields {
		int32_t value__;
	};
	struct DynamicBoneCollider_________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct DynamicBoneCollider_________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		DynamicBoneCollider_________________________VTable vtable;
	};
	struct DynamicBoneCollider_________________________o {
		DynamicBoneCollider_________________________Fields fields;
	};
	struct DynamicBoneCollider_________________________1_Fields {
		int32_t value__;
	};
	struct DynamicBoneCollider_________________________1_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct DynamicBoneCollider_________________________1_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		DynamicBoneCollider_________________________1_VTable vtable;
	};
	struct DynamicBoneCollider_________________________1_o {
		DynamicBoneCollider_________________________1_Fields fields;
	};
	struct DynamicBoneCollider_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Vector3_o m_Center;
		float m_Radius;
		float m_Height;
		int32_t m_Direction;
		int32_t m_Bound;
	};
	struct DynamicBoneCollider_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct DynamicBoneCollider_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		DynamicBoneCollider_VTable vtable;
	};
	struct DynamicBoneCollider_o {
		DynamicBoneCollider_c* klass;
		void* monitor;
		DynamicBoneCollider_Fields fields;
	};
	struct ________________________39_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* defaultCamera;
		struct UnityEngine_GameObject_o* oculusCameraRig;
		struct UnityEngine_GameObject_o* steamVRCameraRig;
	};
	struct ________________________39_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________39_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________39_VTable vtable;
	};
	struct ________________________39_o {
		________________________39_c* klass;
		void* monitor;
		________________________39_Fields fields;
	};
	struct ________________________40_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Camera_o* _______________________;
	};
	struct ________________________40_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________40_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________40_VTable vtable;
	};
	struct ________________________40_o {
		________________________40_c* klass;
		void* monitor;
		________________________40_Fields fields;
	};
	struct ________________________41_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		struct UnityEngine_Shader_o* _1________________________;
		struct UnityEngine_Material_o* _2________________________;
	};
	struct ________________________41_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________41_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________41_VTable vtable;
	};
	struct ________________________41_o {
		________________________41_c* klass;
		void* monitor;
		________________________41_Fields fields;
	};
	struct UnityEngine_PropertyAttribute_Fields : System_Attribute_Fields {
	};
	struct UnityEngine_PropertyAttribute_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_get_TypeId;
		VirtualInvokeData _5_Match;
		VirtualInvokeData _6_IsDefaultAttribute;
	};
	struct UnityEngine_PropertyAttribute_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_PropertyAttribute_VTable vtable;
	};
	struct UnityEngine_PropertyAttribute_o {
		UnityEngine_PropertyAttribute_c* klass;
		void* monitor;
		UnityEngine_PropertyAttribute_Fields fields;
	};
	struct ________________________42_Fields : UnityEngine_PropertyAttribute_Fields {
		struct System_Type_o* _______________________;
	};
	struct ________________________42_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_get_TypeId;
		VirtualInvokeData _5_Match;
		VirtualInvokeData _6_IsDefaultAttribute;
	};
	struct ________________________42_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________42_VTable vtable;
	};
	struct ________________________42_o {
		________________________42_c* klass;
		void* monitor;
		________________________42_Fields fields;
	};
	struct ________________________43_Fields : UnityEngine_MonoBehaviour_Fields {
	};
	struct ________________________43_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________43_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________43_VTable vtable;
	};
	struct ________________________43_o {
		________________________43_c* klass;
		void* monitor;
		________________________43_Fields fields;
	};
	struct ________________________44_Fields : UnityEngine_MonoBehaviour_Fields {
		bool enableYaw;
		bool autoRecenterPitch;
		bool autoRecenterRoll;
		struct UnityEngine_Transform_o* _______________________;
		struct UnityEngine_Transform_o* _4________________________;
		struct UnityEngine_Transform_o* _5________________________;
		struct UnityEngine_Vector3_o _6________________________;
	};
	struct ________________________44_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________44_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________44_VTable vtable;
	};
	struct ________________________44_o {
		________________________44_c* klass;
		void* monitor;
		________________________44_Fields fields;
	};
	struct ________________________45_Fields : UnityEngine_MonoBehaviour_Fields {
		float _1________________________;
		float _2________________________;
		struct UnityEngine_AudioClip_array* _3________________________;
		struct UnityEngine_AudioClip_o* _4________________________;
		float _5________________________;
		float _6________________________;
		struct UnityEngine_AudioClip_array* _7________________________;
		struct UnityEngine_AudioClip_o* _8________________________;
		float _9________________________;
		float _10________________________;
		struct UnityEngine_AudioClip_array* _11________________________;
		struct UnityEngine_AudioClip_o* _12________________________;
		float _13________________________;
		float _14________________________;
		struct UnityEngine_AudioClip_array* _15________________________;
		struct UnityEngine_AudioClip_o* _16________________________;
		float _17________________________;
		float _18________________________;
		struct UnityEngine_AudioClip_array* _19________________________;
		struct UnityEngine_AudioClip_o* _20________________________;
		float _21________________________;
		float _22________________________;
		struct UnityEngine_AudioClip_array* _23________________________;
		struct UnityEngine_AudioClip_o* _24________________________;
		float _25________________________;
		float _26________________________;
		struct UnityEngine_AudioClip_array* _27________________________;
		struct UnityEngine_AudioClip_o* _28________________________;
		float _29________________________;
		float _30________________________;
		struct UnityEngine_AudioClip_o* _31________________________;
		struct UnityEngine_AudioClip_o* _32________________________;
		struct UnityEngine_AudioClip_o* _33________________________;
		struct UnityEngine_AudioClip_o* _34________________________;
		struct UnityEngine_AudioClip_o* _35________________________;
		struct UnityEngine_AudioClip_o* _36________________________;
		struct UnityEngine_AudioClip_o* _37________________________;
		struct UnityEngine_AudioClip_o* _38________________________;
		struct UnityEngine_AudioClip_o* _39________________________;
		struct UnityEngine_AudioClip_o* _40________________________;
		struct UnityEngine_AudioClip_o* _41________________________;
		struct UnityEngine_AudioClip_o* _42________________________;
		struct UnityEngine_AudioClip_array* _43________________________;
		struct UnityEngine_AudioClip_o* _44________________________;
		float _45________________________;
		float _46________________________;
	};
	struct ________________________45_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________45_c {
		Il2CppClass_1 _1;
		struct ________________________45_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________45_VTable vtable;
	};
	struct ________________________45_o {
		________________________45_c* klass;
		void* monitor;
		________________________45_Fields fields;
	};
	struct ________________________45_StaticFields {
		struct ________________________45_o* _______________________;
	};
	struct UnityEngine_LayerMask_Fields {
		int32_t m_Mask;
	};
	struct UnityEngine_LayerMask_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct UnityEngine_LayerMask_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_LayerMask_VTable vtable;
	};
	struct UnityEngine_LayerMask_o {
		UnityEngine_LayerMask_Fields fields;
	};
	struct UnityEngine_RaycastHit_Fields {
		struct UnityEngine_Vector3_o m_Point;
		struct UnityEngine_Vector3_o m_Normal;
		uint32_t m_FaceID;
		float m_Distance;
		struct UnityEngine_Vector2_o m_UV;
		int32_t m_Collider;
	};
	struct UnityEngine_RaycastHit_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct UnityEngine_RaycastHit_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_RaycastHit_VTable vtable;
	};
	struct UnityEngine_RaycastHit_o {
		UnityEngine_RaycastHit_Fields fields;
	};
	struct ________________________46_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_LayerMask_o _______________________;
		int32_t _1________________________;
		bool _2________________________;
		struct UnityEngine_Texture_array* _3________________________;
		float _4________________________;
		bool _5________________________;
		float _6________________________;
		float _7________________________;
		bool _8________________________;
		float _9________________________;
		struct UnityEngine_Transform_o* _10________________________;
		struct UnityEngine_Transform_o* _11________________________;
		struct UnityEngine_LineRenderer_o* _12________________________;
		struct UnityEngine_RaycastHit_o _13________________________;
		int32_t _14________________________;
		int32_t _15________________________;
		float _16________________________;
		float _17________________________;
		float _18________________________;
		float _19________________________;
	};
	struct ________________________46_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________46_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________46_VTable vtable;
	};
	struct ________________________46_o {
		________________________46_c* klass;
		void* monitor;
		________________________46_Fields fields;
	};
	struct ________________________47_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Transform_o* _______________________;
		float _1________________________;
		float _2________________________;
		struct UnityEngine_LineRenderer_o* _3________________________;
		int32_t _4________________________;
		float _5________________________;
		float _6________________________;
	};
	struct ________________________47_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________47_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________47_VTable vtable;
	};
	struct ________________________47_o {
		________________________47_c* klass;
		void* monitor;
		________________________47_Fields fields;
	};
	struct ________________________48_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		bool _1________________________;
		struct UnityEngine_AudioSource_o* _2________________________;
	};
	struct ________________________48_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________48_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________48_VTable vtable;
	};
	struct ________________________48_o {
		________________________48_c* klass;
		void* monitor;
		________________________48_Fields fields;
	};
	struct ________________________49_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Light_o* _______________________;
		struct UnityEngine_ParticleSystem_o* _1________________________;
		int32_t _2________________________;
		bool _3________________________;
		struct UnityEngine_ParticleSystem_o* _4________________________;
	};
	struct ________________________49_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________49_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________49_VTable vtable;
	};
	struct ________________________49_o {
		________________________49_c* klass;
		void* monitor;
		________________________49_Fields fields;
	};
	struct ________________________50_Fields {
		int32_t value__;
	};
	struct ________________________50_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________50_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________50_VTable vtable;
	};
	struct ________________________50_o {
		________________________50_Fields fields;
	};
	struct ________________________51_Fields : UnityEngine_MonoBehaviour_Fields {
		struct System_String_array* _1________________________;
		int32_t _2________________________;
		int32_t _3________________________;
		struct UnityEngine_Transform_array* _4________________________;
		struct UnityEngine_ParticleSystem_array* _5________________________;
		int32_t _6________________________;
		struct UnityEngine_Transform_o* _7________________________;
		struct UnityEngine_Transform_o* _8________________________;
		struct UnityEngine_Transform_o* _9________________________;
		struct UnityEngine_Transform_o* _10________________________;
		struct UnityEngine_Transform_o* _11________________________;
		struct UnityEngine_Transform_o* _12________________________;
		struct UnityEngine_Transform_o* _13________________________;
		struct UnityEngine_Transform_o* _14________________________;
		struct UnityEngine_Transform_o* _15________________________;
		struct UnityEngine_Transform_o* _16________________________;
		struct UnityEngine_Transform_o* _17________________________;
		struct UnityEngine_Transform_o* _18________________________;
		struct UnityEngine_Transform_o* _19________________________;
		struct UnityEngine_Transform_o* _20________________________;
		struct UnityEngine_Transform_o* _21________________________;
		struct UnityEngine_Transform_o* _22________________________;
		struct UnityEngine_Transform_o* _23________________________;
		struct UnityEngine_Transform_o* _24________________________;
		struct UnityEngine_Transform_o* _25________________________;
		struct UnityEngine_Transform_o* _26________________________;
		struct UnityEngine_Transform_o* _27________________________;
		struct UnityEngine_Transform_o* _28________________________;
		struct UnityEngine_Transform_o* _29________________________;
		struct UnityEngine_Transform_o* _30________________________;
		struct UnityEngine_Transform_o* _31________________________;
		struct UnityEngine_Transform_o* _32________________________;
		struct UnityEngine_Transform_o* _33________________________;
		struct UnityEngine_Transform_o* _34________________________;
	};
	struct ________________________51_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________51_c {
		Il2CppClass_1 _1;
		struct ________________________51_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________51_VTable vtable;
	};
	struct ________________________51_o {
		________________________51_c* klass;
		void* monitor;
		________________________51_Fields fields;
	};
	struct ________________________51_StaticFields {
		struct ________________________51_o* _______________________;
	};
	struct ________________________52_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_LayerMask_o _______________________;
		struct UnityEngine_Texture_array* _1________________________;
		float _2________________________;
		bool _3________________________;
		int32_t _4________________________;
		float _5________________________;
		float _6________________________;
		bool _7________________________;
		float _8________________________;
		bool _9________________________;
		float _10________________________;
		float _11________________________;
		struct UnityEngine_Transform_o* _12________________________;
		struct UnityEngine_Transform_o* _13________________________;
		struct UnityEngine_LineRenderer_o* _14________________________;
		struct UnityEngine_RaycastHit_o _15________________________;
		int32_t _16________________________;
		int32_t _17________________________;
		int32_t _18________________________;
		float _19________________________;
		float _20________________________;
	};
	struct ________________________52_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________52_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________52_VTable vtable;
	};
	struct ________________________52_o {
		________________________52_c* klass;
		void* monitor;
		________________________52_Fields fields;
	};
	struct ________________________53_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		bool _1________________________;
	};
	struct ________________________53_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________53_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________53_VTable vtable;
	};
	struct ________________________53_o {
		________________________53_c* klass;
		void* monitor;
		________________________53_Fields fields;
	};
	struct ________________________54_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Transform_array* _1________________________;
		struct System_Int32_array* _2________________________;
		struct UnityEngine_Transform_o* _3________________________;
		struct UnityEngine_AudioClip_array* _4________________________;
		struct System_Int32_array* _5________________________;
		struct System_Collections_Generic_Dictionary_Transform__Transform____o* _6________________________;
		struct System_Collections_Generic_Dictionary_AudioClip__AudioSource____o* _7________________________;
	};
	struct ________________________54_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________54_c {
		Il2CppClass_1 _1;
		struct ________________________54_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________54_VTable vtable;
	};
	struct ________________________54_o {
		________________________54_c* klass;
		void* monitor;
		________________________54_Fields fields;
	};
	struct ________________________54_StaticFields {
		struct ________________________54_o* _______________________;
	};
	struct ________________________55_Fields : UnityEngine_MonoBehaviour_Fields {
	};
	struct ________________________55_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________55_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________55_VTable vtable;
	};
	struct ________________________55_o {
		________________________55_c* klass;
		void* monitor;
		________________________55_Fields fields;
	};
	struct ________________________56_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _______________________;
		struct UnityEngine_LayerMask_o _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
		bool _6________________________;
		struct UnityEngine_ParticleSystem_array* _7________________________;
		struct UnityEngine_ParticleSystem_array* _8________________________;
		struct UnityEngine_Transform_o* _9________________________;
		struct UnityEngine_RaycastHit_o _10________________________;
		bool _11________________________;
		bool _12________________________;
		float _13________________________;
	};
	struct ________________________56_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________56_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________56_VTable vtable;
	};
	struct ________________________56_o {
		________________________56_c* klass;
		void* monitor;
		________________________56_Fields fields;
	};
	struct ________________________57_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		struct UnityEngine_Vector3_o _3________________________;
		bool _4________________________;
		struct UnityEngine_Transform_o* _5________________________;
		struct UnityEngine_MeshRenderer_o* _6________________________;
		int32_t _7________________________;
		bool _8________________________;
		bool _9________________________;
		struct UnityEngine_Color_o _10________________________;
		struct UnityEngine_Color_o _11________________________;
		int32_t _12________________________;
	};
	struct ________________________57_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________57_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________57_VTable vtable;
	};
	struct ________________________57_o {
		________________________57_c* klass;
		void* monitor;
		________________________57_Fields fields;
	};
	struct ________________________58_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Transform_o* _______________________;
		struct UnityEngine_Vector3_o _1________________________;
		bool _2________________________;
		bool _3________________________;
		float _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
	};
	struct ________________________58_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________58_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________58_VTable vtable;
	};
	struct ________________________58_o {
		________________________58_c* klass;
		void* monitor;
		________________________58_Fields fields;
	};
	struct ________________________59_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		struct UnityEngine_Vector3_o _3________________________;
	};
	struct ________________________59_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________59_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________59_VTable vtable;
	};
	struct ________________________59_o {
		________________________59_c* klass;
		void* monitor;
		________________________59_Fields fields;
	};
	struct ________________________60_Fields : UnityEngine_MonoBehaviour_Fields {
		struct System_Collections_Generic_List_ParticleCollisionEvent__o* _______________________;
	};
	struct ________________________60_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________60_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________60_VTable vtable;
	};
	struct ________________________60_o {
		________________________60_c* klass;
		void* monitor;
		________________________60_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________2_Fields {
		int32_t _______________________;
		bool _1________________________;
		float _2________________________;
		int32_t _3________________________;
		int32_t _4________________________;
		float _5________________________;
		struct System_Action_o* _6________________________;
	};
	struct ________________________________________________2_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________2_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________2_VTable vtable;
	};
	struct ________________________________________________2_o {
		________________________________________________2_c* klass;
		void* monitor;
		________________________________________________2_Fields fields;
	};
	struct ________________________61_Fields : UnityEngine_MonoBehaviour_Fields {
		struct System_Collections_Generic_List__________________________________________________o* _1________________________;
		struct System_Collections_Generic_List_int__o* _2________________________;
		int32_t _3________________________;
	};
	struct ________________________61_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________61_c {
		Il2CppClass_1 _1;
		struct ________________________61_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________61_VTable vtable;
	};
	struct ________________________61_o {
		________________________61_c* klass;
		void* monitor;
		________________________61_Fields fields;
	};
	struct ________________________61_StaticFields {
		struct ________________________61_o* _______________________;
	};
	struct ________________________62_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Transform_o* _______________________;
		struct UnityEngine_Transform_o* _1________________________;
		struct UnityEngine_RaycastHit_o _2________________________;
		bool _3________________________;
		float _4________________________;
		float _5________________________;
	};
	struct ________________________62_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________62_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________62_VTable vtable;
	};
	struct ________________________62_o {
		________________________62_c* klass;
		void* monitor;
		________________________62_Fields fields;
	};
	struct ________________________63_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_ParticleSystem_o* _______________________;
		struct UnityEngine_Transform_o* _1________________________;
		float _2________________________;
		struct UnityEngine_Vector3_o _3________________________;
		struct UnityEngine_Vector3_o _4________________________;
		bool _5________________________;
		bool _6________________________;
	};
	struct ________________________63_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________63_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________63_VTable vtable;
	};
	struct ________________________63_o {
		________________________63_c* klass;
		void* monitor;
		________________________63_Fields fields;
	};
	struct ________________________64_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Transform_o* _______________________;
		struct UnityEngine_MeshRenderer_o* _1________________________;
		float _2________________________;
		float _3________________________;
		struct UnityEngine_Vector3_o _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
		float _8________________________;
		bool _9________________________;
		float _10________________________;
		int32_t _11________________________;
	};
	struct ________________________64_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________64_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________64_VTable vtable;
	};
	struct ________________________64_o {
		________________________64_c* klass;
		void* monitor;
		________________________64_Fields fields;
	};
	struct ________________________65_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
	};
	struct ________________________65_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________65_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________65_VTable vtable;
	};
	struct ________________________65_o {
		________________________65_c* klass;
		void* monitor;
		________________________65_Fields fields;
	};
	struct __declspec(align(8)) ________________________66_Fields {
	};
	struct ________________________66_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________66_c {
		Il2CppClass_1 _1;
		struct ________________________66_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________66_VTable vtable;
	};
	struct ________________________66_o {
		________________________66_c* klass;
		void* monitor;
		________________________66_Fields fields;
	};
	struct ________________________66_StaticFields {
		struct System_Collections_Generic_Dictionary_MethodInfo__ParameterInfo____o* _______________________;
	};
	struct __declspec(align(8)) FoldoutList_Fields {
		struct System_Collections_Generic_List_bool__o* foldouts;
		bool mainFoldout;
		struct UnityEngine_Vector2_o scrollPos;
	};
	struct FoldoutList_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct FoldoutList_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		FoldoutList_VTable vtable;
	};
	struct FoldoutList_o {
		FoldoutList_c* klass;
		void* monitor;
		FoldoutList_Fields fields;
	};
	struct ________________________67_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		bool _1________________________;
		struct ________________________78_o* _2________________________;
		struct UnityEngine_Material_o* _3________________________;
		bool _4________________________;
		struct UnityEngine_Vector3_o _5________________________;
		struct ________________________83_array* _6________________________;
		struct ________________________84_array* _7________________________;
		struct ________________________91_o* _8________________________;
		struct UnityEngine_Renderer_o* _9________________________;
		struct UnityEngine_Material_o* _10________________________;
		int32_t _11________________________;
		bool _12________________________;
		float _13________________________;
	};
	struct ________________________67_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________67_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________67_VTable vtable;
	};
	struct ________________________67_o {
		________________________67_c* klass;
		void* monitor;
		________________________67_Fields fields;
	};
	struct ________________________68_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* _______________________;
		float _1________________________;
	};
	struct ________________________68_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________68_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________68_VTable vtable;
	};
	struct ________________________68_o {
		________________________68_c* klass;
		void* monitor;
		________________________68_Fields fields;
	};
	struct ________________________69_Fields {
		int32_t value__;
	};
	struct ________________________69_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________69_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________69_VTable vtable;
	};
	struct ________________________69_o {
		________________________69_Fields fields;
	};
	struct ________________________70_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		int32_t _3________________________;
		struct UnityEngine_GameObject_o* _4________________________;
		struct UnityEngine_GameObject_o* _5________________________;
		struct UnityEngine_AnimationCurve_o* _6________________________;
		float _7________________________;
		bool _8________________________;
		bool _9________________________;
		bool _10________________________;
		bool _11________________________;
		bool _12________________________;
		bool _13________________________;
		bool _14________________________;
		bool _15________________________;
		struct ________________________78_o* _16________________________;
		struct UnityEngine_Transform_o* _17________________________;
		struct UnityEngine_Transform_o* _18________________________;
		struct UnityEngine_Transform_o* _19________________________;
		struct UnityEngine_Transform_o* _20________________________;
		struct UnityEngine_Vector3_o _21________________________;
		struct UnityEngine_Vector3_o _22________________________;
		struct UnityEngine_Vector3_o _23________________________;
		struct UnityEngine_RaycastHit_o _24________________________;
		struct UnityEngine_Vector3_o _25________________________;
		struct UnityEngine_Vector3_o _26________________________;
		float _27________________________;
		float _28________________________;
		float _29________________________;
		float _30________________________;
		float _31________________________;
		int32_t _32________________________;
		int32_t _33________________________;
		int32_t _34________________________;
		bool _35________________________;
		bool _36________________________;
		struct UnityEngine_Vector3_o _37________________________;
		bool _38________________________;
	};
	struct ________________________70_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________70_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________70_VTable vtable;
	};
	struct ________________________70_o {
		________________________70_c* klass;
		void* monitor;
		________________________70_Fields fields;
	};
	struct ________________________71_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* _______________________;
		struct UnityEngine_GameObject_o* _1________________________;
		bool _2________________________;
		float _3________________________;
		bool _4________________________;
		struct UnityEngine_Vector3_o _5________________________;
		int32_t _6________________________;
	};
	struct ________________________71_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________71_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________71_VTable vtable;
	};
	struct ________________________71_o {
		________________________71_c* klass;
		void* monitor;
		________________________71_Fields fields;
	};
	struct ________________________72_Fields : UnityEngine_MonoBehaviour_Fields {
		bool _______________________;
		float _1________________________;
		int32_t _2________________________;
		struct UnityEngine_Material_o* _3________________________;
		float _4________________________;
		bool _5________________________;
		bool _6________________________;
		float _7________________________;
		float _8________________________;
	};
	struct ________________________72_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________72_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________72_VTable vtable;
	};
	struct ________________________72_o {
		________________________72_c* klass;
		void* monitor;
		________________________72_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________3_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________73_o* _2________________________;
	};
	struct ________________________________________________3_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________________________________3_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________3_VTable vtable;
	};
	struct ________________________________________________3_o {
		________________________________________________3_c* klass;
		void* monitor;
		________________________________________________3_Fields fields;
	};
	struct ________________________73_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		int32_t _1________________________;
		struct UnityEngine_Color_o _2________________________;
		struct UnityEngine_Material_o* _3________________________;
		float _4________________________;
		float _5________________________;
		float _6________________________;
	};
	struct ________________________73_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________73_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________73_VTable vtable;
	};
	struct ________________________73_o {
		________________________73_c* klass;
		void* monitor;
		________________________73_Fields fields;
	};
	struct ________________________74_Fields : UnityEngine_MonoBehaviour_Fields {
		bool _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
		struct UnityEngine_GameObject_o* _6________________________;
		struct UnityEngine_GameObject_o* _7________________________;
		struct UnityEngine_GameObject_o* _8________________________;
		struct UnityEngine_GameObject_o* _9________________________;
		struct UnityEngine_GameObject_o* _10________________________;
		struct UnityEngine_GameObject_o* _11________________________;
		struct ________________________78_o* _12________________________;
		struct UnityEngine_Transform_o* _13________________________;
		struct UnityEngine_Transform_o* _14________________________;
		bool _15________________________;
		struct UnityEngine_LineRenderer_o* _16________________________;
		int32_t _17________________________;
		struct UnityEngine_RaycastHit_o _18________________________;
	};
	struct ________________________74_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________74_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________74_VTable vtable;
	};
	struct ________________________74_o {
		________________________74_c* klass;
		void* monitor;
		________________________74_Fields fields;
	};
	struct ________________________75_Fields : UnityEngine_MonoBehaviour_Fields {
		bool _______________________;
		float _1________________________;
		bool _2________________________;
		struct ________________________78_o* _3________________________;
	};
	struct ________________________75_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________75_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________75_VTable vtable;
	};
	struct ________________________75_o {
		________________________75_c* klass;
		void* monitor;
		________________________75_Fields fields;
	};
	struct ________________________76_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		bool _1________________________;
	};
	struct ________________________76_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________76_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________76_VTable vtable;
	};
	struct ________________________76_o {
		________________________76_c* klass;
		void* monitor;
		________________________76_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________4_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________77_o* _2________________________;
	};
	struct ________________________________________________4_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
		VirtualInvokeData _15________________________;
	};
	struct ________________________________________________4_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________4_VTable vtable;
	};
	struct ________________________________________________4_o {
		________________________________________________4_c* klass;
		void* monitor;
		________________________________________________4_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________5_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________77_o* _2________________________;
	};
	struct ________________________________________________5_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________________________________5_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________5_VTable vtable;
	};
	struct ________________________________________________5_o {
		________________________________________________5_c* klass;
		void* monitor;
		________________________________________________5_Fields fields;
	};
	struct ________________________77_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		int32_t _1________________________;
		int32_t _2________________________;
		struct UnityEngine_LayerMask_o _3________________________;
		int32_t _4________________________;
		int32_t _5________________________;
		int32_t _6________________________;
		struct UnityEngine_RenderTexture_o* _7________________________;
		struct UnityEngine_Camera_o* _8________________________;
		struct UnityEngine_GameObject_o* _9________________________;
		struct UnityEngine_Vector3_o _10________________________;
		struct UnityEngine_Quaternion_o _11________________________;
		struct UnityEngine_Transform_o* _12________________________;
		bool _13________________________;
		bool _14________________________;
		struct UnityEngine_WaitForSeconds_o* _15________________________;
		struct UnityEngine_WaitForSeconds_o* _16________________________;
		int32_t _18________________________;
		bool _19________________________;
	};
	struct ________________________77_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________77_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________77_VTable vtable;
	};
	struct ________________________77_o {
		________________________77_c* klass;
		void* monitor;
		________________________77_Fields fields;
	};
	struct ________________________________________________6_Fields {
		int32_t value__;
	};
	struct ________________________________________________6_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________6_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________6_VTable vtable;
	};
	struct ________________________________________________6_o {
		________________________________________________6_Fields fields;
	};
	struct ________________________________________________7_Fields {
		int32_t value__;
	};
	struct ________________________________________________7_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________7_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________7_VTable vtable;
	};
	struct ________________________________________________7_o {
		________________________________________________7_Fields fields;
	};
	struct ________________________78_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _______________________;
		float _1________________________;
		float _2________________________;
		bool _3________________________;
		struct UnityEngine_GameObject_o* _4________________________;
		struct UnityEngine_Vector3_o _5________________________;
		float _6________________________;
		bool _7________________________;
		float _8________________________;
		bool _9________________________;
		int32_t _10________________________;
		float _11________________________;
		float _12________________________;
		struct UnityEngine_LayerMask_o _13________________________;
		struct System_EventHandler__________________________o* _14________________________;
		struct System_EventHandler_o* _15________________________;
		struct UnityEngine_GameObject_array* _16________________________;
		struct System_Single_array* _17________________________;
		struct UnityEngine_GameObject_array* _18________________________;
		struct System_Single_array* _19________________________;
		int32_t _20________________________;
		int32_t _21________________________;
		int32_t _22________________________;
		int32_t _23________________________;
		bool _24________________________;
	};
	struct ________________________78_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________78_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________78_VTable vtable;
	};
	struct ________________________78_o {
		________________________78_c* klass;
		void* monitor;
		________________________78_Fields fields;
	};
	struct __declspec(align(8)) System_EventArgs_Fields {
	};
	struct System_EventArgs_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct System_EventArgs_c {
		Il2CppClass_1 _1;
		struct System_EventArgs_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_EventArgs_VTable vtable;
	};
	struct System_EventArgs_o {
		System_EventArgs_c* klass;
		void* monitor;
		System_EventArgs_Fields fields;
	};
	struct System_EventArgs_StaticFields {
		struct System_EventArgs_o* Empty;
	};
	struct ________________________79_Fields : System_EventArgs_Fields {
		struct UnityEngine_RaycastHit_o _______________________;
	};
	struct ________________________79_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________79_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________79_VTable vtable;
	};
	struct ________________________79_o {
		________________________79_c* klass;
		void* monitor;
		________________________79_Fields fields;
	};
	struct ________________________80_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		bool _4________________________;
		bool _5________________________;
		struct UnityEngine_Light_o* _6________________________;
		float _7________________________;
		float _8________________________;
		float _9________________________;
		bool _10________________________;
		bool _11________________________;
		bool _12________________________;
		bool _13________________________;
		bool _14________________________;
		bool _15________________________;
		bool _16________________________;
		bool _17________________________;
		bool _18________________________;
		struct ________________________78_o* _19________________________;
		bool _20________________________;
	};
	struct ________________________80_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________80_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________80_VTable vtable;
	};
	struct ________________________80_o {
		________________________80_c* klass;
		void* monitor;
		________________________80_Fields fields;
	};
	struct ________________________81_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________78_o* _______________________;
		struct UnityEngine_ParticleSystem_array* _1________________________;
		bool _2________________________;
	};
	struct ________________________81_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________81_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________81_VTable vtable;
	};
	struct ________________________81_o {
		________________________81_c* klass;
		void* monitor;
		________________________81_Fields fields;
	};
	struct ________________________82_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _______________________;
		float _1________________________;
		float _2________________________;
		struct UnityEngine_Vector3_o _3________________________;
		float _4________________________;
		float _5________________________;
		bool _6________________________;
		bool _7________________________;
		struct UnityEngine_Transform_o* _8________________________;
		struct ________________________78_o* _9________________________;
		bool _10________________________;
		bool _11________________________;
	};
	struct ________________________82_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________82_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________82_VTable vtable;
	};
	struct ________________________82_o {
		________________________82_c* klass;
		void* monitor;
		________________________82_Fields fields;
	};
	struct ________________________83_Fields : UnityEngine_MonoBehaviour_Fields {
		struct System_String_o* _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		bool _5________________________;
		bool _6________________________;
		bool _7________________________;
		struct UnityEngine_Material_o* _8________________________;
		struct UnityEngine_Color_o _9________________________;
		struct UnityEngine_Color_o _10________________________;
		float _11________________________;
		float _12________________________;
		bool _13________________________;
		bool _14________________________;
		bool _15________________________;
		bool _16________________________;
		bool _17________________________;
		bool _18________________________;
		bool _19________________________;
		bool _20________________________;
		struct ________________________78_o* _21________________________;
		bool _22________________________;
	};
	struct ________________________83_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________83_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________83_VTable vtable;
	};
	struct ________________________83_o {
		________________________83_c* klass;
		void* monitor;
		________________________83_Fields fields;
	};
	struct ________________________84_Fields : UnityEngine_MonoBehaviour_Fields {
		struct System_String_o* _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
		bool _6________________________;
		bool _7________________________;
		struct UnityEngine_Material_o* _8________________________;
		struct UnityEngine_Material_o* _9________________________;
		float _10________________________;
		float _11________________________;
		bool _12________________________;
		bool _13________________________;
		bool _14________________________;
		bool _15________________________;
		bool _16________________________;
		bool _17________________________;
		bool _18________________________;
		bool _19________________________;
		bool _20________________________;
		struct ________________________78_o* _21________________________;
		bool _22________________________;
	};
	struct ________________________84_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________84_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________84_VTable vtable;
	};
	struct ________________________84_o {
		________________________84_c* klass;
		void* monitor;
		________________________84_Fields fields;
	};
	struct ________________________85_Fields {
		int32_t value__;
	};
	struct ________________________85_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________85_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________85_VTable vtable;
	};
	struct ________________________85_o {
		________________________85_Fields fields;
	};
	struct ________________________86_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _______________________;
	};
	struct ________________________86_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________86_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________86_VTable vtable;
	};
	struct ________________________86_o {
		________________________86_c* klass;
		void* monitor;
		________________________86_Fields fields;
	};
	struct ________________________87_Fields : UnityEngine_MonoBehaviour_Fields {
	};
	struct ________________________87_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________87_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________87_VTable vtable;
	};
	struct ________________________87_o {
		________________________87_c* klass;
		void* monitor;
		________________________87_Fields fields;
	};
	struct ________________________88_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________78_o* _______________________;
		bool _1________________________;
	};
	struct ________________________88_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________88_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________88_VTable vtable;
	};
	struct ________________________88_o {
		________________________88_c* klass;
		void* monitor;
		________________________88_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________8_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________89_o* _2________________________;
	};
	struct ________________________________________________8_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
		VirtualInvokeData _15________________________;
	};
	struct ________________________________________________8_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________8_VTable vtable;
	};
	struct ________________________________________________8_o {
		________________________________________________8_c* klass;
		void* monitor;
		________________________________________________8_Fields fields;
	};
	struct ________________________89_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _______________________;
		int32_t _1________________________;
		int32_t _2________________________;
		int32_t _3________________________;
		float _4________________________;
		bool _5________________________;
		struct UnityEngine_Material_o* _6________________________;
		int32_t _7________________________;
		int32_t _8________________________;
		int32_t _9________________________;
		float _10________________________;
		bool _11________________________;
		bool _12________________________;
	};
	struct ________________________89_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________89_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________89_VTable vtable;
	};
	struct ________________________89_o {
		________________________89_c* klass;
		void* monitor;
		________________________89_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________9_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________90_o* _2________________________;
	};
	struct ________________________________________________9_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________________________________9_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________9_VTable vtable;
	};
	struct ________________________________________________9_o {
		________________________________________________9_c* klass;
		void* monitor;
		________________________________________________9_Fields fields;
	};
	struct ________________________90_Fields : UnityEngine_MonoBehaviour_Fields {
		bool _______________________;
		int32_t _1________________________;
		int32_t _2________________________;
		int32_t _3________________________;
		int32_t _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
		float _8________________________;
		bool _9________________________;
	};
	struct ________________________90_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________90_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________90_VTable vtable;
	};
	struct ________________________90_o {
		________________________90_c* klass;
		void* monitor;
		________________________90_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________10_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________91_o* _2________________________;
	};
	struct ________________________________________________10_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________________________________10_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________10_VTable vtable;
	};
	struct ________________________________________________10_o {
		________________________________________________10_c* klass;
		void* monitor;
		________________________________________________10_Fields fields;
	};
	struct ________________________91_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Material_array* _______________________;
		int32_t _1________________________;
		int32_t _2________________________;
		float _3________________________;
		int32_t _4________________________;
		struct UnityEngine_Vector2_o _5________________________;
		bool _6________________________;
		bool _7________________________;
		bool _8________________________;
		bool _9________________________;
		bool _10________________________;
		bool _11________________________;
		bool _12________________________;
		int32_t _13________________________;
		int32_t _14________________________;
		int32_t _15________________________;
		bool _16________________________;
		bool _17________________________;
		struct UnityEngine_Renderer_o* _18________________________;
		struct UnityEngine_Material_o* _19________________________;
		int32_t _20________________________;
		int32_t _21________________________;
		int32_t _22________________________;
		int32_t _23________________________;
		struct UnityEngine_WaitForSeconds_o* _24________________________;
	};
	struct ________________________91_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________91_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________91_VTable vtable;
	};
	struct ________________________91_o {
		________________________91_c* klass;
		void* monitor;
		________________________91_Fields fields;
	};
	struct ________________________92_Fields {
		int32_t value__;
	};
	struct ________________________92_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________92_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________92_VTable vtable;
	};
	struct ________________________92_o {
		________________________92_Fields fields;
	};
	struct OpusCodec_________________________Fields {
		int32_t value__;
	};
	struct OpusCodec_________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct OpusCodec_________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		OpusCodec_________________________VTable vtable;
	};
	struct OpusCodec_________________________o {
		OpusCodec_________________________Fields fields;
	};
	struct OpusCodec_________________________1_Fields {
		int32_t value__;
	};
	struct OpusCodec_________________________1_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct OpusCodec_________________________1_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		OpusCodec_________________________1_VTable vtable;
	};
	struct OpusCodec_________________________1_o {
		OpusCodec_________________________1_Fields fields;
	};
	struct __declspec(align(8)) OpusCodec_Fields {
		struct ________________________1376_o* _______________________;
		struct ________________________1375_o* _2________________________;
		int32_t _3________________________;
		int32_t _4________________________;
		int32_t _5________________________;
		int32_t _6________________________;
		bool _7________________________;
	};
	struct OpusCodec_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct OpusCodec_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		OpusCodec_VTable vtable;
	};
	struct OpusCodec_o {
		OpusCodec_c* klass;
		void* monitor;
		OpusCodec_Fields fields;
	};
	struct ________________________93_Fields {
		int32_t value__;
	};
	struct ________________________93_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________93_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________93_VTable vtable;
	};
	struct ________________________93_o {
		________________________93_Fields fields;
	};
	struct ________________________94_Fields {
		int32_t value__;
	};
	struct ________________________94_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________94_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________94_VTable vtable;
	};
	struct ________________________94_o {
		________________________94_Fields fields;
	};
	struct ________________________95_Fields {
		int32_t value__;
	};
	struct ________________________95_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________95_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________95_VTable vtable;
	};
	struct ________________________95_o {
		________________________95_Fields fields;
	};
	struct ________________________96_Fields {
		int32_t value__;
	};
	struct ________________________96_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________96_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________96_VTable vtable;
	};
	struct ________________________96_o {
		________________________96_Fields fields;
	};
	struct ________________________97_Fields {
		int32_t value__;
	};
	struct ________________________97_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________97_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________97_VTable vtable;
	};
	struct ________________________97_o {
		________________________97_Fields fields;
	};
	struct ________________________98_Fields {
		int32_t value__;
	};
	struct ________________________98_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________98_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________98_VTable vtable;
	};
	struct ________________________98_o {
		________________________98_Fields fields;
	};
	struct ________________________99_Fields {
		int32_t value__;
	};
	struct ________________________99_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________99_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________99_VTable vtable;
	};
	struct ________________________99_o {
		________________________99_Fields fields;
	};
	struct ________________________________________________11_Fields {
		float _______________________;
		int32_t _1________________________;
		int32_t _2________________________;
	};
	struct ________________________________________________11_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________11_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________11_VTable vtable;
	};
	struct ________________________________________________11_o {
		________________________________________________11_Fields fields;
	};
	struct ________________________1255_Fields {
		uint16_t _______________________;
		struct System_Byte_array* _1________________________;
	};
	struct ________________________1255_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Dispose;
	};
	struct ________________________1255_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________1255_VTable vtable;
	};
	struct ________________________1255_o {
		________________________1255_Fields fields;
	};
	struct ________________________________________________12_Fields {
		struct ________________________1255_o _______________________;
		struct System_Single_array* _1________________________;
		int32_t _2________________________;
		uint16_t _3________________________;
		bool _4________________________;
	};
	struct ________________________________________________12_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________12_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________12_VTable vtable;
	};
	struct ________________________________________________12_o {
		________________________________________________12_Fields fields;
	};
	struct ________________________________________________13_Fields {
		struct System_Byte_array* _______________________;
		int32_t _1________________________;
		struct System_Collections_Generic_List_Action__o* _2________________________;
	};
	struct ________________________________________________13_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________13_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________13_VTable vtable;
	};
	struct ________________________________________________13_o {
		________________________________________________13_Fields fields;
	};
	struct __declspec(align(8)) __________________________c_Fields {
	};
	struct __________________________c_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct __________________________c_c {
		Il2CppClass_1 _1;
		struct __________________________c_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		__________________________c_VTable vtable;
	};
	struct __________________________c_o {
		__________________________c_c* klass;
		void* monitor;
		__________________________c_Fields fields;
	};
	struct __________________________c_StaticFields {
		struct __________________________c_o* __9;
		struct System_Func_string__bool__o* __9__155_0;
		struct System_Comparison__________________________o* __9__165_0;
		struct System_Func__________________________string__o* __9__199_0;
	};
	struct __declspec(align(8)) ________________________________________________14_Fields {
		struct ________________________100_o* _______________________;
		int32_t _1________________________;
	};
	struct ________________________________________________14_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________14_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________14_VTable vtable;
	};
	struct ________________________________________________14_o {
		________________________________________________14_c* klass;
		void* monitor;
		________________________________________________14_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________15_Fields {
		struct ________________________1255_o _______________________;
		int32_t _1________________________;
		struct ________________________________________________14_o* _2________________________;
	};
	struct ________________________________________________15_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________15_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________15_VTable vtable;
	};
	struct ________________________________________________15_o {
		________________________________________________15_c* klass;
		void* monitor;
		________________________________________________15_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________16_Fields {
		struct System_Single_array* _______________________;
		struct ________________________________________________15_o* _1________________________;
	};
	struct ________________________________________________16_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________16_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________16_VTable vtable;
	};
	struct ________________________________________________16_o {
		________________________________________________16_c* klass;
		void* monitor;
		________________________________________________16_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________17_Fields {
		struct System_Single_array* _______________________;
		float _1________________________;
		struct ________________________________________________15_o* _2________________________;
	};
	struct ________________________________________________17_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________17_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________17_VTable vtable;
	};
	struct ________________________________________________17_o {
		________________________________________________17_c* klass;
		void* monitor;
		________________________________________________17_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________18_Fields {
		float _______________________;
		struct ________________________100_o* _1________________________;
		struct System_String_o* _2________________________;
	};
	struct ________________________________________________18_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________18_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________18_VTable vtable;
	};
	struct ________________________________________________18_o {
		________________________________________________18_c* klass;
		void* monitor;
		________________________________________________18_Fields fields;
	};
	struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_Fields {
		struct Cysharp_Threading_Tasks_CompilerServices_IStateMachineRunnerPromise_o* runnerPromise;
		struct System_Exception_o* ex;
	};
	struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_VTable vtable;
	};
	struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_o {
		Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_Fields fields;
	};
	struct System_Threading_CancellationToken_Fields {
		struct System_Threading_CancellationTokenSource_o* _source;
	};
	struct System_Threading_CancellationToken_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct System_Threading_CancellationToken_c {
		Il2CppClass_1 _1;
		struct System_Threading_CancellationToken_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_Threading_CancellationToken_VTable vtable;
	};
	struct System_Threading_CancellationToken_o {
		System_Threading_CancellationToken_Fields fields;
	};
	struct System_Threading_CancellationToken_StaticFields {
		struct System_Action_object__o* s_actionToActionObjShunt;
	};
	struct Cysharp_Threading_Tasks_SwitchToMainThreadAwaitable_Awaiter_Fields {
		int32_t playerLoopTiming;
		struct System_Threading_CancellationToken_o cancellationToken;
	};
	struct Cysharp_Threading_Tasks_SwitchToMainThreadAwaitable_Awaiter_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_UnsafeOnCompleted;
		VirtualInvokeData _5_OnCompleted;
	};
	struct Cysharp_Threading_Tasks_SwitchToMainThreadAwaitable_Awaiter_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Cysharp_Threading_Tasks_SwitchToMainThreadAwaitable_Awaiter_VTable vtable;
	};
	struct Cysharp_Threading_Tasks_SwitchToMainThreadAwaitable_Awaiter_o {
		Cysharp_Threading_Tasks_SwitchToMainThreadAwaitable_Awaiter_Fields fields;
	};
	struct Cysharp_Threading_Tasks_UniTask_T__Fields {
		struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
		Il2CppObject* result;
		int16_t token;
	};
	struct Cysharp_Threading_Tasks_UniTask_T__RGCTXs {
		Il2CppClass* _0_Cysharp_Threading_Tasks_UniTask_T_;
		Il2CppClass* _1_Cysharp_Threading_Tasks_IUniTaskSource_T_;
		Il2CppClass* _2_T;
		Il2CppClass* _3_Cysharp_Threading_Tasks_UniTask_Awaiter_T_;
		MethodInfo* _4_Cysharp_Threading_Tasks_UniTask_Awaiter_T___ctor;
		Il2CppClass* _5_Cysharp_Threading_Tasks_UniTask_T_;
		Il2CppClass* _6_Cysharp_Threading_Tasks_UniTask_MemoizeSource_T_;
		MethodInfo* _7_Cysharp_Threading_Tasks_UniTask_MemoizeSource_T___ctor;
		MethodInfo* _8_Cysharp_Threading_Tasks_UniTask_T___ctor;
		MethodInfo* _9_Cysharp_Threading_Tasks_IUniTaskSource_T__GetResult;
		MethodInfo* _10_Cysharp_Threading_Tasks_UniTask_T__AsUniTask;
		Il2CppClass* _11_Cysharp_Threading_Tasks_UniTask_T_;
		Il2CppClass* _12_System_ValueTuple_bool__T_;
		MethodInfo* _13_System_ValueTuple_bool__T___ctor;
		Il2CppClass* _14_Cysharp_Threading_Tasks_UniTask_ValueTuple_bool__T__;
		MethodInfo* _15_Cysharp_Threading_Tasks_UniTask_ValueTuple_bool__T____ctor;
		Il2CppClass* _16_Cysharp_Threading_Tasks_UniTask_IsCanceledSource_T_;
		MethodInfo* _17_Cysharp_Threading_Tasks_UniTask_IsCanceledSource_T___ctor;
		MethodInfo* _18_Cysharp_Threading_Tasks_UniTask_ValueTuple_bool__T____ctor;
		Il2CppClass* _19_Cysharp_Threading_Tasks_IUniTaskSource_ValueTuple_bool__T__;
	};
	struct Cysharp_Threading_Tasks_UniTask_T__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct Cysharp_Threading_Tasks_UniTask_T__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Cysharp_Threading_Tasks_UniTask_T__RGCTXs* rgctx_data;
		Il2CppClass_2 _2;
		Cysharp_Threading_Tasks_UniTask_T__VTable vtable;
	};
	struct Cysharp_Threading_Tasks_UniTask_T__o {
		Cysharp_Threading_Tasks_UniTask_T__Fields fields;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter_bool__Fields {
		struct Cysharp_Threading_Tasks_UniTask_T__o task;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter_bool__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_UnsafeOnCompleted;
		VirtualInvokeData _5_OnCompleted;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter_bool__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Cysharp_Threading_Tasks_UniTask_Awaiter_bool__VTable vtable;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter_bool__o {
		Cysharp_Threading_Tasks_UniTask_Awaiter_bool__Fields fields;
	};
	struct ________________________________________________19_Fields {
		int32_t _______________________;
		struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_o _1________________________;
		struct ________________________100_o* _2________________________;
		struct System_Threading_CancellationToken_o _3________________________;
		struct Cysharp_Threading_Tasks_SwitchToMainThreadAwaitable_Awaiter_o _4________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter_bool__o _5________________________;
	};
	struct ________________________________________________19_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________________________________19_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________19_VTable vtable;
	};
	struct ________________________________________________19_o {
		________________________________________________19_Fields fields;
	};
	struct ________________________________________________20_Fields {
		int32_t _______________________;
		struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_o _1________________________;
		struct ________________________100_o* _2________________________;
		struct System_Threading_CancellationToken_o _3________________________;
		struct Cysharp_Threading_Tasks_SwitchToMainThreadAwaitable_Awaiter_o _4________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter_bool__o _5________________________;
	};
	struct ________________________________________________20_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________________________________20_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________20_VTable vtable;
	};
	struct ________________________________________________20_o {
		________________________________________________20_Fields fields;
	};
	struct Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_Fields {
	};
	struct Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_UnsafeOnCompleted;
		VirtualInvokeData _5_OnCompleted;
	};
	struct Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_c {
		Il2CppClass_1 _1;
		struct Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_VTable vtable;
	};
	struct Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_o {
		Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_Fields fields;
	};
	struct Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_StaticFields {
		struct System_Threading_WaitCallback_o* switchToCallback;
	};
	struct ________________________________________________21_Fields {
		int32_t _______________________;
		struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_o _1________________________;
		struct ________________________100_o* _2________________________;
		struct System_Threading_CancellationToken_o _3________________________;
		struct Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_o _4________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter_bool__o _5________________________;
	};
	struct ________________________________________________21_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________________________________21_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________21_VTable vtable;
	};
	struct ________________________________________________21_o {
		________________________________________________21_Fields fields;
	};
	struct ________________________________________________22_Fields {
		int32_t _______________________;
		struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_o _1________________________;
		struct ________________________100_o* _2________________________;
		struct System_Threading_CancellationToken_o _3________________________;
		struct Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_o _4________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter_bool__o _5________________________;
	};
	struct ________________________________________________22_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________________________________22_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________22_VTable vtable;
	};
	struct ________________________________________________22_o {
		________________________________________________22_Fields fields;
	};
	struct ________________________________________________23_Fields {
		int32_t _______________________;
		struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_o _1________________________;
		struct ________________________100_o* _2________________________;
		struct System_Threading_CancellationToken_o _3________________________;
		struct Cysharp_Threading_Tasks_SwitchToThreadPoolAwaitable_Awaiter_o _4________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter_bool__o _5________________________;
	};
	struct ________________________________________________23_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
	};
	struct ________________________________________________23_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________23_VTable vtable;
	};
	struct ________________________________________________23_o {
		________________________________________________23_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________24_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________100_o* _2________________________;
		float _3________________________;
	};
	struct ________________________________________________24_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________________________________24_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________24_VTable vtable;
	};
	struct ________________________________________________24_o {
		________________________________________________24_c* klass;
		void* monitor;
		________________________________________________24_Fields fields;
	};
	struct System_Nullable_int__Fields {
		bool hasValue;
		int32_t value;
	};
	struct System_Nullable_int__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct System_Nullable_int__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_Nullable_int__VTable vtable;
	};
	struct System_Nullable_int__o {
		System_Nullable_int__Fields fields;
	};
	struct Unity_Profiling_ProfilerMarker_Fields {
		intptr_t m_Ptr;
	};
	struct Unity_Profiling_ProfilerMarker_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct Unity_Profiling_ProfilerMarker_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Unity_Profiling_ProfilerMarker_VTable vtable;
	};
	struct Unity_Profiling_ProfilerMarker_o {
		Unity_Profiling_ProfilerMarker_Fields fields;
	};
	struct ________________________100_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _10________________________;
		int32_t _11________________________;
		int32_t _12________________________;
		int32_t _13________________________;
		float _________________________k__BackingField;
		int32_t _15________________________;
		bool _16________________________;
		int32_t _17________________________;
		bool _18________________________;
		bool _19________________________;
		bool _20________________________;
		struct ________________________1575_o* _21__________________________k__BackingField;
		int64_t _22________________________;
		float _23________________________;
		struct System_Action_o* _27________________________;
		struct System_Action_o* _28________________________;
		bool _29________________________;
		struct ________________________511_o* _34________________________;
		struct UnityEngine_AudioSource_o* _35________________________;
		struct ONSPAudioSource_o* _36________________________;
		struct OVRLipSyncContext_o* _37________________________;
		struct OVRLipSyncContextMorphTarget_o* _38________________________;
		struct ________________________314_o* _39________________________;
		struct ________________________306_o* _40________________________;
		struct UnityEngine_AudioClip_o* _41________________________;
		struct ________________________415_o* _42________________________;
		struct ________________________1257_o* _43________________________;
		int32_t _44________________________;
		bool _45________________________;
		struct ________________________1386_o* _46________________________;
		int32_t _47________________________;
		int32_t _48________________________;
		float _49________________________;
		float _50________________________;
		struct System_Collections_Generic_List__________________________o* _51________________________;
		struct System_Collections_Generic_List__________________________o* _52________________________;
		struct System_Byte_array* _53________________________;
		int32_t _54________________________;
		struct ________________________1256_o* _55________________________;
		struct System_String_o* _56________________________;
		float _57________________________;
		float _58________________________;
		float _59________________________;
		struct ________________________1252_o* _60________________________;
		int32_t _61________________________;
		int32_t _62________________________;
		int32_t _63________________________;
		int32_t _64________________________;
		bool _65________________________;
		int32_t _66________________________;
		int32_t _67________________________;
		int32_t _68________________________;
		int32_t _69________________________;
		int32_t _70________________________;
		int32_t _71________________________;
		float _72________________________;
		uint32_t _73________________________;
		float _74________________________;
		uint32_t _75________________________;
		int64_t _80________________________;
		struct System_Single_array* _81________________________;
		bool _82________________________;
		float _83________________________;
		float _84________________________;
		bool _85________________________;
		float _86________________________;
		float _87________________________;
		int32_t _89________________________;
		float _90________________________;
		float _91________________________;
		float _92________________________;
		float _93________________________;
		double _94________________________;
		float _97________________________;
		float _98________________________;
		float _99________________________;
		int32_t _100________________________;
		int32_t _101________________________;
		struct ________________________1304_o* _102________________________;
		int32_t _103________________________;
		struct System_Nullable_int__o _104________________________;
		float _105________________________;
		int32_t _106________________________;
		struct ________________________________________________11_array* _108________________________;
		int32_t _109________________________;
		int32_t _116________________________;
		int32_t _117________________________;
		float _132________________________;
		float _133________________________;
		float _134________________________;
		float _135________________________;
		int32_t _136________________________;
		int32_t _137________________________;
		int32_t _138________________________;
		int32_t _139________________________;
		int32_t _140________________________;
		struct System_Threading_CancellationTokenSource_o* _144________________________;
		struct Unity_Profiling_ProfilerMarker_o _145________________________;
		struct Cysharp_Threading_Tasks_Channel_float____o* _146________________________;
		struct Cysharp_Threading_Tasks_Channel__________________________________________________o* _147________________________;
		struct Cysharp_Threading_Tasks_Channel__________________________________________________o* _148________________________;
		struct Unity_Profiling_ProfilerMarker_o _149________________________;
		struct Unity_Profiling_ProfilerMarker_o _150________________________;
		struct Unity_Profiling_ProfilerMarker_o _151________________________;
		struct Cysharp_Threading_Tasks_Channel__________________________________________________o* _152________________________;
		struct Cysharp_Threading_Tasks_Channel__________________________________________________o* _153________________________;
		struct Unity_Profiling_ProfilerMarker_o _154________________________;
		struct Unity_Profiling_ProfilerMarker_o _155________________________;
	};
	struct ________________________100_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________100_c {
		Il2CppClass_1 _1;
		struct ________________________100_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________100_VTable vtable;
	};
	struct ________________________100_o {
		________________________100_c* klass;
		void* monitor;
		________________________100_Fields fields;
	};
	struct ________________________100_StaticFields {
		bool _______________________;
		bool _1________________________;
		float _2________________________;
		float _3________________________;
		bool _4________________________;
		struct System_Collections_Generic_List__________________________o* _5________________________;
		struct System_String_o* _6________________________;
		struct System_Action_o* _7________________________;
		struct System_Collections_Generic_List_ValueTuple_float____________________________o* _9________________________;
		struct System_String_array* _30________________________;
		float _77________________________;
		struct System_Nullable_int__o _88________________________;
		struct Unity_Profiling_ProfilerMarker_o _110________________________;
		struct Unity_Profiling_ProfilerMarker_o _111________________________;
		struct Unity_Profiling_ProfilerMarker_o _112________________________;
		struct Unity_Profiling_ProfilerMarker_o _113________________________;
		struct Unity_Profiling_ProfilerMarker_o _114________________________;
		struct Unity_Profiling_ProfilerMarker_o _115________________________;
		struct Unity_Profiling_ProfilerMarker_o _118________________________;
		struct Unity_Profiling_ProfilerMarker_o _119________________________;
		struct Unity_Profiling_ProfilerMarker_o _120________________________;
		struct Unity_Profiling_ProfilerMarker_o _121________________________;
		struct Unity_Profiling_ProfilerMarker_o _122________________________;
		struct Unity_Profiling_ProfilerMarker_o _123________________________;
		struct Unity_Profiling_ProfilerMarker_o _124________________________;
		struct Unity_Profiling_ProfilerMarker_o _125________________________;
		struct Unity_Profiling_ProfilerMarker_o _126________________________;
		struct Unity_Profiling_ProfilerMarker_o _127________________________;
		struct Unity_Profiling_ProfilerMarker_o _128________________________;
		struct Unity_Profiling_ProfilerMarker_o _129________________________;
		struct Unity_Profiling_ProfilerMarker_o _130________________________;
		struct Unity_Profiling_ProfilerMarker_o _131________________________;
		struct Unity_Profiling_ProfilerMarker_o _141________________________;
		struct Unity_Profiling_ProfilerMarker_o _142________________________;
		bool _143________________________;
	};
	struct ________________________101_Fields : UnityEngine_MonoBehaviour_Fields {
		bool _______________________;
		bool _1________________________;
		bool _2________________________;
		bool _3________________________;
		int32_t _4________________________;
		struct UnityEngine_Texture_o* _5________________________;
		struct UnityEngine_Transform_o* _6________________________;
		struct UnityEngine_GUIStyle_o* _7________________________;
		struct UnityEngine_GUIStyle_o* _8________________________;
		struct UnityEngine_GameObject_o* _9________________________;
		struct UnityEngine_GameObject_o* _10________________________;
		struct UnityEngine_RenderTexture_o* _11________________________;
		struct UnityEngine_Vector2_o _12________________________;
		struct UnityEngine_Texture_o* _13________________________;
		bool _14________________________;
	};
	struct ________________________101_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_OnEnable;
		VirtualInvokeData _5_OnDisable;
	};
	struct ________________________101_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________101_VTable vtable;
	};
	struct ________________________101_o {
		________________________101_c* klass;
		void* monitor;
		________________________101_Fields fields;
	};
	struct ________________________________________________25_Fields {
		struct ________________________103_o* _______________________;
	};
	struct ________________________________________________25_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________25_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________25_VTable vtable;
	};
	struct ________________________________________________25_o {
		________________________________________________25_Fields fields;
	};
	struct ________________________102_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_UI_ScrollRect_o* _______________________;
		struct TMPro_TextMeshProUGUI_o* _1________________________;
		struct TMPro_TextMeshProUGUI_o* _2________________________;
		struct TMPro_TextMeshProUGUI_o* _3________________________;
		bool _4________________________;
		bool _5________________________;
		struct ________________________103_o* _6________________________;
		struct ________________________103_o* _7________________________;
		struct ________________________103_o* _8________________________;
		struct VRC_SDKBase_VRC_AvatarDescriptor_o* _9________________________;
		struct VRC_SDK3_Avatars_Components_VRCAvatarDescriptor_o* _10________________________;
	};
	struct ________________________102_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________102_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________102_VTable vtable;
	};
	struct ________________________102_o {
		________________________102_c* klass;
		void* monitor;
		________________________102_Fields fields;
	};
	struct __declspec(align(8)) ________________________103_Fields {
		struct System_Text_StringBuilder_o* _______________________;
		int32_t _1________________________;
	};
	struct ________________________103_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________103_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________103_VTable vtable;
	};
	struct ________________________103_o {
		________________________103_c* klass;
		void* monitor;
		________________________103_Fields fields;
	};
	struct ________________________104_Fields : UnityEngine_MonoBehaviour_Fields {
	};
	struct ________________________104_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________104_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________104_VTable vtable;
	};
	struct ________________________104_o {
		________________________104_c* klass;
		void* monitor;
		________________________104_Fields fields;
	};
	struct ________________________105_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Vector2_o _______________________;
	};
	struct ________________________105_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_OnEnable;
	};
	struct ________________________105_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________105_VTable vtable;
	};
	struct ________________________105_o {
		________________________105_c* klass;
		void* monitor;
		________________________105_Fields fields;
	};
	struct ________________________________________________26_Fields {
		int32_t value__;
	};
	struct ________________________________________________26_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________26_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________26_VTable vtable;
	};
	struct ________________________________________________26_o {
		________________________________________________26_Fields fields;
	};
	struct ________________________106_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________105_o* _______________________;
		int32_t _1________________________;
		bool _2________________________;
		struct ________________________________________________53_o* _3________________________;
	};
	struct ________________________106_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________106_c {
		Il2CppClass_1 _1;
		struct ________________________106_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________106_VTable vtable;
	};
	struct ________________________106_o {
		________________________106_c* klass;
		void* monitor;
		________________________106_Fields fields;
	};
	struct ________________________106_StaticFields {
		float _4________________________;
	};
	struct ________________________107_Fields : ________________________105_Fields {
		struct UnityEngine_Transform_o* _______________________;
		struct UnityEngine_UI_Graphic_o* _1________________________;
		struct UnityEngine_UI_Graphic_o* _2________________________;
		struct UnityEngine_UI_Graphic_o* _3________________________;
		struct UnityEngine_UI_Graphic_o* _4________________________;
		struct UnityEngine_UI_Graphic_o* _5________________________;
		struct UnityEngine_UI_Graphic_o* _6________________________;
	};
	struct ________________________107_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_OnEnable;
	};
	struct ________________________107_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________107_VTable vtable;
	};
	struct ________________________107_o {
		________________________107_c* klass;
		void* monitor;
		________________________107_Fields fields;
	};
	struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskVoidMethodBuilder_Fields {
		struct Cysharp_Threading_Tasks_CompilerServices_IStateMachineRunner_o* runner;
	};
	struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskVoidMethodBuilder_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskVoidMethodBuilder_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskVoidMethodBuilder_VTable vtable;
	};
	struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskVoidMethodBuilder_o {
		Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskVoidMethodBuilder_Fields fields;
	};
	struct Cysharp_Threading_Tasks_UniTask_Fields {
		struct Cysharp_Threading_Tasks_IUniTaskSource_o* source;
		int16_t token;
	};
	struct Cysharp_Threading_Tasks_UniTask_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct Cysharp_Threading_Tasks_UniTask_c {
		Il2CppClass_1 _1;
		struct Cysharp_Threading_Tasks_UniTask_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Cysharp_Threading_Tasks_UniTask_VTable vtable;
	};
	struct Cysharp_Threading_Tasks_UniTask_o {
		Cysharp_Threading_Tasks_UniTask_Fields fields;
	};
	struct Cysharp_Threading_Tasks_UniTask_StaticFields {
		struct Cysharp_Threading_Tasks_UniTask_o CanceledUniTask;
		struct Cysharp_Threading_Tasks_UniTask_o CompletedTask;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter_Fields {
		struct Cysharp_Threading_Tasks_UniTask_o task;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_UnsafeOnCompleted;
		VirtualInvokeData _5_OnCompleted;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Cysharp_Threading_Tasks_UniTask_Awaiter_VTable vtable;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter_o {
		Cysharp_Threading_Tasks_UniTask_Awaiter_Fields fields;
	};
	struct ________________________________________________27_Fields {
		int32_t _______________________;
		struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskVoidMethodBuilder_o _1________________________;
		struct ________________________108_o* _2________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter_o _3________________________;
	};
	struct ________________________________________________27_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________________________________27_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________27_VTable vtable;
	};
	struct ________________________________________________27_o {
		________________________________________________27_Fields fields;
	};
	struct ________________________108_Fields : ________________________105_Fields {
		struct UnityEngine_Transform_o* _______________________;
		struct ________________________4371_o* _1________________________;
		struct UnityEngine_UI_Graphic_o* _2________________________;
		struct UnityEngine_UI_Graphic_o* _3________________________;
		struct UnityEngine_UI_Graphic_o* _4________________________;
		struct UnityEngine_UI_Graphic_o* _5________________________;
	};
	struct ________________________108_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_OnEnable;
	};
	struct ________________________108_c {
		Il2CppClass_1 _1;
		struct ________________________108_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________108_VTable vtable;
	};
	struct ________________________108_o {
		________________________108_c* klass;
		void* monitor;
		________________________108_Fields fields;
	};
	struct ________________________108_StaticFields {
		float _6________________________;
	};
	struct __declspec(align(8)) ________________________109_Fields {
	};
	struct ________________________109_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VirtualInvokeData vtable[32];
	};
	struct ________________________109_o {
		________________________109_c* klass;
		void* monitor;
		________________________109_Fields fields;
	};
	struct VRC_Localization_LocalizableString_Fields {
		struct System_String_o* _key;
		struct System_String_o* _fallbackText;
		Il2CppObject* _arg0;
		Il2CppObject* _arg1;
		Il2CppObject* _arg2;
		bool _isFallbackFormattingRequired;
	};
	struct VRC_Localization_LocalizableString_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct VRC_Localization_LocalizableString_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VRC_Localization_LocalizableString_VTable vtable;
	};
	struct VRC_Localization_LocalizableString_o {
		VRC_Localization_LocalizableString_Fields fields;
	};
	struct ________________________110_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Transform_o* _______________________;
		struct UnityEngine_UI_RawImage_o* _1________________________;
		struct UnityEngine_UI_RawImage_o* _2________________________;
		struct UnityEngine_UI_RawImage_o* _3________________________;
		struct ________________________4371_o* _4________________________;
		struct ________________________4371_o* _5________________________;
		struct UnityEngine_GameObject_o* _6________________________;
		struct UnityEngine_GameObject_o* _7________________________;
		struct UnityEngine_GameObject_o* _8________________________;
		struct VRC_Localization_LocalizableString_o _9________________________;
		struct System_Action_o* _10________________________;
		bool _11________________________;
		struct System_Func_bool__o* _________________________k__BackingField;
		bool _13________________________;
		float _14________________________;
		float _15________________________;
		float _16________________________;
		bool _17________________________;
		bool _18________________________;
	};
	struct ________________________110_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________110_c {
		Il2CppClass_1 _1;
		struct ________________________110_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________110_VTable vtable;
	};
	struct ________________________110_o {
		________________________110_c* klass;
		void* monitor;
		________________________110_Fields fields;
	};
	struct ________________________110_StaticFields {
		float _19________________________;
	};
	struct __declspec(align(8)) ________________________111_Fields {
	};
	struct ________________________111_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VirtualInvokeData vtable[32];
	};
	struct ________________________111_o {
		________________________111_c* klass;
		void* monitor;
		________________________111_Fields fields;
	};
	struct __declspec(align(8)) VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_Fields {
		struct System_String_o* name;
		struct UnityEngine_Texture2D_o* icon;
		int32_t type;
		struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_Parameter_o* parameter;
		float value;
		int32_t style;
		struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_o* subMenu;
		struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_Parameter_array* subParameters;
		struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_Label_array* labels;
	};
	struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_VTable vtable;
	};
	struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_o {
		VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_c* klass;
		void* monitor;
		VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_Fields fields;
	};
	struct ________________________________________________________________________Fields : VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_Fields {
		float _______________________;
		float _1________________________;
		struct System_Action_float__o* _2________________________;
	};
	struct ________________________________________________________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
	};
	struct ________________________________________________________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________________________________VTable vtable;
	};
	struct ________________________________________________________________________o {
		________________________________________________________________________c* klass;
		void* monitor;
		________________________________________________________________________Fields fields;
	};
	struct ________________________________________________28_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________161_o* _______________________;
		struct ________________________111_o* _1________________________;
		struct ________________________158_o* _2________________________;
		struct ________________________________________________________________________o* _3________________________;
		struct ________________________511_o* _4________________________;
		struct ________________________159_o* _5________________________;
		bool _6________________________;
		bool _7________________________;
		bool _8________________________;
		struct UnityEngine_Vector3_o _9________________________;
	};
	struct ________________________________________________28_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Update;
		VirtualInvokeData _5________________________;
	};
	struct ________________________________________________28_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________28_VTable vtable;
	};
	struct ________________________________________________28_o {
		________________________________________________28_c* klass;
		void* monitor;
		________________________________________________28_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________29_Fields {
		struct System_Action_o* _______________________;
		struct System_Action_o* _1________________________;
		struct UnityEngine_Texture2D_o* _2________________________;
		struct VRC_Localization_LocalizableString_o _3________________________;
		struct UnityEngine_GameObject_o* _4________________________;
	};
	struct ________________________________________________29_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________29_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________29_VTable vtable;
	};
	struct ________________________________________________29_o {
		________________________________________________29_c* klass;
		void* monitor;
		________________________________________________29_Fields fields;
	};
	struct ________________________________________________30_Fields {
		int32_t value__;
	};
	struct ________________________________________________30_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________30_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________30_VTable vtable;
	};
	struct ________________________________________________30_o {
		________________________________________________30_Fields fields;
	};
	struct __declspec(align(8)) __________________________c_1_Fields {
	};
	struct __________________________c_1_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct __________________________c_1_c {
		Il2CppClass_1 _1;
		struct __________________________c_1_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		__________________________c_1_VTable vtable;
	};
	struct __________________________c_1_o {
		__________________________c_1_c* klass;
		void* monitor;
		__________________________c_1_Fields fields;
	};
	struct __________________________c_1_StaticFields {
		struct __________________________c_1_o* __9;
		struct System_Func_bool__o* __9__44_0;
		struct System_Func_bool__o* __9__44_1;
		struct System_Action__________________________o* __9__44_3;
		struct System_Func_bool__o* __9__44_2;
		struct System_Action_float____o* __9__83_0;
		struct System_Action_o* __9__83_1;
		struct System_Func_bool__o* __9__84_0;
		struct System_Func_bool__o* __9__84_1;
		struct System_Func_bool__o* __9__100_0;
		struct System_Func_bool__o* __9__100_1;
	};
	struct __declspec(align(8)) ________________________________________________31_Fields {
		struct ________________________112_o* _______________________;
		struct ________________________159_o* _1________________________;
	};
	struct ________________________________________________31_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________31_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________31_VTable vtable;
	};
	struct ________________________________________________31_o {
		________________________________________________31_c* klass;
		void* monitor;
		________________________________________________31_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________32_Fields {
		int32_t _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________32_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________32_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________32_VTable vtable;
	};
	struct ________________________________________________32_o {
		________________________________________________32_c* klass;
		void* monitor;
		________________________________________________32_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________33_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________33_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________33_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________33_VTable vtable;
	};
	struct ________________________________________________33_o {
		________________________________________________33_c* klass;
		void* monitor;
		________________________________________________33_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________34_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________34_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________34_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________34_VTable vtable;
	};
	struct ________________________________________________34_o {
		________________________________________________34_c* klass;
		void* monitor;
		________________________________________________34_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________35_Fields {
		struct ________________________159_o* _______________________;
		int32_t _1________________________;
		struct ________________________112_o* _2________________________;
		struct System_Action_o* _3________________________;
	};
	struct ________________________________________________35_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________35_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________35_VTable vtable;
	};
	struct ________________________________________________35_o {
		________________________________________________35_c* klass;
		void* monitor;
		________________________________________________35_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________36_Fields {
		struct ________________________112_o* _______________________;
		struct VRC_SDK3_Avatars_Components_VRCAvatarDescriptor_o* _1________________________;
	};
	struct ________________________________________________36_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________36_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________36_VTable vtable;
	};
	struct ________________________________________________36_o {
		________________________________________________36_c* klass;
		void* monitor;
		________________________________________________36_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________37_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________37_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________37_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________37_VTable vtable;
	};
	struct ________________________________________________37_o {
		________________________________________________37_c* klass;
		void* monitor;
		________________________________________________37_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________38_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________38_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________38_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________38_VTable vtable;
	};
	struct ________________________________________________38_o {
		________________________________________________38_c* klass;
		void* monitor;
		________________________________________________38_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________39_Fields {
		int32_t _______________________;
	};
	struct ________________________________________________39_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________39_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________39_VTable vtable;
	};
	struct ________________________________________________39_o {
		________________________________________________39_c* klass;
		void* monitor;
		________________________________________________39_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________40_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________40_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________40_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________40_VTable vtable;
	};
	struct ________________________________________________40_o {
		________________________________________________40_c* klass;
		void* monitor;
		________________________________________________40_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________41_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________41_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________41_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________41_VTable vtable;
	};
	struct ________________________________________________41_o {
		________________________________________________41_c* klass;
		void* monitor;
		________________________________________________41_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________42_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________42_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________42_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________42_VTable vtable;
	};
	struct ________________________________________________42_o {
		________________________________________________42_c* klass;
		void* monitor;
		________________________________________________42_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________43_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________43_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________43_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________43_VTable vtable;
	};
	struct ________________________________________________43_o {
		________________________________________________43_c* klass;
		void* monitor;
		________________________________________________43_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________44_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________44_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________44_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________44_VTable vtable;
	};
	struct ________________________________________________44_o {
		________________________________________________44_c* klass;
		void* monitor;
		________________________________________________44_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________45_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________45_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________45_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________45_VTable vtable;
	};
	struct ________________________________________________45_o {
		________________________________________________45_c* klass;
		void* monitor;
		________________________________________________45_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________46_Fields {
		struct ________________________159_o* _______________________;
		struct ________________________112_o* _1________________________;
	};
	struct ________________________________________________46_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________46_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________46_VTable vtable;
	};
	struct ________________________________________________46_o {
		________________________________________________46_c* klass;
		void* monitor;
		________________________________________________46_Fields fields;
	};
	struct ________________________112_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* _______________________;
		struct UnityEngine_GameObject_o* _1________________________;
		struct UnityEngine_GameObject_o* _2________________________;
		struct UnityEngine_GameObject_o* _3________________________;
		struct UnityEngine_GameObject_o* _4________________________;
		struct UnityEngine_GameObject_o* _5________________________;
		struct UnityEngine_GameObject_o* _6________________________;
		struct ________________________4371_o* _7________________________;
		struct UnityEngine_CanvasGroup_o* _8________________________;
		struct UnityEngine_CanvasGroup_o* _9________________________;
		struct ________________________117_o* _10________________________;
		struct ________________________161_o* _11________________________;
		struct System_Collections_Generic_List__________________________o* _12________________________;
		bool _13________________________;
		bool _14________________________;
		bool _15________________________;
		struct ________________________115_o* _16________________________;
		struct System_Collections_Generic_List_GameObject__o* _17________________________;
		struct System_Action_VRCExpressionsMenu_Control__bool__o* _18________________________;
		struct System_String_array* _19________________________;
		struct System_String_array* _20________________________;
		struct ________________________160_o* _21________________________;
		struct System_Action_o* _22________________________;
		struct ________________________463_o* _23________________________;
		struct ________________________463_o* _24________________________;
		struct ________________________463_o* _25________________________;
		bool _29________________________;
		bool _30________________________;
		struct UnityEngine_Vector2_o _31________________________;
		struct UnityEngine_Vector3_o _32________________________;
		struct ________________________159_o* _35________________________;
		struct ________________________159_o* _36________________________;
		struct ________________________132_o* _37________________________;
		struct UnityEngine_GameObject_o* _38________________________;
		struct System_Collections_Generic_List_GameObject__o* _39________________________;
		struct System_Collections_Generic_List__________________________________________________o* _40________________________;
		struct System_Collections_Generic_Dictionary__________________________________________________string__o* _41________________________;
		struct VRC_Localization_LocalizableString_o _42________________________;
		struct VRC_Localization_LocalizableString_o _43________________________;
		struct ________________________121_o* _44________________________;
		bool _48________________________;
		struct UnityEngine_Vector2_o _49________________________;
		struct System_Action_o* _50________________________;
		struct ________________________132_o* _53________________________;
		struct ________________________132_o* _54________________________;
	};
	struct ________________________112_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
	};
	struct ________________________112_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________112_VTable vtable;
	};
	struct ________________________112_o {
		________________________112_c* klass;
		void* monitor;
		________________________112_Fields fields;
	};
	struct ________________________MenuIcons_Fields {
		struct UnityEngine_Texture2D_o* home;
		struct UnityEngine_Texture2D_o* options;
		struct UnityEngine_Texture2D_o* config;
		struct UnityEngine_Texture2D_o* expressions;
		struct UnityEngine_Texture2D_o* emojis;
		struct UnityEngine_Texture2D_o* tools;
		struct UnityEngine_Texture2D_o* micOn;
		struct UnityEngine_Texture2D_o* micOff;
		struct UnityEngine_Texture2D_o* gesturesOn;
		struct UnityEngine_Texture2D_o* gesturesOff;
		struct UnityEngine_Texture2D_o* defaultExpression;
		struct UnityEngine_Texture2D_o* back;
		struct UnityEngine_Texture2D_o* close;
		struct UnityEngine_Texture2D_o* debug;
		struct UnityEngine_Texture2D_o* resetAvatar;
		struct UnityEngine_Texture2D_o* resetPose;
		struct UnityEngine_Texture2D_o* toggleOn;
		struct UnityEngine_Texture2D_o* toggleOff;
		struct UnityEngine_Texture2D_o* settingHudPosition;
		struct UnityEngine_Texture2D_o* settingSize;
		struct UnityEngine_Texture2D_o* settingSizeReset;
		struct UnityEngine_Texture2D_o* settingOpacity;
		struct UnityEngine_Texture2D_o* settingStatus;
		struct UnityEngine_Texture2D_o* nameplate;
		struct UnityEngine_Texture2D_o* settingAvatarOverlay;
		struct UnityEngine_Texture2D_o* arrowUp;
		struct UnityEngine_Texture2D_o* arrowRight;
		struct UnityEngine_Texture2D_o* arrowDown;
		struct UnityEngine_Texture2D_o* arrowLeft;
		struct UnityEngine_Texture2D_o* folder;
		struct UnityEngine_Texture2D_o* visibility;
		struct UnityEngine_Texture2D_o* radioOn;
		struct UnityEngine_Texture2D_o* radioOff;
		struct UnityEngine_Texture2D_o* osc;
		struct UnityEngine_Texture2D_o* chatbox;
		struct UnityEngine_Texture2D_o* keyboard;
		struct UnityEngine_Texture2D_o* camera;
		struct UnityEngine_Texture2D_o* statusOff;
		struct UnityEngine_Texture2D_o* statusLocked;
	};
	struct ________________________MenuIcons_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________MenuIcons_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________MenuIcons_VTable vtable;
	};
	struct ________________________MenuIcons_o {
		________________________MenuIcons_Fields fields;
	};
	struct ________________________EmojiCategoryIcons_Fields {
		struct UnityEngine_Texture2D_o* defaultPage;
		struct UnityEngine_Texture2D_o* customPage;
		struct UnityEngine_Texture2D_o* page1;
		struct UnityEngine_Texture2D_o* page2;
		struct UnityEngine_Texture2D_o* page3;
		struct UnityEngine_Texture2D_o* page4;
		struct UnityEngine_Texture2D_o* accessibility;
		struct UnityEngine_Texture2D_o* fall;
		struct UnityEngine_Texture2D_o* winter;
		struct UnityEngine_Texture2D_o* summer;
	};
	struct ________________________EmojiCategoryIcons_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________EmojiCategoryIcons_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________EmojiCategoryIcons_VTable vtable;
	};
	struct ________________________EmojiCategoryIcons_o {
		________________________EmojiCategoryIcons_Fields fields;
	};
	struct ________________________ExpressionIcons_Fields {
		struct UnityEngine_Texture2D_o* typeToggleOn;
		struct UnityEngine_Texture2D_o* typeToggleOff;
		struct UnityEngine_Texture2D_o* typeFolder;
		struct UnityEngine_Texture2D_o* typeAxis;
		struct UnityEngine_Texture2D_o* typeRadial;
		struct UnityEngine_Texture2D_o* typePlayOn;
		struct UnityEngine_Texture2D_o* typePlayOff;
	};
	struct ________________________ExpressionIcons_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________ExpressionIcons_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________ExpressionIcons_VTable vtable;
	};
	struct ________________________ExpressionIcons_o {
		________________________ExpressionIcons_Fields fields;
	};
	struct ________________________PersonalMirrorIcons_Fields {
		struct UnityEngine_Texture2D_o* mirror;
		struct UnityEngine_Texture2D_o* mirrorOpacity;
		struct UnityEngine_Texture2D_o* mirrorScale;
		struct UnityEngine_Texture2D_o* mirrorTracking;
		struct UnityEngine_Texture2D_o* mirrorVisibility;
		struct UnityEngine_Texture2D_o* mirrorReset;
		struct UnityEngine_Texture2D_o* mirrorPlus;
		struct UnityEngine_Texture2D_o* mirrorMinus;
		struct UnityEngine_Texture2D_o* faceMirror;
		struct UnityEngine_Texture2D_o* faceOpacity;
		struct UnityEngine_Texture2D_o* facePosition;
		struct UnityEngine_Texture2D_o* faceScale;
		struct UnityEngine_Texture2D_o* faceReset;
	};
	struct ________________________PersonalMirrorIcons_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________PersonalMirrorIcons_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________PersonalMirrorIcons_VTable vtable;
	};
	struct ________________________PersonalMirrorIcons_o {
		________________________PersonalMirrorIcons_Fields fields;
	};
	struct ________________________Sounds_Fields {
		struct UnityEngine_AudioClip_o* hover;
		struct UnityEngine_AudioClip_o* deny;
		struct UnityEngine_AudioClip_o* select;
		struct UnityEngine_AudioClip_o* back;
	};
	struct ________________________Sounds_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________Sounds_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________Sounds_VTable vtable;
	};
	struct ________________________Sounds_o {
		________________________Sounds_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________47_Fields {
		struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_Parameter_o* _______________________;
		int32_t _1________________________;
		float _2________________________;
		float _3________________________;
		bool _4________________________;
		bool _5________________________;
	};
	struct ________________________________________________47_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________47_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________47_VTable vtable;
	};
	struct ________________________________________________47_o {
		________________________________________________47_c* klass;
		void* monitor;
		________________________________________________47_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________48_Fields {
		struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_Parameter_o* _______________________;
		float _1________________________;
		struct System_Action_o* _2________________________;
		struct ________________________1588_o* _3________________________;
	};
	struct ________________________________________________48_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________48_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________48_VTable vtable;
	};
	struct ________________________________________________48_o {
		________________________________________________48_c* klass;
		void* monitor;
		________________________________________________48_Fields fields;
	};
	struct ________________________113_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________115_o* _______________________;
		struct ________________________115_o* _1________________________;
		struct ________________________102_o* _2________________________;
		struct ________________________106_o* _3________________________;
		struct ________________________106_o* _4________________________;
		struct UnityEngine_GameObject_o* _5________________________;
		struct System_Action_o* _6________________________;
		struct System_Action_bool__o* _7________________________;
		struct ________________________MenuIcons_o _9________________________;
		struct ________________________EmojiCategoryIcons_o _10________________________;
		struct ________________________ExpressionIcons_o _11________________________;
		struct ________________________PersonalMirrorIcons_o _12________________________;
		struct ________________________Sounds_o _13________________________;
		struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_o* _14________________________;
		struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionParameters_o* _15________________________;
		struct System_Action_o* _17________________________;
		struct VRC_UI_Client_Emoji_EmojiData_o* _18________________________;
		bool _20________________________;
		struct System_Action_o* _21________________________;
		bool _23________________________;
		struct System_Action_o* _24________________________;
		struct ________________________511_o* _25________________________;
		struct System_String_o* _26________________________;
		struct VRC_SDKBase_VRC_AvatarDescriptor_o* _27________________________;
		struct System_Collections_Generic_List__________________________________________________o* _28________________________;
		struct System_Collections_Generic_List__________________________________________________o* _29________________________;
	};
	struct ________________________113_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________113_c {
		Il2CppClass_1 _1;
		struct ________________________113_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________113_VTable vtable;
	};
	struct ________________________113_o {
		________________________113_c* klass;
		void* monitor;
		________________________113_Fields fields;
	};
	struct ________________________113_StaticFields {
		struct UnityEngine_Color_o _8________________________;
		struct ________________________113_o* _16________________________;
	};
	struct __declspec(align(8)) ________________________114_Fields {
	};
	struct ________________________114_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VirtualInvokeData vtable[32];
	};
	struct ________________________114_o {
		________________________114_c* klass;
		void* monitor;
		________________________114_Fields fields;
	};
	struct ________________________________________________49_Fields {
		int32_t value__;
	};
	struct ________________________________________________49_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________49_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________49_VTable vtable;
	};
	struct ________________________________________________49_o {
		________________________________________________49_Fields fields;
	};
	struct ________________________115_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Canvas_o* _______________________;
		struct ________________________112_o* _1________________________;
		struct System_Action_bool__o* _2________________________;
		bool _3________________________;
		struct ________________________________________________53_o* _4________________________;
		int32_t _6________________________;
		struct ________________________463_o* _7________________________;
	};
	struct ________________________115_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________115_c {
		Il2CppClass_1 _1;
		struct ________________________115_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________115_VTable vtable;
	};
	struct ________________________115_o {
		________________________115_c* klass;
		void* monitor;
		________________________115_Fields fields;
	};
	struct ________________________115_StaticFields {
		float _5________________________;
	};
	struct ________________________160_Fields : UnityEngine_MonoBehaviour_Fields {
		struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_o* _______________________;
		struct ________________________111_o* _1________________________;
		struct ________________________________________________48_o* _2________________________;
		bool _3________________________;
	};
	struct ________________________160_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
	};
	struct ________________________160_c {
		Il2CppClass_1 _1;
		struct ________________________160_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________160_VTable vtable;
	};
	struct ________________________160_o {
		________________________160_c* klass;
		void* monitor;
		________________________160_Fields fields;
	};
	struct ________________________160_StaticFields {
		struct System_Collections_Generic_List__________________________o* _4________________________;
	};
	struct ________________________116_Fields : ________________________160_Fields {
		struct ________________________4371_o* _______________________;
		struct ________________________4371_o* _1________________________;
		struct UnityEngine_GameObject_o* _2________________________;
		struct UnityEngine_CanvasGroup_o* _3________________________;
		struct ________________________112_o* _4________________________;
		bool _9________________________;
		bool _10________________________;
	};
	struct ________________________116_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8_OnEnable;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10_Update;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13_OnDisable;
		VirtualInvokeData _14________________________;
	};
	struct ________________________116_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________116_VTable vtable;
	};
	struct ________________________116_o {
		________________________116_c* klass;
		void* monitor;
		________________________116_Fields fields;
	};
	struct ________________________117_Fields : ________________________116_Fields {
		struct UnityEngine_GameObject_o* _______________________;
		struct ________________________157_o* _1________________________;
		struct ________________________157_o* _2________________________;
		struct ________________________157_o* _3________________________;
		struct ________________________157_o* _4________________________;
		struct ________________________110_o* _5________________________;
		struct ________________________110_o* _6________________________;
		struct ________________________110_o* _7________________________;
		struct ________________________110_o* _8________________________;
		bool _9________________________;
		bool _10________________________;
		struct UnityEngine_Vector2_o _12________________________;
	};
	struct ________________________117_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8_OnEnable;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10_Update;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13_OnDisable;
		VirtualInvokeData _14________________________;
	};
	struct ________________________117_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________117_VTable vtable;
	};
	struct ________________________117_o {
		________________________117_c* klass;
		void* monitor;
		________________________117_Fields fields;
	};
	struct ________________________118_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		float _1________________________;
	};
	struct ________________________118_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________118_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________118_VTable vtable;
	};
	struct ________________________118_o {
		________________________118_c* klass;
		void* monitor;
		________________________118_Fields fields;
	};
	struct ________________________119_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
	};
	struct ________________________119_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________119_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________119_VTable vtable;
	};
	struct ________________________119_o {
		________________________119_c* klass;
		void* monitor;
		________________________119_Fields fields;
	};
	struct ________________________120_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		struct UnityEngine_CanvasGroup_o* _3________________________;
	};
	struct ________________________120_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________120_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________120_VTable vtable;
	};
	struct ________________________120_o {
		________________________120_c* klass;
		void* monitor;
		________________________120_Fields fields;
	};
	struct ________________________121_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _______________________;
		struct UnityEngine_Vector3_o _1________________________;
		struct UnityEngine_Vector3_o _2________________________;
		float _3________________________;
		bool _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
		float _8________________________;
		bool _9________________________;
		struct UnityEngine_Camera_o* _10________________________;
	};
	struct ________________________121_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________121_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________121_VTable vtable;
	};
	struct ________________________121_o {
		________________________121_c* klass;
		void* monitor;
		________________________121_Fields fields;
	};
	struct ________________________122_Fields : UnityEngine_MonoBehaviour_Fields {
		struct VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_o* _______________________;
		struct ________________________158_o* _1________________________;
		struct ________________________111_o* _2________________________;
		struct System_Action_o* _3________________________;
	};
	struct ________________________122_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________122_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________122_VTable vtable;
	};
	struct ________________________122_o {
		________________________122_c* klass;
		void* monitor;
		________________________122_Fields fields;
	};
	struct ________________________123_Fields : ________________________122_Fields {
		struct ________________________160_o* _______________________;
	};
	struct ________________________123_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________123_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________123_VTable vtable;
	};
	struct ________________________123_o {
		________________________123_c* klass;
		void* monitor;
		________________________123_Fields fields;
	};
	struct ________________________124_Fields : ________________________122_Fields {
		bool _______________________;
	};
	struct ________________________124_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________124_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________124_VTable vtable;
	};
	struct ________________________124_o {
		________________________124_c* klass;
		void* monitor;
		________________________124_Fields fields;
	};
	struct ________________________125_Fields : ________________________122_Fields {
		struct ________________________160_o* _______________________;
		float _1________________________;
	};
	struct ________________________125_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________125_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________125_VTable vtable;
	};
	struct ________________________125_o {
		________________________125_c* klass;
		void* monitor;
		________________________125_Fields fields;
	};
	struct ________________________126_Fields : ________________________122_Fields {
		struct ________________________________________________48_o* _______________________;
		struct ________________________________________________29_o* _1________________________;
	};
	struct ________________________126_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________126_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________126_VTable vtable;
	};
	struct ________________________126_o {
		________________________126_c* klass;
		void* monitor;
		________________________126_Fields fields;
	};
	struct ________________________127_Fields : ________________________122_Fields {
	};
	struct ________________________127_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________127_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________127_VTable vtable;
	};
	struct ________________________127_o {
		________________________127_c* klass;
		void* monitor;
		________________________127_Fields fields;
	};
	struct ________________________128_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________159_o* _______________________;
	};
	struct ________________________128_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________128_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________128_VTable vtable;
	};
	struct ________________________128_o {
		________________________128_c* klass;
		void* monitor;
		________________________128_Fields fields;
	};
	struct ________________________129_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _index;
		struct ________________________159_o* _______________________;
		struct ________________________298_o* _2________________________;
		bool _3________________________;
	};
	struct ________________________129_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________129_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________129_VTable vtable;
	};
	struct ________________________129_o {
		________________________129_c* klass;
		void* monitor;
		________________________129_Fields fields;
	};
	struct __declspec(align(8)) ________________________130_Fields {
	};
	struct ________________________130_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VirtualInvokeData vtable[32];
	};
	struct ________________________130_o {
		________________________130_c* klass;
		void* monitor;
		________________________130_Fields fields;
	};
	struct __declspec(align(8)) ________________________131_Fields {
	};
	struct ________________________131_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VirtualInvokeData vtable[32];
	};
	struct ________________________131_o {
		________________________131_c* klass;
		void* monitor;
		________________________131_Fields fields;
	};
	struct ________________________132_Fields : VRC_SDK3_Avatars_ScriptableObjects_VRCExpressionsMenu_Control_Fields {
		struct System_Single_array* _______________________;
		struct System_Action_float____o* _1________________________;
	};
	struct ________________________132_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_unknown;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________132_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________132_VTable vtable;
	};
	struct ________________________132_o {
		________________________132_c* klass;
		void* monitor;
		________________________132_Fields fields;
	};
	struct ________________________133_Fields : ________________________122_Fields {
		struct ________________________160_o* _______________________;
	};
	struct ________________________133_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________133_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________133_VTable vtable;
	};
	struct ________________________133_o {
		________________________133_c* klass;
		void* monitor;
		________________________133_Fields fields;
	};
	struct __declspec(align(8)) ________________________134_Fields {
		struct System_String_o* _______________________;
		struct UnityEngine_Texture_o* _1________________________;
	};
	struct ________________________134_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________134_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________134_VTable vtable;
	};
	struct ________________________134_o {
		________________________134_c* klass;
		void* monitor;
		________________________134_Fields fields;
	};
	struct ________________________135_Fields : ________________________122_Fields {
		struct ________________________160_o* _______________________;
		float _1________________________;
	};
	struct ________________________135_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
	};
	struct ________________________135_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________135_VTable vtable;
	};
	struct ________________________135_o {
		________________________135_c* klass;
		void* monitor;
		________________________135_Fields fields;
	};
	struct ________________________136_Fields : UnityEngine_MonoBehaviour_Fields {
		struct VRC_UI_Client_Emoji_EmojiData_o* _______________________;
		bool _1________________________;
		struct ________________________159_o* _2________________________;
	};
	struct ________________________136_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
	};
	struct ________________________136_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________136_VTable vtable;
	};
	struct ________________________136_o {
		________________________136_c* klass;
		void* monitor;
		________________________136_Fields fields;
	};
	struct ________________________138_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________159_o* _________________________k__BackingField;
	};
	struct ________________________138_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_unknown;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
	};
	struct ________________________138_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________138_VTable vtable;
	};
	struct ________________________138_o {
		________________________138_c* klass;
		void* monitor;
		________________________138_Fields fields;
	};
	struct ________________________137_Fields : ________________________138_Fields {
		struct ________________________115_o* _______________________;
	};
	struct ________________________137_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_unknown;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
	};
	struct ________________________137_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________137_VTable vtable;
	};
	struct ________________________137_o {
		________________________137_c* klass;
		void* monitor;
		________________________137_Fields fields;
	};
	struct ________________________139_Fields : ________________________138_Fields {
	};
	struct ________________________139_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________139_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________139_VTable vtable;
	};
	struct ________________________139_o {
		________________________139_c* klass;
		void* monitor;
		________________________139_Fields fields;
	};
	struct ________________________140_Fields : ________________________138_Fields {
	};
	struct ________________________140_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________140_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________140_VTable vtable;
	};
	struct ________________________140_o {
		________________________140_c* klass;
		void* monitor;
		________________________140_Fields fields;
	};
	struct ________________________141_Fields : ________________________138_Fields {
	};
	struct ________________________141_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________141_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________141_VTable vtable;
	};
	struct ________________________141_o {
		________________________141_c* klass;
		void* monitor;
		________________________141_Fields fields;
	};
	struct ________________________142_Fields : ________________________138_Fields {
	};
	struct ________________________142_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________142_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________142_VTable vtable;
	};
	struct ________________________142_o {
		________________________142_c* klass;
		void* monitor;
		________________________142_Fields fields;
	};
	struct ________________________143_Fields : ________________________138_Fields {
		struct ________________________121_o* _______________________;
		bool _1________________________;
		float _2________________________;
		float _3________________________;
		struct UnityEngine_Plane_array* _4________________________;
	};
	struct ________________________143_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________143_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________143_VTable vtable;
	};
	struct ________________________143_o {
		________________________143_c* klass;
		void* monitor;
		________________________143_Fields fields;
	};
	struct ________________________144_Fields : ________________________138_Fields {
	};
	struct ________________________144_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________144_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________144_VTable vtable;
	};
	struct ________________________144_o {
		________________________144_c* klass;
		void* monitor;
		________________________144_Fields fields;
	};
	struct ________________________145_Fields : ________________________138_Fields {
		int32_t _______________________;
		struct VRC_Localization_LocalizableString_o _1________________________;
		bool _2________________________;
		bool _3________________________;
	};
	struct ________________________145_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________145_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________145_VTable vtable;
	};
	struct ________________________145_o {
		________________________145_c* klass;
		void* monitor;
		________________________145_Fields fields;
	};
	struct ________________________146_Fields : ________________________138_Fields {
	};
	struct ________________________146_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________146_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________146_VTable vtable;
	};
	struct ________________________146_o {
		________________________146_c* klass;
		void* monitor;
		________________________146_Fields fields;
	};
	struct ________________________147_Fields : ________________________138_Fields {
		int32_t _______________________;
		struct VRC_Localization_LocalizableString_o _1________________________;
		bool _2________________________;
		bool _3________________________;
	};
	struct ________________________147_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________147_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________147_VTable vtable;
	};
	struct ________________________147_o {
		________________________147_c* klass;
		void* monitor;
		________________________147_Fields fields;
	};
	struct ________________________148_Fields : ________________________138_Fields {
	};
	struct ________________________148_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________148_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________148_VTable vtable;
	};
	struct ________________________148_o {
		________________________148_c* klass;
		void* monitor;
		________________________148_Fields fields;
	};
	struct ________________________149_Fields : ________________________138_Fields {
	};
	struct ________________________149_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________149_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________149_VTable vtable;
	};
	struct ________________________149_o {
		________________________149_c* klass;
		void* monitor;
		________________________149_Fields fields;
	};
	struct ________________________150_Fields : ________________________138_Fields {
	};
	struct ________________________150_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________150_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________150_VTable vtable;
	};
	struct ________________________150_o {
		________________________150_c* klass;
		void* monitor;
		________________________150_Fields fields;
	};
	struct ________________________151_Fields : ________________________138_Fields {
		bool _______________________;
	};
	struct ________________________151_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________151_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________151_VTable vtable;
	};
	struct ________________________151_o {
		________________________151_c* klass;
		void* monitor;
		________________________151_Fields fields;
	};
	struct ________________________152_Fields : ________________________138_Fields {
	};
	struct ________________________152_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________152_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________152_VTable vtable;
	};
	struct ________________________152_o {
		________________________152_c* klass;
		void* monitor;
		________________________152_Fields fields;
	};
	struct ________________________153_Fields : ________________________137_Fields {
	};
	struct ________________________153_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________153_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________153_VTable vtable;
	};
	struct ________________________153_o {
		________________________153_c* klass;
		void* monitor;
		________________________153_Fields fields;
	};
	struct ________________________154_Fields : ________________________137_Fields {
	};
	struct ________________________154_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________154_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________154_VTable vtable;
	};
	struct ________________________154_o {
		________________________154_c* klass;
		void* monitor;
		________________________154_Fields fields;
	};
	struct ________________________155_Fields : ________________________138_Fields {
	};
	struct ________________________155_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________155_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________155_VTable vtable;
	};
	struct ________________________155_o {
		________________________155_c* klass;
		void* monitor;
		________________________155_Fields fields;
	};
	struct ________________________156_Fields : ________________________138_Fields {
	};
	struct ________________________156_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7________________________;
	};
	struct ________________________156_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________156_VTable vtable;
	};
	struct ________________________156_o {
		________________________156_c* klass;
		void* monitor;
		________________________156_Fields fields;
	};
	struct UnityEngine_EventSystems_UIBehaviour_Fields : UnityEngine_MonoBehaviour_Fields {
	};
	struct UnityEngine_EventSystems_UIBehaviour_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnEnable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8_OnDestroy;
		VirtualInvokeData _9_IsActive;
		VirtualInvokeData _10_OnRectTransformDimensionsChange;
		VirtualInvokeData _11_OnBeforeTransformParentChanged;
		VirtualInvokeData _12_OnTransformParentChanged;
		VirtualInvokeData _13_OnDidApplyAnimationProperties;
		VirtualInvokeData _14_OnCanvasGroupChanged;
		VirtualInvokeData _15_OnCanvasHierarchyChanged;
		VirtualInvokeData _16_IsDestroyed;
	};
	struct UnityEngine_EventSystems_UIBehaviour_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_EventSystems_UIBehaviour_VTable vtable;
	};
	struct UnityEngine_EventSystems_UIBehaviour_o {
		UnityEngine_EventSystems_UIBehaviour_c* klass;
		void* monitor;
		UnityEngine_EventSystems_UIBehaviour_Fields fields;
	};
	struct UnityEngine_Vector4_Fields {
		float x;
		float y;
		float z;
		float w;
	};
	struct UnityEngine_Vector4_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Equals;
		VirtualInvokeData _5_ToString;
	};
	struct UnityEngine_Vector4_c {
		Il2CppClass_1 _1;
		struct UnityEngine_Vector4_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_Vector4_VTable vtable;
	};
	struct UnityEngine_Vector4_o {
		UnityEngine_Vector4_Fields fields;
	};
	struct UnityEngine_Vector4_StaticFields {
		struct UnityEngine_Vector4_o zeroVector;
		struct UnityEngine_Vector4_o oneVector;
		struct UnityEngine_Vector4_o positiveInfinityVector;
		struct UnityEngine_Vector4_o negativeInfinityVector;
	};
	struct UnityEngine_UI_Graphic_Fields : UnityEngine_EventSystems_UIBehaviour_Fields {
		struct UnityEngine_Material_o* m_Material;
		struct UnityEngine_Color_o m_Color;
		bool m_SkipLayoutUpdate;
		bool m_SkipMaterialUpdate;
		bool m_RaycastTarget;
		bool m_RaycastTargetCache;
		struct UnityEngine_Vector4_o m_RaycastPadding;
		struct UnityEngine_RectTransform_o* m_RectTransform;
		struct UnityEngine_CanvasRenderer_o* m_CanvasRenderer;
		struct UnityEngine_Canvas_o* m_Canvas;
		bool m_VertsDirty;
		bool m_MaterialDirty;
		struct UnityEngine_Events_UnityAction_o* m_OnDirtyLayoutCallback;
		struct UnityEngine_Events_UnityAction_o* m_OnDirtyVertsCallback;
		struct UnityEngine_Events_UnityAction_o* m_OnDirtyMaterialCallback;
		struct UnityEngine_Mesh_o* m_CachedMesh;
		struct UnityEngine_Vector2_array* m_CachedUvs;
		struct UnityEngine_UI_CoroutineTween_TweenRunner_ColorTween__o* m_ColorTweenRunner;
		bool _useLegacyMeshGeneration_k__BackingField;
	};
	struct UnityEngine_UI_Graphic_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnEnable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8_OnDestroy;
		VirtualInvokeData _9_IsActive;
		VirtualInvokeData _10_OnRectTransformDimensionsChange;
		VirtualInvokeData _11_OnBeforeTransformParentChanged;
		VirtualInvokeData _12_OnTransformParentChanged;
		VirtualInvokeData _13_OnDidApplyAnimationProperties;
		VirtualInvokeData _14_OnCanvasGroupChanged;
		VirtualInvokeData _15_OnCanvasHierarchyChanged;
		VirtualInvokeData _16_IsDestroyed;
		VirtualInvokeData _17_unknown;
		VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
		VirtualInvokeData _19_unknown;
		VirtualInvokeData _20_unknown;
		VirtualInvokeData _21_unknown;
		VirtualInvokeData _22_get_color;
		VirtualInvokeData _23_set_color;
		VirtualInvokeData _24_get_raycastTarget;
		VirtualInvokeData _25_set_raycastTarget;
		VirtualInvokeData _26_SetAllDirty;
		VirtualInvokeData _27_SetLayoutDirty;
		VirtualInvokeData _28_SetVerticesDirty;
		VirtualInvokeData _29_SetMaterialDirty;
		VirtualInvokeData _30_get_rectTransform;
		VirtualInvokeData _31_get_defaultMaterial;
		VirtualInvokeData _32_get_material;
		VirtualInvokeData _33_set_material;
		VirtualInvokeData _34_get_materialForRendering;
		VirtualInvokeData _35_get_mainTexture;
		VirtualInvokeData _36_OnCullingChanged;
		VirtualInvokeData _37_Rebuild;
		VirtualInvokeData _38_LayoutComplete;
		VirtualInvokeData _39_GraphicUpdateComplete;
		VirtualInvokeData _40_UpdateMaterial;
		VirtualInvokeData _41_UpdateGeometry;
		VirtualInvokeData _42_OnFillVBO;
		VirtualInvokeData _43_OnPopulateMesh;
		VirtualInvokeData _44_OnPopulateMesh;
		VirtualInvokeData _45_SetNativeSize;
		VirtualInvokeData _46_Raycast;
		VirtualInvokeData _47_CrossFadeColor;
		VirtualInvokeData _48_CrossFadeColor;
		VirtualInvokeData _49_CrossFadeAlpha;
	};
	struct UnityEngine_UI_Graphic_c {
		Il2CppClass_1 _1;
		struct UnityEngine_UI_Graphic_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_UI_Graphic_VTable vtable;
	};
	struct UnityEngine_UI_Graphic_o {
		UnityEngine_UI_Graphic_c* klass;
		void* monitor;
		UnityEngine_UI_Graphic_Fields fields;
	};
	struct UnityEngine_UI_Graphic_StaticFields {
		struct UnityEngine_Material_o* s_DefaultUI;
		struct UnityEngine_Texture2D_o* s_WhiteTexture;
		struct UnityEngine_Mesh_o* s_Mesh;
		struct UnityEngine_UI_VertexHelper_o* s_VertexHelper;
	};
	struct UnityEngine_UI_MaskableGraphic_Fields : UnityEngine_UI_Graphic_Fields {
		bool m_ShouldRecalculateStencil;
		struct UnityEngine_Material_o* m_MaskMaterial;
		struct UnityEngine_UI_RectMask2D_o* m_ParentMask;
		bool m_Maskable;
		bool m_IsMaskingGraphic;
		bool m_IncludeForMasking;
		struct UnityEngine_UI_MaskableGraphic_CullStateChangedEvent_o* m_OnCullStateChanged;
		bool m_ShouldRecalculate;
		int32_t m_StencilValue;
		struct UnityEngine_Vector3_array* m_Corners;
	};
	struct UnityEngine_UI_MaskableGraphic_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnEnable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8_OnDestroy;
		VirtualInvokeData _9_IsActive;
		VirtualInvokeData _10_OnRectTransformDimensionsChange;
		VirtualInvokeData _11_OnBeforeTransformParentChanged;
		VirtualInvokeData _12_OnTransformParentChanged;
		VirtualInvokeData _13_OnDidApplyAnimationProperties;
		VirtualInvokeData _14_OnCanvasGroupChanged;
		VirtualInvokeData _15_OnCanvasHierarchyChanged;
		VirtualInvokeData _16_IsDestroyed;
		VirtualInvokeData _17_unknown;
		VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
		VirtualInvokeData _19_unknown;
		VirtualInvokeData _20_unknown;
		VirtualInvokeData _21_unknown;
		VirtualInvokeData _22_get_color;
		VirtualInvokeData _23_set_color;
		VirtualInvokeData _24_get_raycastTarget;
		VirtualInvokeData _25_set_raycastTarget;
		VirtualInvokeData _26_SetAllDirty;
		VirtualInvokeData _27_SetLayoutDirty;
		VirtualInvokeData _28_SetVerticesDirty;
		VirtualInvokeData _29_SetMaterialDirty;
		VirtualInvokeData _30_get_rectTransform;
		VirtualInvokeData _31_get_defaultMaterial;
		VirtualInvokeData _32_get_material;
		VirtualInvokeData _33_set_material;
		VirtualInvokeData _34_get_materialForRendering;
		VirtualInvokeData _35_get_mainTexture;
		VirtualInvokeData _36_OnCullingChanged;
		VirtualInvokeData _37_Rebuild;
		VirtualInvokeData _38_LayoutComplete;
		VirtualInvokeData _39_GraphicUpdateComplete;
		VirtualInvokeData _40_UpdateMaterial;
		VirtualInvokeData _41_UpdateGeometry;
		VirtualInvokeData _42_OnFillVBO;
		VirtualInvokeData _43_OnPopulateMesh;
		VirtualInvokeData _44_OnPopulateMesh;
		VirtualInvokeData _45_SetNativeSize;
		VirtualInvokeData _46_Raycast;
		VirtualInvokeData _47_CrossFadeColor;
		VirtualInvokeData _48_CrossFadeColor;
		VirtualInvokeData _49_CrossFadeAlpha;
		VirtualInvokeData _50_UnityEngine_UI_IClippable_get_gameObject;
		VirtualInvokeData _51_unknown;
		VirtualInvokeData _52_unknown;
		VirtualInvokeData _53_unknown;
		VirtualInvokeData _54_unknown;
		VirtualInvokeData _55_unknown;
		VirtualInvokeData _56_unknown;
		VirtualInvokeData _57_unknown;
		VirtualInvokeData _58_GetModifiedMaterial;
		VirtualInvokeData _59_Cull;
		VirtualInvokeData _60_SetClipRect;
		VirtualInvokeData _61_SetClipSoftness;
		VirtualInvokeData _62_ParentMaskStateChanged;
		VirtualInvokeData _63_RecalculateClipping;
		VirtualInvokeData _64_RecalculateMasking;
	};
	struct UnityEngine_UI_MaskableGraphic_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_UI_MaskableGraphic_VTable vtable;
	};
	struct UnityEngine_UI_MaskableGraphic_o {
		UnityEngine_UI_MaskableGraphic_c* klass;
		void* monitor;
		UnityEngine_UI_MaskableGraphic_Fields fields;
	};
	struct ________________________157_Fields : UnityEngine_UI_MaskableGraphic_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		struct UnityEngine_Texture_o* _texture;
	};
	struct ________________________157_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnEnable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8_OnDestroy;
		VirtualInvokeData _9_IsActive;
		VirtualInvokeData _10_OnRectTransformDimensionsChange;
		VirtualInvokeData _11_OnBeforeTransformParentChanged;
		VirtualInvokeData _12_OnTransformParentChanged;
		VirtualInvokeData _13_OnDidApplyAnimationProperties;
		VirtualInvokeData _14_OnCanvasGroupChanged;
		VirtualInvokeData _15_OnCanvasHierarchyChanged;
		VirtualInvokeData _16_IsDestroyed;
		VirtualInvokeData _17_unknown;
		VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
		VirtualInvokeData _19_unknown;
		VirtualInvokeData _20_unknown;
		VirtualInvokeData _21_unknown;
		VirtualInvokeData _22_get_color;
		VirtualInvokeData _23_set_color;
		VirtualInvokeData _24_get_raycastTarget;
		VirtualInvokeData _25_set_raycastTarget;
		VirtualInvokeData _26_SetAllDirty;
		VirtualInvokeData _27_SetLayoutDirty;
		VirtualInvokeData _28_SetVerticesDirty;
		VirtualInvokeData _29_SetMaterialDirty;
		VirtualInvokeData _30_get_rectTransform;
		VirtualInvokeData _31_get_defaultMaterial;
		VirtualInvokeData _32_get_material;
		VirtualInvokeData _33_set_material;
		VirtualInvokeData _34_get_materialForRendering;
		VirtualInvokeData _35_get_mainTexture;
		VirtualInvokeData _36_OnCullingChanged;
		VirtualInvokeData _37_Rebuild;
		VirtualInvokeData _38_LayoutComplete;
		VirtualInvokeData _39_GraphicUpdateComplete;
		VirtualInvokeData _40_UpdateMaterial;
		VirtualInvokeData _41_UpdateGeometry;
		VirtualInvokeData _42_OnFillVBO;
		VirtualInvokeData _43_OnPopulateMesh;
		VirtualInvokeData _44_OnPopulateMesh;
		VirtualInvokeData _45_SetNativeSize;
		VirtualInvokeData _46_Raycast;
		VirtualInvokeData _47_CrossFadeColor;
		VirtualInvokeData _48_CrossFadeColor;
		VirtualInvokeData _49_CrossFadeAlpha;
		VirtualInvokeData _50_UnityEngine_UI_IClippable_get_gameObject;
		VirtualInvokeData _51_unknown;
		VirtualInvokeData _52_unknown;
		VirtualInvokeData _53_unknown;
		VirtualInvokeData _54_unknown;
		VirtualInvokeData _55_unknown;
		VirtualInvokeData _56_unknown;
		VirtualInvokeData _57_unknown;
		VirtualInvokeData _58_GetModifiedMaterial;
		VirtualInvokeData _59_Cull;
		VirtualInvokeData _60_SetClipRect;
		VirtualInvokeData _61_SetClipSoftness;
		VirtualInvokeData _62_ParentMaskStateChanged;
		VirtualInvokeData _63_RecalculateClipping;
		VirtualInvokeData _64_RecalculateMasking;
	};
	struct ________________________157_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________157_VTable vtable;
	};
	struct ________________________157_o {
		________________________157_c* klass;
		void* monitor;
		________________________157_Fields fields;
	};
	struct __declspec(align(8)) ________________________158_Fields {
	};
	struct ________________________158_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VirtualInvokeData vtable[32];
	};
	struct ________________________158_o {
		________________________158_c* klass;
		void* monitor;
		________________________158_Fields fields;
	};
	struct ________________________________________________50_Fields {
		int32_t value__;
	};
	struct ________________________________________________50_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________50_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________50_VTable vtable;
	};
	struct ________________________________________________50_o {
		________________________________________________50_Fields fields;
	};
	struct ________________________159_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________157_o* _______________________;
		struct ________________________110_o* _1________________________;
		struct ________________________112_o* _2________________________;
		struct System_Func_bool__o* _8________________________;
		struct System_Action_o* _9________________________;
		int32_t _10________________________;
		struct System_Func_bool__o* _________________________k__BackingField;
		struct System_Action_o* _12________________________;
		bool _13________________________;
		bool _14________________________;
	};
	struct ________________________159_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
		VirtualInvokeData _15________________________;
	};
	struct ________________________159_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________159_VTable vtable;
	};
	struct ________________________159_o {
		________________________159_c* klass;
		void* monitor;
		________________________159_Fields fields;
	};
	struct ________________________161_Fields : ________________________116_Fields {
		struct ________________________157_o* _______________________;
		struct ________________________157_o* _1________________________;
		struct UnityEngine_GameObject_o* _2________________________;
		struct UnityEngine_GameObject_o* _3________________________;
		struct UnityEngine_GameObject_o* _4________________________;
		struct TMPro_TextMeshProUGUI_o* _5________________________;
		struct UnityEngine_Vector2_o _9________________________;
		float _10________________________;
		float _11________________________;
	};
	struct ________________________161_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8_OnEnable;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10_Update;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13_OnDisable;
		VirtualInvokeData _14________________________;
	};
	struct ________________________161_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________161_VTable vtable;
	};
	struct ________________________161_o {
		________________________161_c* klass;
		void* monitor;
		________________________161_Fields fields;
	};
	struct __declspec(align(8)) System_Delegate_Fields {
		intptr_t method_ptr;
		intptr_t invoke_impl;
		Il2CppObject* m_target;
		intptr_t method;
		intptr_t delegate_trampoline;
		intptr_t extra_arg;
		intptr_t method_code;
		intptr_t interp_method;
		intptr_t interp_invoke_impl;
		struct System_Reflection_MethodInfo_o* method_info;
		struct System_Reflection_MethodInfo_o* original_method_info;
		struct System_DelegateData_o* data;
		bool method_is_virtual;
	};
	struct System_Delegate_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_unknown;
		VirtualInvokeData _5_unknown;
		VirtualInvokeData _6_Clone;
		VirtualInvokeData _7_GetMethodImpl;
		VirtualInvokeData _8_GetObjectData;
		VirtualInvokeData _9_GetInvocationList;
		VirtualInvokeData _10_CombineImpl;
		VirtualInvokeData _11_RemoveImpl;
	};
	struct System_Delegate_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_Delegate_VTable vtable;
	};
	struct System_Delegate_o {
		System_Delegate_c* klass;
		void* monitor;
		System_Delegate_Fields fields;
	};
	struct System_MulticastDelegate_Fields : System_Delegate_Fields {
		struct System_Delegate_array* delegates;
	};
	struct System_MulticastDelegate_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_unknown;
		VirtualInvokeData _5_unknown;
		VirtualInvokeData _6_Clone;
		VirtualInvokeData _7_GetMethodImpl;
		VirtualInvokeData _8_GetObjectData;
		VirtualInvokeData _9_GetInvocationList;
		VirtualInvokeData _10_CombineImpl;
		VirtualInvokeData _11_RemoveImpl;
	};
	struct System_MulticastDelegate_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_MulticastDelegate_VTable vtable;
	};
	struct System_MulticastDelegate_o {
		System_MulticastDelegate_c* klass;
		void* monitor;
		System_MulticastDelegate_Fields fields;
	};
	struct ________________________________________________51_Fields : System_MulticastDelegate_Fields {
	};
	struct ________________________________________________51_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_unknown;
		VirtualInvokeData _5_unknown;
		VirtualInvokeData _6_Clone;
		VirtualInvokeData _7_GetMethodImpl;
		VirtualInvokeData _8_GetObjectData;
		VirtualInvokeData _9_GetInvocationList;
		VirtualInvokeData _10_CombineImpl;
		VirtualInvokeData _11_RemoveImpl;
		VirtualInvokeData _12_Invoke;
		VirtualInvokeData _13_BeginInvoke;
		VirtualInvokeData _14_EndInvoke;
	};
	struct ________________________________________________51_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________51_VTable vtable;
	};
	struct ________________________________________________51_o {
		________________________________________________51_c* klass;
		void* monitor;
		________________________________________________51_Fields fields;
	};
	struct ________________________________________________52_Fields {
		int32_t value__;
	};
	struct ________________________________________________52_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________52_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________52_VTable vtable;
	};
	struct ________________________________________________52_o {
		________________________________________________52_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________53_Fields {
		float _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		struct ________________________________________________51_o* _5________________________;
	};
	struct ________________________________________________53_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________53_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________53_VTable vtable;
	};
	struct ________________________________________________53_o {
		________________________________________________53_c* klass;
		void* monitor;
		________________________________________________53_Fields fields;
	};
	struct __declspec(align(8)) ________________________162_Fields {
	};
	struct ________________________162_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________162_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________162_VTable vtable;
	};
	struct ________________________162_o {
		________________________162_c* klass;
		void* monitor;
		________________________162_Fields fields;
	};
	struct ________________________________________________54_Fields {
		int32_t value__;
	};
	struct ________________________________________________54_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________54_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________54_VTable vtable;
	};
	struct ________________________________________________54_o {
		________________________________________________54_Fields fields;
	};
	struct ________________________________________________55_Fields {
		struct ________________________163_o* _______________________;
		float _1________________________;
		float _2________________________;
	};
	struct ________________________________________________55_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________55_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________55_VTable vtable;
	};
	struct ________________________________________________55_o {
		________________________________________________55_Fields fields;
	};
	struct ________________________163_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________164_o* _2________________________;
		int32_t _3________________________;
		float _4________________________;
		float _5________________________;
		float _6________________________;
		struct System_Collections_Generic_List_CollisionScene_Shape__o* _18________________________;
		struct System_Collections_Generic_HashSet_VRCPhysBoneBase__o* _19________________________;
	};
	struct ________________________163_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_get_Alpha;
		VirtualInvokeData _5_set_Alpha;
		VirtualInvokeData _6_Line;
		VirtualInvokeData _7_Sphere;
	};
	struct ________________________163_c {
		Il2CppClass_1 _1;
		struct ________________________163_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________163_VTable vtable;
	};
	struct ________________________163_o {
		________________________163_c* klass;
		void* monitor;
		________________________163_Fields fields;
	};
	struct ________________________163_StaticFields {
		struct ________________________163_o* _______________________;
		struct ________________________173_o* _1________________________;
		struct UnityEngine_Color_o _7________________________;
		struct UnityEngine_Color_o _8________________________;
		struct UnityEngine_Color_o _9________________________;
		float _10________________________;
		struct UnityEngine_Color_o _11________________________;
		struct UnityEngine_Color_o _12________________________;
		struct UnityEngine_Color_o _13________________________;
		struct UnityEngine_Color_o _14________________________;
		struct UnityEngine_Color_o _15________________________;
		struct UnityEngine_Color_o _16________________________;
		struct UnityEngine_Color_o _17________________________;
	};
	struct __declspec(align(8)) ________________________________________________56_Fields {
		struct VRC_SDK3_Dynamics_PhysBone_Components_VRCPhysBone_o* _______________________;
	};
	struct ________________________________________________56_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________56_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________56_VTable vtable;
	};
	struct ________________________________________________56_o {
		________________________________________________56_c* klass;
		void* monitor;
		________________________________________________56_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________57_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________164_o* _2________________________;
		struct VRC_SDK3_Dynamics_PhysBone_Components_VRCPhysBone_array* _3________________________;
	};
	struct ________________________________________________57_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________________________________57_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________57_VTable vtable;
	};
	struct ________________________________________________57_o {
		________________________________________________57_c* klass;
		void* monitor;
		________________________________________________57_Fields fields;
	};
	struct ________________________164_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* _______________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _1________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _2________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _3________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _4________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _5________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _6________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _7________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _8________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _9________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _10________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _11________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _12________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _13________________________;
		struct VRC_SDK3_Dynamics_Contact_Components_VRCContactSender_o* _14________________________;
		struct ________________________1673_o* _15________________________;
		struct ________________________511_o* _16________________________;
		int32_t _17________________________;
		struct ________________________506_o* _18________________________;
		struct ________________________324_o* _19________________________;
		struct ________________________312_o* _20________________________;
		struct UnityEngine_GameObject_o* _21________________________;
		struct UnityEngine_Animator_o* _22________________________;
		struct VRC_SDK3_Avatars_Components_VRCAvatarDescriptor_o* _23________________________;
		struct UnityEngine_Vector3_o _24________________________;
		bool _25________________________;
	};
	struct ________________________164_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________164_c {
		Il2CppClass_1 _1;
		struct ________________________164_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________164_VTable vtable;
	};
	struct ________________________164_o {
		________________________164_c* klass;
		void* monitor;
		________________________164_Fields fields;
	};
	struct ________________________164_StaticFields {
		struct System_Collections_Generic_List_DynamicBoneCollider__o* _26________________________;
		struct System_Collections_Generic_List_DynamicBone__o* _27________________________;
	};
	struct ________________________________________________58_Fields {
		int32_t value__;
	};
	struct ________________________________________________58_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________58_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________58_VTable vtable;
	};
	struct ________________________________________________58_o {
		________________________________________________58_Fields fields;
	};
	struct ________________________________________________59_Fields {
		int32_t value__;
	};
	struct ________________________________________________59_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________59_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________59_VTable vtable;
	};
	struct ________________________________________________59_o {
		________________________________________________59_Fields fields;
	};
	struct __declspec(align(8)) __________________________c_2_Fields {
	};
	struct __________________________c_2_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct __________________________c_2_c {
		Il2CppClass_1 _1;
		struct __________________________c_2_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		__________________________c_2_VTable vtable;
	};
	struct __________________________c_2_o {
		__________________________c_2_c* klass;
		void* monitor;
		__________________________c_2_Fields fields;
	};
	struct __________________________c_2_StaticFields {
		struct __________________________c_2_o* __9;
	};
	struct ________________________165_Fields : UnityEngine_MonoBehaviour_Fields {
	};
	struct ________________________165_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________165_c {
		Il2CppClass_1 _1;
		struct ________________________165_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________165_VTable vtable;
	};
	struct ________________________165_o {
		________________________165_c* klass;
		void* monitor;
		________________________165_Fields fields;
	};
	struct ________________________165_StaticFields {
		struct ________________________165_o* _______________________;
		int32_t _3________________________;
		bool _4________________________;
		bool _5________________________;
		struct System_Lazy_int__o* _6________________________;
	};
	struct ________________________166_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _______________________;
		struct ________________________173_o* _1________________________;
	};
	struct ________________________166_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________166_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________166_VTable vtable;
	};
	struct ________________________166_o {
		________________________166_c* klass;
		void* monitor;
		________________________166_Fields fields;
	};
	struct ________________________________________________60_Fields {
		struct System_String_o* _______________________;
		struct System_String_o* _1________________________;
	};
	struct ________________________________________________60_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________60_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________60_VTable vtable;
	};
	struct ________________________________________________60_o {
		________________________________________________60_Fields fields;
	};
	struct __declspec(align(8)) __________________________c_3_Fields {
	};
	struct __________________________c_3_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct __________________________c_3_c {
		Il2CppClass_1 _1;
		struct __________________________c_3_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		__________________________c_3_VTable vtable;
	};
	struct __________________________c_3_o {
		__________________________c_3_c* klass;
		void* monitor;
		__________________________c_3_Fields fields;
	};
	struct __________________________c_3_StaticFields {
		struct __________________________c_3_o* __9;
		struct System_Action_ApiContainer__o* __9__15_1;
	};
	struct System_Runtime_CompilerServices_AsyncMethodBuilderCore_Fields {
		struct System_Runtime_CompilerServices_IAsyncStateMachine_o* m_stateMachine;
		struct System_Action_o* m_defaultContextAction;
	};
	struct System_Runtime_CompilerServices_AsyncMethodBuilderCore_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct System_Runtime_CompilerServices_AsyncMethodBuilderCore_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_Runtime_CompilerServices_AsyncMethodBuilderCore_VTable vtable;
	};
	struct System_Runtime_CompilerServices_AsyncMethodBuilderCore_o {
		System_Runtime_CompilerServices_AsyncMethodBuilderCore_Fields fields;
	};
	struct System_Runtime_CompilerServices_AsyncVoidMethodBuilder_Fields {
		struct System_Threading_SynchronizationContext_o* m_synchronizationContext;
		struct System_Runtime_CompilerServices_AsyncMethodBuilderCore_o m_coreState;
		struct System_Threading_Tasks_Task_o* m_task;
	};
	struct System_Runtime_CompilerServices_AsyncVoidMethodBuilder_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct System_Runtime_CompilerServices_AsyncVoidMethodBuilder_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_Runtime_CompilerServices_AsyncVoidMethodBuilder_VTable vtable;
	};
	struct System_Runtime_CompilerServices_AsyncVoidMethodBuilder_o {
		System_Runtime_CompilerServices_AsyncVoidMethodBuilder_Fields fields;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter__________________________Fields {
		struct Cysharp_Threading_Tasks_UniTask_T__o task;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter__________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_UnsafeOnCompleted;
		VirtualInvokeData _5_OnCompleted;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter__________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Cysharp_Threading_Tasks_UniTask_Awaiter__________________________VTable vtable;
	};
	struct Cysharp_Threading_Tasks_UniTask_Awaiter__________________________o {
		Cysharp_Threading_Tasks_UniTask_Awaiter__________________________Fields fields;
	};
	struct ________________________________________________61_Fields {
		int32_t _______________________;
		struct System_Runtime_CompilerServices_AsyncVoidMethodBuilder_o _1________________________;
		struct VRC_Core_ApiAvatar_o* _2________________________;
		struct ________________________167_o* _3________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter__________________________o _4________________________;
	};
	struct ________________________________________________61_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________________________________61_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________61_VTable vtable;
	};
	struct ________________________________________________61_o {
		________________________________________________61_Fields fields;
	};
	struct ________________________167_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* _1________________________;
		struct UnityEngine_RuntimeAnimatorController_o* _2________________________;
		struct System_Collections_Generic_List__________________________________________________o* _3________________________;
		int32_t _4________________________;
		int32_t _5________________________;
		float _6________________________;
		bool _7________________________;
		bool _8________________________;
		bool _9________________________;
		struct System_Collections_Generic_List_GameObject__o* _10________________________;
	};
	struct ________________________167_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________167_c {
		Il2CppClass_1 _1;
		struct ________________________167_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________167_VTable vtable;
	};
	struct ________________________167_o {
		________________________167_c* klass;
		void* monitor;
		________________________167_Fields fields;
	};
	struct ________________________167_StaticFields {
		struct ________________________167_o* _______________________;
	};
	struct ________________________168_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_UI_Button_o* _______________________;
		struct UnityEngine_UI_Button_o* _1________________________;
		struct UnityEngine_UI_Button_o* _2________________________;
		struct TMPro_TextMeshProUGUI_o* _3________________________;
		struct UnityEngine_UI_Button_o* _4________________________;
		struct TMPro_TextMeshProUGUI_o* _5________________________;
		struct UnityEngine_UI_Button_o* _6________________________;
		struct TMPro_TextMeshProUGUI_o* _7________________________;
		struct TMPro_TextMeshProUGUI_o* _8________________________;
		struct UnityEngine_UI_Button_o* _9________________________;
		struct UnityEngine_UI_Button_o* _10________________________;
		struct TMPro_TextMeshProUGUI_o* _11________________________;
		struct UnityEngine_UI_Button_o* _12________________________;
		struct TMPro_TextMeshProUGUI_o* _13________________________;
		struct UnityEngine_UI_Button_o* _14________________________;
	};
	struct ________________________168_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________168_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________168_VTable vtable;
	};
	struct ________________________168_o {
		________________________168_c* klass;
		void* monitor;
		________________________168_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________62_Fields {
		struct System_String_o* _______________________;
		struct System_Collections_Generic_List_float__o* _1________________________;
	};
	struct ________________________________________________62_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________62_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________62_VTable vtable;
	};
	struct ________________________________________________62_o {
		________________________________________________62_c* klass;
		void* monitor;
		________________________________________________62_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________63_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________169_o* _2________________________;
		float _3________________________;
		bool _4________________________;
		int32_t _5________________________;
	};
	struct ________________________________________________63_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
	};
	struct ________________________________________________63_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________63_VTable vtable;
	};
	struct ________________________________________________63_o {
		________________________________________________63_c* klass;
		void* monitor;
		________________________________________________63_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________64_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________169_o* _2________________________;
	};
	struct ________________________________________________64_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________________________________64_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________64_VTable vtable;
	};
	struct ________________________________________________64_o {
		________________________________________________64_c* klass;
		void* monitor;
		________________________________________________64_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________65_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________169_o* _2________________________;
		float _3________________________;
		bool _4________________________;
	};
	struct ________________________________________________65_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________________________________65_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________65_VTable vtable;
	};
	struct ________________________________________________65_o {
		________________________________________________65_c* klass;
		void* monitor;
		________________________________________________65_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________66_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________169_o* _2________________________;
	};
	struct ________________________________________________66_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
		VirtualInvokeData _15________________________;
	};
	struct ________________________________________________66_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________66_VTable vtable;
	};
	struct ________________________________________________66_o {
		________________________________________________66_c* klass;
		void* monitor;
		________________________________________________66_Fields fields;
	};
	struct ________________________169_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* _______________________;
		float _1________________________;
		float _2________________________;
		bool _3________________________;
		float _4________________________;
		struct System_Collections_Generic_List__________________________________________________o* _5________________________;
		struct ________________________________________________62_o* _6________________________;
		bool _7________________________;
		struct System_Collections_Generic_List_GameObject__o* _8________________________;
		struct System_Collections_Generic_List_Vector3__o* _9________________________;
		struct System_Collections_Generic_List_double__o* _10________________________;
	};
	struct ________________________169_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________169_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________169_VTable vtable;
	};
	struct ________________________169_o {
		________________________169_c* klass;
		void* monitor;
		________________________169_Fields fields;
	};
	struct __declspec(align(8)) __________________________c_4_Fields {
	};
	struct __________________________c_4_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct __________________________c_4_c {
		Il2CppClass_1 _1;
		struct __________________________c_4_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		__________________________c_4_VTable vtable;
	};
	struct __________________________c_4_o {
		__________________________c_4_c* klass;
		void* monitor;
		__________________________c_4_Fields fields;
	};
	struct __________________________c_4_StaticFields {
		struct __________________________c_4_o* __9;
		struct System_Action_ApiContainer__o* __9__3_1;
	};
	struct ________________________________________________67_Fields {
		int32_t _______________________;
		struct System_Runtime_CompilerServices_AsyncVoidMethodBuilder_o _1________________________;
		struct VRC_Core_ApiAvatar_o* _2________________________;
		struct ________________________170_o* _3________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter__________________________o _4________________________;
	};
	struct ________________________________________________67_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________________________________67_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________67_VTable vtable;
	};
	struct ________________________________________________67_o {
		________________________________________________67_Fields fields;
	};
	struct ________________________170_Fields : UnityEngine_MonoBehaviour_Fields {
		struct System_String_o* _______________________;
		struct UnityEngine_GameObject_o* _1________________________;
	};
	struct ________________________170_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________170_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________170_VTable vtable;
	};
	struct ________________________170_o {
		________________________170_c* klass;
		void* monitor;
		________________________170_Fields fields;
	};
	struct ________________________171_Fields : UnityEngine_MonoBehaviour_Fields {
	};
	struct ________________________171_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________171_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________171_VTable vtable;
	};
	struct ________________________171_o {
		________________________171_c* klass;
		void* monitor;
		________________________171_Fields fields;
	};
	struct ________________________172_Fields : UnityEngine_MonoBehaviour_Fields {
	};
	struct ________________________172_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________172_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________172_VTable vtable;
	};
	struct ________________________172_o {
		________________________172_c* klass;
		void* monitor;
		________________________172_Fields fields;
	};
	struct ________________________173_Fields : UnityEngine_MonoBehaviour_Fields {
		struct IMDrawLine_o* _______________________;
		struct IMDrawLine_o* _1________________________;
		struct IMDrawShape_o* _2________________________;
		struct UnityEngine_Color_o _4________________________;
		float _5________________________;
		float _6________________________;
		int32_t _7________________________;
		int32_t _8________________________;
	};
	struct ________________________173_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________173_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________173_VTable vtable;
	};
	struct ________________________173_o {
		________________________173_c* klass;
		void* monitor;
		________________________173_Fields fields;
	};
	struct Unity_Collections_NativeArray_TYPE__Fields {
		void* m_Buffer;
		int32_t m_Length;
		int32_t m_AllocatorLabel;
	};
	struct Unity_Collections_NativeArray_TYPE__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Dispose;
		VirtualInvokeData _5_System_Collections_Generic_IEnumerable_T__GetEnumerator;
		VirtualInvokeData _6_System_Collections_IEnumerable_GetEnumerator;
		VirtualInvokeData _7_Equals;
	};
	struct Unity_Collections_NativeArray_TYPE__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Unity_Collections_NativeArray_TYPE__VTable vtable;
	};
	struct Unity_Collections_NativeArray_TYPE__o {
		Unity_Collections_NativeArray_TYPE__Fields fields;
	};
	struct UnityEngine_Bounds_Fields {
		struct UnityEngine_Vector3_o m_Center;
		struct UnityEngine_Vector3_o m_Extents;
	};
	struct UnityEngine_Bounds_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Equals;
		VirtualInvokeData _5_ToString;
	};
	struct UnityEngine_Bounds_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_Bounds_VTable vtable;
	};
	struct UnityEngine_Bounds_o {
		UnityEngine_Bounds_Fields fields;
	};
	struct __declspec(align(8)) IMDrawBuffer_TYPE__Fields {
		struct UnityEngine_Mesh_o* mesh;
		struct UnityEngine_Material_o* material;
		int32_t layer;
		int32_t subMeshIndex;
		struct Unity_Collections_NativeArray_TYPE__o meshProps;
		struct UnityEngine_ComputeBuffer_o* meshPropsBuffer;
		struct UnityEngine_ComputeBuffer_o* argsBuffer;
		struct System_UInt32_array* args;
		int32_t instanceCount;
		int32_t maxCapacity;
		struct UnityEngine_Bounds_o bounds;
		struct UnityEngine_Material_o* materialInst;
	};
	struct IMDrawBuffer_TYPE__RGCTXs {
		Il2CppClass* _0_IMDrawBuffer_TYPE_;
		MethodInfo* _1_IMDrawBuffer_TYPE__get_TypeSize;
		Il2CppClass* _2_Unity_Collections_NativeArray_TYPE_;
		MethodInfo* _3_Unity_Collections_NativeArray_TYPE___ctor;
		MethodInfo* _4_System_Activator_CreateInstance_TYPE_;
		Il2CppClass* _5_TYPE;
		MethodInfo* _6_Unity_Collections_NativeArray_TYPE__set_Item;
		Il2CppClass* _7_Unity_Collections_NativeArray_TYPE_;
		MethodInfo* _8_Unity_Collections_NativeArray_TYPE__get_IsCreated;
		MethodInfo* _9_Unity_Collections_NativeArray_TYPE__Dispose;
		MethodInfo* _10_UnityEngine_ComputeBuffer_SetData_TYPE_;
		MethodInfo* _11_IMDrawBuffer_TYPE_________________________;
		MethodInfo* _12_IMDrawBuffer_TYPE_________________________;
		MethodInfo* _13_IMDrawBuffer_TYPE_________________________;
	};
	struct IMDrawBuffer_TYPE__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Dispose;
		VirtualInvokeData _5_unknown;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
	};
	struct IMDrawBuffer_TYPE__c {
		Il2CppClass_1 _1;
		void* static_fields;
		IMDrawBuffer_TYPE__RGCTXs* rgctx_data;
		Il2CppClass_2 _2;
		IMDrawBuffer_TYPE__VTable vtable;
	};
	struct IMDrawBuffer_TYPE__o {
		IMDrawBuffer_TYPE__c* klass;
		void* monitor;
		IMDrawBuffer_TYPE__Fields fields;
	};
	struct Unity_Mathematics_float3_Fields {
		float x;
		float y;
		float z;
	};
	struct Unity_Mathematics_float3_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Equals;
		VirtualInvokeData _5_ToString;
	};
	struct Unity_Mathematics_float3_c {
		Il2CppClass_1 _1;
		struct Unity_Mathematics_float3_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Unity_Mathematics_float3_VTable vtable;
	};
	struct Unity_Mathematics_float3_o {
		Unity_Mathematics_float3_Fields fields;
	};
	struct Unity_Mathematics_float3_StaticFields {
		struct Unity_Mathematics_float3_o zero;
	};
	struct Unity_Mathematics_float4_Fields {
		float x;
		float y;
		float z;
		float w;
	};
	struct Unity_Mathematics_float4_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Equals;
		VirtualInvokeData _5_ToString;
	};
	struct Unity_Mathematics_float4_c {
		Il2CppClass_1 _1;
		struct Unity_Mathematics_float4_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		Unity_Mathematics_float4_VTable vtable;
	};
	struct Unity_Mathematics_float4_o {
		Unity_Mathematics_float4_Fields fields;
	};
	struct Unity_Mathematics_float4_StaticFields {
		struct Unity_Mathematics_float4_o zero;
	};
	struct IMDrawLine_________________________Fields {
		struct Unity_Mathematics_float3_o _______________________;
		struct Unity_Mathematics_float3_o _1________________________;
		float _2________________________;
		float _3________________________;
		struct Unity_Mathematics_float4_o _4________________________;
	};
	struct IMDrawLine_________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct IMDrawLine_________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		IMDrawLine_________________________VTable vtable;
	};
	struct IMDrawLine_________________________o {
		IMDrawLine_________________________Fields fields;
	};
	struct __declspec(align(8)) IMDrawBuffer_IMDrawLine__________________________Fields {
		struct UnityEngine_Mesh_o* mesh;
		struct UnityEngine_Material_o* material;
		int32_t layer;
		int32_t subMeshIndex;
		struct Unity_Collections_NativeArray_TYPE__o meshProps;
		struct UnityEngine_ComputeBuffer_o* meshPropsBuffer;
		struct UnityEngine_ComputeBuffer_o* argsBuffer;
		struct System_UInt32_array* args;
		int32_t instanceCount;
		int32_t maxCapacity;
		struct UnityEngine_Bounds_o bounds;
		struct UnityEngine_Material_o* materialInst;
	};
	struct IMDrawBuffer_IMDrawLine__________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Dispose;
		VirtualInvokeData _5_unknown;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
	};
	struct IMDrawBuffer_IMDrawLine__________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		IMDrawBuffer_IMDrawLine__________________________VTable vtable;
	};
	struct IMDrawBuffer_IMDrawLine__________________________o {
		IMDrawBuffer_IMDrawLine__________________________c* klass;
		void* monitor;
		IMDrawBuffer_IMDrawLine__________________________Fields fields;
	};
	struct IMDrawLine_Fields : IMDrawBuffer_IMDrawLine__________________________Fields {
	};
	struct IMDrawLine_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Dispose;
		VirtualInvokeData _5_get_TypeSize;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
	};
	struct IMDrawLine_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		IMDrawLine_VTable vtable;
	};
	struct IMDrawLine_o {
		IMDrawLine_c* klass;
		void* monitor;
		IMDrawLine_Fields fields;
	};
	struct UnityEngine_Matrix4x4_Fields {
		float m00;
		float m10;
		float m20;
		float m30;
		float m01;
		float m11;
		float m21;
		float m31;
		float m02;
		float m12;
		float m22;
		float m32;
		float m03;
		float m13;
		float m23;
		float m33;
	};
	struct UnityEngine_Matrix4x4_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Equals;
		VirtualInvokeData _5_ToString;
	};
	struct UnityEngine_Matrix4x4_c {
		Il2CppClass_1 _1;
		struct UnityEngine_Matrix4x4_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_Matrix4x4_VTable vtable;
	};
	struct UnityEngine_Matrix4x4_o {
		UnityEngine_Matrix4x4_Fields fields;
	};
	struct UnityEngine_Matrix4x4_StaticFields {
		struct UnityEngine_Matrix4x4_o zeroMatrix;
		struct UnityEngine_Matrix4x4_o identityMatrix;
	};
	struct IMDrawShape_________________________Fields {
		struct UnityEngine_Matrix4x4_o _______________________;
		struct Unity_Mathematics_float4_o _1________________________;
	};
	struct IMDrawShape_________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct IMDrawShape_________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		IMDrawShape_________________________VTable vtable;
	};
	struct IMDrawShape_________________________o {
		IMDrawShape_________________________Fields fields;
	};
	struct __declspec(align(8)) IMDrawBuffer_IMDrawShape__________________________Fields {
		struct UnityEngine_Mesh_o* mesh;
		struct UnityEngine_Material_o* material;
		int32_t layer;
		int32_t subMeshIndex;
		struct Unity_Collections_NativeArray_TYPE__o meshProps;
		struct UnityEngine_ComputeBuffer_o* meshPropsBuffer;
		struct UnityEngine_ComputeBuffer_o* argsBuffer;
		struct System_UInt32_array* args;
		int32_t instanceCount;
		int32_t maxCapacity;
		struct UnityEngine_Bounds_o bounds;
		struct UnityEngine_Material_o* materialInst;
	};
	struct IMDrawBuffer_IMDrawShape__________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Dispose;
		VirtualInvokeData _5_unknown;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
	};
	struct IMDrawBuffer_IMDrawShape__________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		IMDrawBuffer_IMDrawShape__________________________VTable vtable;
	};
	struct IMDrawBuffer_IMDrawShape__________________________o {
		IMDrawBuffer_IMDrawShape__________________________c* klass;
		void* monitor;
		IMDrawBuffer_IMDrawShape__________________________Fields fields;
	};
	struct IMDrawShape_Fields : IMDrawBuffer_IMDrawShape__________________________Fields {
	};
	struct IMDrawShape_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Dispose;
		VirtualInvokeData _5_get_TypeSize;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
	};
	struct IMDrawShape_c {
		Il2CppClass_1 _1;
		struct IMDrawShape_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		IMDrawShape_VTable vtable;
	};
	struct IMDrawShape_o {
		IMDrawShape_c* klass;
		void* monitor;
		IMDrawShape_Fields fields;
	};
	struct IMDrawShape_StaticFields {
		int32_t typeSize;
	};
	struct ________________________________________________68_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* _______________________;
	};
	struct ________________________________________________68_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________68_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________68_VTable vtable;
	};
	struct ________________________________________________68_o {
		________________________________________________68_c* klass;
		void* monitor;
		________________________________________________68_Fields fields;
	};
	struct __declspec(align(8)) ________________________174_Fields {
		struct System_Collections_Generic_Dictionary_GameObject__List_GameObject___o* _______________________;
	};
	struct ________________________174_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________174_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________174_VTable vtable;
	};
	struct ________________________174_o {
		________________________174_c* klass;
		void* monitor;
		________________________174_Fields fields;
	};
	struct UnityEngine_ScriptableObject_Fields : UnityEngine_Object_Fields {
	};
	struct UnityEngine_ScriptableObject_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct UnityEngine_ScriptableObject_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_ScriptableObject_VTable vtable;
	};
	struct UnityEngine_ScriptableObject_o {
		UnityEngine_ScriptableObject_c* klass;
		void* monitor;
		UnityEngine_ScriptableObject_Fields fields;
	};
	struct ImposterData_Fields : UnityEngine_ScriptableObject_Fields {
		int32_t CapturedAngleCount;
		int32_t DataChunkStart;
		struct UnityEngine_Texture2D_o* ColorAtlas;
		struct UnityEngine_Vector3_o PositionOffset;
		struct UnityEngine_Vector4_o BindPoseRotation;
		struct System_Collections_Generic_List_Vector4__o* CameraOffsets;
		struct System_Collections_Generic_List_Vector4__o* CameraRotations;
		struct System_Collections_Generic_List_Vector4__o* AtlasPosition;
		struct System_Collections_Generic_List_Vector4__o* DepthAtlasPositions;
		struct System_Collections_Generic_List_Vector4__o* BoundsCenter;
		struct System_Collections_Generic_List_Vector4__o* BoundsSize;
		struct System_Collections_Generic_List_Bounds__o* BoundingVolume;
	};
	struct ImposterData_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ImposterData_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		ImposterData_VTable vtable;
	};
	struct ImposterData_o {
		ImposterData_c* klass;
		void* monitor;
		ImposterData_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________69_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________175_o* _2________________________;
		float _3________________________;
	};
	struct ________________________________________________69_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________________________________69_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________69_VTable vtable;
	};
	struct ________________________________________________69_o {
		________________________________________________69_c* klass;
		void* monitor;
		________________________________________________69_Fields fields;
	};
	struct ________________________175_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_CanvasGroup_o* _canvasGroup;
		struct TMPro_TextMeshProUGUI_o* _chatText;
		float _fadeInOutSpeed;
		struct ________________________181_o* _heightFitter;
		struct ________________________182_o* _typingIndicator;
		struct ________________________179_o* _chatBubblePositioner;
		struct ________________________511_o* _______________________;
		float _8________________________;
		float _9________________________;
		bool _10________________________;
		struct System_String_o* _11________________________;
		struct UnityEngine_Coroutine_o* _12________________________;
		float _13________________________;
	};
	struct ________________________175_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Start;
		VirtualInvokeData _5_OnDestroy;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
	};
	struct ________________________175_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________175_VTable vtable;
	};
	struct ________________________175_o {
		________________________175_c* klass;
		void* monitor;
		________________________175_Fields fields;
	};
	struct __declspec(align(8)) ________________________176_Fields {
		struct System_Collections_Generic_List_int__o* _______________________;
	};
	struct ________________________176_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________176_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________176_VTable vtable;
	};
	struct ________________________176_o {
		________________________176_c* klass;
		void* monitor;
		________________________176_Fields fields;
	};
	struct ________________________177_Fields : UnityEngine_MonoBehaviour_Fields {
		struct System_String_o* _______________________;
		struct System_String_o* _1________________________;
		int32_t _characterLimit;
		struct ________________________180_o* _rateLimiter;
		struct ________________________179_o* _chatBubblePositioner;
		struct ________________________176_o* _6________________________;
		struct ________________________511_o* _7________________________;
		struct System_String_o* _8________________________;
		bool _9________________________;
		bool _10________________________;
		bool _11________________________;
		struct VRC_DataModel_KeyboardData_o* _12________________________;
		bool _13________________________;
		struct ________________________463_o* _14________________________;
		bool _15________________________;
	};
	struct ________________________177_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________177_c {
		Il2CppClass_1 _1;
		struct ________________________177_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________177_VTable vtable;
	};
	struct ________________________177_o {
		________________________177_c* klass;
		void* monitor;
		________________________177_Fields fields;
	};
	struct ________________________177_StaticFields {
		struct ________________________177_o* _________________________k__BackingField;
	};
	struct ________________________________________________70_Fields {
		int32_t _______________________;
		struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskVoidMethodBuilder_o _1________________________;
		struct ________________________178_o* _2________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter_o _3________________________;
	};
	struct ________________________________________________70_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________________________________70_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________70_VTable vtable;
	};
	struct ________________________________________________70_o {
		________________________________________________70_Fields fields;
	};
	struct ________________________178_Fields : ________________________175_Fields {
		struct UnityEngine_AudioSource_o* _speaker;
		struct UnityEngine_AudioClip_array* _notificationSFXs;
		struct ________________________183_o* _mirrorChatBubbleDisplay;
	};
	struct ________________________178_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Start;
		VirtualInvokeData _5_OnDestroy;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
	};
	struct ________________________178_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________178_VTable vtable;
	};
	struct ________________________178_o {
		________________________178_c* klass;
		void* monitor;
		________________________178_Fields fields;
	};
	struct ________________________212_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________511_o* _______________________;
		struct UnityEngine_Vector3_o _1________________________;
		struct ________________________211_o* matManager;
		struct ________________________203_o* cullDisableBox;
		struct UnityEngine_Canvas_o* rootCanvas;
		float _5________________________;
		bool _6________________________;
		int32_t _7________________________;
		bool _8________________________;
	};
	struct ________________________212_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnDestroy;
		VirtualInvokeData _6_OnEnable;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10_unknown;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________212_c {
		Il2CppClass_1 _1;
		struct ________________________212_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________212_VTable vtable;
	};
	struct ________________________212_o {
		________________________212_c* klass;
		void* monitor;
		________________________212_Fields fields;
	};
	struct ________________________212_StaticFields {
		int32_t _9________________________;
		int32_t _10________________________;
		int32_t _11________________________;
		struct Unity_Profiling_ProfilerMarker_o _12________________________;
		struct Unity_Profiling_ProfilerMarker_o _13________________________;
		struct Unity_Profiling_ProfilerMarker_o _14________________________;
	};
	struct ________________________216_Fields : ________________________212_Fields {
		float _14________________________;
		struct ________________________506_o* _15________________________;
		struct System_Action_float__o* _16________________________;
		struct UnityEngine_Vector3_o _17________________________;
		float _19________________________;
		float _20________________________;
	};
	struct ________________________216_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnDestroy;
		VirtualInvokeData _6_OnEnable;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________216_c {
		Il2CppClass_1 _1;
		struct ________________________216_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________216_VTable vtable;
	};
	struct ________________________216_o {
		________________________216_c* klass;
		void* monitor;
		________________________216_Fields fields;
	};
	struct ________________________216_StaticFields {
		struct ________________________________________________51_o* _______________________;
		struct ________________________________________________51_o* _11________________________;
		struct Unity_Profiling_ProfilerMarker_o _18________________________;
		struct UnityEngine_Mesh_o* _21________________________;
	};
	struct ________________________179_Fields : ________________________216_Fields {
		struct UnityEngine_AudioSource_o* _______________________;
		float _11________________________;
	};
	struct ________________________179_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnDestroy;
		VirtualInvokeData _6_OnEnable;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________179_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________179_VTable vtable;
	};
	struct ________________________179_o {
		________________________179_c* klass;
		void* monitor;
		________________________179_Fields fields;
	};
	struct ________________________180_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		int32_t _5________________________;
		float _6________________________;
		float _7________________________;
		bool _________________________k__BackingField;
		struct System_Action_o* _9________________________;
		bool _10__________________________k__BackingField;
	};
	struct ________________________180_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________180_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________180_VTable vtable;
	};
	struct ________________________180_o {
		________________________180_c* klass;
		void* monitor;
		________________________180_Fields fields;
	};
	struct ________________________181_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_RectTransform_o* _rectTransform;
		struct TMPro_TextMeshProUGUI_o* _text;
		struct UnityEngine_RectTransform_o* _textRectTransform;
		float _extraHeightPadding;
		bool _updateNameplate;
		struct UnityEngine_RectTransform_o* _______________________;
		struct UnityEngine_Vector3_o _7________________________;
		float _8________________________;
	};
	struct ________________________181_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________181_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________181_VTable vtable;
	};
	struct ________________________181_o {
		________________________181_c* klass;
		void* monitor;
		________________________181_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________71_Fields {
		struct ________________________182_o* _______________________;
		struct System_Action_o* _1________________________;
	};
	struct ________________________________________________71_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________71_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________71_VTable vtable;
	};
	struct ________________________________________________71_o {
		________________________________________________71_c* klass;
		void* monitor;
		________________________________________________71_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________72_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________182_o* _2________________________;
	};
	struct ________________________________________________72_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________________________________72_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________72_VTable vtable;
	};
	struct ________________________________________________72_o {
		________________________________________________72_c* klass;
		void* monitor;
		________________________________________________72_Fields fields;
	};
	struct ________________________182_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_CanvasGroup_o* _canvasGroup;
		struct UnityEngine_RectTransform_o* _rectTransform;
		struct ________________________181_o* _heightFitter;
		float _fadeInOutSpeed;
		float _typingIndicatorOffset;
		struct TMPro_TextMeshProUGUI_o* _indicatorText;
		float _indicatorTextSpeed;
		bool _________________________k__BackingField;
	};
	struct ________________________182_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________182_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________182_VTable vtable;
	};
	struct ________________________182_o {
		________________________182_c* klass;
		void* monitor;
		________________________182_Fields fields;
	};
	struct ________________________183_Fields : ________________________175_Fields {
	};
	struct ________________________183_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Start;
		VirtualInvokeData _5_OnDestroy;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
	};
	struct ________________________183_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________183_VTable vtable;
	};
	struct ________________________183_o {
		________________________183_c* klass;
		void* monitor;
		________________________183_Fields fields;
	};
	struct __declspec(align(8)) ________________________184_Fields {
	};
	struct ________________________184_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________184_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________184_VTable vtable;
	};
	struct ________________________184_o {
		________________________184_c* klass;
		void* monitor;
		________________________184_Fields fields;
	};
	struct ________________________185_Fields : UnityEngine_MonoBehaviour_Fields {
		bool _______________________;
		struct UnityEngine_AudioSource_o* _1________________________;
		float _2________________________;
		bool _3________________________;
		float _4________________________;
	};
	struct ________________________185_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________185_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________185_VTable vtable;
	};
	struct ________________________185_o {
		________________________185_c* klass;
		void* monitor;
		________________________185_Fields fields;
	};
	struct ________________________186_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* innerCone;
		struct UnityEngine_GameObject_o* outerCone;
		float _4________________________;
		float _5________________________;
		float _________________________k__BackingField;
		struct UnityEngine_GameObject_o* parent;
		struct UnityEngine_Material_o* _8________________________;
		struct UnityEngine_Material_o* _9________________________;
		float _10________________________;
		float _11________________________;
		bool _12________________________;
		float _13________________________;
		float _14________________________;
		float _15________________________;
		float _16________________________;
	};
	struct ________________________186_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________186_c {
		Il2CppClass_1 _1;
		struct ________________________186_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________186_VTable vtable;
	};
	struct ________________________186_o {
		________________________186_c* klass;
		void* monitor;
		________________________186_Fields fields;
	};
	struct ________________________186_StaticFields {
		struct ________________________186_o* _______________________;
		int32_t _3________________________;
	};
	struct ________________________187_Fields {
		uint8_t value__;
	};
	struct ________________________187_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________187_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________187_VTable vtable;
	};
	struct ________________________187_o {
		________________________187_Fields fields;
	};
	struct __declspec(align(8)) ________________________188_Fields {
	};
	struct ________________________188_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________188_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________188_VTable vtable;
	};
	struct ________________________188_o {
		________________________188_c* klass;
		void* monitor;
		________________________188_Fields fields;
	};
	struct ________________________189_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________190_o* _______________________;
		struct ________________________190_o* _1________________________;
		bool _3________________________;
		bool _4________________________;
		bool _5________________________;
		struct UnityEngine_Vector3_o _6________________________;
		struct UnityEngine_Vector3_o _7________________________;
	};
	struct ________________________189_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________189_c {
		Il2CppClass_1 _1;
		struct ________________________189_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________189_VTable vtable;
	};
	struct ________________________189_o {
		________________________189_c* klass;
		void* monitor;
		________________________189_Fields fields;
	};
	struct ________________________189_StaticFields {
		struct ________________________189_o* _2________________________;
	};
	struct ________________________________________________73_Fields {
		int32_t value__;
	};
	struct ________________________________________________73_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________73_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________73_VTable vtable;
	};
	struct ________________________________________________73_o {
		________________________________________________73_Fields fields;
	};
	struct ________________________190_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* _______________________;
		struct UnityEngine_GameObject_o* _1________________________;
		struct UnityEngine_GameObject_o* _2________________________;
		bool _3________________________;
		bool _4________________________;
		bool _5________________________;
		struct UnityEngine_Vector3_o _6________________________;
		struct UnityEngine_Vector3_o _7________________________;
		struct UnityEngine_Quaternion_o _8________________________;
		struct UnityEngine_Quaternion_o _9________________________;
		float _10________________________;
		struct UnityEngine_Vector2_o _11________________________;
		bool _12________________________;
		int32_t _16________________________;
	};
	struct ________________________190_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________190_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________190_VTable vtable;
	};
	struct ________________________190_o {
		________________________190_c* klass;
		void* monitor;
		________________________190_Fields fields;
	};
	struct ________________________191_Fields : UnityEngine_MonoBehaviour_Fields {
		struct System_Collections_Generic_Dictionary_int__VRCShader_ShaderVariableType__o* _______________________;
		struct System_Collections_Generic_List_RenderTexture__o* _1________________________;
		struct System_Collections_Generic_List_float__o* _2________________________;
		struct System_Collections_Generic_List_Vector4__o* _3________________________;
		struct System_Collections_Generic_List_Matrix4x4__o* _4________________________;
	};
	struct ________________________191_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________191_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________191_VTable vtable;
	};
	struct ________________________191_o {
		________________________191_c* klass;
		void* monitor;
		________________________191_Fields fields;
	};
	struct __declspec(align(8)) __________________________c_5_Fields {
	};
	struct __________________________c_5_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct __________________________c_5_c {
		Il2CppClass_1 _1;
		struct __________________________c_5_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		__________________________c_5_VTable vtable;
	};
	struct __________________________c_5_o {
		__________________________c_5_c* klass;
		void* monitor;
		__________________________c_5_Fields fields;
	};
	struct __________________________c_5_StaticFields {
		struct __________________________c_5_o* __9;
		struct System_Func_bool__o* __9__17_0;
	};
	struct ________________________________________________74_Fields {
		int32_t _______________________;
		struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskVoidMethodBuilder_o _1________________________;
		struct ________________________4371_o* _2________________________;
		struct ________________________192_o* _3________________________;
		struct System_String_o* _4________________________;
		struct UnityEngine_GameObject_o* _5________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter_o _6________________________;
	};
	struct ________________________________________________74_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
	};
	struct ________________________________________________74_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________74_VTable vtable;
	};
	struct ________________________________________________74_o {
		________________________________________________74_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________75_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________192_o* _2________________________;
	};
	struct ________________________________________________75_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________________________________75_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________75_VTable vtable;
	};
	struct ________________________________________________75_o {
		________________________________________________75_c* klass;
		void* monitor;
		________________________________________________75_Fields fields;
	};
	struct ________________________192_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_CanvasGroup_o* _canvasGroup;
		struct ________________________4371_o* _buttonText;
		struct UnityEngine_UI_Image_o* _buttonImage;
		bool _________________________k__BackingField;
		bool _4__________________________k__BackingField;
		struct UnityEngine_Material_o* _6________________________;
		struct System_String_o* _7________________________;
		struct System_String_o* _8________________________;
		struct ________________________4371_o* _9________________________;
	};
	struct ________________________192_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________192_c {
		Il2CppClass_1 _1;
		struct ________________________192_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________192_VTable vtable;
	};
	struct ________________________192_o {
		________________________192_c* klass;
		void* monitor;
		________________________192_Fields fields;
	};
	struct ________________________192_StaticFields {
		struct ________________________192_o* _______________________;
	};
	struct __declspec(align(8)) ________________________GestureIndicator_Fields {
		struct UnityEngine_Sprite_o* Right;
		struct UnityEngine_Sprite_o* Left;
	};
	struct ________________________GestureIndicator_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________GestureIndicator_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________GestureIndicator_VTable vtable;
	};
	struct ________________________GestureIndicator_o {
		________________________GestureIndicator_c* klass;
		void* monitor;
		________________________GestureIndicator_Fields fields;
	};
	struct ________________________193_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________GestureIndicator_array* gestureImages;
		struct UnityEngine_UI_Image_o* leftGestureDisplay;
		struct UnityEngine_UI_Image_o* rightGestureDisplay;
		struct UnityEngine_Vector2_o posLeftOnDesktopCameraOpen;
		struct UnityEngine_Vector2_o posRightOnDesktopCameraOpen;
		float indicatorPosOffsetForDesktop;
		struct UnityEngine_Vector2_o gestureBarPosDesktop;
		int32_t _______________________;
		int32_t _8________________________;
		float _9________________________;
		float _10________________________;
		float _11________________________;
		struct DG_Tweening_Sequence_o* _12________________________;
		struct DG_Tweening_Sequence_o* _13________________________;
		struct UnityEngine_Vector2_o _14________________________;
		struct UnityEngine_Vector2_o _15________________________;
		struct UnityEngine_Color_o _16________________________;
	};
	struct ________________________193_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________193_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________193_VTable vtable;
	};
	struct ________________________193_o {
		________________________193_c* klass;
		void* monitor;
		________________________193_Fields fields;
	};
	struct ________________________________________________76_Fields {
		int32_t value__;
	};
	struct ________________________________________________76_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________76_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________76_VTable vtable;
	};
	struct ________________________________________________76_o {
		________________________________________________76_Fields fields;
	};
	struct ________________________194_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _______________________;
		struct UnityEngine_UI_Image_o* _1________________________;
		struct TMPro_TextMeshProUGUI_o* _2________________________;
		struct UnityEngine_UI_LayoutElement_o* _3________________________;
		struct UnityEngine_Color_o _6________________________;
		struct DG_Tweening_Sequence_o* _7________________________;
		struct ________________________int__5_o* _8________________________;
		int32_t _9________________________;
	};
	struct ________________________194_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________194_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________194_VTable vtable;
	};
	struct ________________________194_o {
		________________________194_c* klass;
		void* monitor;
		________________________194_Fields fields;
	};
	struct ________________________195_Fields : UnityEngine_MonoBehaviour_Fields {
		int32_t _______________________;
		struct UnityEngine_Vector3_o _1________________________;
		struct UnityEngine_Vector3_o _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
		float _6________________________;
		float _7________________________;
		float _8________________________;
		float _9________________________;
		float _10________________________;
		float _11________________________;
		struct UnityEngine_CanvasGroup_o* _12________________________;
		bool _13________________________;
		float _14________________________;
		float _15________________________;
		bool _16________________________;
	};
	struct ________________________195_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________195_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________195_VTable vtable;
	};
	struct ________________________195_o {
		________________________195_c* klass;
		void* monitor;
		________________________195_Fields fields;
	};
	struct ________________________196_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Vector3_o _______________________;
		struct UnityEngine_Vector3_o _1________________________;
		float _2________________________;
		bool _4________________________;
		float _5________________________;
		float _6________________________;
		struct UnityEngine_Quaternion_o _7________________________;
		float _8________________________;
		float _9________________________;
	};
	struct ________________________196_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________196_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________196_VTable vtable;
	};
	struct ________________________196_o {
		________________________196_c* klass;
		void* monitor;
		________________________196_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________77_Fields {
		struct ________________________197_o* _______________________;
		float _1________________________;
	};
	struct ________________________________________________77_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________77_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________77_VTable vtable;
	};
	struct ________________________________________________77_o {
		________________________________________________77_c* klass;
		void* monitor;
		________________________________________________77_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________78_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		float _2________________________;
		struct System_Action_float__o* _3________________________;
		struct System_Action_o* _4________________________;
		float _5________________________;
		float _6________________________;
	};
	struct ________________________________________________78_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________________________________78_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________78_VTable vtable;
	};
	struct ________________________________________________78_o {
		________________________________________________78_c* klass;
		void* monitor;
		________________________________________________78_Fields fields;
	};
	struct ________________________197_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_UI_Image_o* _______________________;
		struct ________________________4371_o* _1________________________;
		struct ________________________4371_o* _2________________________;
		struct ________________________4371_o* _3________________________;
		struct ________________________157_o* _4________________________;
		struct UnityEngine_CanvasGroup_o* _5________________________;
		float _6________________________;
		float _7________________________;
		struct ________________________bool__5_o* _10________________________;
		struct UnityEngine_Transform_o* backgroundTransform;
		struct UnityEngine_GameObject_o* line;
		struct UnityEngine_UI_RectMask2D_o* mask;
		struct UnityEngine_Vector3_o _14________________________;
		bool _15________________________;
		bool _16________________________;
		struct UnityEngine_Coroutine_o* _17________________________;
	};
	struct ________________________197_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________197_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________197_VTable vtable;
	};
	struct ________________________197_o {
		________________________197_c* klass;
		void* monitor;
		________________________197_Fields fields;
	};
	struct __declspec(align(8)) __________________________c_6_Fields {
	};
	struct __________________________c_6_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct __________________________c_6_c {
		Il2CppClass_1 _1;
		struct __________________________c_6_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		__________________________c_6_VTable vtable;
	};
	struct __________________________c_6_o {
		__________________________c_6_c* klass;
		void* monitor;
		__________________________c_6_Fields fields;
	};
	struct __________________________c_6_StaticFields {
		struct __________________________c_6_o* __9;
		struct System_Func_bool__o* __9__17_0;
	};
	struct ________________________________________________79_Fields {
		int32_t _______________________;
		struct Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskVoidMethodBuilder_o _1________________________;
		struct ________________________4371_o* _2________________________;
		struct System_String_o* _3________________________;
		struct UnityEngine_GameObject_o* _4________________________;
		struct UnityEngine_GameObject_o* _5________________________;
		struct Cysharp_Threading_Tasks_UniTask_Awaiter_o _6________________________;
	};
	struct ________________________________________________79_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_MoveNext;
		VirtualInvokeData _5_SetStateMachine;
		VirtualInvokeData _6________________________;
		VirtualInvokeData _7________________________;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________________________________79_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________79_VTable vtable;
	};
	struct ________________________________________________79_o {
		________________________________________________79_Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________80_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________198_o* _2________________________;
	};
	struct ________________________________________________80_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
	};
	struct ________________________________________________80_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________80_VTable vtable;
	};
	struct ________________________________________________80_o {
		________________________________________________80_c* klass;
		void* monitor;
		________________________________________________80_Fields fields;
	};
	struct ________________________198_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_CanvasGroup_o* _canvasGroup;
		struct ________________________4371_o* _controlsText;
		struct ________________________4371_o* _portalFailureText;
		struct UnityEngine_UI_Image_o* _okButtonImage;
		struct UnityEngine_UI_Image_o* _cancelButtonImage;
		bool _________________________k__BackingField;
		struct UnityEngine_Material_o* _7________________________;
		struct UnityEngine_Material_o* _8________________________;
		struct ________________________4371_o* _9________________________;
		struct System_String_o* _10________________________;
		struct System_String_o* _11________________________;
		struct System_String_o* _12________________________;
	};
	struct ________________________198_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________198_c {
		Il2CppClass_1 _1;
		struct ________________________198_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________198_VTable vtable;
	};
	struct ________________________198_o {
		________________________198_c* klass;
		void* monitor;
		________________________198_Fields fields;
	};
	struct ________________________198_StaticFields {
		struct ________________________198_o* _______________________;
	};
	struct __declspec(align(8)) __________________________c_7_Fields {
	};
	struct __________________________c_7_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct __________________________c_7_c {
		Il2CppClass_1 _1;
		struct __________________________c_7_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		__________________________c_7_VTable vtable;
	};
	struct __________________________c_7_o {
		__________________________c_7_c* klass;
		void* monitor;
		__________________________c_7_Fields fields;
	};
	struct __________________________c_7_StaticFields {
		struct __________________________c_7_o* __9;
		struct System_Func_bool__o* __9__9_0;
	};
	struct __declspec(align(8)) ________________________________________________81_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________199_o* _2________________________;
	};
	struct ________________________________________________81_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________________________________81_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________81_VTable vtable;
	};
	struct ________________________________________________81_o {
		________________________________________________81_c* klass;
		void* monitor;
		________________________________________________81_Fields fields;
	};
	struct ________________________199_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_CanvasGroup_o* _canvasGroup;
		struct TMPro_TMP_Text_o* _promptText;
		bool _________________________k__BackingField;
	};
	struct ________________________199_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________199_c {
		Il2CppClass_1 _1;
		struct ________________________199_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________199_VTable vtable;
	};
	struct ________________________199_o {
		________________________199_c* klass;
		void* monitor;
		________________________199_Fields fields;
	};
	struct ________________________199_StaticFields {
		struct ________________________199_o* _______________________;
		struct System_String_o* _4________________________;
	};
	struct ________________________200_Fields : UnityEngine_MonoBehaviour_Fields {
		float _______________________;
		struct TMPro_TextMeshProUGUI_o* _1________________________;
		struct UnityEngine_RectTransform_o* _2________________________;
		struct UnityEngine_UI_Graphic_o* _3________________________;
		struct ________________________215_o* _4________________________;
		struct UnityEngine_Color_o _5________________________;
		struct UnityEngine_Color_o _6________________________;
	};
	struct ________________________200_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________200_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________200_VTable vtable;
	};
	struct ________________________200_o {
		________________________200_c* klass;
		void* monitor;
		________________________200_Fields fields;
	};
	struct ________________________201_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_GameObject_o* _______________________;
		struct TMPro_TextMeshProUGUI_o* _1________________________;
		struct UnityEngine_UI_Graphic_o* _2________________________;
		struct ________________________212_o* positioner;
		struct ________________________511_o* _4________________________;
		float _5________________________;
		bool _6________________________;
		struct _________________________________________________6_o* _7________________________;
		struct ________________________bool__6_o* _8________________________;
	};
	struct ________________________201_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4________________________;
		VirtualInvokeData _5________________________;
		VirtualInvokeData _6_Dispose;
	};
	struct ________________________201_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________201_VTable vtable;
	};
	struct ________________________201_o {
		________________________201_c* klass;
		void* monitor;
		________________________201_Fields fields;
	};
	struct ________________________202_Fields : ________________________212_Fields {
		struct UnityEngine_Transform_o* _______________________;
	};
	struct ________________________202_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnDestroy;
		VirtualInvokeData _6_OnEnable;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8________________________;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
	};
	struct ________________________202_c {
		Il2CppClass_1 _1;
		struct ________________________202_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________202_VTable vtable;
	};
	struct ________________________202_o {
		________________________202_c* klass;
		void* monitor;
		________________________202_Fields fields;
	};
	struct ________________________202_StaticFields {
		struct UnityEngine_Vector3_o _1________________________;
	};
	struct ________________________________________________82_Fields {
		struct UnityEngine_UI_VertexHelper_o* _______________________;
		struct ________________________203_o* _1________________________;
	};
	struct ________________________________________________82_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________82_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________82_VTable vtable;
	};
	struct ________________________________________________82_o {
		________________________________________________82_Fields fields;
	};
	struct ________________________203_Fields : UnityEngine_UI_MaskableGraphic_Fields {
		float _______________________;
	};
	struct ________________________203_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnEnable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8_OnDestroy;
		VirtualInvokeData _9_IsActive;
		VirtualInvokeData _10_OnRectTransformDimensionsChange;
		VirtualInvokeData _11_OnBeforeTransformParentChanged;
		VirtualInvokeData _12_OnTransformParentChanged;
		VirtualInvokeData _13_OnDidApplyAnimationProperties;
		VirtualInvokeData _14_OnCanvasGroupChanged;
		VirtualInvokeData _15_OnCanvasHierarchyChanged;
		VirtualInvokeData _16_IsDestroyed;
		VirtualInvokeData _17_unknown;
		VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
		VirtualInvokeData _19_unknown;
		VirtualInvokeData _20_unknown;
		VirtualInvokeData _21_unknown;
		VirtualInvokeData _22_get_color;
		VirtualInvokeData _23_set_color;
		VirtualInvokeData _24_get_raycastTarget;
		VirtualInvokeData _25_set_raycastTarget;
		VirtualInvokeData _26_SetAllDirty;
		VirtualInvokeData _27_SetLayoutDirty;
		VirtualInvokeData _28_SetVerticesDirty;
		VirtualInvokeData _29_SetMaterialDirty;
		VirtualInvokeData _30_get_rectTransform;
		VirtualInvokeData _31_get_defaultMaterial;
		VirtualInvokeData _32_get_material;
		VirtualInvokeData _33_set_material;
		VirtualInvokeData _34_get_materialForRendering;
		VirtualInvokeData _35_get_mainTexture;
		VirtualInvokeData _36_OnCullingChanged;
		VirtualInvokeData _37_Rebuild;
		VirtualInvokeData _38_LayoutComplete;
		VirtualInvokeData _39_GraphicUpdateComplete;
		VirtualInvokeData _40_UpdateMaterial;
		VirtualInvokeData _41_UpdateGeometry;
		VirtualInvokeData _42_OnFillVBO;
		VirtualInvokeData _43_OnPopulateMesh;
		VirtualInvokeData _44_OnPopulateMesh;
		VirtualInvokeData _45_SetNativeSize;
		VirtualInvokeData _46_Raycast;
		VirtualInvokeData _47_CrossFadeColor;
		VirtualInvokeData _48_CrossFadeColor;
		VirtualInvokeData _49_CrossFadeAlpha;
		VirtualInvokeData _50_UnityEngine_UI_IClippable_get_gameObject;
		VirtualInvokeData _51_unknown;
		VirtualInvokeData _52_unknown;
		VirtualInvokeData _53_unknown;
		VirtualInvokeData _54_unknown;
		VirtualInvokeData _55_unknown;
		VirtualInvokeData _56_unknown;
		VirtualInvokeData _57_unknown;
		VirtualInvokeData _58_GetModifiedMaterial;
		VirtualInvokeData _59_Cull;
		VirtualInvokeData _60_SetClipRect;
		VirtualInvokeData _61_SetClipSoftness;
		VirtualInvokeData _62_ParentMaskStateChanged;
		VirtualInvokeData _63_RecalculateClipping;
		VirtualInvokeData _64_RecalculateMasking;
	};
	struct ________________________203_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________203_VTable vtable;
	};
	struct ________________________203_o {
		________________________203_c* klass;
		void* monitor;
		________________________203_Fields fields;
	};
	struct __declspec(align(8)) ________________________204_Fields {
	};
	struct ________________________204_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VirtualInvokeData vtable[32];
	};
	struct ________________________204_o {
		________________________204_c* klass;
		void* monitor;
		________________________204_Fields fields;
	};
	struct ________________________________________________83_Fields {
		int32_t value__;
	};
	struct ________________________________________________83_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_ToString;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
	};
	struct ________________________________________________83_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________83_VTable vtable;
	};
	struct ________________________________________________83_o {
		________________________________________________83_Fields fields;
	};
	struct UnityEngine_Rect_Fields {
		float m_XMin;
		float m_YMin;
		float m_Width;
		float m_Height;
	};
	struct UnityEngine_Rect_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Equals;
		VirtualInvokeData _5_ToString;
	};
	struct UnityEngine_Rect_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_Rect_VTable vtable;
	};
	struct UnityEngine_Rect_o {
		UnityEngine_Rect_Fields fields;
	};
	struct ________________________________________________84_Fields {
		struct UnityEngine_UI_VertexHelper_o* _______________________;
		struct ________________________205_o* _1________________________;
		struct UnityEngine_Rect_o _2________________________;
		struct UnityEngine_Vector2_o _3________________________;
		struct UnityEngine_Rect_o _4________________________;
		float _5________________________;
	};
	struct ________________________________________________84_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________84_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________84_VTable vtable;
	};
	struct ________________________________________________84_o {
		________________________________________________84_Fields fields;
	};
	struct ________________________205_Fields : UnityEngine_UI_MaskableGraphic_Fields {
		struct UnityEngine_Sprite_o* _sprite;
		int32_t _______________________;
		bool ShaderFeatureStripes;
		uint32_t ShaderFeatureRectOffsetChannel;
		bool ShaderFeatureMasking;
		float yOffset;
		float _6________________________;
	};
	struct ________________________205_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnEnable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8_OnDestroy;
		VirtualInvokeData _9_IsActive;
		VirtualInvokeData _10_OnRectTransformDimensionsChange;
		VirtualInvokeData _11_OnBeforeTransformParentChanged;
		VirtualInvokeData _12_OnTransformParentChanged;
		VirtualInvokeData _13_OnDidApplyAnimationProperties;
		VirtualInvokeData _14_OnCanvasGroupChanged;
		VirtualInvokeData _15_OnCanvasHierarchyChanged;
		VirtualInvokeData _16_IsDestroyed;
		VirtualInvokeData _17_unknown;
		VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
		VirtualInvokeData _19_unknown;
		VirtualInvokeData _20_unknown;
		VirtualInvokeData _21_unknown;
		VirtualInvokeData _22_get_color;
		VirtualInvokeData _23_set_color;
		VirtualInvokeData _24_get_raycastTarget;
		VirtualInvokeData _25_set_raycastTarget;
		VirtualInvokeData _26_SetAllDirty;
		VirtualInvokeData _27_SetLayoutDirty;
		VirtualInvokeData _28_SetVerticesDirty;
		VirtualInvokeData _29_SetMaterialDirty;
		VirtualInvokeData _30_get_rectTransform;
		VirtualInvokeData _31_get_defaultMaterial;
		VirtualInvokeData _32_get_material;
		VirtualInvokeData _33_set_material;
		VirtualInvokeData _34_get_materialForRendering;
		VirtualInvokeData _35_get_mainTexture;
		VirtualInvokeData _36_OnCullingChanged;
		VirtualInvokeData _37_Rebuild;
		VirtualInvokeData _38_LayoutComplete;
		VirtualInvokeData _39_GraphicUpdateComplete;
		VirtualInvokeData _40_UpdateMaterial;
		VirtualInvokeData _41_UpdateGeometry;
		VirtualInvokeData _42_OnFillVBO;
		VirtualInvokeData _43_OnPopulateMesh;
		VirtualInvokeData _44_OnPopulateMesh;
		VirtualInvokeData _45_SetNativeSize;
		VirtualInvokeData _46_Raycast;
		VirtualInvokeData _47_CrossFadeColor;
		VirtualInvokeData _48_CrossFadeColor;
		VirtualInvokeData _49_CrossFadeAlpha;
		VirtualInvokeData _50_UnityEngine_UI_IClippable_get_gameObject;
		VirtualInvokeData _51_unknown;
		VirtualInvokeData _52_unknown;
		VirtualInvokeData _53_unknown;
		VirtualInvokeData _54_unknown;
		VirtualInvokeData _55_unknown;
		VirtualInvokeData _56_unknown;
		VirtualInvokeData _57_unknown;
		VirtualInvokeData _58_GetModifiedMaterial;
		VirtualInvokeData _59_Cull;
		VirtualInvokeData _60_SetClipRect;
		VirtualInvokeData _61_SetClipSoftness;
		VirtualInvokeData _62_ParentMaskStateChanged;
		VirtualInvokeData _63_RecalculateClipping;
		VirtualInvokeData _64_RecalculateMasking;
		VirtualInvokeData _65________________________;
		VirtualInvokeData _66________________________;
		VirtualInvokeData _67________________________;
	};
	struct ________________________205_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________205_VTable vtable;
	};
	struct ________________________205_o {
		________________________205_c* klass;
		void* monitor;
		________________________205_Fields fields;
	};
	struct ________________________________________________85_Fields {
		struct UnityEngine_Rect_o _______________________;
		float _1________________________;
		float _2________________________;
		struct UnityEngine_Vector2_o _3________________________;
		struct UnityEngine_Vector2_o _4________________________;
		struct ________________________206_o* _5________________________;
	};
	struct ________________________________________________85_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________85_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________85_VTable vtable;
	};
	struct ________________________________________________85_o {
		________________________________________________85_Fields fields;
	};
	struct ________________________206_Fields : UnityEngine_UI_MaskableGraphic_Fields {
		struct UnityEngine_Sprite_o* _______________________;
		float _1________________________;
		float _2________________________;
		float _3________________________;
		float _4________________________;
		float _5________________________;
	};
	struct ________________________206_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnEnable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8_OnDestroy;
		VirtualInvokeData _9_IsActive;
		VirtualInvokeData _10_OnRectTransformDimensionsChange;
		VirtualInvokeData _11_OnBeforeTransformParentChanged;
		VirtualInvokeData _12_OnTransformParentChanged;
		VirtualInvokeData _13_OnDidApplyAnimationProperties;
		VirtualInvokeData _14_OnCanvasGroupChanged;
		VirtualInvokeData _15_OnCanvasHierarchyChanged;
		VirtualInvokeData _16_IsDestroyed;
		VirtualInvokeData _17_unknown;
		VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
		VirtualInvokeData _19_unknown;
		VirtualInvokeData _20_unknown;
		VirtualInvokeData _21_unknown;
		VirtualInvokeData _22_get_color;
		VirtualInvokeData _23_set_color;
		VirtualInvokeData _24_get_raycastTarget;
		VirtualInvokeData _25_set_raycastTarget;
		VirtualInvokeData _26_SetAllDirty;
		VirtualInvokeData _27_SetLayoutDirty;
		VirtualInvokeData _28_SetVerticesDirty;
		VirtualInvokeData _29_SetMaterialDirty;
		VirtualInvokeData _30_get_rectTransform;
		VirtualInvokeData _31_get_defaultMaterial;
		VirtualInvokeData _32_get_material;
		VirtualInvokeData _33_set_material;
		VirtualInvokeData _34_get_materialForRendering;
		VirtualInvokeData _35_get_mainTexture;
		VirtualInvokeData _36_OnCullingChanged;
		VirtualInvokeData _37_Rebuild;
		VirtualInvokeData _38_LayoutComplete;
		VirtualInvokeData _39_GraphicUpdateComplete;
		VirtualInvokeData _40_UpdateMaterial;
		VirtualInvokeData _41_UpdateGeometry;
		VirtualInvokeData _42_OnFillVBO;
		VirtualInvokeData _43_OnPopulateMesh;
		VirtualInvokeData _44_OnPopulateMesh;
		VirtualInvokeData _45_SetNativeSize;
		VirtualInvokeData _46_Raycast;
		VirtualInvokeData _47_CrossFadeColor;
		VirtualInvokeData _48_CrossFadeColor;
		VirtualInvokeData _49_CrossFadeAlpha;
		VirtualInvokeData _50_UnityEngine_UI_IClippable_get_gameObject;
		VirtualInvokeData _51_unknown;
		VirtualInvokeData _52_unknown;
		VirtualInvokeData _53_unknown;
		VirtualInvokeData _54_unknown;
		VirtualInvokeData _55_unknown;
		VirtualInvokeData _56_unknown;
		VirtualInvokeData _57_unknown;
		VirtualInvokeData _58_GetModifiedMaterial;
		VirtualInvokeData _59_Cull;
		VirtualInvokeData _60_SetClipRect;
		VirtualInvokeData _61_SetClipSoftness;
		VirtualInvokeData _62_ParentMaskStateChanged;
		VirtualInvokeData _63_RecalculateClipping;
		VirtualInvokeData _64_RecalculateMasking;
	};
	struct ________________________206_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________206_VTable vtable;
	};
	struct ________________________206_o {
		________________________206_c* klass;
		void* monitor;
		________________________206_Fields fields;
	};
	struct ________________________207_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________206_o* _______________________;
		float _1________________________;
		float _2________________________;
	};
	struct ________________________207_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________207_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________207_VTable vtable;
	};
	struct ________________________207_o {
		________________________207_c* klass;
		void* monitor;
		________________________207_Fields fields;
	};
	struct ________________________208_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_UI_Image_o* _______________________;
		struct UnityEngine_UI_Image_o* _1________________________;
		struct TMPro_TextMeshProUGUI_o* _2________________________;
	};
	struct ________________________208_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________208_c {
		Il2CppClass_1 _1;
		struct ________________________208_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________208_VTable vtable;
	};
	struct ________________________208_o {
		________________________208_c* klass;
		void* monitor;
		________________________208_Fields fields;
	};
	struct ________________________208_StaticFields {
		struct UnityEngine_Color_o _3________________________;
		struct UnityEngine_Color_o _4________________________;
		struct UnityEngine_Color_o _5________________________;
	};
	struct __declspec(align(8)) ________________________________________________86_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________209_o* _2________________________;
	};
	struct ________________________________________________86_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
		VirtualInvokeData _12________________________;
		VirtualInvokeData _13________________________;
		VirtualInvokeData _14________________________;
		VirtualInvokeData _15________________________;
	};
	struct ________________________________________________86_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________86_VTable vtable;
	};
	struct ________________________________________________86_o {
		________________________________________________86_c* klass;
		void* monitor;
		________________________________________________86_Fields fields;
	};
	struct ________________________209_Fields : UnityEngine_MonoBehaviour_Fields {
	};
	struct ________________________209_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________209_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________209_VTable vtable;
	};
	struct ________________________209_o {
		________________________209_c* klass;
		void* monitor;
		________________________209_Fields fields;
	};
	struct __declspec(align(8)) __________________________c_8_Fields {
	};
	struct __________________________c_8_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct __________________________c_8_c {
		Il2CppClass_1 _1;
		struct __________________________c_8_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		__________________________c_8_VTable vtable;
	};
	struct __________________________c_8_o {
		__________________________c_8_c* klass;
		void* monitor;
		__________________________c_8_Fields fields;
	};
	struct __________________________c_8_StaticFields {
		struct __________________________c_8_o* __9;
		struct System_Func_RenderTexture__o* __9__28_0;
	};
	struct __declspec(align(8)) ________________________________________________87_Fields {
		struct UnityEngine_Vector3_o _______________________;
	};
	struct ________________________________________________87_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________________________________87_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________87_VTable vtable;
	};
	struct ________________________________________________87_o {
		________________________________________________87_c* klass;
		void* monitor;
		________________________________________________87_Fields fields;
	};
	struct System_Collections_Generic_List_Enumerator__________________________Fields {
		struct System_Collections_Generic_List_T__o* _list;
		int32_t _index;
		int32_t _version;
		struct ________________________215_o* _current;
	};
	struct System_Collections_Generic_List_Enumerator__________________________VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_get_Current;
		VirtualInvokeData _5_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
	};
	struct System_Collections_Generic_List_Enumerator__________________________c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_Collections_Generic_List_Enumerator__________________________VTable vtable;
	};
	struct System_Collections_Generic_List_Enumerator__________________________o {
		System_Collections_Generic_List_Enumerator__________________________Fields fields;
	};
	struct __declspec(align(8)) ________________________________________________88_Fields {
		int32_t _______________________;
		Il2CppObject* _1________________________;
		struct ________________________210_o* _2________________________;
		struct ________________________________________________87_o* _3________________________;
		struct ________________________511_o* _4________________________;
		bool _5________________________;
		struct System_Collections_Generic_List_Enumerator__________________________o _6________________________;
	};
	struct ________________________________________________88_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_System_Collections_Generic_IEnumerator_System_Object__get_Current;
		VirtualInvokeData _5_System_IDisposable_Dispose;
		VirtualInvokeData _6_MoveNext;
		VirtualInvokeData _7_System_Collections_IEnumerator_get_Current;
		VirtualInvokeData _8_System_Collections_IEnumerator_Reset;
		VirtualInvokeData _9________________________;
		VirtualInvokeData _10________________________;
		VirtualInvokeData _11________________________;
	};
	struct ________________________________________________88_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________________________________88_VTable vtable;
	};
	struct ________________________________________________88_o {
		________________________________________________88_c* klass;
		void* monitor;
		________________________________________________88_Fields fields;
	};
	struct ________________________210_Fields : UnityEngine_MonoBehaviour_Fields {
		struct ________________________bool__5_o* _1________________________;
		bool _2________________________;
		struct System_Collections_Generic_HashSet__________________________o* _3________________________;
		struct System_Collections_Generic_List__________________________o* _4________________________;
		struct UnityEngine_Coroutine_o* _5________________________;
		struct UnityEngine_Texture2D_o* _6________________________;
		struct UnityEngine_Material_o* _7________________________;
		struct UnityEngine_Material_o* _8________________________;
		struct System_Lazy_RenderTexture__o* _9________________________;
	};
	struct ________________________210_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________210_c {
		Il2CppClass_1 _1;
		struct ________________________210_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________210_VTable vtable;
	};
	struct ________________________210_o {
		________________________210_c* klass;
		void* monitor;
		________________________210_Fields fields;
	};
	struct ________________________210_StaticFields {
		struct ________________________210_o* _______________________;
		struct System_String_array* _10________________________;
	};
	struct ________________________211_Fields : UnityEngine_MonoBehaviour_Fields {
		struct UnityEngine_Material_o* _______________________;
		struct UnityEngine_Material_o* _1________________________;
		struct UnityEngine_UI_Graphic_array* CustomMaterialGraphics;
		struct UnityEngine_Material_o* _3________________________;
		struct UnityEngine_Material_o* _4________________________;
		struct System_Collections_Generic_List_Material__o* _5________________________;
		struct System_Collections_Generic_List__________________________o* _6________________________;
	};
	struct ________________________211_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct ________________________211_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		________________________211_VTable vtable;
	};
	struct ________________________211_o {
		________________________211_c* klass;
		void* monitor;
		________________________211_Fields fields;
	};
	struct UnityEngine_Color32_Fields {
		int32_t rgba;
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};
	struct UnityEngine_Color32_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_ToString;
	};
	struct UnityEngine_Color32_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_Color32_VTable vtable;
	};
	struct UnityEngine_Color32_o {
		UnityEngine_Color32_Fields fields;
	};
	struct TMPro_VertexGradient_Fields {
		struct UnityEngine_Color_o topLeft;
		struct UnityEngine_Color_o topRight;
		struct UnityEngine_Color_o bottomLeft;
		struct UnityEngine_Color_o bottomRight;
	};
	struct TMPro_VertexGradient_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_VertexGradient_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_VertexGradient_VTable vtable;
	};
	struct TMPro_VertexGradient_o {
		TMPro_VertexGradient_Fields fields;
	};
	struct TMPro_TMP_TextProcessingStack_float__Fields {
		struct System_Single_array* itemStack;
		int32_t index;
		float m_DefaultItem;
		int32_t m_Capacity;
		int32_t m_RolloverSize;
		int32_t m_Count;
	};
	struct TMPro_TMP_TextProcessingStack_float__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_TextProcessingStack_float__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_TextProcessingStack_float__VTable vtable;
	};
	struct TMPro_TMP_TextProcessingStack_float__o {
		TMPro_TMP_TextProcessingStack_float__Fields fields;
	};
	struct TMPro_TMP_TextProcessingStack_FontWeight__Fields {
		struct TMPro_FontWeight_array* itemStack;
		int32_t index;
		int32_t m_DefaultItem;
		int32_t m_Capacity;
		int32_t m_RolloverSize;
		int32_t m_Count;
	};
	struct TMPro_TMP_TextProcessingStack_FontWeight__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_TextProcessingStack_FontWeight__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_TextProcessingStack_FontWeight__VTable vtable;
	};
	struct TMPro_TMP_TextProcessingStack_FontWeight__o {
		TMPro_TMP_TextProcessingStack_FontWeight__Fields fields;
	};
	struct TMPro_TMP_FontStyleStack_Fields {
		uint8_t bold;
		uint8_t italic;
		uint8_t underline;
		uint8_t strikethrough;
		uint8_t highlight;
		uint8_t superscript;
		uint8_t subscript;
		uint8_t uppercase;
		uint8_t lowercase;
		uint8_t smallcaps;
	};
	struct TMPro_TMP_FontStyleStack_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_FontStyleStack_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_FontStyleStack_VTable vtable;
	};
	struct TMPro_TMP_FontStyleStack_o {
		TMPro_TMP_FontStyleStack_Fields fields;
	};
	struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__Fields {
		struct TMPro_HorizontalAlignmentOptions_array* itemStack;
		int32_t index;
		int32_t m_DefaultItem;
		int32_t m_Capacity;
		int32_t m_RolloverSize;
		int32_t m_Count;
	};
	struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__VTable vtable;
	};
	struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__o {
		TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__Fields fields;
	};
	struct TMPro_Extents_Fields {
		struct UnityEngine_Vector2_o min;
		struct UnityEngine_Vector2_o max;
	};
	struct TMPro_Extents_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_Extents_c {
		Il2CppClass_1 _1;
		struct TMPro_Extents_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_Extents_VTable vtable;
	};
	struct TMPro_Extents_o {
		TMPro_Extents_Fields fields;
	};
	struct TMPro_Extents_StaticFields {
		struct TMPro_Extents_o zero;
		struct TMPro_Extents_o uninitialized;
	};
	struct TMPro_TMP_TextProcessingStack_Color32__Fields {
		struct UnityEngine_Color32_array* itemStack;
		int32_t index;
		struct UnityEngine_Color32_o m_DefaultItem;
		int32_t m_Capacity;
		int32_t m_RolloverSize;
		int32_t m_Count;
	};
	struct TMPro_TMP_TextProcessingStack_Color32__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_TextProcessingStack_Color32__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_TextProcessingStack_Color32__VTable vtable;
	};
	struct TMPro_TMP_TextProcessingStack_Color32__o {
		TMPro_TMP_TextProcessingStack_Color32__Fields fields;
	};
	struct TMPro_TMP_Offset_Fields {
		float m_Left;
		float m_Right;
		float m_Top;
		float m_Bottom;
	};
	struct TMPro_TMP_Offset_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_Offset_c {
		Il2CppClass_1 _1;
		struct TMPro_TMP_Offset_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_Offset_VTable vtable;
	};
	struct TMPro_TMP_Offset_o {
		TMPro_TMP_Offset_Fields fields;
	};
	struct TMPro_TMP_Offset_StaticFields {
		struct TMPro_TMP_Offset_o k_ZeroOffset;
	};
	struct TMPro_HighlightState_Fields {
		struct UnityEngine_Color32_o color;
		struct TMPro_TMP_Offset_o padding;
	};
	struct TMPro_HighlightState_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_HighlightState_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_HighlightState_VTable vtable;
	};
	struct TMPro_HighlightState_o {
		TMPro_HighlightState_Fields fields;
	};
	struct TMPro_TMP_TextProcessingStack_HighlightState__Fields {
		struct TMPro_HighlightState_array* itemStack;
		int32_t index;
		struct TMPro_HighlightState_o m_DefaultItem;
		int32_t m_Capacity;
		int32_t m_RolloverSize;
		int32_t m_Count;
	};
	struct TMPro_TMP_TextProcessingStack_HighlightState__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_TextProcessingStack_HighlightState__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_TextProcessingStack_HighlightState__VTable vtable;
	};
	struct TMPro_TMP_TextProcessingStack_HighlightState__o {
		TMPro_TMP_TextProcessingStack_HighlightState__Fields fields;
	};
	struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__Fields {
		struct TMPro_TMP_ColorGradient_array* itemStack;
		int32_t index;
		struct TMPro_TMP_ColorGradient_o* m_DefaultItem;
		int32_t m_Capacity;
		int32_t m_RolloverSize;
		int32_t m_Count;
	};
	struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_TextProcessingStack_TMP_ColorGradient__VTable vtable;
	};
	struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__o {
		TMPro_TMP_TextProcessingStack_TMP_ColorGradient__Fields fields;
	};
	struct TMPro_TMP_TextProcessingStack_int__Fields {
		struct System_Int32_array* itemStack;
		int32_t index;
		int32_t m_DefaultItem;
		int32_t m_Capacity;
		int32_t m_RolloverSize;
		int32_t m_Count;
	};
	struct TMPro_TMP_TextProcessingStack_int__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_TextProcessingStack_int__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_TextProcessingStack_int__VTable vtable;
	};
	struct TMPro_TMP_TextProcessingStack_int__o {
		TMPro_TMP_TextProcessingStack_int__Fields fields;
	};
	struct TMPro_TMP_Text_SpecialCharacter_Fields {
		struct TMPro_TMP_Character_o* character;
		struct TMPro_TMP_FontAsset_o* fontAsset;
		struct UnityEngine_Material_o* material;
		int32_t materialIndex;
	};
	struct TMPro_TMP_Text_SpecialCharacter_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_Text_SpecialCharacter_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_Text_SpecialCharacter_VTable vtable;
	};
	struct TMPro_TMP_Text_SpecialCharacter_o {
		TMPro_TMP_Text_SpecialCharacter_Fields fields;
	};
	struct TMPro_TMP_Text_TextBackingContainer_Fields {
		struct System_UInt32_array* m_Array;
		int32_t m_Count;
	};
	struct TMPro_TMP_Text_TextBackingContainer_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_Text_TextBackingContainer_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_Text_TextBackingContainer_VTable vtable;
	};
	struct TMPro_TMP_Text_TextBackingContainer_o {
		TMPro_TMP_Text_TextBackingContainer_Fields fields;
	};
	struct TMPro_MaterialReference_Fields {
		int32_t index;
		struct TMPro_TMP_FontAsset_o* fontAsset;
		struct TMPro_TMP_SpriteAsset_o* spriteAsset;
		struct UnityEngine_Material_o* material;
		bool isDefaultMaterial;
		bool isFallbackMaterial;
		struct UnityEngine_Material_o* fallbackMaterial;
		float padding;
		int32_t referenceCount;
	};
	struct TMPro_MaterialReference_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_MaterialReference_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_MaterialReference_VTable vtable;
	};
	struct TMPro_MaterialReference_o {
		TMPro_MaterialReference_Fields fields;
	};
	struct TMPro_TMP_TextProcessingStack_MaterialReference__Fields {
		struct TMPro_MaterialReference_array* itemStack;
		int32_t index;
		struct TMPro_MaterialReference_o m_DefaultItem;
		int32_t m_Capacity;
		int32_t m_RolloverSize;
		int32_t m_Count;
	};
	struct TMPro_TMP_TextProcessingStack_MaterialReference__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_TextProcessingStack_MaterialReference__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_TextProcessingStack_MaterialReference__VTable vtable;
	};
	struct TMPro_TMP_TextProcessingStack_MaterialReference__o {
		TMPro_TMP_TextProcessingStack_MaterialReference__Fields fields;
	};
	struct TMPro_TMP_LineInfo_Fields {
		int32_t controlCharacterCount;
		int32_t characterCount;
		int32_t visibleCharacterCount;
		int32_t spaceCount;
		int32_t wordCount;
		int32_t firstCharacterIndex;
		int32_t firstVisibleCharacterIndex;
		int32_t lastCharacterIndex;
		int32_t lastVisibleCharacterIndex;
		float length;
		float lineHeight;
		float ascender;
		float baseline;
		float descender;
		float maxAdvance;
		float width;
		float marginLeft;
		float marginRight;
		int32_t alignment;
		struct TMPro_Extents_o lineExtents;
	};
	struct TMPro_TMP_LineInfo_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_LineInfo_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_LineInfo_VTable vtable;
	};
	struct TMPro_TMP_LineInfo_o {
		TMPro_TMP_LineInfo_Fields fields;
	};
	struct TMPro_WordWrapState_Fields {
		int32_t previous_WordBreak;
		int32_t total_CharacterCount;
		int32_t visible_CharacterCount;
		int32_t visible_SpriteCount;
		int32_t visible_LinkCount;
		int32_t firstCharacterIndex;
		int32_t firstVisibleCharacterIndex;
		int32_t lastCharacterIndex;
		int32_t lastVisibleCharIndex;
		int32_t lineNumber;
		float maxCapHeight;
		float maxAscender;
		float maxDescender;
		float startOfLineAscender;
		float maxLineAscender;
		float maxLineDescender;
		float pageAscender;
		int32_t horizontalAlignment;
		float marginLeft;
		float marginRight;
		float xAdvance;
		float preferredWidth;
		float preferredHeight;
		float previousLineScale;
		int32_t wordCount;
		int32_t fontStyle;
		int32_t italicAngle;
		float fontScaleMultiplier;
		float currentFontSize;
		float baselineOffset;
		float lineOffset;
		bool isDrivenLineSpacing;
		float glyphHorizontalAdvanceAdjustment;
		float cSpace;
		float mSpace;
		struct TMPro_TMP_TextInfo_o* textInfo;
		struct TMPro_TMP_LineInfo_o lineInfo;
		struct UnityEngine_Color32_o vertexColor;
		struct UnityEngine_Color32_o underlineColor;
		struct UnityEngine_Color32_o strikethroughColor;
		struct UnityEngine_Color32_o highlightColor;
		struct TMPro_TMP_FontStyleStack_o basicStyleStack;
		struct TMPro_TMP_TextProcessingStack_int__o italicAngleStack;
		struct TMPro_TMP_TextProcessingStack_Color32__o colorStack;
		struct TMPro_TMP_TextProcessingStack_Color32__o underlineColorStack;
		struct TMPro_TMP_TextProcessingStack_Color32__o strikethroughColorStack;
		struct TMPro_TMP_TextProcessingStack_Color32__o highlightColorStack;
		struct TMPro_TMP_TextProcessingStack_HighlightState__o highlightStateStack;
		struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__o colorGradientStack;
		struct TMPro_TMP_TextProcessingStack_float__o sizeStack;
		struct TMPro_TMP_TextProcessingStack_float__o indentStack;
		struct TMPro_TMP_TextProcessingStack_FontWeight__o fontWeightStack;
		struct TMPro_TMP_TextProcessingStack_int__o styleStack;
		struct TMPro_TMP_TextProcessingStack_float__o baselineStack;
		struct TMPro_TMP_TextProcessingStack_int__o actionStack;
		struct TMPro_TMP_TextProcessingStack_MaterialReference__o materialReferenceStack;
		struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__o lineJustificationStack;
		int32_t spriteAnimationID;
		struct TMPro_TMP_FontAsset_o* currentFontAsset;
		struct TMPro_TMP_SpriteAsset_o* currentSpriteAsset;
		struct UnityEngine_Material_o* currentMaterial;
		int32_t currentMaterialIndex;
		struct TMPro_Extents_o meshExtents;
		bool tagNoParsing;
		bool isNonBreakingSpace;
	};
	struct TMPro_WordWrapState_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_WordWrapState_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_WordWrapState_VTable vtable;
	};
	struct TMPro_WordWrapState_o {
		TMPro_WordWrapState_Fields fields;
	};
	struct TMPro_TMP_TextProcessingStack_WordWrapState__Fields {
		struct TMPro_WordWrapState_array* itemStack;
		int32_t index;
		struct TMPro_WordWrapState_o m_DefaultItem;
		int32_t m_Capacity;
		int32_t m_RolloverSize;
		int32_t m_Count;
	};
	struct TMPro_TMP_TextProcessingStack_WordWrapState__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TMPro_TMP_TextProcessingStack_WordWrapState__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_TextProcessingStack_WordWrapState__VTable vtable;
	};
	struct TMPro_TMP_TextProcessingStack_WordWrapState__o {
		TMPro_TMP_TextProcessingStack_WordWrapState__Fields fields;
	};
	struct TMPro_TMP_Text_Fields : UnityEngine_UI_MaskableGraphic_Fields {
		struct System_String_o* m_text;
		bool m_IsTextBackingStringDirty;
		struct TMPro_ITextPreprocessor_o* m_TextPreprocessor;
		bool m_isRightToLeft;
		struct TMPro_TMP_FontAsset_o* m_fontAsset;
		struct TMPro_TMP_FontAsset_o* m_currentFontAsset;
		bool m_isSDFShader;
		struct UnityEngine_Material_o* m_sharedMaterial;
		struct UnityEngine_Material_o* m_currentMaterial;
		int32_t m_currentMaterialIndex;
		struct UnityEngine_Material_array* m_fontSharedMaterials;
		struct UnityEngine_Material_o* m_fontMaterial;
		struct UnityEngine_Material_array* m_fontMaterials;
		bool m_isMaterialDirty;
		struct UnityEngine_Color32_o m_fontColor32;
		struct UnityEngine_Color_o m_fontColor;
		struct UnityEngine_Color32_o m_underlineColor;
		struct UnityEngine_Color32_o m_strikethroughColor;
		bool m_enableVertexGradient;
		int32_t m_colorMode;
		struct TMPro_VertexGradient_o m_fontColorGradient;
		struct TMPro_TMP_ColorGradient_o* m_fontColorGradientPreset;
		struct TMPro_TMP_SpriteAsset_o* m_spriteAsset;
		bool m_tintAllSprites;
		bool m_tintSprite;
		struct UnityEngine_Color32_o m_spriteColor;
		struct TMPro_TMP_StyleSheet_o* m_StyleSheet;
		struct TMPro_TMP_Style_o* m_TextStyle;
		int32_t m_TextStyleHashCode;
		bool m_overrideHtmlColors;
		struct UnityEngine_Color32_o m_faceColor;
		struct UnityEngine_Color32_o m_outlineColor;
		float m_outlineWidth;
		float m_fontSize;
		float m_currentFontSize;
		float m_fontSizeBase;
		struct TMPro_TMP_TextProcessingStack_float__o m_sizeStack;
		int32_t m_fontWeight;
		int32_t m_FontWeightInternal;
		struct TMPro_TMP_TextProcessingStack_FontWeight__o m_FontWeightStack;
		bool m_enableAutoSizing;
		float m_maxFontSize;
		float m_minFontSize;
		int32_t m_AutoSizeIterationCount;
		int32_t m_AutoSizeMaxIterationCount;
		bool m_IsAutoSizePointSizeSet;
		float m_fontSizeMin;
		float m_fontSizeMax;
		int32_t m_fontStyle;
		int32_t m_FontStyleInternal;
		struct TMPro_TMP_FontStyleStack_o m_fontStyleStack;
		bool m_isUsingBold;
		int32_t m_HorizontalAlignment;
		int32_t m_VerticalAlignment;
		int32_t m_textAlignment;
		int32_t m_lineJustification;
		struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__o m_lineJustificationStack;
		struct UnityEngine_Vector3_array* m_textContainerLocalCorners;
		float m_characterSpacing;
		float m_cSpacing;
		float m_monoSpacing;
		float m_wordSpacing;
		float m_lineSpacing;
		float m_lineSpacingDelta;
		float m_lineHeight;
		bool m_IsDrivenLineSpacing;
		float m_lineSpacingMax;
		float m_paragraphSpacing;
		float m_charWidthMaxAdj;
		float m_charWidthAdjDelta;
		bool m_enableWordWrapping;
		bool m_isCharacterWrappingEnabled;
		bool m_isNonBreakingSpace;
		bool m_isIgnoringAlignment;
		float m_wordWrappingRatios;
		int32_t m_overflowMode;
		int32_t m_firstOverflowCharacterIndex;
		struct TMPro_TMP_Text_o* m_linkedTextComponent;
		struct TMPro_TMP_Text_o* parentLinkedComponent;
		bool m_isTextTruncated;
		bool m_enableKerning;
		float m_GlyphHorizontalAdvanceAdjustment;
		bool m_enableExtraPadding;
		bool checkPaddingRequired;
		bool m_isRichText;
		bool m_parseCtrlCharacters;
		bool m_isOverlay;
		bool m_isOrthographic;
		bool m_isCullingEnabled;
		bool m_isMaskingEnabled;
		bool isMaskUpdateRequired;
		bool m_ignoreCulling;
		int32_t m_horizontalMapping;
		int32_t m_verticalMapping;
		float m_uvLineOffset;
		int32_t m_renderMode;
		int32_t m_geometrySortingOrder;
		bool m_IsTextObjectScaleStatic;
		bool m_VertexBufferAutoSizeReduction;
		int32_t m_firstVisibleCharacter;
		int32_t m_maxVisibleCharacters;
		int32_t m_maxVisibleWords;
		int32_t m_maxVisibleLines;
		bool m_useMaxVisibleDescender;
		int32_t m_pageToDisplay;
		bool m_isNewPage;
		struct UnityEngine_Vector4_o m_margin;
		float m_marginLeft;
		float m_marginRight;
		float m_marginWidth;
		float m_marginHeight;
		float m_width;
		struct TMPro_TMP_TextInfo_o* m_textInfo;
		bool m_havePropertiesChanged;
		bool m_isUsingLegacyAnimationComponent;
		struct UnityEngine_Transform_o* m_transform;
		struct UnityEngine_RectTransform_o* m_rectTransform;
		struct UnityEngine_Vector2_o m_PreviousRectTransformSize;
		struct UnityEngine_Vector2_o m_PreviousPivotPosition;
		bool _autoSizeTextContainer_k__BackingField;
		bool m_autoSizeTextContainer;
		struct UnityEngine_Mesh_o* m_mesh;
		bool m_isVolumetricText;
		struct System_Action_TMP_TextInfo__o* OnPreRenderText;
		struct TMPro_TMP_SpriteAnimator_o* m_spriteAnimator;
		float m_flexibleHeight;
		float m_flexibleWidth;
		float m_minWidth;
		float m_minHeight;
		float m_maxWidth;
		float m_maxHeight;
		struct UnityEngine_UI_LayoutElement_o* m_LayoutElement;
		float m_preferredWidth;
		float m_renderedWidth;
		bool m_isPreferredWidthDirty;
		float m_preferredHeight;
		float m_renderedHeight;
		bool m_isPreferredHeightDirty;
		bool m_isCalculatingPreferredValues;
		int32_t m_layoutPriority;
		bool m_isLayoutDirty;
		bool m_isAwake;
		bool m_isWaitingOnResourceLoad;
		int32_t m_inputSource;
		float m_fontScaleMultiplier;
		float tag_LineIndent;
		float tag_Indent;
		struct TMPro_TMP_TextProcessingStack_float__o m_indentStack;
		bool tag_NoParsing;
		bool m_isParsingText;
		struct UnityEngine_Matrix4x4_o m_FXMatrix;
		bool m_isFXMatrixSet;
		struct TMPro_TMP_Text_UnicodeChar_array* m_TextProcessingArray;
		int32_t m_InternalTextProcessingArraySize;
		struct TMPro_TMP_CharacterInfo_array* m_internalCharacterInfo;
		int32_t m_totalCharacterCount;
		int32_t m_characterCount;
		int32_t m_firstCharacterOfLine;
		int32_t m_firstVisibleCharacterOfLine;
		int32_t m_lastCharacterOfLine;
		int32_t m_lastVisibleCharacterOfLine;
		int32_t m_lineNumber;
		int32_t m_lineVisibleCharacterCount;
		int32_t m_pageNumber;
		float m_PageAscender;
		float m_maxTextAscender;
		float m_maxCapHeight;
		float m_ElementAscender;
		float m_ElementDescender;
		float m_maxLineAscender;
		float m_maxLineDescender;
		float m_startOfLineAscender;
		float m_startOfLineDescender;
		float m_lineOffset;
		struct TMPro_Extents_o m_meshExtents;
		struct UnityEngine_Color32_o m_htmlColor;
		struct TMPro_TMP_TextProcessingStack_Color32__o m_colorStack;
		struct TMPro_TMP_TextProcessingStack_Color32__o m_underlineColorStack;
		struct TMPro_TMP_TextProcessingStack_Color32__o m_strikethroughColorStack;
		struct TMPro_TMP_TextProcessingStack_HighlightState__o m_HighlightStateStack;
		struct TMPro_TMP_ColorGradient_o* m_colorGradientPreset;
		struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__o m_colorGradientStack;
		bool m_colorGradientPresetIsTinted;
		float m_tabSpacing;
		float m_spacing;
		struct TMPro_TMP_TextProcessingStack_int__array* m_TextStyleStacks;
		int32_t m_TextStyleStackDepth;
		struct TMPro_TMP_TextProcessingStack_int__o m_ItalicAngleStack;
		int32_t m_ItalicAngle;
		struct TMPro_TMP_TextProcessingStack_int__o m_actionStack;
		float m_padding;
		float m_baselineOffset;
		struct TMPro_TMP_TextProcessingStack_float__o m_baselineOffsetStack;
		float m_xAdvance;
		int32_t m_textElementType;
		struct TMPro_TMP_TextElement_o* m_cached_TextElement;
		struct TMPro_TMP_Text_SpecialCharacter_o m_Ellipsis;
		struct TMPro_TMP_Text_SpecialCharacter_o m_Underline;
		struct TMPro_TMP_SpriteAsset_o* m_defaultSpriteAsset;
		struct TMPro_TMP_SpriteAsset_o* m_currentSpriteAsset;
		int32_t m_spriteCount;
		int32_t m_spriteIndex;
		int32_t m_spriteAnimationID;
		bool m_ignoreActiveState;
		struct TMPro_TMP_Text_TextBackingContainer_o m_TextBackingArray;
		struct System_Decimal_array* k_Power;
	};
	struct TMPro_TMP_Text_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnEnable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8_OnDestroy;
		VirtualInvokeData _9_IsActive;
		VirtualInvokeData _10_OnRectTransformDimensionsChange;
		VirtualInvokeData _11_OnBeforeTransformParentChanged;
		VirtualInvokeData _12_OnTransformParentChanged;
		VirtualInvokeData _13_OnDidApplyAnimationProperties;
		VirtualInvokeData _14_OnCanvasGroupChanged;
		VirtualInvokeData _15_OnCanvasHierarchyChanged;
		VirtualInvokeData _16_IsDestroyed;
		VirtualInvokeData _17_unknown;
		VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
		VirtualInvokeData _19_unknown;
		VirtualInvokeData _20_unknown;
		VirtualInvokeData _21_unknown;
		VirtualInvokeData _22_get_color;
		VirtualInvokeData _23_set_color;
		VirtualInvokeData _24_get_raycastTarget;
		VirtualInvokeData _25_set_raycastTarget;
		VirtualInvokeData _26_SetAllDirty;
		VirtualInvokeData _27_SetLayoutDirty;
		VirtualInvokeData _28_SetVerticesDirty;
		VirtualInvokeData _29_SetMaterialDirty;
		VirtualInvokeData _30_get_rectTransform;
		VirtualInvokeData _31_get_defaultMaterial;
		VirtualInvokeData _32_get_material;
		VirtualInvokeData _33_set_material;
		VirtualInvokeData _34_get_materialForRendering;
		VirtualInvokeData _35_get_mainTexture;
		VirtualInvokeData _36_OnCullingChanged;
		VirtualInvokeData _37_Rebuild;
		VirtualInvokeData _38_LayoutComplete;
		VirtualInvokeData _39_GraphicUpdateComplete;
		VirtualInvokeData _40_UpdateMaterial;
		VirtualInvokeData _41_UpdateGeometry;
		VirtualInvokeData _42_OnFillVBO;
		VirtualInvokeData _43_OnPopulateMesh;
		VirtualInvokeData _44_OnPopulateMesh;
		VirtualInvokeData _45_SetNativeSize;
		VirtualInvokeData _46_Raycast;
		VirtualInvokeData _47_CrossFadeColor;
		VirtualInvokeData _48_CrossFadeColor;
		VirtualInvokeData _49_CrossFadeAlpha;
		VirtualInvokeData _50_UnityEngine_UI_IClippable_get_gameObject;
		VirtualInvokeData _51_unknown;
		VirtualInvokeData _52_unknown;
		VirtualInvokeData _53_unknown;
		VirtualInvokeData _54_unknown;
		VirtualInvokeData _55_unknown;
		VirtualInvokeData _56_unknown;
		VirtualInvokeData _57_unknown;
		VirtualInvokeData _58_GetModifiedMaterial;
		VirtualInvokeData _59_Cull;
		VirtualInvokeData _60_SetClipRect;
		VirtualInvokeData _61_SetClipSoftness;
		VirtualInvokeData _62_ParentMaskStateChanged;
		VirtualInvokeData _63_RecalculateClipping;
		VirtualInvokeData _64_RecalculateMasking;
		VirtualInvokeData _65_get_text;
		VirtualInvokeData _66_set_text;
		VirtualInvokeData _67_get_fontSharedMaterial;
		VirtualInvokeData _68_set_fontSharedMaterial;
		VirtualInvokeData _69_get_fontSharedMaterials;
		VirtualInvokeData _70_set_fontSharedMaterials;
		VirtualInvokeData _71_get_fontMaterials;
		VirtualInvokeData _72_set_fontMaterials;
		VirtualInvokeData _73_get_margin;
		VirtualInvokeData _74_set_margin;
		VirtualInvokeData _75_get_autoSizeTextContainer;
		VirtualInvokeData _76_set_autoSizeTextContainer;
		VirtualInvokeData _77_get_mesh;
		VirtualInvokeData _78_add_OnPreRenderText;
		VirtualInvokeData _79_remove_OnPreRenderText;
		VirtualInvokeData _80_get_flexibleHeight;
		VirtualInvokeData _81_get_flexibleWidth;
		VirtualInvokeData _82_get_minWidth;
		VirtualInvokeData _83_get_minHeight;
		VirtualInvokeData _84_get_preferredWidth;
		VirtualInvokeData _85_get_preferredHeight;
		VirtualInvokeData _86_get_renderedWidth;
		VirtualInvokeData _87_get_renderedHeight;
		VirtualInvokeData _88_get_layoutPriority;
		VirtualInvokeData _89_LoadFontAsset;
		VirtualInvokeData _90_SetSharedMaterial;
		VirtualInvokeData _91_GetMaterial;
		VirtualInvokeData _92_SetFontBaseMaterial;
		VirtualInvokeData _93_GetSharedMaterials;
		VirtualInvokeData _94_SetSharedMaterials;
		VirtualInvokeData _95_GetMaterials;
		VirtualInvokeData _96_CreateMaterialInstance;
		VirtualInvokeData _97_SetFaceColor;
		VirtualInvokeData _98_SetOutlineColor;
		VirtualInvokeData _99_SetOutlineThickness;
		VirtualInvokeData _100_SetShaderDepth;
		VirtualInvokeData _101_SetCulling;
		VirtualInvokeData _102_UpdateCulling;
		VirtualInvokeData _103_GetPaddingForMaterial;
		VirtualInvokeData _104_GetPaddingForMaterial;
		VirtualInvokeData _105_GetTextContainerLocalCorners;
		VirtualInvokeData _106_ForceMeshUpdate;
		VirtualInvokeData _107_UpdateGeometry;
		VirtualInvokeData _108_UpdateVertexData;
		VirtualInvokeData _109_UpdateVertexData;
		VirtualInvokeData _110_SetVertices;
		VirtualInvokeData _111_UpdateMeshPadding;
		VirtualInvokeData _112_InternalCrossFadeColor;
		VirtualInvokeData _113_InternalCrossFadeAlpha;
		VirtualInvokeData _114_SetArraySizes;
		VirtualInvokeData _115_CalculatePreferredValues;
		VirtualInvokeData _116_GetCompoundBounds;
		VirtualInvokeData _117_GetCanvasSpaceClippingRect;
		VirtualInvokeData _118_GetTextInfo;
		VirtualInvokeData _119_ComputeMarginSize;
		VirtualInvokeData _120_SaveGlyphVertexInfo;
		VirtualInvokeData _121_SaveSpriteVertexInfo;
		VirtualInvokeData _122_FillCharacterVertexBuffers;
		VirtualInvokeData _123_FillCharacterVertexBuffers;
		VirtualInvokeData _124_FillSpriteVertexBuffers;
		VirtualInvokeData _125_DrawUnderlineMesh;
		VirtualInvokeData _126_DrawTextHighlight;
		VirtualInvokeData _127_SetActiveSubMeshes;
		VirtualInvokeData _128_DestroySubMeshObjects;
		VirtualInvokeData _129_ClearMesh;
		VirtualInvokeData _130_ClearMesh;
		VirtualInvokeData _131_GetParsedText;
		VirtualInvokeData _132_InternalUpdate;
	};
	struct TMPro_TMP_Text_c {
		Il2CppClass_1 _1;
		struct TMPro_TMP_Text_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TMP_Text_VTable vtable;
	};
	struct TMPro_TMP_Text_o {
		TMPro_TMP_Text_c* klass;
		void* monitor;
		TMPro_TMP_Text_Fields fields;
	};
	struct TMPro_TMP_Text_StaticFields {
		struct TMPro_MaterialReference_array* m_materialReferences;
		struct System_Collections_Generic_Dictionary_int__int__o* m_materialReferenceIndexLookup;
		struct TMPro_TMP_TextProcessingStack_MaterialReference__o m_materialReferenceStack;
		struct UnityEngine_Color32_o s_colorWhite;
		struct System_Func_int__string__TMP_FontAsset__o* OnFontAssetRequest;
		struct System_Func_int__string__TMP_SpriteAsset__o* OnSpriteAssetRequest;
		struct System_Char_array* m_htmlTag;
		struct TMPro_RichTextTagAttribute_array* m_xmlAttribute;
		struct System_Single_array* m_attributeParameterValues;
		struct TMPro_WordWrapState_o m_SavedWordWrapState;
		struct TMPro_WordWrapState_o m_SavedLineState;
		struct TMPro_WordWrapState_o m_SavedEllipsisState;
		struct TMPro_WordWrapState_o m_SavedLastValidState;
		struct TMPro_WordWrapState_o m_SavedSoftLineBreakState;
		struct TMPro_TMP_TextProcessingStack_WordWrapState__o m_EllipsisInsertionCandidateStack;
		struct Unity_Profiling_ProfilerMarker_o k_ParseTextMarker;
		struct Unity_Profiling_ProfilerMarker_o k_InsertNewLineMarker;
		struct UnityEngine_Vector2_o k_LargePositiveVector2;
		struct UnityEngine_Vector2_o k_LargeNegativeVector2;
		float k_LargePositiveFloat;
		float k_LargeNegativeFloat;
		int32_t k_LargePositiveInt;
		int32_t k_LargeNegativeInt;
	};
	struct TMPro_TextMeshProUGUI_Fields : TMPro_TMP_Text_Fields {
		bool m_isRebuildingLayout;
		struct UnityEngine_Coroutine_o* m_DelayedGraphicRebuild;
		struct UnityEngine_Coroutine_o* m_DelayedMaterialRebuild;
		struct UnityEngine_Rect_o m_ClipRect;
		bool m_ValidRect;
		struct System_Action_TMP_TextInfo__o* OnPreRenderText;
		bool m_hasFontAssetChanged;
		struct TMPro_TMP_SubMeshUI_array* m_subTextObjects;
		float m_previousLossyScaleY;
		struct UnityEngine_Vector3_array* m_RectTransformCorners;
		struct UnityEngine_CanvasRenderer_o* m_canvasRenderer;
		struct UnityEngine_Canvas_o* m_canvas;
		float m_CanvasScaleFactor;
		bool m_isFirstAllocation;
		int32_t m_max_characters;
		struct UnityEngine_Material_o* m_baseMaterial;
		bool m_isScrollRegionSet;
		struct UnityEngine_Vector4_o m_maskOffset;
		struct UnityEngine_Matrix4x4_o m_EnvMapMatrix;
		bool m_isRegisteredForEvents;
	};
	struct TMPro_TextMeshProUGUI_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_Awake;
		VirtualInvokeData _5_OnEnable;
		VirtualInvokeData _6_Start;
		VirtualInvokeData _7_OnDisable;
		VirtualInvokeData _8_OnDestroy;
		VirtualInvokeData _9_IsActive;
		VirtualInvokeData _10_OnRectTransformDimensionsChange;
		VirtualInvokeData _11_OnBeforeTransformParentChanged;
		VirtualInvokeData _12_OnTransformParentChanged;
		VirtualInvokeData _13_OnDidApplyAnimationProperties;
		VirtualInvokeData _14_OnCanvasGroupChanged;
		VirtualInvokeData _15_OnCanvasHierarchyChanged;
		VirtualInvokeData _16_IsDestroyed;
		VirtualInvokeData _17_unknown;
		VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
		VirtualInvokeData _19_unknown;
		VirtualInvokeData _20_unknown;
		VirtualInvokeData _21_unknown;
		VirtualInvokeData _22_get_color;
		VirtualInvokeData _23_set_color;
		VirtualInvokeData _24_get_raycastTarget;
		VirtualInvokeData _25_set_raycastTarget;
		VirtualInvokeData _26_SetAllDirty;
		VirtualInvokeData _27_SetLayoutDirty;
		VirtualInvokeData _28_SetVerticesDirty;
		VirtualInvokeData _29_SetMaterialDirty;
		VirtualInvokeData _30_get_rectTransform;
		VirtualInvokeData _31_get_defaultMaterial;
		VirtualInvokeData _32_get_material;
		VirtualInvokeData _33_set_material;
		VirtualInvokeData _34_get_materialForRendering;
		VirtualInvokeData _35_get_mainTexture;
		VirtualInvokeData _36_OnCullingChanged;
		VirtualInvokeData _37_Rebuild;
		VirtualInvokeData _38_LayoutComplete;
		VirtualInvokeData _39_GraphicUpdateComplete;
		VirtualInvokeData _40_UpdateMaterial;
		VirtualInvokeData _41_UpdateGeometry;
		VirtualInvokeData _42_OnFillVBO;
		VirtualInvokeData _43_OnPopulateMesh;
		VirtualInvokeData _44_OnPopulateMesh;
		VirtualInvokeData _45_SetNativeSize;
		VirtualInvokeData _46_Raycast;
		VirtualInvokeData _47_CrossFadeColor;
		VirtualInvokeData _48_CrossFadeColor;
		VirtualInvokeData _49_CrossFadeAlpha;
		VirtualInvokeData _50_UnityEngine_UI_IClippable_get_gameObject;
		VirtualInvokeData _51_unknown;
		VirtualInvokeData _52_unknown;
		VirtualInvokeData _53_unknown;
		VirtualInvokeData _54_unknown;
		VirtualInvokeData _55_unknown;
		VirtualInvokeData _56_unknown;
		VirtualInvokeData _57_unknown;
		VirtualInvokeData _58_GetModifiedMaterial;
		VirtualInvokeData _59_Cull;
		VirtualInvokeData _60_SetClipRect;
		VirtualInvokeData _61_SetClipSoftness;
		VirtualInvokeData _62_ParentMaskStateChanged;
		VirtualInvokeData _63_RecalculateClipping;
		VirtualInvokeData _64_RecalculateMasking;
		VirtualInvokeData _65_get_text;
		VirtualInvokeData _66_set_text;
		VirtualInvokeData _67_get_fontSharedMaterial;
		VirtualInvokeData _68_set_fontSharedMaterial;
		VirtualInvokeData _69_get_fontSharedMaterials;
		VirtualInvokeData _70_set_fontSharedMaterials;
		VirtualInvokeData _71_get_fontMaterials;
		VirtualInvokeData _72_set_fontMaterials;
		VirtualInvokeData _73_get_margin;
		VirtualInvokeData _74_set_margin;
		VirtualInvokeData _75_get_autoSizeTextContainer;
		VirtualInvokeData _76_set_autoSizeTextContainer;
		VirtualInvokeData _77_get_mesh;
		VirtualInvokeData _78_add_OnPreRenderText;
		VirtualInvokeData _79_remove_OnPreRenderText;
		VirtualInvokeData _80_get_flexibleHeight;
		VirtualInvokeData _81_get_flexibleWidth;
		VirtualInvokeData _82_get_minWidth;
		VirtualInvokeData _83_get_minHeight;
		VirtualInvokeData _84_get_preferredWidth;
		VirtualInvokeData _85_get_preferredHeight;
		VirtualInvokeData _86_get_renderedWidth;
		VirtualInvokeData _87_get_renderedHeight;
		VirtualInvokeData _88_get_layoutPriority;
		VirtualInvokeData _89_LoadFontAsset;
		VirtualInvokeData _90_SetSharedMaterial;
		VirtualInvokeData _91_GetMaterial;
		VirtualInvokeData _92_SetFontBaseMaterial;
		VirtualInvokeData _93_GetSharedMaterials;
		VirtualInvokeData _94_SetSharedMaterials;
		VirtualInvokeData _95_GetMaterials;
		VirtualInvokeData _96_CreateMaterialInstance;
		VirtualInvokeData _97_SetFaceColor;
		VirtualInvokeData _98_SetOutlineColor;
		VirtualInvokeData _99_SetOutlineThickness;
		VirtualInvokeData _100_SetShaderDepth;
		VirtualInvokeData _101_SetCulling;
		VirtualInvokeData _102_UpdateCulling;
		VirtualInvokeData _103_GetPaddingForMaterial;
		VirtualInvokeData _104_GetPaddingForMaterial;
		VirtualInvokeData _105_GetTextContainerLocalCorners;
		VirtualInvokeData _106_ForceMeshUpdate;
		VirtualInvokeData _107_UpdateGeometry;
		VirtualInvokeData _108_UpdateVertexData;
		VirtualInvokeData _109_UpdateVertexData;
		VirtualInvokeData _110_SetVertices;
		VirtualInvokeData _111_UpdateMeshPadding;
		VirtualInvokeData _112_InternalCrossFadeColor;
		VirtualInvokeData _113_InternalCrossFadeAlpha;
		VirtualInvokeData _114_SetArraySizes;
		VirtualInvokeData _115_CalculatePreferredValues;
		VirtualInvokeData _116_GetCompoundBounds;
		VirtualInvokeData _117_GetCanvasSpaceClippingRect;
		VirtualInvokeData _118_GetTextInfo;
		VirtualInvokeData _119_ComputeMarginSize;
		VirtualInvokeData _120_SaveGlyphVertexInfo;
		VirtualInvokeData _121_SaveSpriteVertexInfo;
		VirtualInvokeData _122_FillCharacterVertexBuffers;
		VirtualInvokeData _123_FillCharacterVertexBuffers;
		VirtualInvokeData _124_FillSpriteVertexBuffers;
		VirtualInvokeData _125_DrawUnderlineMesh;
		VirtualInvokeData _126_DrawTextHighlight;
		VirtualInvokeData _127_SetActiveSubMeshes;
		VirtualInvokeData _128_DestroySubMeshObjects;
		VirtualInvokeData _129_ClearMesh;
		VirtualInvokeData _130_ClearMesh;
		VirtualInvokeData _131_GetParsedText;
		VirtualInvokeData _132_InternalUpdate;
		VirtualInvokeData _133_CalculateLayoutInputHorizontal;
		VirtualInvokeData _134_CalculateLayoutInputVertical;
		VirtualInvokeData _135_unknown;
		VirtualInvokeData _136_unknown;
		VirtualInvokeData _137_unknown;
		VirtualInvokeData _138_unknown;
		VirtualInvokeData _139_unknown;
		VirtualInvokeData _140_unknown;
		VirtualInvokeData _141_unknown;
		VirtualInvokeData _142_GenerateTextMesh;
	};
	struct TMPro_TextMeshProUGUI_c {
		Il2CppClass_1 _1;
		struct TMPro_TextMeshProUGUI_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TMPro_TextMeshProUGUI_VTable vtable;
	};
	struct TMPro_TextMeshProUGUI_o {
		TMPro_TextMeshProUGUI_c* klass;
		void* monitor;
		TMPro_TextMeshProUGUI_Fields fields;
	};
}