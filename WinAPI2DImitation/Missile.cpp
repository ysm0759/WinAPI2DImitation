#include "framework.h"
#include "Missile.h"
#include "Collider.h"


Missile* Missile::clone()
{
	return new Missile(*this);
}

Missile::Missile()
{
	this->m_fVelocity = 0;
	this->m_fvDir = fVec2(0.f, 0.f);
	this->m_bIsGravity = false;
	this->m_fGravity = 0;
	this->setPos(fPoint(0.f, 0.f));
	this->setScale(fPoint(0.f, 0.f));
	this->setID((UINT)ID::MISSILE::MISSILE_PLAYER);
	createCollider();
	getCollider()->setScale(fPoint(23.f, 23.f));
}

Missile::Missile(fVec2 _vec2, fPoint _pos, bool _isGravity)
{

	this->m_fVelocity = 200;
	this->m_fvDir = _vec2;
	this->m_bIsGravity = _isGravity;
	this->m_fGravity = 0;
	this->setPos(_pos);
	this->setScale(fPoint(25.f, 25.f));

	createCollider();
	getCollider()->setScale(fPoint(23.f, 23.f));
}

Missile::~Missile()
{
}

void Missile::update()
{
	fPoint missilePos = this->getPos();
	if (false == m_bIsGravity)
	{
		// ���߷�ź
		// ������ �������ְ� �׹������� źȯ�� ������
		// ���� ���� ������ �ִ�.
		// �밢��źȯ�� ���� źȯ�� �ӵ��� �ٸ��ٴ°�
		// �̸� �ذ��ϱ����� ����ȭ ���־�� �Ѵ�. (nomalize)

		missilePos.x += m_fvDir.normalize().x * m_fVelocity * FDT;
		missilePos.y += m_fvDir.normalize().y * m_fVelocity * FDT;
	}
	else
	{
		// �߷� ź
		// gravitiy�� �����ϰ� �� gravity �ð��� ���� ���� ���ϴ� ���� �������� 
		// �Ʒ������� �������µ��� ȿ���� �� �� �ִ�.
		missilePos.x += m_fvDir.normalize().x * m_fVelocity * FDT;
		missilePos.y += m_fvDir.normalize().y * m_fVelocity * FDT;
		missilePos.y += m_fGravity * FDT;
		if (m_fGravity <= 2000)
			m_fGravity += 100 * FDT;
	}
	setPos(missilePos);
}

void Missile::render(HDC _hDC)
{

	if (false == m_bIsGravity) // ���߷�ź�� ���׶��
	{
		Ellipse(_hDC,
			(int)(getPos().x - getScale().x / 2.f),
			(int)(getPos().y - getScale().y / 2.f),
			(int)(getPos().x + getScale().x / 2.f),
			(int)(getPos().y + getScale().y / 2.f));
	}
	else //�߷�ź�� �׸�
	{
		Rectangle(_hDC,
			(int)(getPos().x - getScale().x / 2.f),
			(int)(getPos().y - getScale().y / 2.f),
			(int)(getPos().x + getScale().x / 2.f),
			(int)(getPos().y + getScale().y / 2.f));
	}
	
	
	componentRender(_hDC);
}


void Missile::onCollisionEnter(Collider* _pOther)
{
	GameObject* pOtherObj = _pOther->getObj();
	if (pOtherObj->getID() == (UINT)ID::MONSTER::DEFAULT)
	{
		DELETEOBJ(this);
	}
}
