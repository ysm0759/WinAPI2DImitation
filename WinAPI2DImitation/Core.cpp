#include "framework.h"
#include "Core.h"
#include "GameObject.h"

Player player(fPoint(100.f, 100.f), fPoint(100.f, 100.f));

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
	KeyManager::getInst()->update();
	

	player.update();
	//monster.update();
	//monster.update();
	//monster.update();
	//monster.update();
	//monster.update();
	//missile.update();
	//missile.update();
	//missile.update();
	//missile.update();
	//missile.update();

	//���� ���� ��������ϸ� �ھ �δ��� ũ�� 
	//�װ� �ذ��ϱ� ���ؼ� scene�� �ΰ� scene manager�� �����ؾ��Ѵ�.
	
}

void Core::render()
{
	//��� �׷��ֱ�
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);



	player.render(m_hMemDC);
	//monster.render();
	//monster.render();
	//monster.render();
	//monster.render();
	//monster.render();
	//missile.render();
	//missile.render();
	//missile.render();
	//missile.render();
	//missile.render();
	//���� ���� ��������ϸ� �ھ �δ��� ũ�� 
	//�װ� �ذ��ϱ� ���ؼ� scene�� �ΰ� scene manager�� �����ؾ��Ѵ�.
	
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


}
