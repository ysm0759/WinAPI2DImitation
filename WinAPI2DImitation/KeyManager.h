#pragma once
class KeyManager
{
	SINGLETON(KeyManager);

private:
	static const int VKEY_SIZE = 0xff;   //VK의 최대 갯수

	bool m_arrPrevKey[VKEY_SIZE];        // 이전 키의 입력상태
	bool m_arrCurKey[VKEY_SIZE];		 // 현재 키의 입력상태
	fPoint m_fptCurMousePos;				// 마우스 좌표

public:
	void update();
	void init();

	bool keyPressed(const int _key);      // 키가 눌려진 상태 true
	bool keyReleased(const int _key);     // 키가 내려간 순간 true
	bool keyDown(const int _key);		 // 키가 내려간 순간 true

	fPoint getMousePos();					// 마우스 좌표 얻기
};

