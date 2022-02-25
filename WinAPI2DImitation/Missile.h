#pragma once
class Missile : public GameObject
{

private :
	Vec2 m_fvDir;
	float m_fVelocity;

public:
	Missile();
	Missile(Vec2 _vec2, fPoint _pos);
	~Missile();


	virtual void update();
	virtual void render(HDC _hDC);
};

