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

	fPoint pos = object.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		pos.x -= 20;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		pos.x += 20;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		pos.y -= 20;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		pos.y += 20;
	}

	object.SetPos(pos);
}

void Core::render()
{
	Rectangle(m_hDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);
	hWnd;
	Rectangle(m_hDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2);

	//BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);

	// 오른쪽 상단에 FPS 표시
	

}

void Core::init()
{


	m_hDC = GetDC(hWnd);

	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	object = GameObject(fPoint(100, 100), fPoint{ 100, 100 });
}
