#pragma once

class GameObject;

struct tEvent
{
	TYPE_EVENT eEven;	 //이벤트 타입
	DWORD_PTR lParam;	// 이벤트 정보
	DWORD_PTR wParam;	// 이벤트 정보


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


