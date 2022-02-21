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

void GameObject::SetPos(fPoint pos)
{
	m_fptPos = pos;
}

void GameObject::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

fPoint GameObject::GetPos()
{
	return m_fptPos;
}

fPoint GameObject::GetScale()
{
	return m_fptScale;
}
