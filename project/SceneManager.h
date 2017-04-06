#ifndef SCENE_MANAGER_DEF
#define SCENE_MANAGER_DEF

// �V�[����\���N���X�̊��N���X
class Scene {
public :
	virtual Scene* Update() = 0;
	virtual void Draw() = 0;
};

// �^�C�g���V�[��
class TitleScene : public Scene {
private:
	int imgHandle;

public :
	TitleScene();
	Scene* Update();
	void Draw();
};

// �Q�[���N���A�V�[��
class GameClearScene : public Scene {
private:
	int imgHandle;

public :
	GameClearScene();
	Scene* Update();
	void Draw();
};

// �V�[���̐؂�ւ����Ǘ�����}�l�[�W��
class SceneManager {
public :
	void Update();
	void Draw();
	SceneManager();

private:
	Scene* scene;
};

#endif