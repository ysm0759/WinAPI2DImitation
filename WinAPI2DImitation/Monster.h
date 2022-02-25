#pragma once


class Monster : public GameObject
{
private:

	bool isUp;
	unsigned int velocity;

public:
	Monster();
	~Monster();

	virtual void update();
	virtual void render(HDC _hDC);

};

