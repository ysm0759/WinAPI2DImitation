#pragma once
#include "Core.h"

class SelectGDI
{
private:

	HDC m_hDC;
	HPEN m_hDefaultPen;
	HBRUSH m_hDefaultBrush;

public:

	SelectGDI(HDC _hDC, TYPE_BRUSH _brushType)
	{
		m_hDC = _hDC;
		HBRUSH hBrush = Core::getInst()->getBrush(_brushType);
		m_hDefaultBrush = (HBRUSH)SelectObject(_hDC, hBrush);
		m_hDefaultPen = 0;
	}

	SelectGDI(HDC _hDC, TYPE_PEN _penType)
	{
		m_hDC = _hDC;
		HPEN hPen = Core::getInst()->getPen(_penType);
		m_hDefaultPen = (HPEN)SelectObject(_hDC, hPen);
		m_hDefaultBrush = 0;
	}

	~SelectGDI()
	{
		SelectObject(m_hDC, m_hDefaultBrush);
		SelectObject(m_hDC, m_hDefaultPen);
	}
};
