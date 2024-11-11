#pragma once
#include "WinApp.h"
#include <d3d12.h>


class WinApp
{
public://静的メンバ関数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
public://メンバ変数
	//初期化
	void Initialize();
	//更新
	void Update();
};

