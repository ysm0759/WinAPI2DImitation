#include "framework.h"
#include "Player.h"
#include "Scene.h"
#include "Missile.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Player::Player(fPoint _pos)
{
	m_pTex = ResourceManager::getInst()->loadTexture(L"PlayerTex", L"texture\\Animation_Player.bmp");

	this->setPos(_pos);
	this->setScale(fPoint((float)PLAYER_SIZE_X, (float)PLAYER_SIZE_Y));
	this->setID((UINT)ID::PLAYER::DEFAULT);
	createCollider();
	getCollider()->setScale(fPoint(40.f, 40.f));
	getCollider()->setOffsetPos(fPoint(0.f, 10.f));

	createAnimator();
	getAnimator()->createAnimation(L"LeftNone", m_pTex, fPoint(0.f, 0.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.5f, 2);
	getAnimator()->createAnimation(L"RightNone", m_pTex, fPoint(0.f, 70.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.5f, 2);
	getAnimator()->createAnimation(L"LeftMove", m_pTex, fPoint(0.f, 140.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 3);
	getAnimator()->createAnimation(L"RightMove", m_pTex, fPoint(0.f, 210.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 3);
	getAnimator()->createAnimation(L"LeftHit", m_pTex, fPoint(140.f, 0.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 1);
	getAnimator()->createAnimation(L"RightHit", m_pTex, fPoint(140.f, 70.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 1);
	getAnimator()->play(L"LeftNone");

	Animation* pAni;
	pAni = getAnimator()->findAnimation(L"LeftMove");
	pAni->getFrame(1).fptOffset = fPoint(0.f, -20.f);
	pAni = getAnimator()->findAnimation(L"RightMove");
	pAni->getFrame(1).fptOffset = fPoint(0.f, -20.f);
}

Player::~Player()
{

}
void Player::update()
{
	fPoint playerPos = getPos();

	if (KEYPRESSED(VK_LEFT))
	{
		playerPos.x -= (float)(PLAYER_SPEED * DT);
		getAnimator()->play(L"LeftMove");
	}

	if (KEYPRESSED(VK_RIGHT))
	{
		playerPos.x += (float)(PLAYER_SPEED * DT);
		getAnimator()->play(L"RightMove");
	}

	if (KEYPRESSED(VK_UP))
	{
		playerPos.y -= (float)(PLAYER_SPEED * DT);
	}

	if (KEYPRESSED(VK_DOWN))
	{
		playerPos.y += (float)(PLAYER_SPEED * DT);
	}

	if (KEYDOWN(VK_SPACE))
	{
		// ?????????? space?? ?????????? ???????? ???????? ????
		createMissile();
		getAnimator()->play(L"LeftHit");
	}
	setPos(playerPos);
	if (KEYDOWN(VK_RBUTTON))
	{

		fPoint fptLookAt = CameraManager::getInst()->getRealPos(this->getPos());
		CameraManager::getInst()->setTargetObj(this);
	}
	getAnimator()->update();
}

void Player::render(HDC _hDC)
{


	//TransparentBlt(
	//	_hDC,										//[in] HDC  hdcDest,		
	//	(int)(pos.x - (float)(width / 2)),  		//[in] int  xoriginDest,    
	//	(int)(pos.y - (float)(height / 2)),			//[in] int  yoriginDest,	
	//	width,										//[in] int  wDest,			
	//	height,										//[in] int  hDest,			
	//	m_pTex->getDC(),     						//[in] HDC  hdcSrc,
	//	0,											//[in] int  xoriginSrc,
	//	0,											//[in] int  yoriginSrc,
	//	width,										//[in] int  wSrc,
	//	height, 									//[in] int  hSrc,
	//	RGB(255, 0, 255)); 							//[in] UINT crTransparent
													

	componentRender(_hDC);

}

void Player::createMissile()
{
	Scene* pCurScene = CURSCENE;
	fPoint missilePos = this->getPos();
	
	//???????? ??
	Missile* missile1 = new Missile(fVec2(100, 100), missilePos);
	// ??????????
	Missile* missile2 = new Missile(fVec2(100, -100), missilePos,true);

	CREATEOBJ(missile1, GROUP_GAMEOBJ::MISSILE_PLAYER);
	CREATEOBJ(missile2, GROUP_GAMEOBJ::MISSILE_PLAYER);

}


Player* Player::clone()
{
	return new Player(*this);
}