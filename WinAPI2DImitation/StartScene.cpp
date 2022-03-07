#include "framework.h"
#include "StartScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Monster.h"

StartScene::StartScene()
{

}

StartScene::~StartScene()
{
}

void  StartScene::update()
{
	Scene::update();
	
	if (KEYDOWN(VK_ESCAPE))
	{
		CHANGESCN(GROUP_SCENE::TOOL_SCENE);
	}
}

// 각 씬들이 넣어야하는 object를 넣어주는 함수
void StartScene::enter()
{

	// Player
	GameObject* pPlayer = new Player(fPoint(100.f,100.f));
	pPlayer->setPos(fPoint(200, 200));
	pPlayer->setScale(fPoint(100, 100));
	
  	GameObject* pMonster = new Monster();
	pMonster->setPos(fPoint(300, 200));
	pMonster->setScale(fPoint(100, 100));
	


	CREATEOBJ(pMonster, GROUP_GAMEOBJ::MONSTER);
	CREATEOBJ(pPlayer, GROUP_GAMEOBJ::PLAYER);

	CollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::MONSTER);
	CollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::MISSILE_PLAYER, GROUP_GAMEOBJ::MONSTER);
}


// 씬 전환시 자기 씬의 모든 오브젝트들을 처리해주는 함수
// 지우거나 , 아니면 유지시켜서 씬 전환할 때 다시 나타나게 하거나
// 안지우면 메모리를 잡아먹지만 이전씬으로 이동했을때 몬스터들이 유지된다.
void StartScene::exit()
{
	deleteAll();

	CollisionManager::getInst()->Reset();
}

