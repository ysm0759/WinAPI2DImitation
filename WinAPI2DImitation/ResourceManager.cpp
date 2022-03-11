#include "framework.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Sound.h"

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
	//������ �ִ� ���ҽ��� ���� ����
	map<wstring, Texture*>::iterator texIter = this->m_mapTex.begin();
	map<wstring, Sound*>::iterator soundIter = this->m_mapSound.begin();
	for (; texIter != m_mapTex.end(); texIter++)
		delete texIter->second;

	for (; soundIter != m_mapSound.end(); soundIter++)
		delete soundIter->second;


	m_mapTex.clear(); // �׳� clear�� ���� �Ǹ� �����Ͱ� ������� �ʰ� delete iter -> second �������;
	m_mapSound.clear();
	
}

void ResourceManager::init()
{

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

Sound* ResourceManager::findSound(const wstring& _strKey)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(_strKey);

	if (m_mapSound.end() == iter)
	{
		return nullptr;
	}

	return iter->second;
}

Sound* ResourceManager::loadSound(const wstring& _strKey, const wstring& _strRelativePath)
{
	// map�� ���ϴ� �����Ͱ� ������ ������ �� ���ҽ��� ��ȯ
	Sound* loadSound = findSound(_strKey);
	if (nullptr != loadSound)
	{
		return loadSound;
	}

	// ���� ��� Ȯ��
	wstring strFilePath = PathManager::getInst()->getContentRelativePath(); //������ path�� 
	strFilePath += _strRelativePath; // �߰� ��θ� ���̰�

	// ���� �� ����
	loadSound = new Sound;
	loadSound->load(strFilePath); //�ε�
	loadSound->setKey(_strKey); // Ű�� ����
	loadSound->setRelativePath(_strRelativePath); // ��� ����
	m_mapSound.insert(make_pair(_strKey, loadSound));  // ����Ʈ���� ����
	return loadSound;
}
