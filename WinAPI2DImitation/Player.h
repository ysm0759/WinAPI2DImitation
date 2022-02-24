#pragma once
class Player : public GameObject
{

public:
	Player(fPoint _pos);
	~Player();
	
	virtual void update();
	virtual void render(HDC hDC);
};

