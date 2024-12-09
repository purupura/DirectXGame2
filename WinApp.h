#pragma once
#include <Windows.h>
#include <cstdint>
#include <wrl.h>
#include <WinUser.h>

class WinApp
{
public:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	//クライアント領域のサイズ　横　縦
	static const int32_t kClientWidth = 1280;
	static const int32_t kClientHeight = 720;



	HWND GetHwnd() const { return hwnd; }

	HINSTANCE GetHInstance() const { return wc.hInstance; }

	void Initialize();

	void Update();

	void Finalize();

	bool ProcessMessage();

private:
	HWND hwnd = nullptr;
	WNDCLASS wc{};

};