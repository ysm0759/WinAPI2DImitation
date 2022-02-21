
#pragma once
class GameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	GameObject();
	GameObject(fPoint pos, fPoint scale);
	~GameObject();

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);

	fPoint GetPos();
	fPoint GetScale();
};
