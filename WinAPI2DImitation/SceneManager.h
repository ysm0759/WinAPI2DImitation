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

	//���� Scene�� ������Ʈ���� �߰��ؾ������� CurScene�� ��ȯ���ִ� �Լ�
	Scene* getCurScene();
};

