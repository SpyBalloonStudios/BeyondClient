#include "renderui.h"

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx11.h"
#include "../imgui/imgui_impl_win32.h"

#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>
#include <cstdio>
#include <chrono>
#include <ctime>
#include <list>
#include <vector>
#include <thread>
#include <functional>
#include <deque>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <mutex>

//#include "../Definitons/il2cpp.h"

#define WKey 0x87
#define AKey 0x65
#define SKey 0x83
#define DKey 0x68

#define ShiftKey 0x16


//... Initialize Headers
#include "../Definitions.h"
// Important

#include "../OS-ImGui.h"
#include "../Definitions.h"
#include "../Functions.h"
#include "../TMPro_TextMeshProUGUI_o.h"
#include "../Offsets.h"
#include "../Vector3.h"
#include "../Config.h"
#include "../LogWriter.h"
#include "../Log.h"
#include "../SoundEffects.h"
// Utils
#include "../Notify/imgui_notify.h"
#include "../NotificationManager.h"
#include "../LogWindow.h"

#include "../Objects/Button.h"
#include "../Object.h"
#include "../Objects/Gameobject.h"
#include "../Objects/Text.h"
#include "../Objects/TextMeshPro.h"
#include "../Objects/Unity.h"
#include "../Gizmos.h"
#include "../Component.h"
#include "../Objects/transform.h"
#include "../VRC_SDKBase_VRCPickup_o.h"
#include "../VRC_SDKBase_VRCPlayerApi_o.h"
#include "../UnityEngine_UI_Button_o.h"
#include "../UnityEngine_Renderer_o.h"
#include "../UnityEngine_MeshRenderer_o.h"
#include "../ButtonUtils.h"
Unity unity;
#include "../Objects/playernet.h"
#include "../Objects/vrcplayer.h"
#include "../Objects/VRCPlayerAPI.h"
#include "../Networking.h"
#include "../Objects/ApiAvatar.h"
#include "../Objects/ApiUser.h"
#include "../Objects/Player.h"
#include "../Objects/Camera.h"
#include "../ItemOrbit.h"
#include "../VRCCombat.h"
#include "../Render.h"

#include "../InputManager.h"
#include "../SingleButton.h"

#include "../PhotonUtils.h"
#include "../Handler/Bot.h"

#include "../Handler/FlyHandler.h"
#include "../Handler/BunnyHop.h"

#include "../HookManager.h"
#include "../Hooks.h"

#include "Raw.h"
#include "../Menu.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
ResizeBuffers oResizeBuffers;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
static uint64_t* g_methodsTable = NULL;

bool rdr::initdx() {
	WNDCLASSEX windowClass;
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = DefWindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = GetModuleHandle(NULL);
	windowClass.hIcon = NULL;
	windowClass.hCursor = NULL;
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = "ImDX11";
	windowClass.hIconSm = NULL;

	::RegisterClassEx(&windowClass);

	HWND window = ::CreateWindow(windowClass.lpszClassName, "BeyondClient", WS_OVERLAPPEDWINDOW, 0, 0, 100, 100, NULL, NULL, windowClass.hInstance, NULL);
	HMODULE libD3D11;
	if ((libD3D11 = ::GetModuleHandle("d3d11.dll")) == NULL)
	{
		::DestroyWindow(window);
		::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
		return 0;
	}

	void* D3D11CreateDeviceAndSwapChain;
	if ((D3D11CreateDeviceAndSwapChain = ::GetProcAddress(libD3D11, "D3D11CreateDeviceAndSwapChain")) == NULL)
	{
		::DestroyWindow(window);
		::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
		return 0;
	}

	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_11_0 };

	DXGI_RATIONAL refreshRate;
	refreshRate.Numerator = 60;
	refreshRate.Denominator = 1;

	DXGI_MODE_DESC bufferDesc;
	bufferDesc.Width = 100;
	bufferDesc.Height = 100;
	bufferDesc.RefreshRate = refreshRate;
	bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	DXGI_SAMPLE_DESC sampleDesc;
	sampleDesc.Count = 1;
	sampleDesc.Quality = 0;

	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	swapChainDesc.BufferDesc = bufferDesc;
	swapChainDesc.SampleDesc = sampleDesc;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 1;
	swapChainDesc.OutputWindow = window;
	swapChainDesc.Windowed = 1;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	IDXGISwapChain* swapChain;
	ID3D11Device* device;
	ID3D11DeviceContext* context;

	if (((long(__stdcall*)(
		IDXGIAdapter*,
		D3D_DRIVER_TYPE,
		HMODULE,
		UINT,
		const D3D_FEATURE_LEVEL*,
		UINT,
		UINT,
		const DXGI_SWAP_CHAIN_DESC*,
		IDXGISwapChain**,
		ID3D11Device**,
		D3D_FEATURE_LEVEL*,
		ID3D11DeviceContext**))(D3D11CreateDeviceAndSwapChain))(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, featureLevels, 1, D3D11_SDK_VERSION, &swapChainDesc, &swapChain, &device, &featureLevel, &context) < 0)
	{
		::DestroyWindow(window);
		::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
		return 0;
	}

	g_methodsTable = (uint64_t*)::calloc(205, sizeof(uint64_t));
	::memcpy(g_methodsTable, *(uint64_t**)swapChain, 18 * sizeof(uint64_t));
	::memcpy(g_methodsTable + 18, *(uint64_t**)device, 43 * sizeof(uint64_t));
	::memcpy(g_methodsTable + 18 + 43, *(uint64_t**)context, 144 * sizeof(uint64_t));

	MH_Initialize();

	swapChain->Release();
	swapChain = NULL;

	device->Release();
	device = NULL;

	context->Release();
	context = NULL;

	::DestroyWindow(window);
	::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
	
	return 1;
}

