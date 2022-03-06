#pragma once

class Core
{
	SINGLETON(Core);

private:
	HDC m_hDC;
	HDC m_hMemDC;
	HBITMAP m_hBMP;

	// GDI
	HBRUSH m_arrBrush[(int)TYPE_BRUSH::SIZE];
	HPEN m_arrPen[(int)TYPE_PEN::SIZE];

public:
	void update();
	void render();
	void init();

	HDC getMainDC();
	HDC getMemDC();

	void createBrushPen();
	HBRUSH getBrush(TYPE_BRUSH _type);
	HPEN getPen(TYPE_PEN _type);
};

