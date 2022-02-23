#pragma once
class Player : public GameObject
{

public:
	Player(fPoint _pos, fPoint _scale);
	~Player();
	
	virtual void update();
	virtual void render(HDC hDC);
};

