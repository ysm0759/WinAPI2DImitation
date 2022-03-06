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
		// 대각선의 길이를 구해준다음에
		float length = (float)sqrt((double)x * x + (double)y * y);

		if (0 == length)
		{
			x = 0;
			y = 0;
		}
		else
		{
			/***
			* 그 길이만큼 x 축 y축을 나누어주면
			* ex 내가 0 , 0 좌표에서
			* 200 , 100 좌표방향으로 보내고싶으면
			* 100 * 100 + 100 * 100 = 20000
			* root(20000)
			* root(20000)을 각 축에 나누어주면
			* x축 비율과 y축 비율이 나온다
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