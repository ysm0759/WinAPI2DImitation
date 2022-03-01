#pragma once

class Texture;

class ResourceManager
{
	SINGLETON(ResourceManager);

private:
	map<wstring, Texture*> m_mapTex; // Texture ���ҽ��� ���� �ڷ� ����


public:
	Texture* findTexture(const wstring& _strKey); //����� Texture Ž��
	Texture* loadTexture(const wstring& _strKey, const wstring& strRelatviePath);// Texture �ҷ����� �̹� �ִ� ��� �ִ� Texture ��ȯ
};

