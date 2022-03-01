#pragma once

class Texture;

class ResourceManager
{
	SINGLETON(ResourceManager);

private:
	map<wstring, Texture*> m_mapTex; // Texture 리소스의 저장 자료 구조


public:
	Texture* findTexture(const wstring& _strKey); //저장된 Texture 탐색
	Texture* loadTexture(const wstring& _strKey, const wstring& strRelatviePath);// Texture 불러오기 이미 있는 경우 있던 Texture 반환
};

