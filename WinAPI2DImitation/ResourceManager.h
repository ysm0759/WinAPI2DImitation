#pragma once

class Texture;
class Sound;

class ResourceManager
{
	SINGLETON(ResourceManager);

private:
	map<wstring, Texture*> m_mapTex; // Texture ���ҽ��� ���� �ڷ� ����
	map<wstring, Sound*> m_mapSound;

public:
	void init();
	Texture* findTexture(const wstring& _strKey); //����� Texture Ž��
	Texture* loadTexture(const wstring& _strKey, const wstring& strRelatviePath);// Texture �ҷ����� �̹� �ִ� ��� �ִ� Texture ��ȯ

	Sound* findSound(const wstring& _strKey);
	Sound* loadSound(const wstring& _strKey, const wstring& _strRelativePath);
};

