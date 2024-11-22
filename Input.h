#pragma once

#pragma once
#include "Windows.h"
#include <wrl.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include "WinApp.h"
using namespace Microsoft::WRL;
class Input
{
public:
	//namespace省略
	template<class T>using Comptr = Microsoft::WRL::ComPtr<T>;

public://メンバ変数
	
	//初期化
	void Initialize(WinApp*winApp);
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
	WinApp* winApp = nullptr;

};