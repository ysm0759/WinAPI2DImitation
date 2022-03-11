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

	// ���������� �̵��ؼ�
	// \\Output\\content\\ ������ �̵�
	for (int i = strLen - 1; i >= 0; --i)  //wchar_t ���ڿ��� ���� Ȯ��
	{
		if ('\\' == m_strContentPath[i])
		{
			m_strContentPath[i] = '\0';
			break;
		}
	}
		wcscat_s(m_strContentPath, 255, L"\\Release\\content\\"); // ������ ���ڿ� �ڿ�  \\output\\ content\\ ���̱�	}

		// �ϴ� ���� release debug ��� ��� ���ҽ��� ����ؾ��ϴµ�
		// ���࿡ �� ���� ��� ���ҽ������� ������ ������ ���ҽ� �뷮�� 2�谡 �ȴ�
		// ���� ���ҽ��� 2���� ������ �ֱ� ������ ��ȿ������
		// �׷��� ���ҽ� ������ ���� �� ������ �����ϱ� ����

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
