#pragma once

class Texture;
class Sound;

class ResourceManager
{
	SINGLETON(ResourceManager);

private:
	map<wstring, Texture*> m_mapTex; // Texture 리소스의 저장 자료 구조
	map<wstring, Sound*> m_mapSound;

public:
	void init();
	Texture* findTexture(const wstring& _strKey); //저장된 Texture 탐색
	Texture* loadTexture(const wstring& _strKey, const wstring& strRelatviePath);// Texture 불러오기 이미 있는 경우 있던 Texture 반환

	Sound* findSound(const wstring& _strKey);
	Sound* loadSound(const wstring& _strKey, const wstring& _strRelativePath);
};

