#include "framework.h"
#include "Missile.h"



Missile::Missile()
{
	this->m_fVelocity = 0;
	this->m_fvDir = Vec2(0.f, 0.f);
	this->setPos(fPoint(0.f, 0.f));
	this->setScale(fPoint(0.f, 0.f));

}

Missile::Missile(Vec2 _vec2, fPoint _pos)
{

	this->m_fVelocity = 200;
	this->m_fvDir = _vec2;
	this->setPos(_pos);

	this->setScale(fPoint(25.f, 25.f));
}

Missile::~Missile()
{
}

void Missile::update()
{
	fPoint missilePos = this->getPos();
	// ������ �������ְ� �׹������� źȯ�� ������
	// ���� ���� ������ �ִ�.
	// �밢��źȯ�� ���� źȯ�� �ӵ��� �ٸ��ٴ°�
	// �̸� �ذ��ϱ����� ����ȭ ���־�� �Ѵ�. (nomalize)

  	missilePos.x += m_fvDir.normalize().x * m_fVelocity * FDT;
	missilePos.y += m_fvDir.normalize().y * m_fVelocity * FDT;

	setPos(missilePos);
}

void Missile::render(HDC _hDC)
{


	Ellipse(_hDC,
		(int)(getPos().x - getScale().x / 2.f),
		(int)(getPos().y - getScale().y / 2.f),
		(int)(getPos().x + getScale().x / 2.f),
		(int)(getPos().y + getScale().y / 2.f));

}
