
#include "framework.h"
#include "Resource.h"

Resource::Resource()
{
}

Resource::~Resource()
{
}

void Resource::setKey(const wstring& _strKey)
{
	m_strKey = _strKey;
}

void Resource::setRelativePath(const wstring& _strPath)
{
	m_strRelativePath = _strPath;
}

const wstring& Resource::getKey()
{
	return m_strKey;
}

const wstring& Resource::getRelativePath()
{
	return m_strRelativePath;
}
