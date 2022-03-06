
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
	virtual void finalUpdate() final;	// 상속받는 클래스가 오버라이딩 할 수 없게 막는 final 키워드
	virtual void render(HDC _hDC) = 0;
	virtual void componentRender(HDC _hDC);	// 컴포넌트들의 영역을 표시하기 위해


	Collider* getCollider();				// 충돌체 반환
	void createCollider();					// 충돌체 생성

	bool isDead() { return true; }

	virtual void onCollision(Collider* _pOther) {}			// 재정의용 충돌중 가상함수
	virtual void onCollisionEnter(Collider* _pOther) {}	// 재정의용 충돌시 가상함수
	virtual void onCollisionExit(Collider* _pOther) {}		// 재정의용 탈충돌 가상함수
};
