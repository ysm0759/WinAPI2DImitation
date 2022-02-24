

// WINDOW ����
#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX


// Maneger ����
#define DT TimeManager::getInst()->getDT()
#define KEYPRESSED(VK_KEY) KeyManager::getInst()->keyPressed(VK_KEY)
#define KEYRELEASED(VK_KEY) KeyManager::getInst()->keyReleased(VK_KEY)
#define KEYDOWN(VK_KEY) KeyManager::getInst()->keyDown(VK_KEY)


// Object ����
// ������Ʈ �׸��� ���� ������ ���� ���� �������� �׷��� ���� ������ ��Ÿ����. 
//����� ������ 1���� ��ó�� �׸��� ������ ��� ������Ʈ���� �׷������
enum class GAMEOBJ_GROUP
{
	DEFAULT,
	PLAYER,
	MONSTER,
	SIZE,
};


// Player ����
#define PLAYER_SPEED 1000
#define PLAYER_SIZE_X 100
#define PLAYER_SIZE_Y 100



//Scene ����
enum class SCENE_GROUP
{
	START_SCENE,
	STAGE1,
	STAGE2,
	SIZE,
};