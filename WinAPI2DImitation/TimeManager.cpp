#include "framework.h"
#include "TimeManager.h"

TimeManager::TimeManager()
{

}

TimeManager::~TimeManager()
{

}

void TimeManager::update()
{
	static unsigned int updateCount = 0;
	static double updateOneSecond = 0;

	QueryPerformanceCounter(&m_llCurCount);
	// ���� �������� ī���ð�, ���� ������ ī���� ���� ���̸� ���Ѵ�.
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / m_llFrequency.QuadPart;
	// ���� �������� ���� ������ ī���� ������ �ִ´�.
	m_llPrevCount = m_llCurCount;

	++updateCount;
	updateOneSecond += m_dDT;
	if (updateOneSecond >= 1.0)
	{
		m_uiFPS = updateCount;

		updateOneSecond = 0;
		updateCount = 0;
	}
}

void TimeManager::init()
{
	QueryPerformanceCounter(&m_llCurCount);
	QueryPerformanceFrequency(&m_llFrequency);
}

unsigned int TimeManager::getFPS()
{
	return m_uiFPS;
}

double TimeManager::getDT()
{
	return m_dDT;
}
