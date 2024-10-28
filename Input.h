#pragma once

#include <wrl/client.h>
#include <Windows.h>

class Input
{
public://メンバ変数
	//初期化
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	//更新
	void Update();

};