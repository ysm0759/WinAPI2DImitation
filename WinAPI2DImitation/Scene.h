#pragma once

class GameObject;

class Scene
{

private:
	vector<GameObject*> m_arrObj[(int)GROUP_GAMEOBJ::SIZE]; // ��ӹ��� ���� ������ �־���� ������Ʈ��
	wstring m_sceneName; // �� �̸�

public:
	Scene();
	virtual ~Scene();

	virtual void update();			// ������ �ִ� ������Ʈ���� ��� ���� ���ִ� �Լ�
	virtual void finalUpdate();
	virtual void render(HDC _hDC);	// ������ �ִ� ������Ʈ���� ��� �׷��ִ� �Լ�

	virtual void enter() = 0;		// �� ������ ������ �� �־��ϴ� object�� �־�����ϴ� �Լ�
	virtual void exit() = 0;		// ������ ��� ������ ������Ʈ���� �����ִ� �Լ�


	void setName(const wstring& _sceneName);
	wstring getName();

	void addObject(GameObject* _pObj, GROUP_GAMEOBJ _type); // ���� ������Ʈ���� type���� �־��ִ� �Լ� 
	const vector<GameObject*>& getGroupObject(GROUP_GAMEOBJ _group);
	void deleteGroup(GROUP_GAMEOBJ _group);
	void deleteAll();

};

