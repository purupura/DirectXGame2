#include "WinApp.h"
#include <cstdint>
#include "externals/imgui/imgui.h"
#include <Windows.h>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam)) {
		return true;
	}

	switch (msg) {
	
	case WM_DESTROY:

		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);

}


void WinApp::Initialize()
{
	HRESULT hr= CoInitializeEx(0, COINIT_MULTITHREADED);

#pragma region Windouの生成
	WNDCLASS wc{};

	//ウィンドウプロシージャ
	wc.lpfnWndProc = WindowProc;
	//ウィンドウクラス名
	wc.lpszClassName = L"C62WindowClass";
	//インスタンスハンドル
	wc.hInstance = GetModuleHandle(nullptr);
	//カーソル
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	//ウィンドウクラスの登録
	RegisterClass(&wc);

	//クライアント領域のサイズ　横　縦
	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;
	//　ウィンドウサイズを表す構造体にクライアント領域を入れる
	RECT wrc = { 0, 0,kClientWidth,kClientHeight };


	HWND hwnd = CreateWindow(
		wc.lpszClassName,
		L"GE3",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wrc.right - wrc.left,
		wrc.bottom - wrc.top,
		nullptr,
		nullptr,
		wc.hInstance,
		nullptr);

	ShowWindow(hwnd, SW_SHOW);

}

void WinApp::Update()
{
}
