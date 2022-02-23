#include "framework.h"
#include "Player.h"


Player::Player(fPoint _pos , fPoint _scale)
{
	this->setPos(_pos);
	this->setScale(_scale);
}

Player::~Player()
{

}

void Player::update()
{
	fPoint playerPos = getPos();
	if (KeyManager::getInst()->keyPressed(VK_LEFT))
	{
		playerPos.x -= (float)(100 * TimeManager::getInst()->getDT());
	}

	if (KeyManager::getInst()->keyPressed(VK_RIGHT))
	{
		playerPos.x += (float)(100 * TimeManager::getInst()->getDT());
	}

	if (KeyManager::getInst()->keyPressed(VK_UP))
	{
		playerPos.y -= (float)(100 * TimeManager::getInst()->getDT());
	}

	if (KeyManager::getInst()->keyPressed(VK_DOWN))
	{
		playerPos.y += (float)(100 * TimeManager::getInst()->getDT());
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
