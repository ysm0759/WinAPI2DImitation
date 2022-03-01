#pragma once

class Core
{
	SINGLETON(Core);

private:
	HDC m_hDC;
	HDC m_hMemDC;
	HBITMAP m_hBMP;


public:
	void update();
	void render();
	void init();
	HDC getMainDC();
	HDC getMemDC();
};

