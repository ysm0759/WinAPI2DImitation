#include <assert.h>


struct iPoint
{
	int x;
	int y;
};

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

	fPoint& operator=(const fPoint& _other)
	{
		x = _other.x;
		y = _other.y;
		return *this;
	}

	fPoint operator+(const fPoint& _other)
	{
		return fPoint(x + _other.x, y + _other.y);
	}

	fPoint operator-(const fPoint& _other)
	{
		return fPoint(x - _other.x, y - _other.y);
	}


	template <typename T>
	fPoint operator*(T num)
	{
		return fPoint(x * num, y * num);
	}

	template <typename T>
	fPoint operator/(T num)
	{
		assert(0 != num);

		return fPoint(x / num, y / num);
	}

	fPoint& normalize()
	{
		// �밢���� ���̸� �����ش�����
		float length = (float)sqrt((double)x * x + (double)y * y);

		if (0 == length)
		{
			x = 0;
			y = 0;
		}
		else
		{
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
		}

		return *this;
	}

	float Length()
	{
		return (float)sqrt((double)x * x + (double)y * y);
	}
};



typedef iPoint iVec2;
typedef fPoint fVec2;