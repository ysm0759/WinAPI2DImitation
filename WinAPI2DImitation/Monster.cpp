#include "framework.h"
#include "Monster.h"
#include "Collider.h"
Monster::Monster()
{
	this->isUp = true;
	this->velocity = 500;
	this->setID((UINT)ID::MONSTER::DEFAULT);
	createCollider();
	getCollider()->setScale(fPoint(90.f, 90.f));
}

Monster::~Monster()
{
}

Monster* Monster::clone()
{
	return new Monster(*this);
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

	fPoint fptRenderPos = CameraManager::getInst()->getRenderPos(getPos());
	Rectangle(_hDC,
		(int)(fptRenderPos.x - getScale().x / 2),
		(int)(fptRenderPos.y - getScale().y / 2),
		(int)(fptRenderPos.x + getScale().x / 2),
		(int)(fptRenderPos.y + getScale().y / 2));

	componentRender(_hDC);
}
