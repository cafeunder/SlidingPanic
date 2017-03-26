#include <DxLib.h>
#include "main.h"
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
	this->status = PlayScene::Status::STATUS_START;
	this->startImage = GETIMAGE("start");
	this->clearImage = GETIMAGE("clear");
	this->gameoverImage = GETIMAGE("gameover");
	this->count = 0;
}

PlayScene::~PlayScene() {
	delete this->stage;
}

Scene* PlayScene::Update() {
	switch (this->status) {
	case STATUS_START:
		if (this->count >= START_COUNT) {
			this->status = PlayScene::Status::STATUS_PLAY;
			this->count = 0;
		} else {
			this->count++;
		}
		break;
	case STATUS_PLAY:
		switch (this->stage->Update()) {
		case 1:
			this->status = PlayScene::Status::STATUS_CLEAR;
			break;
		case -1:
			this->status = PlayScene::Status::STATUS_GAMEOVER;
			break;
		}
		break;
	case STATUS_CLEAR:
		if (this->count >= CLEAR_COUNT) {
			this->status = PlayScene::Status::STATUS_START;
			this->count = 0;
		} else {
			this->stage->Update();
			this->count++;
		}
		break;
	case STATUS_GAMEOVER:
		if (this->count >= GAMEOVER_COUNT) {
			return new TitleScene();
		} else {
			this->count++;
		}
	}
	return 0;
}

void PlayScene::Draw() {
	this->stage->Draw();

	int width, height;
	switch (this->status) {
	case STATUS_START:
		GetGraphSize(this->startImage, &width, &height);
		DrawGraph((WINDOW_WIDTH - width) / 2, (WINDOW_HEIGHT - height) / 2, this->startImage, true);
		break;
	case STATUS_PLAY:
		break;
	case STATUS_CLEAR:
		GetGraphSize(this->startImage, &width, &height);
		DrawGraph((WINDOW_WIDTH - width) / 2, (WINDOW_HEIGHT - height) / 2, this->clearImage, true);
		break;
	case STATUS_GAMEOVER:
		GetGraphSize(this->gameoverImage, &width, &height);
		DrawGraph((WINDOW_WIDTH - width) / 2, (WINDOW_HEIGHT - height) / 2, this->gameoverImage, true);
		break;
	}
}
