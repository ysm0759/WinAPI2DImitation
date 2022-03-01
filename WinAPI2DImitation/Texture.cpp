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
		nullptr,								// hInstance . nullptr 로 해도 됨
		_strFilePath.c_str(),					// 파일 경로를 c style 문자열로 변환
		IMAGE_BITMAP,							// 이미지 타입, 미트맵 이미지로 지정
		0, 0,									// 이미지의 X, Y 크기, 0을 주면 이미지 크기로 설정
		LR_CREATEDIBSECTION | LR_LOADFROMFILE	// 이미지 로딩 타입.
	);

	assert(m_hBMP); //이미지가 없다면 assert
	

	// 비트맵과 연결할 DC
	m_hDC = CreateCompatibleDC(Core::getInst()->getMainDC());

	// 비트맵과 DC 연결
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hDC, m_hBMP);

	// 비트맵 정보
	GetObject(m_hBMP, sizeof(BITMAP), &m_bmpInfo);

}
