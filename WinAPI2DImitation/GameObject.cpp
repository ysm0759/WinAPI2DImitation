#include "framework.h"
#include "GameObject.h"

GameObject::GameObject()
{
	m_fptPos = fPoint();
	m_fptScale = fPoint();
}

GameObject::GameObject(fPoint pos, fPoint scale)
{
	m_fptPos = pos;
	m_fptScale = scale;
}

GameObject::~GameObject()
{

}

void GameObject::setPos(fPoint pos)
{
	m_fptPos = pos;
}

void GameObject::setScale(fPoint scale)
{
	m_fptScale = scale;
}

fPoint GameObject::getPos()
{
	return m_fptPos;
}

fPoint GameObject::getScale()
{
	return m_fptScale;
}


// ���� �����Լ��� ������ �׳� �����Լ��� ������ ��� �غ���.
void GameObject::update()
{

}

void GameObject::render(HDC hDC)
{

}


