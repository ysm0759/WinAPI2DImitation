#include "framework.h"
#include "Player.h"
#include "Scene.h"
#include "Missile.h"
#include "ResourceManager.h"
#include "Texture.h"

Player::Player(fPoint _pos)
{
	m_pTex = ResourceManager::getInst()->loadTexture(L"PlayerTex", L"texture\\Player.bmp");

	this->setPos(_pos);
	this->setScale(fPoint((float)PLAYER_SIZE_X, (float)PLAYER_SIZE_Y));
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
	}

	if (KEYPRESSED(VK_RIGHT))
	{
		playerPos.x += (float)(PLAYER_SPEED * DT);
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
		// 플레이어가 space를 누를때마다 미사일이 생성되게 작성
		createMissile();
	}
	setPos(playerPos);
}

void Player::render(HDC _hDC)
{
	int width = (int)(m_pTex->getBmpWidth());
	int height = (int)(m_pTex->getBmpHeight());
	fPoint pos = getPos();


	TransparentBlt(
		_hDC,										//[in] HDC  hdcDest,		
		(int)(pos.x - (float)(width / 2)),  		//[in] int  xoriginDest,    
		(int)(pos.y - (float)(height / 2)),			//[in] int  yoriginDest,	
		width,										//[in] int  wDest,			
		height,										//[in] int  hDest,			
		m_pTex->getDC(),     						//[in] HDC  hdcSrc,
		0,											//[in] int  xoriginSrc,
		0,											//[in] int  yoriginSrc,
		width,										//[in] int  wSrc,
		height, 									//[in] int  hSrc,
		RGB(255, 0, 255)); 							//[in] UINT crTransparent
													


}

void Player::createMissile()
{
	Scene* pCurScene = CURSCENE;
	fPoint missilePos = this->getPos();
	
	//중력없는 탄
	Missile* missile1 = new Missile(Vec2(100, 100), missilePos);
	Missile* missile2 = new Missile(Vec2(100, -100), missilePos );
	Missile* missile3 = new Missile(Vec2(1280- missilePos.x, 0 - missilePos.y) , missilePos );
	
	// 중력있는탄
	Missile* missile4 = new Missile(Vec2(100, -100), missilePos,true);

	pCurScene->AddObject(missile1, GAMEOBJ_GROUP::MISSILE);
	pCurScene->AddObject(missile2, GAMEOBJ_GROUP::MISSILE);
	pCurScene->AddObject(missile3, GAMEOBJ_GROUP::MISSILE);
	pCurScene->AddObject(missile4, GAMEOBJ_GROUP::MISSILE);


}