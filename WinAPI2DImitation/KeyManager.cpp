#include "framework.h"
#include "KeyManager.h"

KeyManager::KeyManager()
{
	// 키 상태를 모두 눌리지 않은 상태로 초기화
	// true면 눌린것 false 안눌린것
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
	// 현재 선택(Focus)된 윈도우가 게임 윈도우인가를 확인
	HWND curWnd = GetFocus();
	
	if (hWnd != curWnd)
	{
		// 이 과정이 없으면 폴더상태에서 키를 입력해도 app에 키가 눌린것 처럼 행동한다.
		// 윈도우가 선택(Focus)된 상태가 아닐 경우 키입력을 해제시킴
		for (int key = 0; key < VKEY_SIZE; key++)
		{
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;

		}
		return;
	}

	// 모든 키 사이즈만큼 반복하여 입력상태를 확인

	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];

		// GetAsuncKeyState : 메시지 큐에 키 입력을 받는 방식이 아닌 현재 상태의 키 입력상태를 확인
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
	//최근키가 눌렸으면서 이전키도 눌려있으면 눌린상태
	return (true == m_arrCurKey[key] && true == m_arrPrevKey[key]);
}

bool KeyManager::keyReleased(const int key)
{
	// 최근키가 안눌리고 이전키가 눌려있으면 뗀 상태
	return (false == m_arrCurKey[key] && true == m_arrPrevKey[key]);
}

bool KeyManager::keyDown(const int key)
{
	// 최근키가 눌리고 이전키가 안눌려있었으면 눌린시작점
	return (true == m_arrCurKey[key] && false == m_arrPrevKey[key]);
}

