#include "framework.h"
#include "StartScene.h"
#include "GameObject.h"
#include "Player.h"
StartScene::StartScene()
{

}

StartScene::~StartScene()
{
}


// �� ������ �־���ϴ� object�� �־��ִ� �Լ�
void StartScene::enter()
{
	// Default 
	GameObject* pObj = new GameObject;
	pObj->setPos(fPoint(100, 100));
	pObj->setScale(fPoint(100, 100));
	AddObject(pObj, GAMEOBJ_GROUP::DEFAULT);
	
	// Player
	GameObject* pPlayer = new Player(fPoint(100.f,100.f));
	pPlayer->setPos(fPoint(200, 200));
	pPlayer->setScale(fPoint(100, 100));
	AddObject(pPlayer, GAMEOBJ_GROUP::PLAYER);
}


// �� ��ȯ�� �ڱ� ���� ��� ������Ʈ���� ó�����ִ� �Լ�
// ����ų� , �ƴϸ� �������Ѽ� �� ��ȯ�� �� �ٽ� ��Ÿ���� �ϰų�
// ������� �޸𸮸� ��Ƹ����� ���������� �̵������� ���͵��� �����ȴ�.
void StartScene::exit()
{

}
