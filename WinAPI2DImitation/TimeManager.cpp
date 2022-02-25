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
	// 이전 프레임의 카운팅과, 현재 프레임 카운팅 값의 차이를 구한다.
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / m_llFrequency.QuadPart;
	// 이전 프레임을 현재 프레임 카운팅 값으로 넣는다.
	m_llPrevCount = m_llCurCount;

	++updateCount;
	updateOneSecond += m_dDT; // 걸린시간 누적
	if (updateOneSecond >= 1.0) // 시간이 1초가 되면
	{ // 다시 FPS 프레임 계산 , 초기화
		m_uiFPS = updateCount;

		updateOneSecond = 0;
		updateCount = 0;
	}
	

	
}

void TimeManager::init()
{
	// init 함수가 호출될 때 m_llPrevCount에 입력	
	QueryPerformanceCounter(&m_llPrevCount);
	// 초당 카운트 횟수
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

float TimeManager::getFDT()
{
	return (float)m_dDT;
}