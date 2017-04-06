#ifndef PLAYSCENE_DEF
#define PLAYSCENE_DEF

#include "SceneManager.h"
class Stage;
class Score;

// プレイシーン
class PlayScene : public Scene {
private:
	enum Status{
		// ステージスタート
		STATUS_START,
		// ステージプレイ中
		STATUS_PLAY,
		// ステージクリア
		STATUS_CLEAR,
		// ゲームオーバー
		STATUS_GAMEOVER
	};
	static const int START_COUNT = 60;
	static const int CLEAR_COUNT = 240;
	static const int GAMEOVER_COUNT = 180;

	Stage* stage;
	Score* score;
	Status status;
	int startImage;
	int clearImage;
	int gameoverImage;
	int count;
	int stageIndex;

public :
	PlayScene();
	~PlayScene();
	Scene* Update();
	void Draw();
};

#endif