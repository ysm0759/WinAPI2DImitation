#include "framework.h"
#include "Core.h"
#include "GameObject.h"

Core::Core()
{
	// ���� ȭ���� �׸��� ���� DC �ڵ鰪 �ʱ�ȭ
	m_hDC = 0 ;
	m_hMemDC = 0 ;
	m_hBMP = 0;
}

Core::~Core()
{
	// ���� �ھ� ���� ������ DC �ڵ鰪 �ݳ�
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
	//��� �׷��ֱ�
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	SceneManager::getInst()->render(m_hMemDC);



	// ������ ��ܿ� FPS ǥ��
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
	// TODO: ���⿡ return ���� �����մϴ�.
}

HDC Core::getMemDC()
{
	return m_hMemDC;
}
