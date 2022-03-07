
#pragma once

class Collider;

class GameObject
{

	friend class EventManager;

private:
	fPoint m_fptPos;
	fPoint m_fptScale;
	UINT m_ID;
	Collider* m_pCollider;

	bool m_bAlive;
	void setDead();

public:
	
	GameObject();
	GameObject(fPoint pos, fPoint scale);

	virtual ~GameObject();
	virtual GameObject* clone() = 0;
	virtual void render(HDC _hDC) = 0;
	virtual void update() = 0;


	void setPos(fPoint pos);
	void setScale(fPoint scale);
	void setID(UINT _ID);
	fPoint getPos();
	fPoint getScale();
	UINT getID();
	bool isDead();


	virtual void finalUpdate() final;	// ��ӹ޴� Ŭ������ �������̵� �� �� ���� ���� final Ű����
	virtual void componentRender(HDC _hDC);	// ������Ʈ���� ������ ǥ���ϱ� ����


	Collider* getCollider();				// �浹ü ��ȯ
	void createCollider();					// �浹ü ����

	virtual void onCollision(Collider* _pOther) {}			// �����ǿ� �浹�� �����Լ�
	virtual void onCollisionEnter(Collider* _pOther) {}	// �����ǿ� �浹�� �����Լ�
	virtual void onCollisionExit(Collider* _pOther) {}		// �����ǿ� Ż�浹 �����Լ�
};
