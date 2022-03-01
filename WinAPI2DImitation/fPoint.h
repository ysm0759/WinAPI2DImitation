#include <assert.h>

struct fPoint
{
	float x;
	float y;

	fPoint()
	{
		x = -0.f;
		y = -0.f;
	}

	fPoint(float _x, float _y)
	{
		this->x = _x;
		this->y = _y;
	}
};


struct Vec2
{
	float x;
	float y;

	Vec2()
	{
		x = -0.f;
		y = -0.f;
	}

	Vec2(float _x, float _y)
	{
		this->x = _x;
		this->y = _y;
	}
	Vec2& normalize()
	{
		// �밢���� ���̸� �����ش�����
		float length = (float)sqrt((double)(x * x + y * y));

		assert(length != 0.f);
		/***
		* �� ���̸�ŭ x �� y���� �������ָ�
		* ex ���� 0 , 0 ��ǥ����
		* 200 , 100 ��ǥ�������� �����������
		* 100 * 100 + 100 * 100 = 20000
		* root(20000)
		* root(20000)�� �� �࿡ �������ָ� 
		* x�� ������ y�� ������ ���´�
		***/
		x = x / length;
		y = y / length;

		return *this;

	}

};