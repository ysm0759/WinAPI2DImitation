#pragma once
class PathManager
{
	SINGLETON(PathManager);


private:
	WCHAR m_strContentPath[255]; //������ �ִ� ��� 255

public:
	void init();
	const wchar_t* getContentPath(); // ���ҽ� ���� ������ ��� ��ȯ
};

