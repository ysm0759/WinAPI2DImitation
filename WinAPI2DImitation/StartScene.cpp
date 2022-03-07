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

// �� ������ �־���ϴ� object�� �־��ִ� �Լ�
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


// �� ��ȯ�� �ڱ� ���� ��� ������Ʈ���� ó�����ִ� �Լ�
// ����ų� , �ƴϸ� �������Ѽ� �� ��ȯ�� �� �ٽ� ��Ÿ���� �ϰų�
// ������� �޸𸮸� ��Ƹ����� ���������� �̵������� ���͵��� �����ȴ�.
void StartScene::exit()
{
	deleteAll();

	CollisionManager::getInst()->Reset();
}

