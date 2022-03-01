#pragma once
#include "Resource.h"

class Texture : public Resource
{
private:
	HDC m_hDC;
	HBITMAP m_hBMP;
	BITMAP m_bmpInfo;

public:
	Texture();
	virtual ~Texture();

	HDC getDC();
	HBITMAP getBitmap();
	BITMAP getBitInfo();


	int getBmpWidth();
	int getBmpHeight();

	void load(const wstring& _strFilePath);


};