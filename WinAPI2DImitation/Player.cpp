#include "framework.h"
#include "Player.h"
#include "Scene.h"
#include "Missile.h"

Player::Player(fPoint _pos)
{
	this->setPos(_pos);
	this->setScale(fPoint((float)PLAYER_SIZE_X, (float)PLAYER_SIZE_Y));
}

Player::~Player()
{

}

void Player::update()
{
	fPoint playerPos = getPos();

	if (KEYPRESSED(VK_LEFT))
	{
		playerPos.x -= (float)(PLAYER_SPEED * DT);
	}

	if (KEYPRESSED(VK_RIGHT))
	{
		playerPos.x += (float)(PLAYER_SPEED * DT);
	}

	if (KEYPRESSED(VK_UP))
	{
		playerPos.y -= (float)(PLAYER_SPEED * DT);
	}

	if (KEYPRESSED(VK_DOWN))
	{
		playerPos.y += (float)(PLAYER_SPEED * DT);
	}

	if (KEYDOWN(VK_SPACE))
	{
		// �÷��̾ space�� ���������� �̻����� �����ǰ� �ۼ�
		createMissile();
	}
	setPos(playerPos);
}

void Player::render(HDC _hDC)
{

	Rectangle(_hDC,
		(int)(getPos().x - getScale().x / 2),
		(int)(getPos().y - getScale().y / 2),
		(int)(getPos().x + getScale().x / 2),
		(int)(getPos().y + getScale().y / 2));

}

void Player::createMissile()
{
	Scene* pCurScene = CURSCENE;
	fPoint missilePos = this->getPos();
	
	Missile* missile1 = new Missile(Vec2(100, 100), missilePos);
	Missile* missile2 = new Missile(Vec2(100, -100), missilePos);
	Missile* missile3 = new Missile(Vec2(100, 0), missilePos);
	Missile* missile4 = new Missile(Vec2(0, -100), missilePos);
	Missile* missile5 = new Missile(Vec2(100, 50), missilePos);
	Missile* missile6 = new Missile(Vec2(1280- missilePos.x, 0 - missilePos.y) , missilePos);

	pCurScene->AddObject(missile1, GAMEOBJ_GROUP::MISSILE);
	pCurScene->AddObject(missile2, GAMEOBJ_GROUP::MISSILE);
	pCurScene->AddObject(missile3, GAMEOBJ_GROUP::MISSILE);
	pCurScene->AddObject(missile4, GAMEOBJ_GROUP::MISSILE);
	pCurScene->AddObject(missile5, GAMEOBJ_GROUP::MISSILE);
	pCurScene->AddObject(missile6, GAMEOBJ_GROUP::MISSILE);

}