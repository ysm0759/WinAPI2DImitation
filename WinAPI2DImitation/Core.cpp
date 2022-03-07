#include "framework.h"
#include "Core.h"
#include "GameObject.h"

Core::Core()
{
	// ���� ȭ���� �׸��� ���� DC �ڵ鰪 �ʱ�ȭ
	m_hDC = 0 ;
	m_hMemDC = 0 ;
	m_hBMP = 0;
	m_arrPen[0] = 0;
	m_arrBrush[0] = 0;
}

Core::~Core()
{
	// ���� �ھ� ���� ������ DC �ڵ鰪 �ݳ�
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
	// ���� update���� �߰��� �̺�Ʈ�� ������ �ʱ⿡ �Ѳ����� ó��
	EventManager::getInst()->update();

	TimeManager::getInst()->update();
	KeyManager::getInst()->update();
	SceneManager::getInst()->update();
	CollisionManager::getInst()->update();
	
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
	// TODO: ���⿡ return ���� �����մϴ�.
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
