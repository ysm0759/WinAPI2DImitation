#include "framework.h"
#include "PathManager.h"


PathManager::PathManager()
{
	m_strContentPath[0] = {};
}

PathManager::~PathManager()
{

}

void PathManager::init()
{
	GetCurrentDirectory(255, m_strContentPath);

	int strLen = (int)wcslen(m_strContentPath);

	// 상위폴더로 이동해서
	// \\Output\\content\\ 폴더로 이동
	for (int i = strLen - 1; i >= 0; --i)  //wchar_t 문자열의 길이 확인
	{
		if ('\\' == m_strContentPath[i])
		{
			m_strContentPath[i] = '\0';
			break;
		}
	}
		wcscat_s(m_strContentPath, 255, L"\\Release\\content\\"); // 기존에 문자열 뒤에  \\output\\ content\\ 붙이기	}

		// 하는 이유 release debug 모드 모두 리소스를 사용해야하는데
		// 만약에 두 폴더 모두 리소스파일을 가지고 있으면 리소스 용량이 2배가 된다
		// 같은 리소스를 2개씩 가지고 있기 때문에 비효율적임
		// 그래서 리소스 폴더로 가서 한 폴더로 관리하기 위함

		Logger::info(m_strContentPath);
	
}
const wchar_t* PathManager::getContentPath()
{
	return m_strContentPath;
}

const wchar_t* PathManager::getContentRelativePath()
{
	return L"..\\Release\\content\\";
}
