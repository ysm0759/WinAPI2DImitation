#pragma once

class Scene;

class SceneManager
{

	friend class EventManager;

	SINGLETON(SceneManager);

private:
	Scene* m_arrScene[(int)GROUP_SCENE::SIZE];
	Scene* m_pCurScene;

	void changeScene(GROUP_SCENE _scene);			// 씬 전환

public:
	void update();
	void render(HDC _hDC);
	void init();

	//현재 Scene에 오브젝트들을 추가해야함으로 CurScene을 반환해주는 함수
	Scene* getCurScene();
};

