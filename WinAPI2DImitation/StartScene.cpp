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


// �� ������ �־���ϴ� object�� �־��ִ� �Լ�
void StartScene::enter()
{

	// Player
	GameObject* pPlayer = new Player(fPoint(100.f,100.f));
	pPlayer->setPos(fPoint(200, 200));
	pPlayer->setScale(fPoint(100, 100));
	AddObject(pPlayer, GAMEOBJ_GROUP::PLAYER);

  	GameObject* pMonster = new Monster();
	pMonster->setPos(fPoint(300, 200));
	pMonster->setScale(fPoint(100, 100));
	AddObject(pMonster, GAMEOBJ_GROUP::MONSTER);


}


// �� ��ȯ�� �ڱ� ���� ��� ������Ʈ���� ó�����ִ� �Լ�
// ����ų� , �ƴϸ� �������Ѽ� �� ��ȯ�� �� �ٽ� ��Ÿ���� �ϰų�
// ������� �޸𸮸� ��Ƹ����� ���������� �̵������� ���͵��� �����ȴ�.
void StartScene::exit()
{

}
