#include "framework.h"
#include "GameObject.h"
#include "Collider.h"
#include "Animator.h"

GameObject::GameObject()
{
	m_fptPos = fPoint();
	m_fptScale = fPoint();
	m_pCollider = nullptr;
	m_bAlive = true;
}

GameObject::GameObject(fPoint pos, fPoint scale)
{
	m_fptPos = pos;
	m_fptScale = scale;
	m_pCollider = nullptr;
	m_bAlive = true;
}

GameObject::~GameObject()
{
	if (nullptr != m_pCollider)
		delete m_pCollider;
	
	if (nullptr != m_pAnimator)
		delete m_pAnimator;
}

void GameObject::setPos(fPoint pos)
{
	m_fptPos = pos;
}

void GameObject::setScale(fPoint scale)
{
	m_fptScale = scale;
}

void GameObject::setID(UINT _ID)
{
	this->m_ID = _ID;
}

fPoint GameObject::getPos()
{
	return m_fptPos;
}

fPoint GameObject::getScale()
{
	return m_fptScale;
}

UINT GameObject::getID()
{
	return m_ID;
}

void GameObject::setDead()
{
	m_bAlive = false;
}

// 순수 가상함수로 만들지 그냥 가상함수로 만들지 고민 해보자.
void GameObject::update()
{

}

void GameObject::finalUpdate()
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->finalUpdate();
	}
}

void GameObject::render(HDC _hDC)
{
}

void GameObject::componentRender(HDC _hDC)
{
	if (nullptr != m_pCollider)
		m_pCollider->render(_hDC);
	
	if (nullptr != m_pAnimator)
		m_pAnimator->render(_hDC);
}

Collider* GameObject::getCollider()
{
	return m_pCollider;
}

void GameObject::createCollider()
{
	m_pCollider = new Collider();
	m_pCollider->m_pOwner = this;
}

bool GameObject::isDead()
{
	
	return !m_bAlive;
}


Animator* GameObject::getAnimator()
{
	return m_pAnimator;
}

void GameObject::createAnimator()
{
	m_pAnimator = new Animator;
	m_pAnimator->m_pOwner = this;
}
