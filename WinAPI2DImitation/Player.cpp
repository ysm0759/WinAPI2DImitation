#include "framework.h"
#include "Player.h"


Player::Player(fPoint _pos )
{
	this->setPos(_pos);
	this->setScale(fPoint( (float)PLAYER_SIZE_X , (float)PLAYER_SIZE_Y ) );
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

	if (KEYRELEASED(VK_UP))
	{
		playerPos.y -= (float)(PLAYER_SPEED * DT);
	}

	if (KEYDOWN(VK_DOWN))
	{
		playerPos.y += (float)(PLAYER_SPEED * DT);
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
