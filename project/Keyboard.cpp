#include <DxLib.h>
#include "Keyboard.h"

//------------------------------------------------------//
// �L�[�{�[�h���͂��󂯕t����N���X                     //
//------------------------------------------------------//

// �X�V���\�b�h
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

// �L�[�R�[�h������A�����ꂽ�t���[������Ԃ����\�b�h
int Keyboard::GetKeyInput(int keyCode) {
	return key[keyCode];
}
