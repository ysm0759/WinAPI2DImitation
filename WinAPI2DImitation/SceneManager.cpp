#include "framework.h"
#include "SceneManager.h"
#include "StartScene.h"
#include "SceneTool.h"
// SceneManager -> update(); ȣ���ϸ�
// SceneManager ���� ���� (curScene)
// Scene ���� ������ �ִ� ������Ʈ���� 
// GameObject -> update ȣ���Ѵ�.  

SceneManager::SceneManager()
{
	// SceneManager �� ������ �⺻�� nullptr �ʱ�ȭ
	for (int i = 0; i < (int)GROUP_SCENE::SIZE; i++)
	{
		m_arrScene[i] = nullptr;
	}
	m_pCurScene = nullptr;
}


SceneManager::~SceneManager()
{

	for (int i = 0; i < (int)GROUP_SCENE::SIZE; i++)
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
	m_pCurScene->finalUpdate();
}

void SceneManager::render(HDC _hDC)
{
	// ���� ����Ű�� �ִ� scene �� render
	m_pCurScene->render(_hDC);
}


void SceneManager::init()
{
	m_arrScene[(size_t)GROUP_SCENE::TOOL_SCENE] = new SceneTool;
	m_arrScene[(size_t)GROUP_SCENE::TOOL_SCENE]->setName(L"Tool_Scene");

	// �ʱ�ȭ�� 
	m_arrScene[(int)GROUP_SCENE::START_SCENE] = new StartScene;
	m_arrScene[(int)GROUP_SCENE::START_SCENE]->setName(L"Start_Scene");

	m_pCurScene = m_arrScene[(int)GROUP_SCENE::START_SCENE];
	m_pCurScene->enter();
}

Scene* SceneManager::getCurScene()
{
	return this->m_pCurScene;
}

void SceneManager::changeScene(GROUP_SCENE _scene)
{
	m_pCurScene->exit();
	m_pCurScene = m_arrScene[(UINT)_scene];
	m_pCurScene->enter();
}