#include <DxLib.h>
#include "main.h"
#include "ImageManager.h"
#include "Keyboard.h"
#include "SceneManager.h"
#include "PlayScene.h"
#include "Stage.h"

// シーンマネージャ
SceneManager::SceneManager() {
	this->scene = new TitleScene();
}

void SceneManager::Update() {
	Scene* result = this->scene->Update();
	if (result != 0) {
		delete this->scene;
		this->scene = result;
	}
}

void SceneManager::Draw() {
	this->scene->Draw();
}


// タイトルシーン
TitleScene::TitleScene() {
	this->imgHandle = GETIMAGE("title");
}

Scene* TitleScene::Update() {
	if (KEYINPUT(KEY_INPUT_SPACE) == 1) {
		return new PlayScene();
	}
	return 0;
}

void TitleScene::Draw() {
	DrawGraph(0, 0, this->imgHandle, false);
}


// ゲームクリアシーン
GameClearScene::GameClearScene() {
	this->imgHandle = GETIMAGE("gameclear");
}

Scene* GameClearScene::Update() {
	if (KEYINPUT(KEY_INPUT_SPACE) == 1) {
		return new TitleScene();
	}
	return 0;
}

void GameClearScene::Draw() {
	DrawGraph(0, 0, this->imgHandle, false);
}
