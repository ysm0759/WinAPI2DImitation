#include "framework.h"
#include "Animator.h"
#include "Animation.h"

Animator::Animator()
{
	m_pCurAni = nullptr;
	m_pOwner = nullptr;
}

Animator::~Animator()
{
	for (map<wstring, Animation*>::iterator iter = m_mapAni.begin(); iter != m_mapAni.end(); iter++)
	{
		if (nullptr != iter->second)
			delete iter->second;
	}
	m_mapAni.clear();
}

GameObject* Animator::getObj()
{
	return m_pOwner;
}

void Animator::update()
{
	if (nullptr != m_pCurAni)
	{
		m_pCurAni->update();
	}
}

void Animator::render(HDC _hDC)
{
	if (nullptr != m_pCurAni)
	{
		m_pCurAni->render(_hDC);
	}
}

void Animator::createAnimation(const wstring& _strName, Texture* _tex, fPoint _lt, fPoint _slice, fPoint _step, float _duration, UINT _frmCount)
{
	Animation* pAni = findAnimation(_strName);
	assert(nullptr == pAni);

	pAni = new Animation;

	pAni->setName(_strName);
	pAni->m_pAnimator = this;
	pAni->create(_tex, _lt, _slice, _step, _duration, _frmCount);

	m_mapAni.insert(make_pair(_strName, pAni));

}

Animation* Animator::findAnimation(const wstring& _strName)
{
	map<wstring, Animation*>::iterator iter = m_mapAni.find(_strName);

	if (iter == m_mapAni.end())
	{
		return nullptr;
	}
	return iter->second;
}

void Animator::play(const wstring& _strName)
{

	m_pCurAni = findAnimation(_strName);
}
