#include "framework.h"
#include "Core.h"
#include "GameObject.h"

Core::Core()
{
	// 게임 화면을 그리기 위한 DC 핸들값 초기화
	m_hDC = 0 ;
	m_hMemDC = 0 ;
	m_hBMP = 0;
}

Core::~Core()
{
	// 게임 코어 종료 시점에 DC 핸들값 반납
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

void Core::update()
{
	TimeManager::getInst()->update();
	KeyManager::getInst()->update();
	SceneManager::getInst()->update();

	
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
	TimeManager::getInst()->init();
	KeyManager::getInst()->init();
	SceneManager::getInst()->init();
	PathManager::getInst()->init();

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
