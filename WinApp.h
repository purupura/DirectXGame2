#pragma once
#include <Windows.h>
#include <cstdint>
#include <wrl.h>
#include <WinUser.h>



class WinApp
{
public://静的メンバ関数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparm, LPARAM lparam);
public://メンバ変数
	//初期化
	void Initialize();
	//更新
	void Update();

	void Finalize();
public://定数
	//クライアント領域のサイズ
	static const int32_t kClientWidth = 1280;
	static const int32_t kClientHeight = 720;

	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return wc.hInstance; }

private:
	
	HWND hwnd = nullptr;
	WNDCLASS wc{};

	
};

