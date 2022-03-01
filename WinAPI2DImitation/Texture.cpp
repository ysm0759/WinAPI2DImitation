#pragma once
#include "framework.h"
#include "Texture.h"

Texture::Texture()
{
	m_hDC = { 0 };
	m_hBMP = { 0 };
	m_bmpInfo = { 0 };
}

Texture::~Texture()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hBMP);
}

HDC Texture::getDC()
{
	return m_hDC;
}

HBITMAP Texture::getBitmap()
{
	return m_hBMP;
}

BITMAP Texture::getBitInfo()
{
	return m_bmpInfo;
}

int Texture::getBmpWidth()
{
	return (int)(m_bmpInfo.bmWidth);
}

int Texture::getBmpHeight()
{
	return (int)(m_bmpInfo.bmHeight);
}

void Texture::load(const wstring& _strFilePath)
{
	m_hBMP = (HBITMAP)LoadImage(
		nullptr,								// hInstance . nullptr �� �ص� ��
		_strFilePath.c_str(),					// ���� ��θ� c style ���ڿ��� ��ȯ
		IMAGE_BITMAP,							// �̹��� Ÿ��, ��Ʈ�� �̹����� ����
		0, 0,									// �̹����� X, Y ũ��, 0�� �ָ� �̹��� ũ��� ����
		LR_CREATEDIBSECTION | LR_LOADFROMFILE	// �̹��� �ε� Ÿ��.
	);

	assert(m_hBMP); //�̹����� ���ٸ� assert
	

	// ��Ʈ�ʰ� ������ DC
	m_hDC = CreateCompatibleDC(Core::getInst()->getMainDC());

	// ��Ʈ�ʰ� DC ����
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hDC, m_hBMP);

	// ��Ʈ�� ����
	GetObject(m_hBMP, sizeof(BITMAP), &m_bmpInfo);

}
