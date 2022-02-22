#include "framework.h"
#include "Core.h"
#include "GameObject.h"

GameObject object;

Core::Core()
{
	// 게임 화면을 그리기 위한 DC 핸들값 초기화
	m_hDC = 0;
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

	fPoint pos = object.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		pos.x -= 100 * TimeManager::getInst()->getDT();
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		pos.x += 100 * TimeManager::getInst()->getDT();
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		pos.y -= 100 * TimeManager::getInst()->getDT();
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		pos.y += 100 * TimeManager::getInst()->getDT();
	}

	object.SetPos(pos);
}

void Core::render()
{
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);
	hWnd;
	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2);

	// 오른쪽 상단에 FPS 표시
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", TimeManager::getInst()->getFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);


	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);

}

void Core::init()
{
	TimeManager::getInst()->init();

	m_hDC = GetDC(hWnd);


	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	// 주로 컴퓨터 그래픽에서 사용되는 용어로서 비디오 
	// 메모리만을 사용한 싱글 버퍼링으로 그래픽을 그릴 경우 
	// 데이터를 저장하는 동안에는 다음 그림의 데이터를 
	// 전송할 수 없기 때문에 지우고 그리고 지우고 그리고 
	// 할 경우 필연적으로 발생하는 
	// 깜빡임, 찢어짐 등의 상황을 막기 위해서 사용되는 기법이다.
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);


	object = GameObject(fPoint(100, 100), fPoint{ 100, 100 });
}
