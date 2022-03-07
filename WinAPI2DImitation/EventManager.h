#pragma once

class GameObject;

struct tEvent
{
	TYPE_EVENT eEven;	 //�̺�Ʈ Ÿ��
	DWORD_PTR lParam;	// �̺�Ʈ ����
	DWORD_PTR wParam;	// �̺�Ʈ ����


};


class EventManager
{
	SINGLETON(EventManager);

private:
	vector<tEvent> m_vecEvent;
	vector<GameObject*> m_vecDead;

	void execute(const tEvent& _event);

public:
	void update();

	void addEvent(const tEvent& _event);
	void eventCreateObject(GameObject* _pObj, GROUP_GAMEOBJ _group);
	void eventDeleteObject(GameObject* _pObj);
	void eventChangeScene(GROUP_SCENE _scene);
};


