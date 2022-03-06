
#pragma once

class Collider;

class GameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;
	Collider* m_pCollider;
	
public:
	
	GameObject();
	GameObject(fPoint pos, fPoint scale);
	virtual ~GameObject();

	void setPos(fPoint pos);
	void setScale(fPoint scale);

	fPoint getPos();
	fPoint getScale();

	virtual void update() = 0;
	virtual void finalUpdate() final;	// ��ӹ޴� Ŭ������ �������̵� �� �� ���� ���� final Ű����
	virtual void render(HDC _hDC) = 0;
	virtual void componentRender(HDC _hDC);	// ������Ʈ���� ������ ǥ���ϱ� ����


	Collider* getCollider();				// �浹ü ��ȯ
	void createCollider();					// �浹ü ����

	bool isDead() { return true; }

	virtual void onCollision(Collider* _pOther) {}			// �����ǿ� �浹�� �����Լ�
	virtual void onCollisionEnter(Collider* _pOther) {}	// �����ǿ� �浹�� �����Լ�
	virtual void onCollisionExit(Collider* _pOther) {}		// �����ǿ� Ż�浹 �����Լ�
};
