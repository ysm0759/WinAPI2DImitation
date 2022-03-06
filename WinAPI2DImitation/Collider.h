#pragma once

class GameObject;

class Collider
{
	friend class GameObject;

private:
	static UINT s_iID;

	GameObject* m_pOwner;		// �浹ü�� ������ ���ӿ�����Ʈ�� �ּ�
	fPoint m_fptOffsetPos;		// �浹ü�� ������(������)
	fPoint m_fptFinalPos;		// �浹ü�� ���� ��ġ
	fPoint m_fptScale;			// �浹ü�� ũ��
	int m_iColCount;			// �浹��

	UINT m_iID;					// �浹ü ������ ID ��

public:
	Collider();
	Collider(const Collider& _other);
	~Collider();

	GameObject* getObj();
	fPoint getOffsetPos();
	fPoint getFinalPos();
	fPoint getScale();

	void setOffsetPos(fPoint _offsetPos);
	void setFinalPos(fPoint _finalPos);
	void setScale(fPoint _scale);
	UINT getID();

	Collider& operator=(Collider& _other) = delete;	// �Լ��� ����� �� ���� ����.

	void finalUpdate();
	void render(HDC hDC);

	// �浹 ���� �Լ�
	void onCollision(Collider* pOther);
	void onCollisionEnter(Collider* pOther);
	void onCollisionExit(Collider* pOther);
};

