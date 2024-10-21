#pragma once

#include <wrl/client.h>
#include <assert.h>
#include <Windows.h>



using Microsoft::WRL::ComPtr;
class Input
{
public://メンバ変数
	//初期化
	void Initialize(HINSTANCE hInstance,HWND hwnd);
	//更新
	void Update();

}