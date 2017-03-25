#include <DxLib.h>
#include "ImageManager.h"
#include "Keyboard.h"
#include "SceneManager.h"
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


// プレイシーン
PlayScene::PlayScene() {
	this->stage = new Stage();
	this->stage->ReadFile("stage2");
}

PlayScene::~PlayScene() {
	delete this->stage;
}

Scene* PlayScene::Update() {
	this->stage->Update();
	return 0;
}

void PlayScene::Draw() {
	this->stage->Draw();
}
