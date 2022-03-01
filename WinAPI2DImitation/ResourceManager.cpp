#include "framework.h"
#include "ResourceManager.h"
#include "Texture.h"

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
	//가지고 있는 리소스들 전부 삭제
	map<wstring, Texture*>::iterator iter = this->m_mapTex.begin();

	for (; iter != m_mapTex.end(); iter++)
		delete iter->second;

	m_mapTex.clear(); // 그냥 clear만 쓰게 되면 데이터가 사라지지 않고 delete iter -> second 해줘야함;
	
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
	// map에 원하는 데이터가 기존에 있으면 그 리소스를 반환
	Texture* loadTexture = findTexture(_strKey);
	if (nullptr != loadTexture)
	{
		return loadTexture;
	}

	// 저장 경로 확인
	wstring strFilePath = PathManager::getInst()->getContentPath(); //가져온 path에 
	strFilePath += _strRelativePath; // 추가 경로를 붙이고

	// 생성 후 저장
	loadTexture = new Texture;
	loadTexture->load(strFilePath); //로드
	loadTexture->setKey(_strKey); // 키값 세팅
	loadTexture->setRelativePath(_strRelativePath); // 경로 세팅
	m_mapTex.insert(make_pair(_strKey, loadTexture));  // 이진트리에 삽입
	return loadTexture;
}
