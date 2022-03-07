#pragma once
class Missile : public GameObject
{

private :
	fVec2 m_fvDir;
	float m_fVelocity;
	bool m_bIsGravity;
	float m_fGravity;

public:
	Missile();
	Missile(fVec2 _vec2, fPoint _pos , bool _isGravity = false);
	~Missile();

	virtual Missile* clone();



	virtual void update();
	virtual void render(HDC _hDC);

	void onCollisionEnter(Collider* _pOther);
};


