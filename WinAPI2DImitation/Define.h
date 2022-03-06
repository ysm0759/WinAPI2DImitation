#pragma once

// WINDOW ����
#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX


// Maneger ����
#define DT TimeManager::getInst()->getDT()
#define FDT TimeManager::getInst()->getFDT()

#define KEYPRESSED(VK_KEY) KeyManager::getInst()->keyPressed(VK_KEY)
#define KEYRELEASED(VK_KEY) KeyManager::getInst()->keyReleased(VK_KEY)
#define KEYDOWN(VK_KEY) KeyManager::getInst()->keyDown(VK_KEY)

#define CURSCENE SceneManager::getInst()->getCurScene()

// Object ����
// ������Ʈ �׸��� ���� ������ ���� ���� �������� �׷��� ���� ������ ��Ÿ����. 
//����� ������ 1���� ��ó�� �׸��� ������ ��� ������Ʈ���� �׷������




enum class GROUP_GAMEOBJ
{
	DEFAULT,
	PLAYER,
	MONSTER,
	MISSILE,
	SIZE,
};


enum class GROUP_SCENE
{
	START_SCENE,
	SIZE,
};

enum class TYPE_BRUSH
{
	HOLLOW,
	SIZE,
};


enum class TYPE_PEN
{
	RED,
	GREEN,
	BLUE,
	SIZE,
};


// Player ����
#define PLAYER_SPEED 1000
#define PLAYER_SIZE_X 100
#define PLAYER_SIZE_Y 100


