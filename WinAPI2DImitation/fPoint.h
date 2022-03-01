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
		// 대각선의 길이를 구해준다음에
		float length = (float)sqrt((double)(x * x + y * y));

		assert(length != 0.f);
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

		return *this;

	}

};