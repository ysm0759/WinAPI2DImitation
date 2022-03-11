#include "framework.h"
#include "Animation.h"
#include "Animator.h"
#include "GameObject.h"
#include "Texture.h"
Animation::Animation()
{
    m_strName = L"";
    m_pAnimator = nullptr;
    m_pTex = nullptr;
    m_iCurFrm = 0;
    m_fAccTime = 0;
}

Animation::~Animation()
{
}

void Animation::setName(const wstring& _strName)
{
    this->m_strName = _strName;
}

const wstring& Animation::getName()
{
    return m_strName;
}

void Animation::setFrame(int _frmIndex)
{
    m_iCurFrm = _frmIndex;
}

AniFrm& Animation::getFrame(int _frmIndex)
{
    return m_vecFrm[_frmIndex];
}

void Animation::update()
{
    m_fAccTime += FDT;

    if (m_vecFrm[m_iCurFrm].fDuration < m_fAccTime)
    {
        m_iCurFrm++;
        m_iCurFrm %= m_vecFrm.size();
        m_fAccTime -= m_vecFrm[m_iCurFrm].fDuration;
    }
}

void Animation::render(HDC hDC)
{
    GameObject* pObj = m_pAnimator->getObj();
    fPoint fptPos = pObj->getPos();
    AniFrm frm = m_vecFrm[m_iCurFrm];

    fptPos = fptPos + frm.fptOffset;
    fptPos = CameraManager::getInst()->getRenderPos(fptPos);
    TransparentBlt(hDC,
        (int)(fptPos.x - frm.fptSlice.x / 2.f),
        (int)(fptPos.y - frm.fptSlice.y / 2.f),
        (int)(frm.fptSlice.x),
        (int)(frm.fptSlice.y),
        m_pTex->getDC(),
        (int)(frm.fptLT.x),
        (int)(frm.fptLT.y),
        (int)(frm.fptSlice.x),
        (int)(frm.fptSlice.y),
        RGB(255, 0, 255));
}

void Animation::create(Texture* _tex,            // 애니메이션의 이미지
                       fPoint _lt,               // 애니메이션 시작 프레임의 좌상단 좌표
                       fPoint _slice,            // 애니메이션 프레임의 크기
                       fPoint _step,             // 애니메이션 프레임의 반복 위치
                       float _duration,          // 애니메이션 프레임 지속시간
                       UINT _frmCount)           // 애니메이션 프레임 갯수
                        
{
    m_pTex = _tex;

    AniFrm frm = {};
    for (UINT i = 0; i < _frmCount; i++)
    {
        frm.fDuration = _duration;
        frm.fptSlice = _slice;
        frm.fptLT = _lt + _step * i;
        m_vecFrm.push_back(frm);
    }

}
