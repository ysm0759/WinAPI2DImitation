#include "framework.h"
#include "Collider.h"
#include "GameObject.h"

#include "SelectGDI.h"

UINT Collider::s_iID = 0;

Collider::Collider()
{
	m_pOwner = nullptr;
	m_fptOffsetPos = {};
	m_fptFinalPos = {};
	m_fptScale = {};
	m_iColCount = 0;
	m_iID = s_iID++;
}

Collider::Collider(const Collider& _other)
{
	m_pOwner = nullptr;
	m_fptOffsetPos = _other.m_fptOffsetPos;
	m_fptFinalPos = _other.m_fptFinalPos;
	m_fptScale = _other.m_fptScale;
	m_iColCount = _other.m_iColCount;
	m_iID = s_iID++;
}

Collider::~Collider()
{
}

GameObject* Collider::getObj()
{
	return m_pOwner;
}

fPoint Collider::getOffsetPos()
{
	return m_fptOffsetPos;
}

fPoint Collider::getFinalPos()
{
	return m_fptFinalPos;
}

fPoint Collider::getScale()
{
	return m_fptScale;
}

void Collider::setOffsetPos(fPoint _offsetPos)
{
	m_fptOffsetPos = _offsetPos;
}

void Collider::setFinalPos(fPoint _finalPos)
{
	m_fptFinalPos = _finalPos;
}

void Collider::setScale(fPoint _scale)
{
	m_fptScale = _scale;
}

UINT Collider::getID()
{
	return m_iID;
}

void Collider::finalUpdate()
{
	fPoint fptObjectPos = m_pOwner->getPos();
	m_fptFinalPos = fptObjectPos + m_fptOffsetPos;
}

void Collider::render(HDC _hDC)
{
	TYPE_PEN typePen;
	if (m_iColCount)
		typePen = TYPE_PEN::RED;
	else
		typePen = TYPE_PEN::GREEN;

	SelectGDI brush(_hDC, TYPE_BRUSH::HOLLOW);
	SelectGDI pen(_hDC, typePen);
	fPoint fptRenderPos = CameraManager::getInst()->getRenderPos(m_fptFinalPos);

	Rectangle(_hDC,
		(int)(fptRenderPos.x - m_fptScale.x / 2.f),
		(int)(fptRenderPos.y - m_fptScale.y / 2.f),
		(int)(fptRenderPos.x + m_fptScale.x / 2.f),
		(int)(fptRenderPos.y + m_fptScale.y / 2.f));
}

void Collider::onCollision(Collider* _pOther)
{
	m_pOwner->onCollision(_pOther);
}

void Collider::onCollisionEnter(Collider* _pOther)
{
	m_pOwner->onCollisionEnter(_pOther);
	m_iColCount++;
}

void Collider::onCollisionExit(Collider* _pOther)
{
	m_pOwner->onCollisionExit(_pOther);
	m_iColCount--;
}
