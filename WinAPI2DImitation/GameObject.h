
#pragma once

class Collider;
class Animator;

class GameObject
{

	friend class EventManager;

private:
	fPoint m_fptPos;
	fPoint m_fptScale;
	UINT m_ID;
	Collider* m_pCollider;
	Animator* m_pAnimator;
	bool m_bAlive;
	void setDead();

public:
	
	GameObject();
	GameObject(fPoint pos, fPoint scale);

	virtual ~GameObject();

	//���� �����Լ�
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


	// collider ����
	Collider* getCollider();				// �浹ü ��ȯ
	void createCollider();					// �浹ü ����
	virtual void onCollision(Collider* _pOther) {}			// �����ǿ� �浹�� �����Լ�
	virtual void onCollisionEnter(Collider* _pOther) {}	// �����ǿ� �浹�� �����Լ�
	virtual void onCollisionExit(Collider* _pOther) {}		// �����ǿ� Ż�浹 �����Լ�
	virtual void componentRender(HDC _hDC);	// ������Ʈ���� ������ ǥ���ϱ� ����
	virtual void finalUpdate() final;	// ��ӹ޴� Ŭ������ �������̵� �� �� ���� ���� final Ű����


	// Animator
	Animator* getAnimator();				// �ִϸ����� ��ȯ
	void createAnimator();					// �ִϸ����� ����

};
