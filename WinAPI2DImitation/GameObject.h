
#pragma once
class GameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	
	GameObject();
	GameObject(fPoint pos, fPoint scale);
	virtual ~GameObject();

	void setPos(fPoint pos);
	void setScale(fPoint scale);

	fPoint getPos();
	fPoint getScale();

	virtual void update();
	virtual void render(HDC hDC);

};
