#pragma once

#pragma once
#include "Windows.h"
#include <wrl.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

class Input
{
public:
	//namespace省略
	template<class T>using Comptr = Microsoft::WRL::ComPtr<T>;

public://メンバ変数
	
	//初期化
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	//更新
	void Update();
	//プッシュ
	bool PushKey(BYTE keyNumber);
	//トリガー
	bool TriggerKey(BYTE keyNumber);
private://メンバ変数
	//キーボードのデバイス
	ComPtr<IDirectInputDevice8> keyboard;
	ComPtr<IDirectInput8> directInput;
	BYTE key[256] = {};
	BYTE keyPre[256] = {};

};