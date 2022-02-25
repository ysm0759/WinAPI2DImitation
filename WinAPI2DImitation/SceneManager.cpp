#include "framework.h"
#include "SceneManager.h"
#include "StartScene.h"

// SceneManager -> update(); ȣ���ϸ�
// SceneManager ���� ���� (curScene)
// Scene ���� ������ �ִ� ������Ʈ���� 
// GameObject -> update ȣ���Ѵ�.  

SceneManager::SceneManager()
{
	// SceneManager �� ������ �⺻�� nullptr �ʱ�ȭ
	for (int i = 0; i < (int)SCENE_GROUP::SIZE; i++)
	{
		m_arrScene[i] = nullptr;
	}
	m_pCurScene = nullptr;
}


SceneManager::~SceneManager()
{

	for (int i = 0; i < (int)SCENE_GROUP::SIZE; i++)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}


void SceneManager::update()
{
	//���� ����Ű�� �ִ� scene�� ������Ʈ
	m_pCurScene->update();
}

void SceneManager::render(HDC _hDC)
{
	// ���� ����Ű�� �ִ� scene �� render
	m_pCurScene->render(_hDC);
}


void SceneManager::init()
{
	// �ʱ�ȭ�� 
	m_arrScene[(int)SCENE_GROUP::START_SCENE] = new StartScene;
	m_arrScene[(int)SCENE_GROUP::START_SCENE]->setName(L"Start_Scene");

	m_pCurScene = m_arrScene[(int)SCENE_GROUP::START_SCENE];
	m_pCurScene->enter();
}

Scene* SceneManager::getCurScene()
{
	return this->m_pCurScene;
}
