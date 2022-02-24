#pragma once

class GameObject;

class Scene
{

private:
	vector<GameObject*> m_arrObj[(int)GAMEOBJ_GROUP::SIZE]; // ��ӹ��� ���� ������ �־���� ������Ʈ��
	wstring m_sceneName; // �� �̸�

public:
	Scene();
	virtual ~Scene();

	virtual void update();			// ������ �ִ� ������Ʈ���� ��� ���� ���ִ� �Լ�
	virtual void render(HDC _hDC);	// ������ �ִ� ������Ʈ���� ��� �׷��ִ� �Լ�

	virtual void enter() = 0;		// �� ������ ������ �� �־��ϴ� object�� �־�����ϴ� �Լ�
	virtual void exit() = 0;		// ������ ��� ������ ������Ʈ���� �����ִ� �Լ�


	void setName(const wstring& _sceneName);
	wstring getName();

	void AddObject(GameObject* _pObj, GAMEOBJ_GROUP _type); // ���� ������Ʈ���� type���� �־��ִ� �Լ� 


};

