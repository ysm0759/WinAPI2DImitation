#include "framework.h"
#include "CameraManager.h"
#include "GameObject.h"

CameraManager::CameraManager()
{
	m_fptLookAt = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);
	m_fptCurLookAt = m_fptLookAt;
	m_fptPrevLookAt = m_fptLookAt;
	m_pTargetObj = nullptr;
	m_fAccTime = m_fTime;
	m_fSpeed = 0;
	m_fPreSpeed = m_fSpeed;
	m_fAccel = 0;
}

CameraManager::~CameraManager()
{

}

void CameraManager::update()
{
	if (m_pTargetObj)
	{
		if (m_pTargetObj->isDead())
		{
			m_pTargetObj = nullptr;
		}
		else
		{
			setLookAt(m_pTargetObj->getPos());
		}
	}

	// ȭ�� �߾Ӱ� ī�޶� LookAt ��ǥ ������ ���� ���
	CalDiff();
}

void CameraManager::setLookAt(fPoint _lookAt)
{

	m_fptLookAt = _lookAt;
	float fMoveDist = (m_fptLookAt - m_fptPrevLookAt).Length();
	m_fAccel = fMoveDist / m_fTime;		// ��ӵ� ���
	m_fAccel *= m_fAccDir;

	if (m_fAccDir < 0) // �ʱ� �ӵ� ����
	{
		m_fSpeed = fMoveDist;
	}
	else
	{
		m_fSpeed = 500.f;
	}
	m_fAccTime = 0.f;
}

void CameraManager::setTargetObj(GameObject* _target)
{
	m_pTargetObj = _target;
}

fPoint CameraManager::getLookAt()
{
	return m_fptCurLookAt;
}

fPoint CameraManager::getRenderPos(fPoint _objPos)
{
	return _objPos - m_fptDiff;
}

fPoint CameraManager::getRealPos(fPoint _renderPos)
{	
	// ������ ��ǥ���� ���̰���ŭ �����ָ� ���� ��ǥ�� ����.
	return _renderPos + m_fptDiff;
}


void CameraManager::CalDiff()
{
	m_fAccTime += FDT;

	fVec2 fvLookDir = m_fptLookAt - m_fptPrevLookAt;

	// �ð��� �����ų� ���� ������ ũ�Ⱑ 0�̶��, �����Ѱ����� ����. �ӵ��� 0����
	if (m_fTime <= m_fAccTime || fvLookDir.Length() < 1)
	{
		m_fptCurLookAt = m_fptLookAt;
		m_fSpeed = 0.f;
	}
	else
	{
		m_fptCurLookAt = m_fptPrevLookAt + fvLookDir.normalize() * m_fSpeed * FDT;

	}

	fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);

	m_fptDiff = m_fptCurLookAt - fptCenter;
	m_fptPrevLookAt = m_fptCurLookAt;
	m_fPreSpeed = m_fSpeed;

	// ��ӵ���ŭ �����ӵ��� ������.
	m_fSpeed = m_fPreSpeed += m_fAccel * FDT;
}