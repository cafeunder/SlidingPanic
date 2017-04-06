#include <DxLib.h>
#include "main.h"
#include "Keyboard.h"
#include "ImageManager.h"
#include "PlayScene.h"
#include "Stage.h"
#include "Score.h"

// プレイシーン
PlayScene::PlayScene() {
	this->stage = new Stage();
	this->score = new Score();
	this->status = PlayScene::Status::STATUS_START;
	this->startImage = GETIMAGE("start");
	this->clearImage = GETIMAGE("clear");
	this->gameoverImage = GETIMAGE("gameover");
	this->count = 0;

	this->stageIndex = 0;
	this->stage->ReadFile(this->stageIndex);
}

PlayScene::~PlayScene() {
	delete this->stage;
	delete this->score;
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

	case STATUS_PLAY: {
		int repeat = (KEYINPUT(KEY_INPUT_SPACE) > 0) ? 3 : 1;
		for (int i = 0; i < repeat; i++) {
			switch (this->stage->Update(this->score)) {
			case 1:
				this->status = PlayScene::Status::STATUS_CLEAR;
				goto END_UPDATE;
			case -1:
				this->status = PlayScene::Status::STATUS_GAMEOVER;
				goto END_UPDATE;
			}
		}
	} END_UPDATE:
		break;

	case STATUS_CLEAR:
		if (this->count >= CLEAR_COUNT) {
			this->status = PlayScene::Status::STATUS_START;
			this->count = 0;

			++this->stageIndex;
			if (this->stageIndex < STAGE_NUM) {
				this->stage->ReadFile(this->stageIndex);
			} else {
				return new GameClearScene();
			}
		} else {
			this->stage->Update(this->score);
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
	this->score->Draw();

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
		DrawFormatString(160, 20, GetColor(255,255,255), "clear bonus : %d", this->score->GetStageClearBonus());
		DrawFormatString(160, 40, GetColor(255,255,255), "time bonus  : %d", this->score->GetTimeBonus());
		break;

	case STATUS_GAMEOVER:
		GetGraphSize(this->gameoverImage, &width, &height);
		DrawGraph((WINDOW_WIDTH - width) / 2, (WINDOW_HEIGHT - height) / 2, this->gameoverImage, true);
		break;
	}
}
