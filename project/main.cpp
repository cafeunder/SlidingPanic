#include <DxLib.h>
#include "main.h"
#include "Keyboard.h"
#include "ImageManager.h"
#include "SceneManager.h"

//------------------------------------------------------//
// メイン関数                                           //
//------------------------------------------------------//

//********************************************************
//* 使用 : DXライブラリ.net                              *
//* http://homepage2.nifty.com/natupaji/DxLib/index.html *
//* DX Library Copyright (C) 2001-2017 Takumi Yamada.    *
//********************************************************

// フルスクリーンモードをやめる場合は以下をコメントアウトする
//#define FULL_SCREEN

// メイン関数
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
	SetMainWindowText("Sample Game");
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
#ifdef FULL_SCREEN
	ChangeWindowMode(FALSE); // フルスクリーンモードに
#else
	ChangeWindowMode(TRUE);
#endif
	
	if (DxLib_Init() == -1) { // DXライブラリの初期化
		ErrorExit("DXライブラリの初期化に失敗しました。");
	}
	SetDrawScreen(DX_SCREEN_BACK); // ダブルバッファのためのセッタ
	ImageManager::GetInstance();

	SceneManager sceneManager;
	while (true) {
		if (!LoopStart()) break; // 初期化処理
		Keyboard::GetInstance()->Update();
		if (KEYINPUT(KEY_INPUT_ESCAPE) == 1) break;

		sceneManager.Update();
		sceneManager.Draw();
	}

	DxLib_End();
	return 0;
}

// ループ初期化処理
bool LoopStart(){
	if(ScreenFlip() == -1) return false; // 裏画面処理
	if(ProcessMessage() == -1) return false; // Windowsへのシステム応答
	if(ClearDrawScreen() == -1) return false; // 画面の初期化

	return true;
}

// エラー終了
void ErrorExit(const char* message){
	MessageBox(NULL, message, "エラー", MB_OK);

	DxLib_End();
	exit(1);
}
