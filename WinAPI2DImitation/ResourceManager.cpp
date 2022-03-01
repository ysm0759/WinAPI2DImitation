#include "framework.h"
#include "ResourceManager.h"
#include "Texture.h"

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
	//������ �ִ� ���ҽ��� ���� ����
	map<wstring, Texture*>::iterator iter = this->m_mapTex.begin();

	for (; iter != m_mapTex.end(); iter++)
		delete iter->second;

	m_mapTex.clear(); // �׳� clear�� ���� �Ǹ� �����Ͱ� ������� �ʰ� delete iter -> second �������;
	
}


Texture* ResourceManager::findTexture(const wstring& _strKey)
{
	map<wstring, Texture*>::iterator iter = m_mapTex.find(_strKey);

	if (m_mapTex.end() == iter)
	{
		return nullptr;
	}

	return iter->second;
}

Texture* ResourceManager::loadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	// map�� ���ϴ� �����Ͱ� ������ ������ �� ���ҽ��� ��ȯ
	Texture* loadTexture = findTexture(_strKey);
	if (nullptr != loadTexture)
	{
		return loadTexture;
	}

	// ���� ��� Ȯ��
	wstring strFilePath = PathManager::getInst()->getContentPath(); //������ path�� 
	strFilePath += _strRelativePath; // �߰� ��θ� ���̰�

	// ���� �� ����
	loadTexture = new Texture;
	loadTexture->load(strFilePath); //�ε�
	loadTexture->setKey(_strKey); // Ű�� ����
	loadTexture->setRelativePath(_strRelativePath); // ��� ����
	m_mapTex.insert(make_pair(_strKey, loadTexture));  // ����Ʈ���� ����
	return loadTexture;
}
