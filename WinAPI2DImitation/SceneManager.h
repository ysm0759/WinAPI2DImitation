#pragma once

class Scene;

class SceneManager
{
	SINGLETON(SceneManager);
	
private:
	Scene* m_arrScene[(int)SCENE_GROUP::SIZE];
	Scene* m_pCurScene;

public:
	void update();
	void render(HDC _hDC);
	void init();
};

