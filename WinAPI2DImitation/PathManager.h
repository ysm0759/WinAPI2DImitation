#pragma once
class PathManager
{
	SINGLETON(PathManager);


private:
	WCHAR m_strContentPath[255]; //윈도우 최대 경로 255

public:
	void init();
	const wchar_t* getContentPath(); // 리소스 저장 폴더의 경로 반환
};

