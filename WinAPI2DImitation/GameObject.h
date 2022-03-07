
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


	virtual void finalUpdate() final;	// 상속받는 클래스가 오버라이딩 할 수 없게 막는 final 키워드
	virtual void componentRender(HDC _hDC);	// 컴포넌트들의 영역을 표시하기 위해


	Collider* getCollider();				// 충돌체 반환
	void createCollider();					// 충돌체 생성

	virtual void onCollision(Collider* _pOther) {}			// 재정의용 충돌중 가상함수
	virtual void onCollisionEnter(Collider* _pOther) {}	// 재정의용 충돌시 가상함수
	virtual void onCollisionExit(Collider* _pOther) {}		// 재정의용 탈충돌 가상함수
};
