#pragma once

using namespace RendererStruct;
namespace MeshRendererStruct {
	struct UnityEngine_MeshRenderer_Fields : UnityEngine_Renderer_Fields {
	};

	struct UnityEngine_MeshRenderer_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};

	struct UnityEngine_MeshRenderer_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		UnityEngine_MeshRenderer_VTable vtable;
	};

	struct UnityEngine_MeshRenderer_o {
		UnityEngine_MeshRenderer_c* klass;
		void* monitor;
		UnityEngine_MeshRenderer_Fields fields;
	};
}