void rdr::init() {
	bool ihook = false;
	do {
		if (rdr::initdx()) {
			ihook = true;
			MH_CreateHook((void*)g_methodsTable[8], hkPresent, (void**)&oPresent);
			MH_CreateHook((void*)g_methodsTable[13], hkResizeBuffers, (void**)&oResizeBuffers);
			Hooks::InitHooks();
			MH_EnableHook(MH_ALL_HOOKS);
		}
	} while (!ihook);
}

LRESULT __stdcall rdr::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool hkinit = false;
ImFont* fnt;
HRESULT __stdcall rdr::hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!hkinit)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();
			io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
			ImGui_ImplWin32_Init(window);
			ImGui_ImplDX11_Init(pDevice, pContext);

			// FONTS

			//fnt = io.Fonts->AddFontFromMemoryTTF(HelveticaNeueLight, sizeof HelveticaNeueLight, 25.f);
			//static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
			//ImFontConfig icons_config;
			//icons_config.MergeMode = true;
			//icons_config.PixelSnapH = true;
			//io.Fonts->AddFontFromMemoryTTF(&font_awesome_binary, sizeof font_awesome_binary, 30, &icons_config, icon_ranges);
			hkinit = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	//ImGui::PushFont(fnt);
	//SetupImGuiStyle();
	//ImGui::ShowDemoWindow();
	MainRendererHandler();
	//ImGui::PopFont();


	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

HRESULT rdr::hkResizeBuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
{
	if (mainRenderTargetView) {
		pContext->OMSetRenderTargets(0, 0, 0);
		mainRenderTargetView->Release();
	}

	HRESULT hr = oResizeBuffers(pSwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);

	ID3D11Texture2D* pBuffer;
	pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBuffer);

	pDevice->CreateRenderTargetView(pBuffer, NULL, &mainRenderTargetView);
	pBuffer->Release();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);

	D3D11_VIEWPORT vp;
	vp.Width = Width;
	vp.Height = Height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	pContext->RSSetViewports(1, &vp);
	return hr;
}

void rdr::term() {
	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();

	::free(g_methodsTable);
	g_methodsTable = NULL;

	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	SetWindowLongPtr(
		window,
		GWLP_WNDPROC,
		reinterpret_cast<LONG_PTR>(oWndProc)
	);
	if (pDevice) {
		pDevice->Release();
		pDevice = NULL;
	}
	if (pContext) {
		pContext->Release();
		pContext = NULL;
	}
	if (mainRenderTargetView) {
		mainRenderTargetView->Release();
		mainRenderTargetView = NULL;
	}
}
