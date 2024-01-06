#pragma once

namespace ButtonStruct
{

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

    struct UnityEngine_UI_Navigation_Fields {
        int32_t m_Mode;
        bool m_WrapAround;
        struct UnityEngine_UI_Selectable_o* m_SelectOnUp;
        struct UnityEngine_UI_Selectable_o* m_SelectOnDown;
        struct UnityEngine_UI_Selectable_o* m_SelectOnLeft;
        struct UnityEngine_UI_Selectable_o* m_SelectOnRight;
    };
    struct UnityEngine_UI_Navigation_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
        VirtualInvokeData _4_Equals;
    };
    struct UnityEngine_UI_Navigation_c {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        UnityEngine_UI_Navigation_VTable vtable;
    };
    struct UnityEngine_UI_Navigation_o {
        UnityEngine_UI_Navigation_Fields fields;
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

    struct UnityEngine_UI_ColorBlock_Fields {
        struct UnityEngine_Color_o m_NormalColor;
        struct UnityEngine_Color_o m_HighlightedColor;
        struct UnityEngine_Color_o m_PressedColor;
        struct UnityEngine_Color_o m_SelectedColor;
        struct UnityEngine_Color_o m_DisabledColor;
        float m_ColorMultiplier;
        float m_FadeDuration;
    };
    struct UnityEngine_UI_ColorBlock_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
        VirtualInvokeData _4_Equals;
    };
    struct UnityEngine_UI_ColorBlock_c {
        Il2CppClass_1 _1;
        struct UnityEngine_UI_ColorBlock_StaticFields* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        UnityEngine_UI_ColorBlock_VTable vtable;
    };
    struct UnityEngine_UI_ColorBlock_o {
        UnityEngine_UI_ColorBlock_Fields fields;
    };
    struct UnityEngine_UI_ColorBlock_StaticFields {
        struct UnityEngine_UI_ColorBlock_o defaultColorBlock;
    };
    struct UnityEngine_UI_SpriteState_Fields {
        struct UnityEngine_Sprite_o* m_HighlightedSprite;
        struct UnityEngine_Sprite_o* m_PressedSprite;
        struct UnityEngine_Sprite_o* m_SelectedSprite;
        struct UnityEngine_Sprite_o* m_DisabledSprite;
    };
    struct UnityEngine_UI_SpriteState_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
        VirtualInvokeData _4_Equals;
    };
    struct UnityEngine_UI_SpriteState_c {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        UnityEngine_UI_SpriteState_VTable vtable;
    };
    struct UnityEngine_UI_SpriteState_o {
        UnityEngine_UI_SpriteState_Fields fields;
    };

    struct UnityEngine_UI_Selectable_Fields : UnityEngine_EventSystems_UIBehaviour_Fields {
        bool m_EnableCalled;
        struct UnityEngine_UI_Navigation_o m_Navigation;
        int32_t m_Transition;
        struct UnityEngine_UI_ColorBlock_o m_Colors;
        struct UnityEngine_UI_SpriteState_o m_SpriteState;
        struct UnityEngine_UI_AnimationTriggers_o* m_AnimationTriggers;
        bool m_Interactable;
        struct UnityEngine_UI_Graphic_o* m_TargetGraphic;
        bool m_GroupsAllowInteraction;
        int32_t m_CurrentIndex;
        bool _isPointerInside_k__BackingField;
        bool _isPointerDown_k__BackingField;
        bool _hasSelection_k__BackingField;
        struct System_Collections_Generic_List_CanvasGroup__o* m_CanvasGroupCache;
    };
    struct UnityEngine_UI_Selectable_VTable {
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
        VirtualInvokeData _18_unknown;
        VirtualInvokeData _19_unknown;
        VirtualInvokeData _20_unknown;
        VirtualInvokeData _21_unknown;
        VirtualInvokeData _22_unknown;
        VirtualInvokeData _23_unknown;
        VirtualInvokeData _24_IsInteractable;
        VirtualInvokeData _25_InstantClearState;
        VirtualInvokeData _26_DoStateTransition;
        VirtualInvokeData _27_FindSelectableOnLeft;
        VirtualInvokeData _28_FindSelectableOnRight;
        VirtualInvokeData _29_FindSelectableOnUp;
        VirtualInvokeData _30_FindSelectableOnDown;
        VirtualInvokeData _31_OnMove;
        VirtualInvokeData _32_OnPointerDown;
        VirtualInvokeData _33_OnPointerUp;
        VirtualInvokeData _34_OnPointerEnter;
        VirtualInvokeData _35_OnPointerExit;
        VirtualInvokeData _36_OnSelect;
        VirtualInvokeData _37_OnDeselect;
        VirtualInvokeData _38_Select;
    };
    struct UnityEngine_UI_Selectable_c {
        Il2CppClass_1 _1;
        struct UnityEngine_UI_Selectable_StaticFields* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        UnityEngine_UI_Selectable_VTable vtable;
    };
    struct UnityEngine_UI_Selectable_o {
        UnityEngine_UI_Selectable_c* klass;
        void* monitor;
        UnityEngine_UI_Selectable_Fields fields;
    };

    struct UnityEngine_UI_Button_Fields : UnityEngine_UI_Selectable_Fields {
        struct UnityEngine_UI_Button_ButtonClickedEvent_o* m_OnClick;
    };
    struct UnityEngine_UI_Button_VTable {
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
        VirtualInvokeData _18_unknown;
        VirtualInvokeData _19_unknown;
        VirtualInvokeData _20_unknown;
        VirtualInvokeData _21_unknown;
        VirtualInvokeData _22_unknown;
        VirtualInvokeData _23_unknown;
        VirtualInvokeData _24_IsInteractable;
        VirtualInvokeData _25_InstantClearState;
        VirtualInvokeData _26_DoStateTransition;
        VirtualInvokeData _27_FindSelectableOnLeft;
        VirtualInvokeData _28_FindSelectableOnRight;
        VirtualInvokeData _29_FindSelectableOnUp;
        VirtualInvokeData _30_FindSelectableOnDown;
        VirtualInvokeData _31_OnMove;
        VirtualInvokeData _32_OnPointerDown;
        VirtualInvokeData _33_OnPointerUp;
        VirtualInvokeData _34_OnPointerEnter;
        VirtualInvokeData _35_OnPointerExit;
        VirtualInvokeData _36_OnSelect;
        VirtualInvokeData _37_OnDeselect;
        VirtualInvokeData _38_Select;
        VirtualInvokeData _39_unknown;
        VirtualInvokeData _40_unknown;
        VirtualInvokeData _41_OnPointerClick;
        VirtualInvokeData _42_OnSubmit;
    };
    struct UnityEngine_UI_Button_c {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        UnityEngine_UI_Button_VTable vtable;
    };
    struct UnityEngine_UI_Button_o {
        UnityEngine_UI_Button_c* klass;
        void* monitor;
        UnityEngine_UI_Button_Fields fields;
    };
}