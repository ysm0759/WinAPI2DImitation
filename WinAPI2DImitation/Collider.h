#pragma once

class GameObject;

class Collider
{
	friend class GameObject;

private:
	static UINT s_iID;

	GameObject* m_pOwner;		// 충돌체를 가지는 게임오브젝트의 주소
	fPoint m_fptOffsetPos;		// 충돌체의 변위차(수정값)
	fPoint m_fptFinalPos;		// 충돌체의 최종 위치
	fPoint m_fptScale;			// 충돌체의 크기
	int m_iColCount;			// 충돌중

	UINT m_iID;					// 충돌체 고유한 ID 값

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

	Collider& operator=(Collider& _other) = delete;	// 함수를 사용할 수 없게 막음.

	void finalUpdate();
	void render(HDC hDC);

	// 충돌 시점 함수
	void onCollision(Collider* pOther);
	void onCollisionEnter(Collider* pOther);
	void onCollisionExit(Collider* pOther);
};

