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
	* ���� �׷찣�� �浹�� ��Ʈ�� ���ؼ� ����
	* ex) m_arrCheck[GROUP_GAMEOBJ::PLAYER] = 0000 0000 0000 1100 �϶�
	* player �׷��� 3, 2 ��° �׷��� Missile�� Monster�� �浹�Ѵ�.
	***/

	UINT m_arrCheck[(UINT)GROUP_GAMEOBJ::SIZE];		//�浹�ؾ��ϴ� �׷���� ���� �迭
	map<ULONGLONG, bool> m_mapCollInfo;				// �浹ü ���� ���� update �浹 ����

	void CollisionGroupUpdate(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight);
	bool IsCollision(Collider* _pLeftCollider, Collider* _pRightCollider);

public:
	void init();
	void update();

	void CheckGroup(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight);	// �׷찣 �浹 ����
	void UnCheckGroup(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight);	// �׷찣 �浹 ����
	void Reset();
};

