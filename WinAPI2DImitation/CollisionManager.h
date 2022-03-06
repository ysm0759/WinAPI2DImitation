#pragma once

class Collider;

union ColliderID
{
	struct
	{
		UINT leftID;
		UINT rightID;
	};
	ULONGLONG ID;
};


class CollisionManager
{
	SINGLETON(CollisionManager);

private:
	/***
	* 여러 그룹간의 충돌을 비트를 통해서 구분
	* ex) m_arrCheck[GROUP_GAMEOBJ::PLAYER] = 0000 0000 0000 1100 일때
	* player 그룹은 3, 2 번째 그룹인 Missile과 Monster에 충돌한다.
	***/

	UINT m_arrCheck[(UINT)GROUP_GAMEOBJ::SIZE];		//충돌해야하는 그룹들을 가진 배열
	map<ULONGLONG, bool> m_mapCollInfo;				// 충돌체 간의 이전 update 충돌 정보

	void CollisionGroupUpdate(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight);
	bool IsCollision(Collider* _pLeftCollider, Collider* _pRightCollider);

public:
	void init();
	void update();

	void CheckGroup(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight);	// 그룹간 충돌 설정
	void UnCheckGroup(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight);	// 그룹간 충돌 해제
	void Reset();
};

