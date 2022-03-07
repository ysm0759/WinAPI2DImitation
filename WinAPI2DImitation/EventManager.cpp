#include "framework.h"
#include "EventManager.h"
#include "Scene.h"

EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}




void EventManager::execute(const tEvent& _event)
{
	switch (_event.eEven)
	{
	case TYPE_EVENT::CREATE_OBJECT:
	{
		// lParam : Object �ּ�
		// wParam : Group 
		GameObject* pObj = (GameObject*)_event.lParam;
		GROUP_GAMEOBJ group = (GROUP_GAMEOBJ)_event.wParam;

		SceneManager::getInst()->getCurScene()->addObject(pObj, group);
	}
	break;
	case TYPE_EVENT::DELETE_OBJECT:
	{
		// lParam : Object �ּ�
		// Object�� ���� ���� ���·� ����
		// �������� ������Ʈ���� ��Ƶд�
		GameObject* pObj = (GameObject*)_event.lParam;
		pObj->setDead();
		m_vecDead.push_back(pObj);
	}
	break;
	case TYPE_EVENT::CHANGE_SCENE:
	{
		// lParam : scene �׷�
		GROUP_SCENE scene = (GROUP_SCENE)_event.lParam;
		SceneManager::getInst()->changeScene(scene);
	}
	break;
	}
	
}

void EventManager::update()
{
	// ��ϵ� ���� ���� ������Ʈ���� ����

	for (int i = 0; i < m_vecDead.size(); i++)
	{
		delete m_vecDead[i];
	}

	m_vecDead.clear();


	// �̺�Ʈ ó��
	for (int i = 0; i < m_vecEvent.size(); i++)
	{
		execute(m_vecEvent[i]);
	}
	m_vecEvent.clear();

}


void EventManager::addEvent(const tEvent& _event)
{
	m_vecEvent.push_back(_event);
}

void EventManager::eventCreateObject(GameObject* _pObj, GROUP_GAMEOBJ _group)
{
	tEvent event = {};
	event.eEven = TYPE_EVENT::CREATE_OBJECT;
	event.lParam = (DWORD_PTR)_pObj;
	event.wParam = (DWORD_PTR)_group;

	addEvent(event);
}

void EventManager::eventDeleteObject(GameObject* _pObj)
{
	tEvent event = {};
	event.eEven = TYPE_EVENT::DELETE_OBJECT;
	event.lParam = (DWORD_PTR)_pObj;

	addEvent(event);
}

void EventManager::eventChangeScene(GROUP_SCENE _scene)
{
	tEvent event = {};
	event.eEven = TYPE_EVENT::CHANGE_SCENE;
	event.lParam = (DWORD_PTR)_scene;

	addEvent(event);
}
