#pragma once

#include <wrl.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include "WinApp.h"




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
	Comptr<IDirectInputDevice8> keyboard;
	Comptr<IDirectInput8> directInput;
	BYTE key[256] = {};
	BYTE keyPre[256] = {};
	WinApp* winApp = nullptr;
	HRESULT result;

};