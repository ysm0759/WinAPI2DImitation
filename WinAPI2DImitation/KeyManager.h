#pragma once
class KeyManager
{
	SINGLETON(KeyManager);

private:
	static const int VKEY_SIZE = 0xff;   //VK�� �ִ� ����

	bool m_arrPrevKey[VKEY_SIZE];        // ���� Ű�� �Է»���
	bool m_arrCurKey[VKEY_SIZE];		 // ���� Ű�� �Է»���
	fPoint m_fptCurMousePos;				// ���콺 ��ǥ

public:
	void update();
	void init();

	bool keyPressed(const int _key);      // Ű�� ������ ���� true
	bool keyReleased(const int _key);     // Ű�� ������ ���� true
	bool keyDown(const int _key);		 // Ű�� ������ ���� true

	fPoint getMousePos();					// ���콺 ��ǥ ���
};

