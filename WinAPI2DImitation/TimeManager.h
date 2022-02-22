#pragma once

/***
* ��ǻ�� ���� ���� �ӵ��� �ٸ���.
* ������ǻ�Ϳ����� 1�ʿ� 100000�� �����ϰ�
* ����� ��ǻ�Ϳ����� 1�ʿ� 10�� �����Ѵٰ� �����ϸ�
* �� ��ǻ�Ϳ� ��翡 ���� ���� �ӵ��� �޶�����.
* 100pixel�� �Ÿ���ŭ ���ٰ� �ڵ��ؼ� += 100 �ϸ�
* ������ǻ�ʹ� 1�ʿ� 10000000 pixel��ŭ �̵��ϰ�
* ����� ��ǻ�ʹ� 1�ʿ� 1000 pixel ��ŭ �̵��Ѵ�
* �̸� �ذ��ϱ� ����
* ������Ʈ ī��Ʈ�� ���ؼ� 
* �� ī��Ʈ ��ŭ ���� �Ÿ���ŭ �̵��ϸ� ��ǻ��
* �ӵ��� ������� ���� �Ÿ��� �̵��Ѵ�.
* 100 * 1 / 100000  = 1/1000 ������ǻ�� 1�� ������Ʈ�� �̵��ϴ°Ÿ�
* 100 * 1 / 10      = 10 ����� ��ǻ�� 1�� ������Ʈ�� �̵��ϴ°Ÿ�
* �̷� ������� �ذ��Ѵ�.
***/

class TimeManager
{
	SINGLETON(TimeManager);

private:

	// LARGE_INTEGER : long long ������ ����ü HighPart + LowPart = QuadPart
	LARGE_INTEGER m_llCurCount;		// ���� ī��Ʈ
	LARGE_INTEGER m_llPrevCount;	// ���� ī��Ʈ
	LARGE_INTEGER m_llFrequency;	// �ʴ� ī��Ʈ Ƚ��

	unsigned int	m_uiFPS;	// FPS		: 1�ʴ� �׷��� ȭ�� ��
	double			m_dDT;		// Delta Time	: 1�����Ӵ� �ҿ�� �ð�

public:
	void update();
	void init();

	unsigned int getFPS();
	double getDT();
};

