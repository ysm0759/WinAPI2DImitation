#include "framework.h"
#include "SceneManager.h"
#include "StartScene.h"
#include "SceneTool.h"
// SceneManager -> update(); 호출하면
// SceneManager 현재 씬에 (curScene)
// Scene 씬이 가지고 있는 오브젝트들을 
// GameObject -> update 호출한다.  

SceneManager::SceneManager()
{
	// SceneManager 각 씬들의 기본값 nullptr 초기화
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
	//현재 가르키고 있는 scene만 업데이트
	m_pCurScene->update();
	m_pCurScene->finalUpdate();
}

void SceneManager::render(HDC _hDC)
{
	// 현재 가르키고 있는 scene 만 render
	m_pCurScene->render(_hDC);
}


void SceneManager::init()
{
	m_arrScene[(size_t)GROUP_SCENE::TOOL_SCENE] = new SceneTool;
	m_arrScene[(size_t)GROUP_SCENE::TOOL_SCENE]->setName(L"Tool_Scene");

	// 초기화면 
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