#pragma once

class Scene;

class SceneManager
{

	friend class EventManager;

	SINGLETON(SceneManager);

private:
	Scene* m_arrScene[(int)GROUP_SCENE::SIZE];
	Scene* m_pCurScene;

	void changeScene(GROUP_SCENE _scene);			// �� ��ȯ

public:
	void update();
	void render(HDC _hDC);
	void init();

	//���� Scene�� ������Ʈ���� �߰��ؾ������� CurScene�� ��ȯ���ִ� �Լ�
	Scene* getCurScene();
};

