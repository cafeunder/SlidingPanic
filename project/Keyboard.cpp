#include <DxLib.h>
#include "Keyboard.h"

//------------------------------------------------------//
// キーボード入力を受け付けるクラス                     //
//------------------------------------------------------//

// 更新メソッド
void Keyboard::Update() {
	char temp[256];
	GetHitKeyStateAll(temp);

	for(int i = 0; i < 256; i++) { 
		if(temp[i] != 0) {
			key[i]++;
		} else {
			key[i] = 0;
		}
	}
}

// キーコードを受取り、押されたフレーム数を返すメソッド
int Keyboard::GetKeyInput(int keyCode) {
	return key[keyCode];
}
