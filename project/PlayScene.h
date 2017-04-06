#ifndef PLAYSCENE_DEF
#define PLAYSCENE_DEF

#include "SceneManager.h"
class Stage;
class Score;

// �v���C�V�[��
class PlayScene : public Scene {
private:
	enum Status{
		// �X�e�[�W�X�^�[�g
		STATUS_START,
		// �X�e�[�W�v���C��
		STATUS_PLAY,
		// �X�e�[�W�N���A
		STATUS_CLEAR,
		// �Q�[���I�[�o�[
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