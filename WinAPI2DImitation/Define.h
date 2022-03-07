#pragma once

// WINDOW 관련
#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX


// Maneger 관련
#define		   			 DT		TimeManager::getInst()->getDT()
#define					FDT		TimeManager::getInst()->getFDT()

#define  KEYPRESSED(VK_KEY)		KeyManager::getInst()->keyPressed(VK_KEY)
#define KEYRELEASED(VK_KEY)		KeyManager::getInst()->keyReleased(VK_KEY)
#define		KEYDOWN(VK_KEY)		KeyManager::getInst()->keyDown(VK_KEY)

#define				CURSCENE	SceneManager::getInst()->getCurScene()

#define CREATEOBJ(pObj, group)	EventManager::getInst()->eventCreateObject(pObj, group)
#define DELETEOBJ(pObj)			EventManager::getInst()->eventDeleteObject(pObj)
#define CHANGESCN(scene)		EventManager::getInst()->eventChangeScene(scene)



// Object 관련
// 오브젝트 그리는 순서 순위가 낮을 수록 마지막에 그려져 가장 맨위에 나타난다. 
//배경은 순위가 1위로 맨처음 그리고 그위에 모든 오브젝트들을 그려줘야함




enum class GROUP_GAMEOBJ
{
	DEFAULT,
	PLAYER,
	MONSTER,
	MISSILE_PLAYER,
	SIZE,
};

class ID
{
	int _objID;
public:

	ID( UINT _objID)
	{
		_objID = (UINT)_objID;
	}

	enum class PLAYER //10000
	{
		DEFAULT = 10000,
	};

	enum class MONSTER // 20000
	{
		DEFAULT = 20000,
	};

	enum class TILE  // 30000
	{

		DEFAULT = 30000,
	};

	enum class MISSILE //40000
	{
		DEFAULT = 40000,
		MISSILE_PLAYER
	};
};



enum class GROUP_SCENE
{
	TOOL_SCENE,
	START_SCENE,
	STAGE_01,
	STAGE_02,
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

enum class TYPE_EVENT
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	CHANGE_SCENE,
	SIZE,
};


// Player 관련
#define PLAYER_SPEED 1000
#define PLAYER_SIZE_X 100
#define PLAYER_SIZE_Y 100


