#include "WinApp.h"

#include "externals/imgui/imgui_impl_win32.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WinApp::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lParam) {
	if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lParam)) {
		return true;
	}

	switch (msg) {

	case WM_DESTROY:

		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wparam, lParam);
}

void WinApp::Initialize()
{
	HRESULT hr= CoInitializeEx(0, COINIT_MULTITHREADED);

#pragma region Windowの生成

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

void WinApp::Finalize()
{
	CloseWindow(hwnd);
	CoUninitialize();
}
