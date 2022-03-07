#include "framework.h"
#include "Scene.h"
#include "GameObject.h"


Scene::Scene()
{
	m_sceneName = L"";
}

Scene::~Scene()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			delete m_arrObj[i][j];
		}
	}
}

void Scene::update()
{

	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			if (!m_arrObj[i][j]->isDead())
				m_arrObj[i][j]->update();
		}
	}

}
void Scene::finalUpdate()
{
	// 씬이 가진 모든 오브젝트 finalupdate
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->finalUpdate();
		}
	}
}
void Scene::render(HDC _hDC)
{

	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (vector<GameObject*>::iterator iter = m_arrObj[i].begin();
			iter != m_arrObj[i].end(); )
		{
			if (!(*iter)->isDead())
			{
				(*iter)->render(_hDC);
				iter++;
			}
			else
			{
				iter = m_arrObj[i].erase(iter);
			}
		}
	}
}


void Scene::setName(const wstring& _sceneName)
{
	m_sceneName = _sceneName;
}

wstring Scene::getName()
{
	return m_sceneName;
}

void Scene::addObject(GameObject* _pObj, GROUP_GAMEOBJ _type)
{
	m_arrObj[(int)_type].push_back(_pObj);
}

const vector<GameObject*>& Scene::getGroupObject(GROUP_GAMEOBJ _group)
{
	return m_arrObj[(UINT)_group];
}

void Scene::deleteGroup(GROUP_GAMEOBJ _group)
{
	for (int i = 0; i < m_arrObj[(UINT)_group].size(); i++)
	{
		delete m_arrObj[(UINT)_group][i];
	}
	m_arrObj[(UINT)_group].clear();
}

void Scene::deleteAll()
{
	for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		deleteGroup((GROUP_GAMEOBJ)i);
	}
}



