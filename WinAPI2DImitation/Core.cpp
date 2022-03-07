#include "framework.h"
#include "Core.h"
#include "GameObject.h"

Core::Core()
{
	// 게임 화면을 그리기 위한 DC 핸들값 초기화
	m_hDC = 0 ;
	m_hMemDC = 0 ;
	m_hBMP = 0;
	m_arrPen[0] = 0;
	m_arrBrush[0] = 0;
}

Core::~Core()
{
	// 게임 코어 종료 시점에 DC 핸들값 반납
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);

	for (int i = 0; i < (int)TYPE_PEN::SIZE; i++)
	{
		DeleteObject(m_arrPen[i]);
	}
}

void Core::update()
{
	// 이전 update에서 추가된 이벤트를 프레임 초기에 한꺼번에 처리
	EventManager::getInst()->update();

	TimeManager::getInst()->update();
	KeyManager::getInst()->update();
	SceneManager::getInst()->update();
	CollisionManager::getInst()->update();
	
}

void Core::render()
{
	//배경 그려주기
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	SceneManager::getInst()->render(m_hMemDC);



	// 오른쪽 상단에 FPS 표시
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", TimeManager::getInst()->getFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);

}

void Core::init()
{
	// GDI
	createBrushPen();

	PathManager::getInst()->init();
	TimeManager::getInst()->init();
	KeyManager::getInst()->init();
	SceneManager::getInst()->init();
	CollisionManager::getInst()->init();

	m_hDC = GetDC(hWnd);


	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);


}

HDC Core::getMainDC()
{

	return this->m_hDC;
	// TODO: 여기에 return 문을 삽입합니다.
}

HDC Core::getMemDC()
{
	return m_hMemDC;
}


void Core::createBrushPen()
{
	// brush
	m_arrBrush[(int)TYPE_BRUSH::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	// pen
	m_arrPen[(int)TYPE_PEN::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(int)TYPE_PEN::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(int)TYPE_PEN::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}

HBRUSH Core::getBrush(TYPE_BRUSH _type)
{
	return m_arrBrush[(int)_type];
}

HPEN Core::getPen(TYPE_PEN _type)
{
	return m_arrPen[(int)_type];
}
