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
	Stage* stage;

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