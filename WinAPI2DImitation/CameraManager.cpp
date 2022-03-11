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

	// 화면 중앙과 카메라 LookAt 좌표 사이의 차이 계산
	CalDiff();
}

void CameraManager::setLookAt(fPoint _lookAt)
{

	m_fptLookAt = _lookAt;
	float fMoveDist = (m_fptLookAt - m_fptPrevLookAt).Length();
	m_fAccel = fMoveDist / m_fTime;		// 등가속도 계산
	m_fAccel *= m_fAccDir;

	if (m_fAccDir < 0) // 초기 속도 세팅
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
	// 렌더링 좌표에서 차이값만큼 더해주면 절대 좌표가 나옴.
	return _renderPos + m_fptDiff;
}


void CameraManager::CalDiff()
{
	m_fAccTime += FDT;

	fVec2 fvLookDir = m_fptLookAt - m_fptPrevLookAt;

	// 시간이 지났거나 방향 벡터의 크기가 0이라면, 도착한것으로 간주. 속도를 0으로
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

	// 등가속도만큼 이전속도에 더해줌.
	m_fSpeed = m_fPreSpeed += m_fAccel * FDT;
}