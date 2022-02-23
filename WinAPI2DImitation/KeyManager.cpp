#include "framework.h"
#include "KeyManager.h"

KeyManager::KeyManager()
{
	// Ű ���¸� ��� ������ ���� ���·� �ʱ�ȭ
	// true�� ������ false �ȴ�����
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = false;
		m_arrCurKey[key] = false;
	}
}

KeyManager::~KeyManager()
{

}


void KeyManager::update()
{
	// ���� ����(Focus)�� �����찡 ���� �������ΰ��� Ȯ��
	HWND curWnd = GetFocus();
	
	if (hWnd != curWnd)
	{
		// �� ������ ������ �������¿��� Ű�� �Է��ص� app�� Ű�� ������ ó�� �ൿ�Ѵ�.
		// �����찡 ����(Focus)�� ���°� �ƴ� ��� Ű�Է��� ������Ŵ
		for (int key = 0; key < VKEY_SIZE; key++)
		{
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;

		}
		return;
	}

	// ��� Ű �����ŭ �ݺ��Ͽ� �Է»��¸� Ȯ��

	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];

		// GetAsuncKeyState : �޽��� ť�� Ű �Է��� �޴� ����� �ƴ� ���� ������ Ű �Է»��¸� Ȯ��
		if (GetAsyncKeyState(key) & 0x8000)
			m_arrCurKey[key] = true;		
		else
			m_arrCurKey[key] = false;
	}

}

void KeyManager::init()
{

}


bool KeyManager::keyPressed(const int key)
{
	//�ֱ�Ű�� �������鼭 ����Ű�� ���������� ��������
	return (true == m_arrCurKey[key] && true == m_arrPrevKey[key]);
}

bool KeyManager::keyReleased(const int key)
{
	// �ֱ�Ű�� �ȴ����� ����Ű�� ���������� �� ����
	return (false == m_arrCurKey[key] && true == m_arrPrevKey[key]);
}

bool KeyManager::keyDown(const int key)
{
	// �ֱ�Ű�� ������ ����Ű�� �ȴ����־����� ����������
	return (true == m_arrCurKey[key] && false == m_arrPrevKey[key]);
}

