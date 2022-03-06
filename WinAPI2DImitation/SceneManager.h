#pragma once

class Scene;

class SceneManager
{
	SINGLETON(SceneManager);
	
private:
	Scene* m_arrScene[(int)GROUP_SCENE::SIZE];
	Scene* m_pCurScene;

public:
	void update();
	void render(HDC _hDC);
	void init();

	//현재 Scene에 오브젝트들을 추가해야함으로 CurScene을 반환해주는 함수
	Scene* getCurScene();
};

