#pragma once
class Texture;

class Player : public GameObject
{
	Texture* m_pTex;
	float m_fVelocity = 300;

	void createMissile();

public:
	Player(fPoint _pos);
	~Player();
	virtual Player* Clone();
	
	virtual void update();
	virtual void render(HDC hDC);
};

