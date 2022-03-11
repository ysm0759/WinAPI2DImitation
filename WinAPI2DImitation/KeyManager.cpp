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

	// Mouse 좌표 계산
	POINT ptPos = {};
	// GetCursorPos() 윈도우에서 모니터 좌상단 기준 마우스의 좌표를 반환
	GetCursorPos(&ptPos);
	// 모니터 좌상단 기준 마우스 좌표를 게임 윈도우 기준 마우스 위치로 계산
	ScreenToClient(hWnd, &ptPos);



	m_fptCurMousePos = fPoint((float)ptPos.x, (float)ptPos.y);

	if (KEYDOWN(VK_LBUTTON))
	{
		char charTmp[17];
		wchar_t tmp[17];
		wchar_t mouseInfo[40] = {};

		_gcvt_s(charTmp, sizeof(charTmp), ptPos.x, 8);
		mbstowcs_s(NULL, tmp, sizeof(tmp) / 2, charTmp, sizeof(charTmp));

		wcscat_s(mouseInfo, L"Mouse.X : ");
		wcscat_s(mouseInfo, tmp);
		wcscat_s(mouseInfo, L"\t");

		_gcvt_s(charTmp, sizeof(charTmp), ptPos.y, 8);
		mbstowcs_s(NULL, tmp, sizeof(tmp) / 2, charTmp, sizeof(charTmp));

		wcscat_s(mouseInfo, L"Mouse.Y : ");
		wcscat_s(mouseInfo, tmp);

		Logger::info(mouseInfo);
	}
}

void KeyManager::init()
{

}


bool KeyManager::keyPressed(const int _key)
{
	//최근키가 눌렸으면서 이전키도 눌려있으면 눌린상태
	return (true == m_arrCurKey[_key] && true == m_arrPrevKey[_key]);
}

bool KeyManager::keyReleased(const int _key)
{
	// 최근키가 안눌리고 이전키가 눌려있으면 뗀 상태
	return (false == m_arrCurKey[_key] && true == m_arrPrevKey[_key]);
}

bool KeyManager::keyDown(const int _key)
{
	// 최근키가 눌리고 이전키가 안눌려있었으면 눌린시작점
	return (true == m_arrCurKey[_key] && false == m_arrPrevKey[_key]);
}


fPoint KeyManager::getMousePos()
{
	return m_fptCurMousePos;
}

