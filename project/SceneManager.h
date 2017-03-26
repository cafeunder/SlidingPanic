#ifndef SCENE_MANAGER_DEF
#define SCENE_MANAGER_DEF

class Stage;

class Scene {
public :
	virtual Scene* Update() = 0;
	virtual void Draw() = 0;
};

class TitleScene : public Scene {
private:
	int imgHandle;

public :
	TitleScene();
	Scene* Update();
	void Draw();
};

class PlayScene : public Scene {
private:
	enum Status{
		STATUS_START,
		STATUS_PLAY,
		STATUS_CLEAR,
		STATUS_GAMEOVER
	};
	static const int START_COUNT = 60;
	static const int CLEAR_COUNT = 240;
	static const int GAMEOVER_COUNT = 180;

	Stage* stage;
	Status status;
	int startImage;
	int clearImage;
	int gameoverImage;
	int count;

public :
	PlayScene();
	~PlayScene();
	Scene* Update();
	void Draw();
};

class SceneManager {
public :
	void Update();
	void Draw();
	SceneManager();

private:
	Scene* scene;
};

#endif