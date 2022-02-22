#pragma once

/***
* 컴퓨터 마다 연산 속도가 다르다.
* 슈퍼컴퓨터에서는 1초에 100000번 연산하고
* 콩순이 컴퓨터에서는 1초에 10번 연산한다고 가정하면
* 각 컴퓨터에 사양에 따라 게임 속도가 달라진다.
* 100pixel의 거리만큼 간다고 코딩해서 += 100 하면
* 슈퍼컴퓨터는 1초에 10000000 pixel만큼 이동하고
* 콩순이 컴퓨터는 1초에 1000 pixel 만큼 이동한다
* 이를 해결하기 위해
* 업데이트 카운트를 구해서 
* 그 카운트 만큼 나눈 거리만큼 이동하면 컴퓨터
* 속도에 관계없이 같은 거리를 이동한다.
* 100 * 1 / 100000  = 1/1000 슈퍼컴퓨터 1번 업데이트에 이동하는거리
* 100 * 1 / 10      = 10 콩순이 컴퓨터 1번 업데이트에 이동하는거리
* 이런 방법으로 해결한다.
***/

class TimeManager
{
	SINGLETON(TimeManager);

private:

	// LARGE_INTEGER : long long 변수의 공용체 HighPart + LowPart = QuadPart
	LARGE_INTEGER m_llCurCount;		// 현재 카운트
	LARGE_INTEGER m_llPrevCount;	// 이전 카운트
	LARGE_INTEGER m_llFrequency;	// 초당 카운트 횟수

	unsigned int	m_uiFPS;	// FPS		: 1초당 그려진 화면 수
	double			m_dDT;		// Delta Time	: 1프레임당 소요된 시간

public:
	void update();
	void init();

	unsigned int getFPS();
	double getDT();
};

