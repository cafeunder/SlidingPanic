#ifndef SCENE_MANAGER_DEF
#define SCENE_MANAGER_DEF

// シーンを表すクラスの基底クラス
class Scene {
public :
	virtual Scene* Update() = 0;
	virtual void Draw() = 0;
};

// タイトルシーン
class TitleScene : public Scene {
private:
	int imgHandle;

public :
	TitleScene();
	Scene* Update();
	void Draw();
};

// ゲームクリアシーン
class GameClearScene : public Scene {
private:
	int imgHandle;

public :
	GameClearScene();
	Scene* Update();
	void Draw();
};

// シーンの切り替えを管理するマネージャ
class SceneManager {
public :
	void Update();
	void Draw();
	SceneManager();

private:
	Scene* scene;
};

#endif