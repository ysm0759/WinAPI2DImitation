#pragma once

// WINDOW 관련
#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX


// Maneger 관련
#define DT TimeManager::getInst()->getDT()
#define FDT TimeManager::getInst()->getFDT()

#define KEYPRESSED(VK_KEY) KeyManager::getInst()->keyPressed(VK_KEY)
#define KEYRELEASED(VK_KEY) KeyManager::getInst()->keyReleased(VK_KEY)
#define KEYDOWN(VK_KEY) KeyManager::getInst()->keyDown(VK_KEY)

#define CURSCENE SceneManager::getInst()->getCurScene()

// Object 관련
// 오브젝트 그리는 순서 순위가 낮을 수록 마지막에 그려져 가장 맨위에 나타난다. 
//배경은 순위가 1위로 맨처음 그리고 그위에 모든 오브젝트들을 그려줘야함




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


// Player 관련
#define PLAYER_SPEED 1000
#define PLAYER_SIZE_X 100
#define PLAYER_SIZE_Y 100


