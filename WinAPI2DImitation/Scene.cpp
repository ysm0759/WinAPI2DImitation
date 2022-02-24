#include "framework.h"
#include "Scene.h"
#include "GameObject.h"


Scene::Scene()
{
	m_sceneName = L"";
}

Scene::~Scene()
{
	for (int i = 0; i < (int)GAMEOBJ_GROUP::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			delete m_arrObj[i][j];
		}
	}
}

void Scene::update()
{

	for (int i = 0; i < (int)GAMEOBJ_GROUP::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->update();
		}
	}

}
void Scene::render(HDC _hDC)
{

	for (int i = 0; i < (int)GAMEOBJ_GROUP::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->render(_hDC);
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

void Scene::AddObject(GameObject* _pObj, GAMEOBJ_GROUP _type)
{
	m_arrObj[(int)_type].push_back(_pObj);
}