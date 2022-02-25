#include "framework.h"
#include "Monster.h"

Monster::Monster()
{
	this->isUp = true;
	this->velocity = 500;

}

Monster::~Monster()
{
}

void Monster::update()
{
	fPoint monsterPos = this->getPos();
	if (monsterPos.y > 600)
		isUp = true;
	else if (monsterPos.y < 100)
		isUp = false;

	float tmp = FDT;
	if (isUp == true)
		monsterPos.y -= (float)(velocity * FDT);
	else
		monsterPos.y += (float)(velocity * DT);

	this->setPos(monsterPos);
}

void Monster::render(HDC _hDC)
{

	Rectangle(_hDC,
		(int)(getPos().x - getScale().x / 2),
		(int)(getPos().y - getScale().y / 2),
		(int)(getPos().x + getScale().x / 2),
		(int)(getPos().y + getScale().y / 2));
}
