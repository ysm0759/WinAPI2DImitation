#include "framework.h"
#include "Core.h"
#include "GameObject.h"

GameObject object;

Core::Core()
{
	// ���� ȭ���� �׸��� ���� DC �ڵ鰪 �ʱ�ȭ
	m_hDC = 0;
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

	// ������ ��ܿ� FPS ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", TimeManager::getInst()->getFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);


	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);

}

void Core::init()
{
	TimeManager::getInst()->init();

	m_hDC = GetDC(hWnd);


	// ���� ���۸��� �޸� DC�� ��Ʈ�� ����
	// �ַ� ��ǻ�� �׷��ȿ��� ���Ǵ� ���μ� ���� 
	// �޸𸮸��� ����� �̱� ���۸����� �׷����� �׸� ��� 
	// �����͸� �����ϴ� ���ȿ��� ���� �׸��� �����͸� 
	// ������ �� ���� ������ ����� �׸��� ����� �׸��� 
	// �� ��� �ʿ������� �߻��ϴ� 
	// ������, ������ ���� ��Ȳ�� ���� ���ؼ� ���Ǵ� ����̴�.
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);


	object = GameObject(fPoint(100, 100), fPoint{ 100, 100 });
}
